#!/usr/bin/env python3
"""
Check this computer's setup for the Scarface decomp project, and say how to fix what isn't right.

    python portal/doctor.py            everything, with how to fix each problem
    python portal/doctor.py --share    the same, safe to paste into #help on Discord (no user name or folders)
    python portal/doctor.py --startup  only the problems, quickly (START_PORTAL runs this)

It changes nothing: it reads the game files' fingerprints, asks the compiler for its version and compiles a
one-line test, looks at git and the portal's port, and (unless --offline) whether decomp.me answers.
Exit code 1 when something needs fixing.
"""

from __future__ import annotations

import argparse
import os
import platform
import re
import shutil
import socket
import subprocess
import sys
import urllib.error
import urllib.request
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable, List, Optional

PORTAL = Path(__file__).resolve().parent
ROOT = PORTAL.parent
sys.path.insert(0, str(PORTAL / "tools"))

MIN_PYTHON = (3, 9)
ACCEPTED_BUILDS = ("13.10.3052", "13.10.3077")
GAME_COPY_GB = 13          # every version, no duplicates (README: about 12.4 GB)


@dataclass
class Check:
    state: str              # "ok", "fix" (something needs doing) or "note" (optional, or for information)
    title: str
    fix: List[str] = field(default_factory=list)


@dataclass
class Report:
    checks: List[Check] = field(default_factory=list)

    def add(self, state: str, title: str, *fix: str) -> None:
        self.checks.append(Check(state, title, [f for f in fix if f]))

    @property
    def problems(self) -> List[Check]:
        return [c for c in self.checks if c.state == "fix"]


# --------------------------------------------------------------------------- the checks

def check_python(r: Report, version=sys.version_info) -> None:
    v = f"{version[0]}.{version[1]}.{version[2]}"
    if tuple(version[:2]) >= MIN_PYTHON:
        r.add("ok", f"Python {v}")
    else:
        r.add("fix", f"Python {v} is too old (the portal needs {MIN_PYTHON[0]}.{MIN_PYTHON[1]} or newer)",
              "Install a current Python from https://www.python.org/downloads/ (tick \"Add python.exe to PATH\").")


def check_packages(r: Report, root: Path = ROOT) -> None:
    venv = root / "portal" / ".venv"
    if (venv / "Scripts" / "python.exe").exists() or (venv / "bin" / "python").exists():
        r.add("ok", "The portal's Python packages are set up (portal/.venv)")
    else:
        r.add("note", "The portal's Python packages aren't set up yet",
              "START_PORTAL.bat (or sh start_portal.sh) installs them the first time it runs.")


def _git(args: List[str], cwd: Path) -> Optional[str]:
    try:
        p = subprocess.run(["git"] + args, cwd=cwd, capture_output=True, text=True, timeout=30)
    except (OSError, subprocess.TimeoutExpired):
        return None
    return p.stdout.strip() if p.returncode == 0 else None


def check_git(r: Report, root: Path = ROOT, git: Callable = _git) -> None:
    if shutil.which("git") is None and git is _git:
        r.add("note", "Git isn't installed",
              "You can work without it, but to submit and update easily install Git from https://git-scm.com/ "
              "and clone the project (docs/CONTRIBUTING.md).")
        return
    top = git(["rev-parse", "--show-toplevel"], root)
    if not top or Path(top).resolve() != root.resolve():
        r.add("note", "This folder isn't a git clone (a ZIP download?)",
              "Matches still save on this computer, but to update and send your work easily, connect the folder "
              "to Git: docs/CONTRIBUTING.md, \"Downloaded the ZIP?\".")
        return
    branch = git(["rev-parse", "--abbrev-ref", "HEAD"], root) or "?"
    counts = git(["rev-list", "--left-right", "--count", "HEAD...@{upstream}"], root)
    if counts and re.match(r"^\d+\s+\d+$", counts):
        ahead, behind = (int(x) for x in counts.split())
        if behind:
            r.add("note", f"Git clone, branch {branch}: {behind} update(s) on GitHub you don't have yet "
                  "(as of your last fetch)", "Update with: git pull")
        else:
            r.add("ok", f"Git clone, branch {branch}" + (f", {ahead} commit(s) not pushed yet" if ahead else ", up to date"))
    else:
        r.add("ok", f"Git clone, branch {branch}")


def check_game_files(r: Report, bin_dir: Path) -> None:
    import game_files as GF
    import game_assets as GA
    sources = {}
    try:
        sources, _notes = GA.find_sources(bin_dir, installed_pc=True)
    except Exception:  # noqa: BLE001 - only used to say where a missing file will come from
        pass
    usable = 0
    labels = {"default.xbe": ("Xbox", "xbox", True), "Scarface.exe": ("PC 1.00.2", "pc", False),
              "SLUS_211.11": ("PS2", "ps2", False), "game.xbe": ("Xbox prototype", "prototype", False)}
    for name, (label, version, main) in labels.items():
        path = bin_dir / name
        state = GF.check(path)
        if state == "ok":
            r.add("ok", f"{name}: {GF.EXPECTED[name][1]} (accepted)")
            usable += name in GF.REQUIRED_ONE_OF
            continue
        if state == "different":
            r.add("fix", f"{name} is not the accepted copy", GF.refusal(path) or "")
            continue
        # missing: will the portal take it out of something in binaries/ when it starts?
        where = ""
        if name == "Scarface.exe":
            patch = GF._patch_installer(bin_dir)
            if patch and GF._exe_in_patch(patch):
                where = f"the patch ({patch.name})"
            elif GF._installed_pc_exe():
                where = "your installed PC game"
        elif name == "SLUS_211.11":
            ps2 = GF._ps2_sources(bin_dir)
            where = ps2[0].name if ps2 else ""
        elif version in sources:
            where = sources[version].path.name
        if where:
            r.add("ok", f"{name}: not taken out yet; the portal gets it from {where} when it starts")
            usable += name in GF.REQUIRED_ONE_OF
        elif main:
            r.add("fix", f"No {label} game ({name})",
                  "Put the US Xbox disc, or the .7z / .zip / .iso download it came in, in the binaries folder. "
                  "See docs/GAME_VERSIONS.md for the accepted copy.")
        else:
            extra = {"Scarface.exe": "Put the official 1.00.2 patch (or an installed, patched Scarface.exe) in binaries/.",
                     "SLUS_211.11": "Put the US PS2 disc download (with \"ps2\" in its name) in binaries/.",
                     "game.xbe": "Put the April 2006 prototype's .zip in binaries/."}[name]
            r.add("note", f"{label} ({name}): not there (optional)", extra)
    if not usable and not any(c.state == "fix" and "default.xbe" in c.title for c in r.checks):
        r.add("fix", "No accepted Xbox or PC game file", "The portal needs default.xbe (Xbox) or Scarface.exe (PC 1.00.2).")


def check_compiler(r: Report, compile_test: bool = True) -> None:
    import msvc_verify as MV
    bin_dir = MV.find_msvc71_bin()
    if bin_dir is None:
        r.add("fix", "The compiler (Visual C++ Toolkit 2003) isn't set up",
              "Download VCToolkitSetup.exe (see docs/CONTRIBUTING.md), put it in the project folder and start the portal again: "
              "it sets the compiler up by itself (or run: python portal/scripts/setup_msvc71.py VCToolkitSetup.exe)",
              "Until then you can still work on decomp.me (the decomp.me button in the portal).")
        return
    if os.name != "nt" and shutil.which("wine") is None:
        r.add("fix", "The compiler is there, but Wine isn't installed (cl.exe is a Windows program)",
              "Install Wine (macOS: brew install --cask wine-stable; Debian/Ubuntu: sudo apt install wine), then try again.")
        return
    build = MV.compiler_build(bin_dir)
    if build not in ACCEPTED_BUILDS:
        r.add("fix", f"The compiler reports \"{MV.compiler_version(bin_dir)}\", not 13.10.3052 or 13.10.3077",
              "The game was built with the Visual C++ Toolkit 2003 (cl.exe 13.10.3052 or 13.10.3077); other "
              "versions make different bytes. Run portal/scripts/setup_msvc71.py with VCToolkitSetup.exe.")
        return
    if not compile_test:
        r.add("ok", f"Compiler: cl.exe {build} ({MV.TOOLKIT_BUILDS.get(build, '')})")
        return
    res = MV.compile_cpp("int scarface_doctor_test() { return 1; }", "/nologo /c /O2")
    if res.ok and res.obj:
        r.add("ok", f"Compiler: cl.exe {build}, and a test compile works")
    else:
        lines = (res.error or "no object file").strip().splitlines()
        r.add("fix", f"Compiler: cl.exe {build} is there, but a one-line test didn't compile",
              lines[0][:200] if lines else "", "Run portal/scripts/setup_msvc71.py again, or ask in #help with --share.")


def _portal_answers(port: int) -> bool:
    try:
        with urllib.request.urlopen(f"http://127.0.0.1:{port}/api/state", timeout=3) as resp:
            return resp.status == 200 and b"progress" in resp.read(4096)
    except (urllib.error.URLError, OSError, ValueError):
        return False


def check_port(r: Report, port: Optional[int] = None) -> None:
    port = port or int(os.environ.get("SCARFACE_PORT", "8085") or 8085)
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        s.bind(("127.0.0.1", port))
        free = True
    except OSError:
        free = False
    finally:
        s.close()
    if free:
        r.add("ok", f"Port {port} is free for the portal")
    elif _portal_answers(port):
        r.add("note", f"The portal is already running: open http://localhost:{port}",
              "Starting it a second time won't work while this one runs; close its window first.")
    else:
        r.add("fix", f"Something else is using port {port}",
              "Close that program, or start the portal on another port: set SCARFACE_PORT=8090 (Windows: "
              "set SCARFACE_PORT=8090 before START_PORTAL.bat; macOS/Linux: SCARFACE_PORT=8090 sh start_portal.sh).")


def check_decompme(r: Report, fetch: Optional[Callable[[], int]] = None) -> None:
    def default() -> int:
        req = urllib.request.Request("https://decomp.me/api/compiler", headers={"User-Agent": "scarface-decomp-doctor"})
        try:
            with urllib.request.urlopen(req, timeout=8) as resp:
                return resp.status
        except urllib.error.HTTPError as e:
            return e.code
    try:
        status = (fetch or default)()
    except (urllib.error.URLError, OSError, ValueError):
        r.add("note", "decomp.me: can't reach it from here (no internet, or blocked)",
              "Only PS2 functions and the decomp.me button need it.")
        return
    if status == 200:
        r.add("ok", "decomp.me answers this computer directly")
    else:
        r.add("ok", f"decomp.me turns away programs (HTTP {status}): the portal goes through your browser instead",
              "The first time, the portal shows a bookmark to drag to your bookmarks bar and click on decomp.me "
              "(docs/PS2.md).")


def check_extras(r: Report, bin_dir: Path) -> None:
    try:
        free = shutil.disk_usage(bin_dir if bin_dir.exists() else ROOT).free
        gb = free / 1e9
        if gb < GAME_COPY_GB + 2:
            r.add("note", f"{gb:.1f} GB free on this drive",
                  f"Copying out every version's game files (the portal's Game files section) takes up to "
                  f"{GAME_COPY_GB} GB; the rest of the project needs little space.")
        else:
            r.add("ok", f"{gb:.0f} GB free on this drive")
    except OSError:
        pass
    import game_files as GF
    if any(p.suffix.lower() == ".7z" for p in (bin_dir.iterdir() if bin_dir.is_dir() else [])):
        r.add("ok" if GF._seven_zip_program() else "note",
              "7-Zip: found" if GF._seven_zip_program() else "7-Zip isn't installed",
              "" if GF._seven_zip_program() else
              "Only needed for .7z downloads packed in an unusual way: the portal reads ordinary ones by itself. "
              "If it says it can't read one, install 7-Zip from https://www.7-zip.org/.")
    webhook = os.environ.get("SCARFACE_DISCORD_WEBHOOK") or (ROOT / "portal" / "private" / "discord_webhook.txt").exists()
    if webhook:
        import discord_feed as D
        r.add("ok" if D.webhook_url(ROOT) else "fix",
              "Discord announcements: set up" if D.webhook_url(ROOT) else "The Discord webhook isn't a Discord webhook address",
              "" if D.webhook_url(ROOT) else "It must look like https://discord.com/api/webhooks/<number>/<token> (CONTRIBUTING.md).")


# --------------------------------------------------------------------------- output

MARK = {"ok": "  OK  ", "fix": "  FIX ", "note": "  NOTE"}


def redact(text: str, root: Path = ROOT) -> str:
    """For --share: no folders on this computer and no user name."""
    out = text.replace(str(root), "<project>").replace(str(root).replace("\\", "/"), "<project>")
    home = str(Path.home())
    out = out.replace(home, "~").replace(home.replace("\\", "/"), "~")
    user = os.environ.get("USERNAME") or os.environ.get("USER") or ""
    if len(user) >= 3:
        out = re.sub(re.escape(user), "<user>", out, flags=re.IGNORECASE)
    return out


def render(r: Report, share: bool = False, only_problems: bool = False) -> str:
    lines = []
    if not only_problems:
        lines.append("Scarface decomp: checking your setup")
        if share:
            lines.append(f"({platform.system()} {platform.release()}, {platform.machine()})")
        lines.append("")
    for c in r.checks:
        if only_problems and c.state != "fix" and not c.title.startswith("The portal is already running"):
            continue
        lines.append(f"{MARK[c.state]}  {c.title}")
        for f in c.fix:
            lines.append(f"          -> {f}")
    n = len(r.problems)
    if only_problems:
        if n:
            lines.insert(0, f"Setup check: {n} thing{'' if n == 1 else 's'} to fix (python portal/doctor.py for details)")
            lines.append("")
    else:
        lines.append("")
        lines.append("All good." if not n else f"{n} thing{'' if n == 1 else 's'} to fix.")
    text = "\n".join(lines)
    return redact(text) if share else text


def run(online: bool = True, compile_test: bool = True, bin_dir: Path = ROOT / "binaries") -> Report:
    r = Report()
    check_python(r)
    check_packages(r)
    check_git(r)
    check_game_files(r, bin_dir)
    check_compiler(r, compile_test)
    check_port(r)
    if online:
        check_decompme(r)
    check_extras(r, bin_dir)
    return r


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--share", action="store_true", help="safe to paste in Discord: no user name or folders")
    ap.add_argument("--startup", action="store_true", help="only the problems, without the network check")
    ap.add_argument("--offline", action="store_true", help="skip the decomp.me check")
    a = ap.parse_args(argv)
    r = run(online=not (a.offline or a.startup))
    out = render(r, share=a.share, only_problems=a.startup)
    if out:
        print(out)
    return 1 if r.problems else 0


if __name__ == "__main__":
    raise SystemExit(main())
