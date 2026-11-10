"""
Name Scarface's functions in IDA: every function the project knows (its start and size), with the names found
so far (from the game's own class information, the PS2-to-Xbox pairing, verified matches and names people
worked out), applied to the database you have open.

Use: File > Script file... and pick this file, with default.xbe, game.xbe, Scarface.exe (1.00.2), SLUS_211.11
or a PS2 overlay's ELF file (portal/tools/ps2_overlay.py --elf) loaded. It asks for your copy of the repository (any file in it, for example README.md).
IDA 7.4 or later (IDAPython 3). Names with "::" are kept when IDA accepts them; otherwise IDA puts "_" in
place of what it doesn't accept. See docs/NAMES.md.
"""
from __future__ import print_function

import json
import os
import re

VERSIONS = [
    # (label, file in reconstructed_src/, key prefix in reports/names.json, words in the program's name)
    ("Xbox (default.xbe)", "Original_Binary_Order_Xbox.cpp", "xb", ("default.xbe", "default")),
    ("PC 1.00.2 (Scarface.exe)", "Original_Binary_Order_PC_1002.cpp", "pc", ("scarface.exe", ".exe")),
    ("PS2 (SLUS_211.11)", "Original_Binary_Order_PS2.cpp", "ps2", ("slus_211.11", "slus")),
    ("Xbox prototype, April 2006 (game.xbe)", "Original_Binary_Order_Proto.cpp", "proto", ("game.xbe",)),
    # the PS2 program's code overlays, opened as the ELF files portal/tools/ps2_overlay.py --elf writes
    ("PS2 pause menu overlay (PauseMenuOverlayf)", "Original_Binary_Order_PS2_PauseMenu.cpp", "ps2pause", ("pausemenuoverlayf",)),
    ("PS2 exotics shop overlay (ExoticsOverlayf)", "Original_Binary_Order_PS2_Exotics.cpp", "ps2exotics", ("exoticsoverlayf",)),
    ("PS2 business screens overlay (ModalsOverlayf)", "Original_Binary_Order_PS2_Modals.cpp", "ps2modals", ("modalsoverlayf",)),
    ("PS2 empire and mansion screens overlay (ModalsOverlay1f)", "Original_Binary_Order_PS2_Modals1.cpp", "ps2modals1", ("modalsoverlay1f",)),
    ("PS2 weapon screens overlay (ModalsOverlay2f)", "Original_Binary_Order_PS2_Modals2.cpp", "ps2modals2", ("modalsoverlay2f",)),
    ("PS2 gambling mini-games overlay (MiniGamesOverlayf)", "Original_Binary_Order_PS2_MiniGames.cpp", "ps2games", ("minigamesoverlayf",)),
]
TODO_RE = re.compile(r"^// \[TODO\] 0x([0-9A-Fa-f]{8}) (.*) \((\d+) B\)$")
DONE_RE = re.compile(r"^// \[VERIFIED\] (.*) \((0x[0-9A-Fa-f]{8}), (\d+) B\)$")
DEFAULT_RE = re.compile(r"^(sub|func|FUN|thunk)_[0-9A-Fa-f]+$")


def read_functions(repo, version):
    """[(address, size, name, verified)] for one version, with names from reports/names.json on top."""
    _label, fname, prefix, _words = version
    out = {}
    with open(os.path.join(repo, "reconstructed_src", fname), "rb") as f:
        for raw in f:
            line = raw.decode("utf-8", "replace").rstrip("\r\n")
            m = TODO_RE.match(line)
            if m:
                out[int(m.group(1), 16)] = [int(m.group(3)), m.group(2), False]
                continue
            m = DONE_RE.match(line)
            if m:
                out[int(m.group(2), 16)] = [int(m.group(3)), m.group(1), True]
    try:
        with open(os.path.join(repo, "reports", "names.json"), "rb") as f:
            names = json.loads(f.read().decode("utf-8")).get("names", {})
    except (IOError, OSError, ValueError):
        names = {}
    for key, info in names.items():
        b, _, va = key.partition(":")
        if b == prefix and va:
            addr = int(va, 16)
            if addr in out and not out[addr][2]:          # a verified match keeps the name it was matched with
                out[addr][1] = info.get("name") or out[addr][1]
    return [(a, s, n, v) for a, (s, n, v) in sorted(out.items())]


def guess_version(program_name):
    low = (program_name or "").lower()
    for v in VERSIONS:
        if any(w in low for w in v[3]):
            return v
    return None


def find_repo(path):
    """The repository folder above a file the person picked."""
    d = os.path.dirname(os.path.abspath(path))
    while True:
        if os.path.isfile(os.path.join(d, "reconstructed_src", VERSIONS[0][1])):
            return d
        up = os.path.dirname(d)
        if up == d:
            return None
        d = up


def main():
    import ida_funcs
    import ida_kernwin
    import ida_name
    import ida_nalt
    import idc

    picked = ida_kernwin.ask_file(0, "*.*", "Scarface decomp: any file in your copy of the repository (e.g. README.md)")
    repo = find_repo(picked) if picked else None
    if not repo:
        ida_kernwin.warning("That isn't inside the Scarface decomp repository (no reconstructed_src/ above it).")
        return
    guess = guess_version(ida_nalt.get_root_filename()) or VERSIONS[0]
    labels = [v[0] for v in VERSIONS]
    form = "Which version is this database?\n" + "\n".join("%d: %s" % (i + 1, l) for i, l in enumerate(labels))
    n = ida_kernwin.ask_long(VERSIONS.index(guess) + 1, form)
    if n is None or not 1 <= n <= len(VERSIONS):
        return
    version = VERSIONS[n - 1]
    funcs = read_functions(repo, version)
    made = named = missing = 0
    flags = ida_name.SN_NOCHECK | ida_name.SN_NOWARN | ida_name.SN_FORCE
    ida_kernwin.show_wait_box("Naming Scarface's functions...")
    try:
        for i, (ea, size, name, verified) in enumerate(funcs):
            if i % 500 == 0 and ida_kernwin.user_cancelled():
                break
            if not idc.is_mapped(ea):
                missing += 1
                continue
            if ida_funcs.get_func(ea) is None:
                if ida_funcs.add_func(ea, ea + size if size else idc.BADADDR) or ida_funcs.add_func(ea):
                    made += 1
            if not DEFAULT_RE.match(name) and ida_name.set_name(ea, name, flags):
                named += 1
            if verified:
                idc.set_func_cmt(ea, "Scarface decomp: verified match. Its C++ is in reconstructed_src/ (search for 0x%08X)." % ea, 1)
    finally:
        ida_kernwin.hide_wait_box()
    msg = "%s: %d functions known, %d created, %d named, %d not in this database." % (
        version[0], len(funcs), made, named, missing)
    print(msg)
    ida_kernwin.info(msg)


if __name__ == "__main__":
    try:
        main()
    except ImportError:
        print("Run this from IDA: File > Script file...")
