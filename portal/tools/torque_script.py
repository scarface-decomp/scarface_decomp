#!/usr/bin/env python3
"""
Scarface's compiled TorqueScript (.cso / .dso) as readable TorqueScript, checked 1:1.

    decompile(raw)        compiled script -> TorqueScript text
    compile_text(text)    TorqueScript text -> compiled script, laid out exactly as the game's compiler does
    check(raw)            both: the text, and whether compiling it gives back the identical bytes

The pieces (docs/SCRIPTS.md):
    torque_dso.py         the file layout: tables, bytecode, identifier patches
    torque_decompile.py   bytecode -> syntax tree (a stack machine over the instructions)
    torque_print.py       syntax tree -> TorqueScript text
    torque_parse.py       TorqueScript text -> syntax tree
    torque_compile.py     syntax tree -> bytecode, following Torque's code generation (astNodes.cc)
    torque_names.py       the hashed names (stx...) and recovering readable ones from the game files

Every compiled script decompiles to text that compiles back to the identical file: the 635 on the
retail PS2 and Xbox discs, and the 864 in the April 2006 prototype (whose compiler differed in small
ways, see torque_compile.compile_script). Identifiers are stored hashed; about half of them are recovered as words by hashing
candidate names found in the game's own executables and scripts (torque_names.recover). The rest stay
as their hash (stxabcdefgh), which compiles to the same bytes.
"""

from __future__ import annotations

import re
import sys
from pathlib import Path
from typing import Dict, Iterable, Optional, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import torque_dso as TD  # noqa: E402
from torque_compile import CompileError, compile_script  # noqa: E402
from torque_decompile import END_MARK, DecompileError, Decompiler, listing, padding  # noqa: E402
from torque_names import candidates, is_hashed, name_key, recover, style_of  # noqa: E402
from torque_parse import ParseError, parse  # noqa: E402
from torque_print import PrintError, to_text  # noqa: E402

EXECUTABLES = ("default.xbe", "game.xbe", "Scarface.exe")
# The April 2006 prototype's compiler padded the code with leftover memory instead of 0xCDCD; a script
# that needs another value says so on this line, and compile_text() uses it.
PAD_LINE = re.compile(r"^// compiler padding: 0x([0-9A-Fa-f]{1,4})$", re.M)


class ScriptError(Exception):
    pass


def _names_in(s: TD.CompiledScript) -> list:
    return [v for v in s.strings(s.global_strings).values() if is_hashed(v)]


def decompile(raw: bytes, names: Optional[Dict[int, str]] = None) -> str:
    try:
        s = TD.parse(raw)
        text = to_text(Decompiler(s).decompile(), names)
    except (TD.DsoError, DecompileError, PrintError) as e:
        raise ScriptError(str(e)) from e
    pad = padding(s.codes)
    if pad is not None and pad != END_MARK:
        text = f"// compiler padding: 0x{pad:04X}\n" + text
    return text


def compile_text(text: str, style: str = "stx") -> bytes:
    """style: how names are written: "stx" (retail PS2, Xbox, PC) or "ste" (the April 2006 prototype)."""
    m = PAD_LINE.search(text)
    try:
        return compile_script(parse(text), style, int(m.group(1), 16) if m else END_MARK)
    except (ParseError, CompileError) as e:
        raise ScriptError(str(e)) from e


def check(raw: bytes, names: Optional[Dict[int, str]] = None) -> Tuple[str, bool, str]:
    """(text, exact, message): the readable script and whether it compiles back to these exact bytes."""
    text = decompile(raw, names)
    s = TD.parse(raw)
    try:
        again = compile_text(text, style_of(_names_in(s)))
    except ScriptError as e:
        return text, False, f"the text does not compile: {e}"
    if again == raw:
        return text, True, "compiles back byte for byte"
    first = next((i for i, (a, b) in enumerate(zip(again, raw)) if a != b), min(len(again), len(raw)))
    return text, False, f"compiles to a different file (from byte {first})"


def header(filename: str, text: str, exact: bool, msg: str, names: Optional[Dict[int, str]]) -> str:
    total = len({w for w in _words(text) if is_hashed(w.lstrip("%$"))})
    lines = [f"// {filename}: decompiled from Scarface's compiled TorqueScript.",
             f"// Check: {msg}." if exact else f"// CHECK FAILED: {msg}. Treat this text with care.",
             "// Names were hashed by the game (stx + 8 letters); recovered ones are shown as words, the "
             f"{total} still unknown keep their hash." if names is not None else
             "// Names are as the game stores them: hashed (stx + 8 letters).",
             ""]
    return "\n".join(lines) + "\n"


def _words(text: str) -> Iterable[str]:
    import re
    return re.findall(r"[%$]?[A-Za-z_][A-Za-z0-9_]*", text)


def names_for(script_files: Iterable[Path], bin_dir: Path) -> Dict[int, str]:
    """Readable names for the hashed identifiers in these scripts, from the user's own game files."""
    wanted, texts = set(), []
    for p in script_files:
        if not p.is_file() or p.suffix.lower() not in (".cso", ".dso", ".cs"):
            continue
        raw = p.read_bytes()
        if p.suffix.lower() == ".cs":
            texts.append(raw.decode("latin-1"))
            continue
        try:
            s = TD.parse(raw)
        except TD.DsoError:
            continue
        for table in (s.global_strings, s.function_strings):
            for v in s.strings(table).values():
                if is_hashed(v):
                    wanted.add(name_key(v))
                else:
                    texts.append(v)
    bins = [(bin_dir / e).read_bytes() for e in EXECUTABLES if (bin_dir / e).is_file()]
    return recover(wanted, candidates(bins, texts))


def main(argv=None) -> int:
    import argparse
    ap = argparse.ArgumentParser(description="Decompile Scarface .cso/.dso files to TorqueScript (checked byte for "
                                             "byte), or compile a .cs file the way the game's compiler does.")
    sub = ap.add_subparsers(dest="cmd", required=True)
    d = sub.add_parser("decompile", help="write NAME.cs next to each file (or into --out), checked 1:1")
    d.add_argument("files", nargs="+", type=Path, help=".cso/.dso files or folders")
    d.add_argument("--out", type=Path, help="folder for the .cs files (keeps the folder layout)")
    d.add_argument("--bin", type=Path, default=Path(__file__).resolve().parents[2] / "binaries",
                   help="folder with the game's executables, for names (default: binaries/)")
    d.add_argument("--hashed", action="store_true", help="keep every name hashed (no name recovery)")
    c = sub.add_parser("compile", help="compile one TorqueScript file")
    c.add_argument("source", type=Path)
    c.add_argument("-o", "--output", type=Path, required=True)
    c.add_argument("--style", choices=("stx", "ste"), default="stx",
                   help="which compiler to copy: stx (the retail game, default) or ste (the April 2006 prototype)")
    a = ap.parse_args(argv)
    if a.cmd == "compile":
        try:
            a.output.write_bytes(compile_text(a.source.read_text(encoding="latin-1"), a.style))
        except ScriptError as e:
            print(f"{a.source}: {e}")
            return 1
        print(f"{a.output}: written")
        return 0
    files = []
    for f in a.files:
        files += sorted(p for p in f.rglob("*") if p.suffix.lower() in (".cso", ".dso")) if f.is_dir() else [f]
    roots = {f: f for f in a.files if f.is_dir()}
    names = None if a.hashed else names_for(files, a.bin)
    exact = failed = 0
    for p in files:
        root = next((r for r in roots if r in p.parents), p.parent)
        dest = (a.out / p.relative_to(root) if a.out else p).with_name(p.name + ".cs")
        try:
            text, ok, msg = check(p.read_bytes(), names)
        except ScriptError as e:
            print(f"[FAIL] {p}: {e}")
            failed += 1
            continue
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(header(p.name, text, ok, msg, names) + text, encoding="latin-1")
        exact += ok
        failed += not ok
        if not ok:
            print(f"[DIFF] {p}: {msg}")
    print(f"{exact} of {len(files)} scripts decompiled and checked byte for byte"
          + (f"; {len(names)} names recovered" if names is not None else ""))
    return 0 if not failed else 1


if __name__ == "__main__":
    raise SystemExit(main())
