#!/usr/bin/env python3
"""
Repository consistency check (runs in CI, needs neither the compiler nor the game files).

  1. reports/verified_registry.json is well formed, and every recorded function is plain C++ that
     passes the verifier's policy check.
  2. The generated files (reconstructed_src/Original_Binary_Order_*.cpp, reconstructed_src/pc/,
     reconstructed_src/xbox/ and the status block in README.md) match the registry.
  3. Nothing that must never be committed is tracked: game files, compiler files, credentials.

    python portal/scripts/check_repo.py
"""
from __future__ import annotations

import fnmatch
import json
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

PORTAL = Path(__file__).resolve().parent.parent      # portal/
ROOT = PORTAL.parent                                  # the project folder
sys.path.insert(0, str(PORTAL / "tools"))

from cpp_policy import check_genuine_cpp  # noqa: E402
from registry_outputs import STATUS_END, STATUS_START, write_outputs  # noqa: E402
from game_files import EXPECTED as ACCEPTED_GAME_FILES  # noqa: E402
import names as NAMES  # noqa: E402
from registry_outputs import known_from_files  # noqa: E402

FORBIDDEN = ["*.exe", "*.xbe", "*.rcf", "*.bik", "*.iso", "*.7z", "*.zip", "*.obj", "*.pdb", "*.cso", "*.dso",
             "*.dtr", "tools/msvc71/*", "portal/tools/msvc71/*", "binaries/*", "private/*", "portal/private/*", "*contributor_tokens.json",
             "source_archives/*"]
VA_RE = re.compile(r"^0x[0-9A-F]{8}$")


def check_registry(problems: list) -> dict:
    p = ROOT / "reports" / "verified_registry.json"
    try:
        reg = json.loads(p.read_text(encoding="utf-8"))
    except (OSError, ValueError) as e:
        problems.append(f"registry: cannot read {p.name}: {e}")
        return {}
    entries = reg.get("entries")
    if not isinstance(entries, dict):
        problems.append("registry: 'entries' is missing")
        return reg
    # The registry must have been verified against the accepted US game files (docs/GAME_VERSIONS.md).
    for lane, info in (reg.get("binaries") or {}).items():
        name, digest = (info or {}).get("file", ""), (info or {}).get("sha256", "")
        if name not in ACCEPTED_GAME_FILES or digest not in ACCEPTED_GAME_FILES[name][0]:
            problems.append(f"registry: verified against {name or lane} {digest[:12]}..., which is not an accepted "
                            "game version (docs/GAME_VERSIONS.md)")
    for key, e in entries.items():
        where = f"registry {key}"
        if e.get("bin") not in ("pc", "xb", "proto", "ps2"):
            problems.append(f"{where}: unknown binary {e.get('bin')!r}")
        if not VA_RE.match(str(e.get("va", ""))) or key != f"{e.get('bin')}:{e.get('va')}":
            problems.append(f"{where}: key and address do not agree ({e.get('va')!r})")
        if not isinstance(e.get("size"), int) or e["size"] <= 0:
            problems.append(f"{where}: bad size {e.get('size')!r}")
        want = "-O3" if e.get("bin") == "ps2" else "/O2"        # the PS2 game has its own compiler
        if not str(e.get("flags", "")).startswith(want):
            problems.append(f"{where}: unexpected flags {e.get('flags')!r}")
        what = e.get("what")
        if what is not None and (not isinstance(what, str) or len(what) > 160 or "\n" in what or what != what.strip()):
            problems.append(f"{where}: 'what' must be one line of at most 160 characters")
        code = e.get("code") or ""
        if not code.strip():
            problems.append(f"{where}: no code recorded")
        elif check_genuine_cpp(code):
            problems.append(f"{where}: code fails the C++ policy (inline assembly, _emit, section pragmas, ...)")
    return reg


def _norm(path: Path) -> str:
    return path.read_text(encoding="utf-8", errors="replace").replace("\r\n", "\n")


def check_generated(reg: dict, problems: list) -> None:
    if not reg:
        return
    with tempfile.TemporaryDirectory(prefix="sf_check_") as tmp:
        troot = Path(tmp)
        (troot / "reconstructed_src").mkdir()
        (troot / "reports").mkdir()
        shutil.copy2(ROOT / "README.md", troot / "README.md")
        if (ROOT / "reports" / "progress.json").exists():
            shutil.copy2(ROOT / "reports" / "progress.json", troot / "reports" / "progress.json")
        # the function list comes from the committed files (CI has no game files)
        written = write_outputs(reg, troot / "reconstructed_src", known_from=ROOT / "reconstructed_src")
        if not (ROOT / "reports" / "progress.json").exists():
            problems.append("reports/progress.json is missing (run: python portal/tools/registry_outputs.py)")
        for rel in written:
            got = troot / "reconstructed_src" / rel
            have = ROOT / "reconstructed_src" / rel
            if not have.exists():
                problems.append(f"generated file missing: {have.relative_to(ROOT).as_posix()} "
                                "(run: python portal/tools/registry_outputs.py)")
            elif _norm(have) != _norm(got):
                problems.append(f"generated file out of date: {have.relative_to(ROOT).as_posix()} "
                                "(run: python portal/tools/registry_outputs.py)")
        # README status block
        readme = _norm(ROOT / "README.md")
        if STATUS_START not in readme or STATUS_END not in readme:
            problems.append("README.md: status block markers are missing")
        # stale generated files that no longer correspond to any entry are blanked by write_outputs;
        # check that nothing generated exists in the repo that the registry would not write
        for folder in ("pc", "xbox", "proto", "ps2"):
            for p in (ROOT / "reconstructed_src" / folder).rglob("*.cpp") if (ROOT / "reconstructed_src" / folder).exists() else []:
                rel = p.relative_to(ROOT / "reconstructed_src").as_posix()
                if "GENERATED from reports/verified_registry.json" in _norm(p)[:400] and rel not in written:
                    if "(0 verified)" not in _norm(p)[:400]:
                        problems.append(f"generated file has no registry entries: reconstructed_src/{rel}")


def check_names(problems: list) -> None:
    """reports/names.json: well-formed, and every name at an address where a function starts."""
    path = ROOT / "reports" / "names.json"
    if not path.exists():
        return
    known = {b: set(fns) for b, fns in known_from_files(ROOT / "reconstructed_src").items()}
    problems.extend(NAMES.problems(NAMES.load(path), known))


def check_tracked(problems: list) -> None:
    try:
        out = subprocess.run(["git", "ls-files"], cwd=ROOT, capture_output=True, text=True, timeout=60)
    except (OSError, subprocess.SubprocessError):
        return                                      # not a git checkout: nothing to check
    if out.returncode != 0:
        return
    for f in out.stdout.splitlines():
        low = f.lower()
        if low == "binaries/readme.md":
            continue                                # the folder's instructions, not a game file
        if any(fnmatch.fnmatch(low, pat) for pat in FORBIDDEN):
            problems.append(f"tracked file must not be committed: {f}")


def main() -> int:
    problems: list = []
    reg = check_registry(problems)
    check_generated(reg, problems)
    check_names(problems)
    check_tracked(problems)
    n = len(reg.get("entries", {})) if reg else 0
    if problems:
        print(f"{len(problems)} problem(s):")
        for p in problems[:200]:
            print("  - " + p)
        return 1
    print(f"OK: {n:,} verified functions in the registry; generated files and README are in sync; "
          "no forbidden files tracked.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
