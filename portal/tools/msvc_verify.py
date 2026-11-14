#!/usr/bin/env python3
"""
Byte-exact verification of a C++ submission against a function in the retail binaries.

One implementation shared by the portal server (/api/verify, /api/cancel), portal/verify.py and
portal/scripts/reverify_all.py, so every path applies the same rules:

  1. Genuine-C++ policy on the raw source AND on cl.exe's preprocessed output (portal/tools/cpp_policy.py).
  2. Compile with MSVC 7.10 (cl.exe; under Wine on Linux/macOS) with a hard timeout.
  3. Pick the function by name. Never fall back to "some other function" when the name is
     ambiguous; a single-function .obj is accepted as-is.
  4. Compare EXACT length and every byte. Relocation slots are not blindly masked:
       * targets inside the same function (jump tables, branches) must land at the same offset;
       * data the .obj defines itself (string literals, float constants, const tables) must have
         identical bytes at the address the original code references;
       * the same external symbol must resolve to the same address everywhere in the function;
       * external symbols listed in `known_symbols` must resolve to their known address.
     Anything else is reported as "unverified relocation" (counted, shown, but not a mismatch).
"""

from __future__ import annotations

import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import time
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional, Sequence, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from cpp_policy import check_genuine_cpp, check_preprocessed, format_violations  # noqa: E402

PORTAL = Path(__file__).resolve().parent.parent      # portal/
ROOT = PORTAL.parent                                  # the project folder
COMPILE_TIMEOUT_SEC = int(os.environ.get("SCARFACE_CL_TIMEOUT", "30"))

IMAGE_SCN_CNT_CODE = 0x00000020
IMAGE_SCN_LNK_COMDAT = 0x00001000
REL_DIR32 = 0x0006
REL_REL32 = 0x0014

# --------------------------------------------------------------------------- #
# Compiler discovery / invocation
# --------------------------------------------------------------------------- #

def find_msvc71_bin() -> Optional[Path]:
    env = os.environ.get("SCARFACE_MSVC_BIN")
    cands = [Path(env)] if env else []
    cands += [
        PORTAL / "tools" / "msvc71" / "bin",
        ROOT / "tools" / "msvc71" / "bin",          # where older copies installed it
        ROOT.parent / "tools" / "msvc71" / "bin",
        Path(r"C:\Program Files (x86)\Microsoft Visual C++ Toolkit 2003\bin"),
        Path(r"C:\Program Files (x86)\Microsoft Visual Studio .NET 2003\Vc7\bin"),
    ]
    for c in cands:
        if (c / "cl.exe").exists():
            return c
    return None


def _runner(bin_dir: Path) -> List[str]:
    cl = str(bin_dir / "cl.exe")
    if os.name == "nt":
        return [cl]
    wine = shutil.which("wine")
    if not wine:
        raise RuntimeError("cl.exe is a Windows program; install Wine to run it on this OS.")
    return [wine, cl]


def _compiler_path(p: Path) -> str:
    """How cl.exe will spell a path in #line markers (Wine maps / to Z:\\)."""
    if os.name == "nt":
        return str(p)
    return "Z:" + str(p).replace("/", "\\")


def compiler_version(bin_dir: Optional[Path] = None) -> str:
    bin_dir = bin_dir or find_msvc71_bin()
    if not bin_dir:
        return "cl.exe not found"
    try:
        p = subprocess.run(_runner(bin_dir), capture_output=True, timeout=COMPILE_TIMEOUT_SEC, env=_env(bin_dir, []))
        text = (p.stdout + p.stderr).decode("latin-1", "replace")
        for line in text.splitlines():
            if "Version" in line:
                return line.strip()
        return text.strip().splitlines()[0] if text.strip() else "unknown"
    except Exception as e:  # pragma: no cover - diagnostic only
        return f"error: {e}"


# The two releases of the Visual C++ Toolkit 2003. Microsoft: 1.01 only renumbered the compiler to match
# Visual Studio .NET 2003, "no compilation-related behavior changes" (checked here on 450 game functions).
TOOLKIT_BUILDS = {
    "13.10.3052": "Visual C++ Toolkit 2003 1.0 (April 2004)",
    "13.10.3077": "Visual C++ Toolkit 2003 1.01 (July 2004)",
}
_BUILD_CACHE: dict = {}


def compiler_build(bin_dir: Optional[Path] = None) -> str:
    """'13.10.3052' or '13.10.3077' (or whatever cl.exe reports; '' when there is none). Cached per folder."""
    bin_dir = bin_dir or find_msvc71_bin()
    if not bin_dir:
        return ""
    key = str(bin_dir)
    if key not in _BUILD_CACHE:
        m = re.search(r"Version (\d+\.\d+\.\d+)", compiler_version(bin_dir))
        _BUILD_CACHE[key] = m.group(1) if m else ""
    return _BUILD_CACHE[key]


def _env(bin_dir: Path, include_dirs: Sequence[Path]) -> dict:
    env = os.environ.copy()
    env["PATH"] = str(bin_dir) + os.pathsep + env.get("PATH", "")
    env["INCLUDE"] = ";".join(_compiler_path(Path(d)) for d in include_dirs if Path(d).exists())
    env["LIB"] = ""
    env.setdefault("WINEDEBUG", "-all")
    return env


@dataclass
class CompileResult:
    ok: bool
    obj: bytes = b""
    error: str = ""
    policy_violation: bool = False


def compile_cpp(cpp_code: str, flags: str, include_dirs: Optional[Sequence[Path]] = None,
                bin_dir: Optional[Path] = None, timeout: int = COMPILE_TIMEOUT_SEC) -> CompileResult:
    """Policy-check, preprocess-check and compile one translation unit. Returns the .obj bytes."""
    violations = check_genuine_cpp(cpp_code)
    if violations:
        return CompileResult(False, error=format_violations(violations), policy_violation=True)

    bin_dir = bin_dir or find_msvc71_bin()
    if not bin_dir:
        return CompileResult(False, error="MSVC 7.10 cl.exe not found (expected portal/tools/msvc71/bin/cl.exe).")
    include_dirs = [Path(d) for d in (include_dirs if include_dirs is not None else [ROOT / "reconstructed_src" / "include"])]
    project_dirs = list(include_dirs)          # only these count as "user code" for the /E policy check
    std_inc = bin_dir.parent / "include"
    if (std_inc / "stddef.h").exists() and std_inc not in include_dirs:
        include_dirs.append(std_inc)          # CRT/STL headers from the VC++ Toolkit 2003
    allowed = {f for f in flags.split() if f}
    bad_flags = [f for f in allowed if f.lower().startswith(("/fo", "/fe", "/fa", "/fd", "/fp", "/fr", "/yc", "/yu", "/i", "/fi", "/d"))]
    if bad_flags:
        return CompileResult(False, error=f"Refusing task flags that touch files or macros: {' '.join(bad_flags)}")

    runner = _runner(bin_dir)
    env = _env(bin_dir, include_dirs)
    with tempfile.TemporaryDirectory(prefix="sfv_") as tmp:
        tmp_path = Path(tmp)
        src = tmp_path / "candidate.cpp"
        obj = tmp_path / "candidate.obj"
        src.write_text(cpp_code, encoding="utf-8")
        base = runner + ["/nologo"] + flags.split()
        try:
            # Compile first: a failing /E run can hang under Wine, and errors are reported faster this way.
            rc, out, err = _run_cl(base + ["/c", f"/Fo{obj.name}", src.name], tmp_path, env, timeout)
            if rc != 0 or not obj.exists():
                return CompileResult(False, error=_clean(out + err, tmp_path) or "cl.exe failed to compile.")
            rc, out, err = _run_cl(base + ["/E", src.name], tmp_path, env, timeout)
            if rc != 0:
                return CompileResult(False, error=_clean(out + err, tmp_path) or "Preprocessing failed.")
            pp_text = out.decode("latin-1", "replace")
            user_paths = (["candidate.cpp", str(tmp_path), _compiler_path(tmp_path)]
                          + [str(d) for d in project_dirs] + [_compiler_path(d) for d in project_dirs])
            violations = check_preprocessed(pp_text, user_paths=user_paths)
            if violations:
                return CompileResult(False, error=format_violations(violations), policy_violation=True)
        except subprocess.TimeoutExpired:
            return CompileResult(False, error=f"cl.exe did not finish within {timeout} s (template recursion or a huge translation unit?).")
        return CompileResult(True, obj=obj.read_bytes())


_FATAL_RE = re.compile(rb"\) : fatal error C\d{4}|^cl : Command line error", re.M)


def _run_cl(cmd: List[str], cwd: Path, env: dict, timeout: int) -> Tuple[int, bytes, bytes]:
    """Run cl.exe with output going to files. Under Wine, cl.exe 13.10 can spin forever after printing a
    fatal error (C1083 "Cannot open include file", ...), so once a fatal error has been printed and the
    process has not exited within a couple of seconds, it is stopped and treated as failed."""
    out_p, err_p = cwd / "_cl_stdout.txt", cwd / "_cl_stderr.txt"
    with open(out_p, "wb") as fo, open(err_p, "wb") as fe:
        proc = subprocess.Popen(cmd, cwd=cwd, env=env, stdout=fo, stderr=fe, stdin=subprocess.DEVNULL)
        start = time.monotonic()
        fatal_seen = None
        while True:
            try:
                rc = proc.wait(timeout=0.1)
                break
            except subprocess.TimeoutExpired:
                pass
            now = time.monotonic()
            if now - start > timeout:
                proc.kill()
                proc.wait()
                raise subprocess.TimeoutExpired(cmd, timeout)
            if fatal_seen is None and now - start > 0.5:
                tail = out_p.read_bytes()[-4096:] + err_p.read_bytes()[-4096:]
                if _FATAL_RE.search(tail):
                    fatal_seen = now
            if fatal_seen is not None and now - fatal_seen > 2.0:
                proc.kill()
                proc.wait()
                rc = 2
                break
    return rc, out_p.read_bytes(), err_p.read_bytes()


def _clean(raw: bytes, tmp: Path) -> str:
    text = raw.decode("latin-1", "replace").replace("\r", "")
    for p in (str(tmp), _compiler_path(tmp)):
        text = text.replace(p + "\\", "").replace(p + "/", "").replace(p, "")
    lines = [ln for ln in text.splitlines() if ln.strip() and ln.strip() != "candidate.cpp"]
    return "\n".join(lines[:200])


# --------------------------------------------------------------------------- #
# COFF parsing
# --------------------------------------------------------------------------- #

@dataclass
class CoffSymbol:
    index: int
    name: str
    value: int
    section: int        # 1-based, 0 = undefined/external, negative = absolute/debug
    type: int
    storage: int


@dataclass
class CoffSection:
    index: int          # 1-based
    name: str
    chars: int
    data: bytes
    relocs: List[Tuple[int, int, int]]   # (offset, symbol index, type)


@dataclass
class ObjFunction:
    name: str
    section: int
    offset: int
    size: int
    code: bytes
    relocs: List[Tuple[int, int, int]]   # (offset within function, symbol index, type)


class CoffObject:
    def __init__(self, data: bytes):
        if len(data) < 20:
            raise ValueError("not a COFF object")
        self.data = data
        machine, nsec, _ts, symoff, nsym, opt, _ch = struct.unpack_from("<HHIIIHH", data, 0)
        if machine != 0x14C:
            raise ValueError(f"unexpected machine 0x{machine:X} (expected i386)")
        self.strtab_off = symoff + nsym * 18
        self.sections: List[CoffSection] = []
        so = 20 + opt
        for i in range(nsec):
            o = so + i * 40
            raw_name = data[o:o + 8]
            _vs, _va, rsz, rptr, relptr, _ln, nrel, _nln, chars = struct.unpack_from("<IIIIIIHHI", data, o + 8)
            name = self._name(raw_name, is_section=True)
            sec_data = data[rptr:rptr + rsz] if rptr and rsz else b""
            relocs = []
            for r in range(nrel):
                va, sym, typ = struct.unpack_from("<IIH", data, relptr + r * 10)
                relocs.append((va, sym, typ))
            self.sections.append(CoffSection(i + 1, name, chars, sec_data, relocs))
        self.symbols: Dict[int, CoffSymbol] = {}
        idx = 0
        while idx < nsym:
            o = symoff + idx * 18
            raw_name = data[o:o + 8]
            value, secn, typ, storage, naux = struct.unpack_from("<IhHBB", data, o + 8)
            self.symbols[idx] = CoffSymbol(idx, self._name(raw_name), value, secn, typ, storage)
            idx += 1 + naux

    def _name(self, raw8: bytes, is_section: bool = False) -> str:
        if raw8[:4] == b"\0\0\0\0":
            off = struct.unpack_from("<I", raw8, 4)[0]
            start = self.strtab_off + off
            end = self.data.find(b"\0", start)
            return self.data[start:end].decode("latin-1")
        name = raw8.rstrip(b"\0").decode("latin-1")
        if is_section and name.startswith("/") and name[1:].isdigit():
            start = self.strtab_off + int(name[1:])
            end = self.data.find(b"\0", start)
            return self.data[start:end].decode("latin-1")
        return name

    def functions(self) -> List[ObjFunction]:
        by_sec: Dict[int, List[CoffSymbol]] = {}
        for s in self.symbols.values():
            if (s.type & 0xF0) == 0x20 and s.section > 0 and s.storage in (2, 3):
                sec = self.sections[s.section - 1]
                if sec.chars & IMAGE_SCN_CNT_CODE:
                    by_sec.setdefault(s.section, []).append(s)
        out: List[ObjFunction] = []
        for secn, syms in by_sec.items():
            sec = self.sections[secn - 1]
            syms.sort(key=lambda x: x.value)
            for i, s in enumerate(syms):
                end = syms[i + 1].value if i + 1 < len(syms) else len(sec.data)
                rel = [(o - s.value, si, t) for (o, si, t) in sec.relocs if s.value <= o < end]
                out.append(ObjFunction(s.name, secn, s.value, end - s.value, sec.data[s.value:end], rel))
        return out


_ADDR_NAME_RE = re.compile(r"^(?:_|\?)?(?:DAT|PTR|FUN|sub|off|unk|g)_([0-9A-Fa-f]{8})(?:$|@)")


def address_named(name: str) -> Optional[int]:
    """Symbols named for their address (DAT_0043A0C0, sub_00412340, ...) are checked against that address.
    Works for extern "C" names (_DAT_0043A0C0) and C++ decorated ones (?DAT_0043A0C0@@3HA)."""
    m = _ADDR_NAME_RE.match(name)
    return int(m.group(1), 16) if m else None


def source_name(name: str) -> str:
    """The name as written in the C++: _DAT_0043A0C0 -> DAT_0043A0C0, ?DAT_0043A0C0@@3HA -> DAT_0043A0C0."""
    if name.startswith("?"):
        return name[1:].split("@", 1)[0] or name
    if name.startswith("_") and not name.startswith("__"):
        return name[1:]
    return name


_PLAIN = re.compile(r"[A-Za-z_]\w*$")


def qualified_name(name: str) -> Optional[str]:
    """The C++ name a compiled symbol stands for, when it can be read off without guessing:
    ?Reload@Weapon@game@@QAEXXZ -> game::Weapon::Reload, _Tick -> Tick. None for constructors,
    operators, templates and anything else whose decorated name needs more than splitting."""
    if name.startswith("?") and not name.startswith("??"):
        parts = name[1:].split("@@", 1)[0].split("@")
        return "::".join(reversed(parts)) if parts and all(_PLAIN.match(p) for p in parts) else None
    if name.startswith("_") and not name.startswith("__"):
        plain = name[1:].split("@", 1)[0]
        return plain if _PLAIN.match(plain) else None
    return None


def _split_scopes(qualified: str) -> List[str]:
    """'core::ConcreteClassRep<a::B>' -> ['core', 'ConcreteClassRep<a::B>'] (only top-level '::')."""
    parts, depth, cur, i = [], 0, "", 0
    while i < len(qualified):
        ch = qualified[i]
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth -= 1
        if depth == 0 and qualified.startswith("::", i):
            parts.append(cur)
            cur, i = "", i + 2
            continue
        cur += ch
        i += 1
    parts.append(cur)
    return [p for p in parts if p]


def decorated_hint(qualified_cls: str, name: str) -> str:
    """The part of the MSVC decorated name that picks out qualified_cls::name in an .obj.

    Destructors give '??_GClass@...|??1Class@...' (the scalar deleting destructor first, since
    that is what a vtable slot points at), constructors '??0Class@...', and a class template
    with one class argument the '?$Name@VArg@@@' form. '|' separates alternatives; see
    select_function."""
    scopes = _split_scopes(qualified_cls)
    if not scopes:
        return name
    cls, outer = scopes[-1], scopes[:-1]
    base = cls.split("<")[0]
    tail = "".join(sc + "@" for sc in reversed(outer))
    targ = re.fullmatch(r"\w+<\s*(\w+)\s*>", cls)
    if targ:
        forms = [f"?${base}@V{targ.group(1)}@@@", f"?${base}@U{targ.group(1)}@@@"]
    elif "<" in cls:
        forms, tail = ["?$" + base + "@"], ""
    else:
        forms = [base + "@"]
    if name.startswith("~"):
        return "|".join([f"??_G{f}{tail}" for f in forms] + [f"??1{f}{tail}" for f in forms])
    if name == base:
        return "|".join(f"??0{f}{tail}" for f in forms)
    return "|".join(f"{name}@{f}{tail}" for f in forms)


def is_helper_function(name: str) -> bool:
    return name.startswith(("__ehhandler$", "__unwindfunclet$", "__catch$", "$", "__tryend$"))


def select_function(funcs: List[ObjFunction], match_substr: str = "") -> Tuple[Optional[ObjFunction], str]:
    """Pick the target function out of an .obj. match_substr may list alternatives separated by '|';
    the first alternative that picks out exactly one function wins."""
    if "|" in match_substr:
        last = (None, "")
        for alt in [a for a in match_substr.split("|") if a]:
            fn, why = select_function(funcs, alt)
            if fn is not None:
                return fn, ""
            last = (None, why)
        return last
    main = [f for f in funcs if not is_helper_function(f.name)]
    if match_substr:
        hits = [f for f in main if match_substr in f.name]
        if len(hits) == 1:
            return hits[0], ""
        if len(hits) > 1:
            exact = [f for f in hits if f.name.startswith("?" + match_substr + "@") or f.name in (match_substr, "_" + match_substr)]
            if len(exact) == 1:
                return exact[0], ""
            return None, ("Several functions match '" + match_substr + "': " + ", ".join(f.name for f in hits)
                          + ". Keep only the target function out-of-line in this translation unit.")
    if len(main) == 1:
        return main[0], ""
    if not main:
        return None, "No function was emitted. Define the target function out-of-line (not inline/static-unused)."
    want = f" (name it so its symbol contains '{match_substr}')" if match_substr else ""
    return None, ("The .obj contains several functions and none is clearly the target" + want + ": "
                  + ", ".join(f.name for f in main[:12]))


# --------------------------------------------------------------------------- #
# Comparison
# --------------------------------------------------------------------------- #

@dataclass
class CompareResult:
    is_exact: bool
    matched: int
    total: int
    compiled_size: int
    diff_details: List[dict]
    reloc_checked: int = 0
    reloc_unverified: int = 0
    reloc_mismatch: List[str] = field(default_factory=list)
    notes: List[str] = field(default_factory=list)
    hardcoded_addresses: List[str] = field(default_factory=list)

    @property
    def percent(self) -> float:
        return round(self.matched / self.total * 100.0, 2) if self.total else 0.0

    def as_dict(self) -> dict:
        return {
            "is_exact": self.is_exact,
            "matched_bytes": self.matched,
            "total_bytes": self.total,
            "compiled_size": self.compiled_size,
            "match_percent": self.percent,
            "diff_details": self.diff_details,
            "reloc_checked": self.reloc_checked,
            "reloc_unverified": self.reloc_unverified,
            "reloc_mismatch": self.reloc_mismatch,
            "notes": self.notes,
            "hardcoded_addresses": self.hardcoded_addresses,
        }


def compare_function(target: bytes, fn: ObjFunction, coff: CoffObject, fn_va: Optional[int] = None,
                     image=None, known_symbols: Optional[Dict[str, int]] = None,
                     known_names: Optional[Dict[str, int]] = None) -> CompareResult:
    """
    target: original bytes of the function (exact size).
    fn_va / image: the original function's address and a BinaryImage, used to check relocation targets.
    known_names: C++ names that are known to live at one address in this build ("Weapon::Reload" ->
    0x0011E4A0). Code may call such a function by its name and the address is still checked.
    """
    known_symbols = known_symbols or {}
    known_names = known_names or {}
    code = fn.code
    n_t, n_c = len(target), len(code)
    status = ["match"] * max(n_t, n_c)
    notes: List[str] = []
    mismatch: List[str] = []
    checked = unverified = 0
    ext_seen: Dict[str, int] = {}

    reloc_slots = {}
    linked_to: Dict[int, tuple] = {}
    for off, si, typ in fn.relocs:
        reloc_slots[off] = (si, typ)

    for off, (si, typ) in sorted(reloc_slots.items()):
        for k in range(4):
            if off + k < len(status):
                status[off + k] = "reloc"
        if off + 4 > n_t or off + 4 > n_c:
            mismatch.append(f"+0x{off:X}: relocation outside the original function")
            for k in range(4):
                if off + k < len(status):
                    status[off + k] = "diff"
            continue
        sym = coff.symbols.get(si)
        addend = struct.unpack_from("<i", code, off)[0]
        orig_field = struct.unpack_from("<I", target, off)[0]
        verdict = "unverified"
        why = ""
        if fn_va is not None and typ in (REL_DIR32, REL_REL32) and sym is not None:
            if typ == REL_DIR32:
                orig_target = orig_field
            else:
                orig_target = (fn_va + off + 4 + struct.unpack_from("<i", target, off)[0]) & 0xFFFFFFFF
            sym_va_in_orig = (orig_target - addend) & 0xFFFFFFFF

            if sym.section == -1 and typ == REL_DIR32:           # absolute symbol, e.g. __except_list (fs:[0])
                expected = (sym.value + addend) & 0xFFFFFFFF
                if orig_field == expected:
                    verdict = "ok"
                else:
                    verdict, why = "bad", f"+0x{off:X}: '{sym.name}' is the constant 0x{expected:X}, but the original has 0x{orig_field:X}"
            elif sym.section == fn.section:                       # same function / same COMDAT
                expected = (fn_va - fn.offset + sym.value + addend) & 0xFFFFFFFF
                if orig_target == expected:
                    verdict = "ok"
                else:
                    verdict, why = "bad", f"+0x{off:X}: internal reference goes to 0x{orig_target:08X} in the original, 0x{expected:08X} here"
            elif sym.section > 0 and not (coff.sections[sym.section - 1].chars & IMAGE_SCN_CNT_CODE):
                sec = coff.sections[sym.section - 1]
                # Only this symbol's own bytes: stop at the next symbol in the same section.
                later = [o.value for o in coff.symbols.values()
                         if o is not None and o.section == sym.section and o.value > sym.value]
                end = min(later) if later else len(sec.data)
                payload = sec.data[sym.value:end]
                # Pointers inside the data (vtable slots, string tables) are relocated by the
                # linker, so their bytes in the .obj are placeholders: leave them out.
                masked = {o - sym.value + k for (o, _si, _t) in sec.relocs
                          if sym.value <= o < end for k in range(4)}
                if image is None:
                    verdict = "unverified"
                elif not payload:
                    verdict = "unverified"
                else:
                    orig_bytes = image.read(sym_va_in_orig, len(payload))
                    if orig_bytes is None:
                        verdict = "unverified"
                    elif all(i in masked or orig_bytes[i] == payload[i] for i in range(len(payload))):
                        verdict = "ok"
                    else:
                        verdict = "bad"
                        why = (f"+0x{off:X}: '{sym.name}' data differs from what the original references at "
                               f"0x{sym_va_in_orig:08X} ({payload[:16].hex(' ')} vs {orig_bytes[:16].hex(' ')})")
            else:                                                 # external symbol (or another code section)
                prev = ext_seen.get(sym.name)
                if prev is not None and prev != sym_va_in_orig:
                    verdict, why = "bad", f"+0x{off:X}: '{sym.name}' is used for two different original addresses"
                elif address_named(sym.name) is not None:
                    want = address_named(sym.name)
                    if want == sym_va_in_orig:
                        verdict = "ok"
                    else:
                        verdict, why = "bad", (f"+0x{off:X}: '{sym.name}' is named for 0x{want:08X}, but the "
                                               f"original uses 0x{sym_va_in_orig:08X} here")
                elif sym.name in known_symbols:
                    if known_symbols[sym.name] == sym_va_in_orig:
                        verdict = "ok"
                    else:
                        verdict, why = "bad", (f"+0x{off:X}: '{sym.name}' is 0x{known_symbols[sym.name]:08X}, but the "
                                               f"original uses 0x{sym_va_in_orig:08X} here")
                elif qualified_name(sym.name) in known_names:
                    want = known_names[qualified_name(sym.name)]
                    if want == sym_va_in_orig:
                        verdict = "ok"
                    else:
                        verdict, why = "bad", (f"+0x{off:X}: '{qualified_name(sym.name)}' is at 0x{want:08X}, but "
                                               f"the original uses 0x{sym_va_in_orig:08X} here")
                else:
                    verdict = "unverified"
                ext_seen.setdefault(sym.name, sym_va_in_orig)
        elif typ not in (REL_DIR32, REL_REL32):
            notes.append(f"+0x{off:X}: relocation type 0x{typ:X} not checked")

        if verdict == "ok":
            checked += 1
            # Proven: the linker writes the same address the original has, so these bytes match.
            for k in range(4):
                status[off + k] = "linked"
            linked_to[off] = (sym.name, orig_target)    # only reachable when the check above ran
        elif verdict == "bad":
            mismatch.append(why)
            for k in range(4):
                status[off + k] = "diff"
        else:
            unverified += 1

    matched = 0
    details = []
    for i in range(max(n_t, n_c)):
        t = target[i] if i < n_t else None
        c = code[i] if i < n_c else None
        st = status[i]
        if t is None or c is None:
            st = "diff"
        elif st == "match" and t != c:
            st = "diff"
        if st in ("match", "reloc", "linked") and i < n_t:
            matched += 1
        d = {"idx": i, "target": f"{t:02X}" if t is not None else "--",
             "compiled": f"{c:02X}" if c is not None else "--", "status": st}
        if st == "linked":
            slot = max(o for o in linked_to if o <= i)
            name, va = linked_to[slot]
            d["symbol"] = source_name(name)
            if va is not None:
                d["address"] = f"0x{va:08X}"
        details.append(d)
    if n_c != n_t:
        notes.append(f"Compiled function is {n_c} bytes; the original is {n_t} bytes.")
    exact = n_c == n_t and matched == n_t and not mismatch
    hard = find_hardcoded_addresses(code, set(reloc_slots), image) if image is not None else []
    return CompareResult(exact, matched, n_t, n_c, details, checked, unverified, mismatch, notes, hard)


def find_hardcoded_addresses(code: bytes, reloc_offsets: set, image) -> List[str]:
    """
    Operands in the compiled code that hold a literal address inside the original image without a
    relocation, e.g. `*(int*)0x00419E48` or `return 0x0085AEF4;`. They can match bytes, but they are
    not reconstructed source (the address only exists in the 2006 binary), so they block VERIFIED.
    """
    try:
        import capstone
        from capstone import x86_const as X
    except ImportError as e:
        # Never skip this check silently: without it a hard-coded address would count as verified.
        raise RuntimeError("The Capstone disassembler is required: pip install capstone") from e
    lo = min(s.va for s in image.sections) if image.sections else 0
    hi = max(s.va + max(s.vsize, s.raw_size) for s in image.sections) if image.sections else 0
    lo = max(lo, image.image_base + 0x1000)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True
    out = []
    for insn in md.disasm(code, 0):
        if insn.group(capstone.CS_GRP_JUMP) or insn.group(capstone.CS_GRP_CALL):
            continue
        for op in insn.operands:
            val = None
            if op.type == X.X86_OP_IMM and op.size == 4:
                val = op.imm & 0xFFFFFFFF
            elif op.type == X.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
                val = op.mem.disp & 0xFFFFFFFF
            if val is None or not (lo <= val < hi):
                continue
            raw = struct.pack("<I", val)
            pos = code.find(raw, insn.address, insn.address + insn.size)
            if pos != -1 and pos not in reloc_offsets:
                out.append(f"+0x{insn.address:X}: {insn.mnemonic} {insn.op_str}")
    return out


# --------------------------------------------------------------------------- #
# One-call API
# --------------------------------------------------------------------------- #

def verify_submission(cpp_code: str, target: bytes, flags: str, match_substr: str = "",
                      fn_va: Optional[int] = None, image=None, known_symbols: Optional[Dict[str, int]] = None,
                      include_dirs: Optional[Sequence[Path]] = None, bin_dir: Optional[Path] = None,
                      known_names: Optional[Dict[str, int]] = None) -> dict:
    """Returns {"ok": False, "compiler_error": ...} or {"ok": True, ...CompareResult fields, compiled_sym, compiled_hex}."""
    cr = compile_cpp(cpp_code, flags, include_dirs=include_dirs, bin_dir=bin_dir)
    if not cr.ok:
        return {"ok": False, "compiler_error": cr.error, "policy_violation": cr.policy_violation}
    try:
        coff = CoffObject(cr.obj)
    except ValueError as e:
        return {"ok": False, "compiler_error": f"Could not read the compiled object: {e}"}
    fn, why = select_function(coff.functions(), match_substr)
    if fn is None:
        return {"ok": False, "compiler_error": why}
    res = compare_function(target, fn, coff, fn_va=fn_va, image=image, known_symbols=known_symbols,
                           known_names=known_names)
    out = {"ok": True, **res.as_dict(), "compiled_sym": fn.name,
           "compiled_hex": " ".join(f"{b:02X}" for b in fn.code)}
    return out
