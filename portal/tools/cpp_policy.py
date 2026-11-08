#!/usr/bin/env python3
"""
Genuine-C++ submission policy for the Scarface decomp portal (MSVC 7.1, cl.exe 13.10.3052).

Drop-in replacement for the comment stripping + keyword check at the top of
``compile_and_verify_cpp()`` in ``portal/decomp_portal_server.py``.

What it fixes compared to the old regex version:
  * Comment stripping understands string and character literals, so ``"http://x"``
    and ``"/*"`` no longer eat real code (which could hide code from the check).
  * Translation phases 1-2 are applied first (trigraphs, backslash-newline splices),
    so ``__a\\<newline>sm`` is seen as ``__asm``.
  * ``naked`` is only rejected inside ``__declspec(...)``; an ordinary identifier
    called ``naked`` is allowed.
  * Section/segment pragmas, ``__declspec(allocate)``, ``#import``/``#using``,
    computed includes and include paths that escape the project are rejected.
  * Text inside string literals is ignored by the keyword scan.

Macros can still assemble forbidden tokens, so the authoritative check is the
*preprocessed* output.  Recommended server flow:

    violations = check_genuine_cpp(cpp_code)                 # fast pre-check on raw source
    if violations:
        return {"ok": False, "compiler_error": format_violations(violations)}

    # compile as usual, plus a preprocess-only pass with the SAME flags/includes:
    #   cl /nologo /E <flags> submission.cpp  > submission.i     (/E keeps #line markers)
    violations = check_preprocessed(pp_text, user_paths=[submission_dir, repo_include_dir])
    if violations:
        return {"ok": False, "compiler_error": format_violations(violations)}

``user_paths`` limits the preprocessed check to lines that came from the
submission and the project's own headers, so SDK/CRT headers cannot trigger
false positives.
"""

from __future__ import annotations

import re
from dataclasses import dataclass
from typing import Iterable, List, Optional, Sequence, Tuple

__all__ = [
    "Violation",
    "strip_cpp_comments",
    "check_genuine_cpp",
    "check_preprocessed",
    "format_violations",
]

# --------------------------------------------------------------------------- #
# Rules
# --------------------------------------------------------------------------- #

FORBIDDEN_TOKENS = {
    "__asm": "inline assembly (__asm)",
    "_asm": "inline assembly (_asm)",
    "asm": "inline assembly (asm)",
    "__asm__": "inline assembly (__asm__)",
    "_emit": "raw byte emission (_emit)",
    "__emit": "raw byte emission (__emit)",
    "__pragma": "__pragma() operator (use of section/segment pragmas is not allowed)",
    "_Pragma": "_Pragma() operator (use of section/segment pragmas is not allowed)",
}

FORBIDDEN_DECLSPEC_WORDS = {
    "naked": "__declspec(naked) functions",
    "allocate": "__declspec(allocate) section placement",
    "code_seg": "__declspec(code_seg) section placement",
}

FORBIDDEN_PRAGMAS = {
    "code_seg": "#pragma code_seg (moves code into custom sections)",
    "data_seg": "#pragma data_seg (moves data into custom sections)",
    "const_seg": "#pragma const_seg (moves data into custom sections)",
    "bss_seg": "#pragma bss_seg (moves data into custom sections)",
    "section": "#pragma section (declares custom sections)",
    "alloc_text": "#pragma alloc_text (moves code into custom sections)",
    "init_seg": "#pragma init_seg (changes static-init sections)",
    "comment": "#pragma comment (embeds linker/library directives)",
}

FORBIDDEN_DIRECTIVES = {
    "import": "#import (loads type libraries from the server)",
    "using": "#using (loads assemblies from the server)",
}

_TRIGRAPHS = {"=": "#", "/": "\\", "'": "^", "(": "[", ")": "]", "!": "|", "<": "{", ">": "}", "-": "~"}
_TRIGRAPH_RE = re.compile(r"\?\?([=/'()!<>\-])")
_TOKEN_RE = re.compile(r"(?<![A-Za-z0-9_$])(" + "|".join(sorted(map(re.escape, FORBIDDEN_TOKENS), key=len, reverse=True)) + r")(?![A-Za-z0-9_$])")
_DECLSPEC_RE = re.compile(r"(?<![A-Za-z0-9_$])_{1,2}declspec\s*\(((?:[^()]|\([^()]*\))*)\)")
_DIRECTIVE_RE = re.compile(r"^\s*#\s*([A-Za-z_]\w*)(.*)$")
_LINE_MARKER_RE = re.compile(r'^\s*#\s*(?:line\s+)?(\d+)\s+"((?:[^"\\]|\\.)*)"')


@dataclass(frozen=True)
class Violation:
    line: int          # 1-based physical line in the submitted text
    rule: str          # short rule id
    message: str       # human-readable explanation
    snippet: str       # offending text (trimmed)

    def __str__(self) -> str:
        return f"line {self.line}: {self.message}  ->  {self.snippet}"


# --------------------------------------------------------------------------- #
# Translation phases 1-3 (enough for scanning)
# --------------------------------------------------------------------------- #

def _replace_trigraphs(src: str) -> str:
    return _TRIGRAPH_RE.sub(lambda m: _TRIGRAPHS[m.group(1)], src)


def _logical_lines(src: str) -> Tuple[List[str], List[int]]:
    """Join backslash-continued physical lines. Returns (logical_lines, starting_physical_line_numbers)."""
    phys = src.replace("\r\n", "\n").replace("\r", "\n").split("\n")
    logical: List[str] = []
    starts: List[int] = []
    buf: Optional[str] = None
    start = 1
    for i, line in enumerate(phys, 1):
        if buf is None:
            buf, start = "", i
        if line.endswith("\\"):
            buf += line[:-1]
            continue
        buf += line
        logical.append(buf)
        starts.append(start)
        buf = None
    if buf is not None:
        logical.append(buf)
        starts.append(start)
    return logical, starts


def _strip(text: str) -> Tuple[str, str]:
    """
    Remove comments from already-spliced text.

    Returns (code_without_comments, scan_text) where scan_text additionally blanks the
    *contents* of string/char literals (quotes kept) so keywords inside strings are ignored.
    Newlines are preserved in both outputs so line indexes stay aligned.
    """
    out_code: List[str] = []
    out_scan: List[str] = []
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        nxt = text[i + 1] if i + 1 < n else ""
        if c == "/" and nxt == "/":
            j = text.find("\n", i)
            j = n if j == -1 else j
            out_code.append(" ")
            out_scan.append(" ")
            i = j
            continue
        if c == "/" and nxt == "*":
            j = text.find("*/", i + 2)
            end = n if j == -1 else j + 2
            newlines = text.count("\n", i, end)
            filler = " " + "\n" * newlines
            out_code.append(filler)
            out_scan.append(filler)
            i = end
            continue
        if c == '"' or c == "'":
            quote = c
            j = i + 1
            while j < n:
                ch = text[j]
                if ch == "\\" and j + 1 < n and text[j + 1] != "\n":
                    j += 2
                    continue
                if ch == quote or ch == "\n":
                    break
                j += 1
            closed = j < n and text[j] == quote
            end = j + 1 if closed else j
            literal = text[i:end]
            out_code.append(literal)
            inner_len = max(0, len(literal) - (2 if closed else 1))
            out_scan.append(quote + " " * inner_len + (quote if closed else ""))
            i = end
            continue
        out_code.append(c)
        out_scan.append(c)
        i += 1
    return "".join(out_code), "".join(out_scan)


def _prepare(src: str) -> Tuple[List[str], List[str], List[int]]:
    logical, starts = _logical_lines(_replace_trigraphs(src))
    code, scan = _strip("\n".join(logical))
    return code.split("\n"), scan.split("\n"), starts


def strip_cpp_comments(src: str) -> str:
    """
    Remove // and /* */ comments while leaving string and character literals intact.
    Same name and return type as the old helper, so existing callers keep working.
    """
    code_lines, _, _ = _prepare(src)
    return "\n".join(code_lines)


# --------------------------------------------------------------------------- #
# Checks
# --------------------------------------------------------------------------- #

def _include_problem(arg: str) -> Optional[str]:
    arg = arg.strip()
    m = re.match(r'^(?:"([^"]*)"|<([^>]*)>)', arg)
    if not m:
        return "computed #include (the path must be a literal \"file.h\" or <file.h>)"
    path = (m.group(1) if m.group(1) is not None else m.group(2)).strip()
    p = path.replace("\\", "/")
    if not p:
        return "empty #include path"
    if p.startswith("/") or re.match(r"^[A-Za-z]:", p) or p.startswith("//"):
        return "absolute #include path"
    if any(part == ".." for part in p.split("/")):
        return "#include path containing '..'"
    return None


def _check_lines(code_lines: Sequence[str], scan_lines: Sequence[str], line_numbers: Sequence[int],
                 active: Optional[Sequence[bool]] = None, check_includes: bool = True) -> List[Violation]:
    found: List[Violation] = []
    for idx, (code, scan) in enumerate(zip(code_lines, scan_lines)):
        if active is not None and not active[idx]:
            continue
        ln = line_numbers[idx] if idx < len(line_numbers) else idx + 1
        snippet = code.strip()[:160]

        d = _DIRECTIVE_RE.match(code)
        if d:
            name, rest = d.group(1), d.group(2)
            if name == "pragma":
                pm = re.match(r"\s*([A-Za-z_]\w*)", rest)
                if pm and pm.group(1) in FORBIDDEN_PRAGMAS:
                    found.append(Violation(ln, "pragma:" + pm.group(1), FORBIDDEN_PRAGMAS[pm.group(1)] + " is not allowed", snippet))
            elif name in FORBIDDEN_DIRECTIVES:
                found.append(Violation(ln, "directive:" + name, FORBIDDEN_DIRECTIVES[name] + " is not allowed", snippet))
            elif name == "include" and check_includes:
                problem = _include_problem(rest)
                if problem:
                    found.append(Violation(ln, "include", problem + " is not allowed", snippet))

        for m in _TOKEN_RE.finditer(scan):
            tok = m.group(1)
            found.append(Violation(ln, "token:" + tok, FORBIDDEN_TOKENS[tok] + " is not allowed", snippet))

        for m in _DECLSPEC_RE.finditer(scan):
            words = set(re.findall(r"[A-Za-z_]\w*", m.group(1)))
            for w, why in FORBIDDEN_DECLSPEC_WORDS.items():
                if w in words:
                    found.append(Violation(ln, "declspec:" + w, why + " are not allowed", snippet))
    return found


def check_genuine_cpp(src: str) -> List[Violation]:
    """Check raw submitted source. Returns a list of violations (empty = OK)."""
    code_lines, scan_lines, starts = _prepare(src)
    return _check_lines(code_lines, scan_lines, starts)


def _norm_path(p: str) -> str:
    return p.replace("\\\\", "\\").replace("\\", "/").rstrip("/").lower()


def check_preprocessed(pp_text: str, user_paths: Optional[Iterable[str]] = None) -> List[Violation]:
    """
    Check cl.exe preprocessor output (``cl /E``, which keeps ``#line`` markers).

    If ``user_paths`` is given, only lines that originate from files under one of those
    directories (or exactly those files) are checked, so SDK / CRT headers are ignored.
    Line numbers in the result refer to lines of the preprocessed text.
    """
    prefixes = [_norm_path(p) for p in user_paths] if user_paths else None
    code_lines, scan_lines, starts = _prepare(pp_text)

    active: List[bool] = []
    current_ok = True
    for code in code_lines:
        mk = _LINE_MARKER_RE.match(code)
        if mk:
            fname = _norm_path(mk.group(2))
            current_ok = prefixes is None or any(fname == p or fname.startswith(p + "/") for p in prefixes)
            active.append(False)            # the marker line itself is not user code
            continue
        active.append(current_ok)
    # Includes are already resolved in preprocessed output.
    return _check_lines(code_lines, scan_lines, starts, active=active, check_includes=False)


def format_violations(violations: Sequence[Violation], limit: int = 20) -> str:
    """Message for the compiler-error box in the Workbench."""
    if not violations:
        return ""
    head = ("Genuine C++ policy: this submission uses constructs that are not allowed for VERIFIED status.\n"
            "Write ordinary C++ classes, structs and functions; inline assembly, raw byte emission and "
            "section/segment placement are rejected.\n")
    body = "\n".join("  " + str(v) for v in violations[:limit])
    more = f"\n  ... and {len(violations) - limit} more" if len(violations) > limit else ""
    return head + body + more


if __name__ == "__main__":   # tiny CLI: python3 cpp_policy.py file.cpp [--pp]
    import sys
    if len(sys.argv) < 2:
        print("usage: cpp_policy.py <file> [--pp]", file=sys.stderr)
        sys.exit(2)
    text = open(sys.argv[1], encoding="utf-8", errors="replace").read()
    vs = check_preprocessed(text) if "--pp" in sys.argv[2:] else check_genuine_cpp(text)
    print(format_violations(vs) or "OK")
    sys.exit(1 if vs else 0)
