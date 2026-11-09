"""
Downloads from the portal: the functions, the game scripts and the source files. Each comes as a .zip that
keeps the original layout, or as one organised .txt. Order and place always follow the game itself:
functions by their address in the game file, scripts by their folder inside the game's archive.

Everything is built on request from what is on this computer (the registry, the function list, the
scripts copied out of your own game files); nothing is uploaded anywhere.
"""
from __future__ import annotations

import datetime as dt
import io
import tempfile
import zipfile
from pathlib import Path
from typing import Callable, Dict, Iterable, List, Optional, Tuple

RULE = "=" * 100
BUILD_ORDER = ("xb", "pc", "proto")
BUILD_NAMES = {"xb": "Xbox (retail default.xbe)", "pc": "PC (Scarface.exe 1.00.2)", "proto": "Xbox prototype (April 2006 game.xbe)"}
ONE_TO_ONE = ("Every [VERIFIED] function compiles with the game's own compiler (Visual C++ 2003) to exactly the "
              "bytes in the game file.")


def stamp() -> str:
    return dt.datetime.now().strftime("%Y-%m-%d %H:%M")


def to_zip(files: Dict[str, str], root: str) -> bytes:
    buf = io.BytesIO()
    with zipfile.ZipFile(buf, "w", zipfile.ZIP_DEFLATED, compresslevel=6) as z:
        for rel, text in files.items():
            z.writestr(f"{root}/{rel}", text.encode("utf-8"))
    return buf.getvalue()


def to_txt(files: Dict[str, str], title: str, intro: Iterable[str]) -> str:
    """One file: a header, a numbered table of contents, then every file under its own heading, in order."""
    out = [RULE, title, *intro, RULE, "", f"CONTENTS ({len(files):,} file{'s' if len(files) != 1 else ''}, in order)"]
    out += [f"  {i:>5}. {rel}" for i, rel in enumerate(files, 1)]
    out.append("")
    for i, (rel, text) in enumerate(files.items(), 1):
        out += [RULE, f"FILE {i:,} of {len(files):,}: {rel}", RULE, text.rstrip("\n"), ""]
    return "\n".join(out) + "\n"


# --------------------------------------------------------------------------- functions

def function_files(registry: dict, queue: Optional[list], builds: Iterable[str], verified_only: bool,
                   write_outputs: Callable, bin_info: dict, by_class: bool = True) -> Dict[str, str]:
    """{path: text}: per game file, every function in address order (or only the verified ones), plus the
    verified code grouped by class. Built with the same generator as reconstructed_src/."""
    builds = [b for b in BUILD_ORDER if b in set(builds)]
    entries = {k: e for k, e in registry.get("entries", {}).items() if e.get("bin") in builds}
    reg = {"compiler": registry.get("compiler", "MSVC 7.10"), "entries": entries}
    q = [] if verified_only else [t for t in (queue or []) if t.get("bin") in builds]
    files: Dict[str, str] = {}
    with tempfile.TemporaryDirectory(prefix="sf_dl_") as tmp:
        root = Path(tmp)
        recon, empty = root / "reconstructed_src", root / "none"
        recon.mkdir()
        empty.mkdir()
        (root / "reports").mkdir()
        written = write_outputs(reg, recon, queue=q, known_from=empty)
        for b in builds:
            fname, folder, _label = bin_info[b]
            if (recon / fname).exists():
                files[f"{folder}/{fname}"] = (recon / fname).read_text(encoding="utf-8")
        if by_class:
            for rel in sorted(w for w in written if "/" in w and not w.startswith("..")):
                folder, rest = rel.split("/", 1)
                if any(bin_info[b][1] == folder for b in builds):
                    files[f"{folder}/by_class/{rest}"] = (recon / rel).read_text(encoding="utf-8")
    return files


def functions_readme(builds: List[str], verified_only: bool, counts: Dict[str, Tuple[int, int]]) -> str:
    lines = ["Scarface: The World Is Yours: decompiled functions", f"Downloaded from the local portal on {stamp()}.", "",
             "<build>/Original_Binary_Order_*.cpp holds the functions in the order they are in the game file",
             "(by address), so the code sits exactly where it belongs."]
    if verified_only:
        lines += ["This download holds the verified functions only, still in address order."]
    else:
        lines += ["Every function of the game file is listed. Functions not matched yet appear in their place as",
                  "  // [TODO] address name (size)",
                  "so you can see what is missing and where. Matched ones are the C++ itself."]
    lines += ["<build>/by_class/ holds the same verified code grouped by class.", "", ONE_TO_ONE,
              "Each block compiles on its own; a whole file is not one translation unit.", "", "Progress:"]
    for b in builds:
        done, total = counts.get(b, (0, 0))
        lines.append(f"  {BUILD_NAMES[b]}: {done:,} of {total:,} matched" + (f" ({done / total * 100:.2f}%)" if total else ""))
    return "\n".join(lines) + "\n"


# --------------------------------------------------------------------------- game scripts

def script_out_name(path: str) -> str:
    """xbox/scriptc/missions/foo.cso -> xbox/scriptc/missions/foo.cs; main.cs.dso -> main.cs; .dtr -> .dtr.txt"""
    low = path.lower()
    if low.endswith(".cso"):
        return path[:-4] + ".cs"
    if low.endswith(".dso"):
        base = path[:-4]
        return base if base.lower().endswith(".cs") else base + ".cs"
    if low.endswith(".dtr"):
        return path + ".txt"
    return path


def script_files(items: List[dict], detail: Callable[[str], dict], exact: Dict[str, bool], only_exact: bool,
                 versions: Optional[Iterable[str]] = None, dtr_exact: Optional[Callable[[str], bool]] = None,
                 progress: Optional[Callable[[int, int], None]] = None) -> Tuple[Dict[str, str], Dict[str, int]]:
    """{path: TorqueScript text} in the game's own folder layout, and counts. `exact`: the 1:1 check of each
    .cso/.dso (decompiled, compiled again, identical). With only_exact, files not proven 1:1 are left out."""
    keep = set(versions or [])
    chosen = [it for it in items if not keep or it["version"] in keep]
    files: Dict[str, str] = {}
    stats = {"files": 0, "exact": 0, "not_exact": 0, "unchecked": 0, "left_out": 0}
    for i, it in enumerate(chosen, 1):
        if progress:
            progress(i, len(chosen))
        ext = it["ext"].upper()
        if ext in ("CSO", "DSO"):
            ok = exact.get(it["path"])
        elif ext == "DTR":
            ok = dtr_exact(it["path"]) if dtr_exact else None
        else:                                       # plain .cs left in the game files: it is the source
            ok = True
        if only_exact and ok is not True:
            stats["left_out"] += 1
            continue
        d = detail(it["path"])
        if not d.get("ok"):
            stats["left_out"] += 1
            continue
        if ext in ("CSO", "DSO"):
            state = {True: "1:1 (decompiled, compiled again, identical)", False: "NOT 1:1 yet", None: "not checked yet"}[ok]
        elif ext == "DTR":
            state = "layout rebuilt byte for byte; program words not decoded yet" if ok else "not checked yet"
        else:
            state = "original TorqueScript source, as stored in the game files"
        head = f"// {it['path']}  |  {d.get('format', '')}  |  {state}\n"
        files[script_out_name(it["path"])] = head + (d.get("decompiled_code") or "").rstrip("\n") + "\n"
        stats["files"] += 1
        stats["exact" if ok is True else "not_exact" if ok is False else "unchecked"] += 1
    return files, stats


def scripts_readme(only_exact: bool, stats: Dict[str, int], versions: List[str]) -> str:
    return "\n".join([
        "Scarface: The World Is Yours: game scripts as readable TorqueScript",
        f"Downloaded from the local portal on {stamp()}, from your own copy of the game.",
        "",
        "The folders are the ones inside the game's archive (cement.rcf), one folder per version: " + ", ".join(versions) + ".",
        "Each .cso/.dso became a .cs file of TorqueScript, the game's own scripting language; .dtr (AI task trees)",
        "became a .dtr.txt description. The first line of every file says whether it is proven 1:1: decompiled,",
        "compiled again the way the game's compiler does it, and identical to the original byte for byte.",
        "",
        ("Only files proven 1:1 are included." if only_exact else "All script files are included."),
        f"Files: {stats.get('files', 0):,} (1:1: {stats.get('exact', 0):,}, not 1:1 yet: {stats.get('not_exact', 0):,}, "
        f"not checked yet: {stats.get('unchecked', 0):,}; left out: {stats.get('left_out', 0):,}).",
        "",
        "Comments and the original formatting are not in the compiled files, so they cannot come back. Names the",
        "game stores as hashes are written as words where they were found, and stay hashed where not yet.",
        "These files come from your copy of the game: keep them to yourself, don't upload them.",
    ]) + "\n"


# --------------------------------------------------------------------------- source files

SOURCE_EXTS = (".cpp", ".h", ".hpp", ".md", ".txt")


def source_files(recon_dir: Path, verified_only: bool, regenerate: Callable[[], Dict[str, str]]) -> Dict[str, str]:
    """reconstructed_src/ as it is (the files on GitHub), or with the generated files rebuilt from the verified
    functions only. The address-order files come first, then the rest in folder order."""
    files: Dict[str, str] = {}
    for p in sorted(recon_dir.rglob("*")):
        if p.is_file() and (p.suffix.lower() in SOURCE_EXTS or p.name == "CMakeLists.txt"):
            text = p.read_text(encoding="utf-8", errors="replace")
            if verified_only and "GENERATED from reports/verified_registry.json" in text[:600]:
                continue
            files[p.relative_to(recon_dir).as_posix()] = text
    if verified_only:
        files.update(regenerate())
    return dict(sorted(files.items(), key=lambda kv: (0 if kv[0].startswith("Original_Binary_Order") else 1, kv[0])))
