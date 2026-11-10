# Name Scarface's functions in Ghidra: every function the project knows (its start and size), with the names
# found so far (from the game's own class information, the PS2-to-Xbox pairing, verified matches and names
# people worked out), applied to the program you have open.
#
# Use: Window > Script Manager > "Manage Script Directories", add this folder (portal/scripts), then run
# ghidra_scarface_names.py on default.xbe, game.xbe, Scarface.exe (1.00.2) or SLUS_211.11. It asks for your
# copy of the repository (the folder with reconstructed_src/ in it). Nothing is changed outside the program.
# Works in Ghidra's Jython (Python 2.7) and in PyGhidra (Python 3). Headless: -postScript
# ghidra_scarface_names.py <repository folder> [xb|pc|ps2|proto]. See docs/NAMES.md.
#
#@author Scarface decomp project
#@category Scarface
#@menupath Tools.Scarface.Apply names
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


def split_name(name):
    """'a::B<c::D>::f' -> ['a', 'B<c_D>', 'f']: namespaces, then the function's own name."""
    parts, depth, cur, i = [], 0, "", 0
    while i < len(name):
        ch = name[i]
        if ch == "<":
            depth += 1
        elif ch == ">":
            depth = max(0, depth - 1)
        if depth == 0 and name.startswith("::", i):
            parts.append(cur)
            cur, i = "", i + 2
            continue
        cur += ch
        i += 1
    parts.append(cur)
    return [p.replace("::", "_").replace(" ", "_") for p in parts if p]


def guess_version(program_name):
    low = (program_name or "").lower()
    for v in VERSIONS:
        if any(w in low for w in v[3]):
            return v
    return None


def main():
    from ghidra.program.model.symbol import SourceType

    args = list(getScriptArgs())                    # headless: <repository folder> [xb|pc|ps2|proto]
    if args:
        repo = args[0]
    else:
        repo = askDirectory("Scarface decomp: your copy of the repository", "Use this folder").getAbsolutePath()
    if not os.path.isfile(os.path.join(repo, "reconstructed_src", VERSIONS[0][1])):
        popup("That folder has no reconstructed_src/. Pick the folder you cloned or unzipped the project into.")
        return
    labels = [v[0] for v in VERSIONS]
    guess = guess_version(currentProgram.getName()) or VERSIONS[0]
    if len(args) > 1:
        version = [v for v in VERSIONS if v[2] == args[1]][0]
    elif args:
        version = guess
    else:
        version = VERSIONS[labels.index(askChoice("Scarface decomp", "Which version is this program?", labels, guess[0]))]
    funcs = read_functions(repo, version)
    table = currentProgram.getSymbolTable()
    listing = currentProgram.getListing()
    made = named = missing = 0
    monitor.initialize(len(funcs))
    for addr_int, size, name, verified in funcs:
        if monitor.isCancelled():
            break
        monitor.incrementProgress(1)
        addr = toAddr(addr_int)
        if not currentProgram.getMemory().contains(addr):
            missing += 1
            continue
        fn = getFunctionAt(addr)
        if fn is None:
            if listing.getInstructionAt(addr) is None:
                disassemble(addr)
            fn = createFunction(addr, None)
            if fn is None:
                missing += 1
                continue
            made += 1
        if DEFAULT_RE.match(name):
            continue
        parts = split_name(name)
        ns = currentProgram.getGlobalNamespace()
        for part in parts[:-1]:
            found = table.getNamespace(part, ns)
            ns = found if found is not None else table.createNameSpace(ns, part, SourceType.IMPORTED)
        try:
            fn.setName(parts[-1], SourceType.IMPORTED)
            fn.setParentNamespace(ns)
            named += 1
        except Exception as e:                      # a clash with another symbol: leave that one as it is
            print("0x%08X %s: %s" % (addr_int, name, e))
        if verified:
            fn.setComment("Scarface decomp: verified match. Its C++ is in reconstructed_src/ (search for 0x%08X)." % addr_int)
    msg = "%s: %d functions known, %d created, %d named, %d not in this program." % (
        version[0], len(funcs), made, named, missing)
    print(msg)
    popup(msg)


if "currentProgram" in globals():
    main()
