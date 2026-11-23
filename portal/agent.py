#!/usr/bin/env python3
"""
A command-line way to work on functions, for a coding agent (or a person who lives in a terminal).
No browser, no AI key and no PIN: it reads the same files the portal does and checks with the same rules.

    python portal/agent.py next --bin xb --max-size 40      functions still open, smallest first
    python portal/agent.py packet xb 0x00248810             everything known about one, and a starter file
    python portal/agent.py check work/xb_00248810.cpp       compile it and compare with the original bytes
    python portal/agent.py keep work/xb_00248810.cpp        an exact match goes to reports/to_submit/

No game files or compiler? Matched functions still need a one-line description of what they do:

    python portal/agent.py describe --who yourname           a batch of matched functions with none yet
    python portal/agent.py describe-keep work/descriptions_yourname.json     check them; ready to send

A match is only *recorded* by the portal, under a person's handle: after `keep`, the person runs
`python portal/scripts/submit_matches.py`. See AGENTS.md for the whole loop and the rules.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import random
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "portal" / "tools"))
sys.path.insert(0, str(ROOT / "portal"))

import names as NAMES  # noqa: E402
import ps2_overlay as PO  # noqa: E402
import readability as READ  # noqa: E402
import registry_outputs as RO  # noqa: E402

BINARIES = {"pc": ROOT / "binaries" / "Scarface.exe", "xb": ROOT / "binaries" / "default.xbe",
            "proto": ROOT / "binaries" / "game.xbe"}
QUEUE = ROOT / "reports" / "full_remaining_queue.json"
WORK = ROOT / "work"
TO_SUBMIT = ROOT / "reports" / "to_submit"
DEFAULT_FLAGS = "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4"
HEADER = re.compile(r"^//\s*(bin|va|what|tool|spec):\s*(.*)$", re.M)
CLASSMATES = 3
NEAREST = 3            # matched functions with the most similar instructions (portal/tools/similar.py)
NEAREST_FLOOR = 0.6


def registry() -> dict:
    p = ROOT / "reports" / "verified_registry.json"
    return json.loads(p.read_text(encoding="utf-8")).get("entries", {}) if p.exists() else {}


def functions() -> list:
    """Every function the project knows of on the Xbox, PC and prototype builds: the portal's queue when this
    computer has one, otherwise the address-order lists that come with the repository."""
    if QUEUE.exists():
        return [t for t in json.loads(QUEUE.read_text(encoding="utf-8")) if t.get("bin") in BINARIES and "fva_int" in t]
    return [t for b, fns in RO.known_from_files(ROOT / "reconstructed_src").items() if b in BINARIES for t in fns.values()]


def key_of(b: str, va: int) -> str:
    return f"{b}:0x{va:08X}"


def find(b: str, va: int) -> dict:
    for t in functions():
        if t["bin"] == b and t["fva_int"] == va:
            return t
    e = registry().get(key_of(b, va))
    if e and e.get("size"):                  # matched already, so no longer in the queue of open work
        return {"bin": b, "fva_int": va, "va": f"0x{va:08X}", "size": int(e["size"]), "symbol": e.get("symbol", ""),
                "flags": e.get("flags") or DEFAULT_FLAGS}
    sys.exit(f"{key_of(b, va)} is not a function the project knows of. `next` lists the ones that are open.")


def image(b: str):
    from sf_binaries import BinaryImage
    from game_files import refusal
    path = BINARIES[b]
    if not path.exists():
        sys.exit(f"binaries/{path.name} is missing: this needs your own copy of the game (binaries/README.md).")
    problem = refusal(path)
    if problem:
        sys.exit(problem)
    return BinaryImage(path)


def flags_for(t: dict, target=None) -> list:
    import msvc_verify as MV
    return MV.flag_options(t["bin"], t.get("flags") or DEFAULT_FLAGS, target)


def known_names(b: str) -> dict:
    return NAMES.addresses(NAMES.load(ROOT / "reports" / "names.json"), b)


def codegen_hints(b: str, tb: bytes) -> list:
    """What the function's own instructions say about how its source was written (checked on the Xbox
    game against the matched functions; see docs/METHODOLOGY.md section 5)."""
    try:
        import capstone
    except ImportError:
        return []
    from msvc_verify import P6_ONLY as MV_P6
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    insns = list(md.disasm(bytes(tb), 0))
    mn = {i.mnemonic for i in insns}
    text = [f"{i.mnemonic} {i.op_str}" for i in insns]
    out = []
    if any(t.startswith("and esp, 0xfffffff8") for t in text[:4]):
        out.append("the frame is aligned to 8 bytes (and esp, -8): it has a local that needs that alignment, "
                   "a double or an __int64; no flag change is needed.")
    if b in ("xb", "proto") and mn & {"fsqrt", "fsin", "fcos", "fpatan"} and \
            any("xmm" in i.op_str or i.mnemonic.startswith(MV_P6) for i in insns):
        out.append("x87 math next to SSE code: write sqrt()/sin()/cos()/atan2() on doubles (the SSE of the "
                   "console has no doubles, so they stay on the x87), not sqrtf; keep /arch:SSE.")
    if b in ("xb", "proto") and any(t.startswith("fstp dword ptr [esp") for t in text) and "movss" in mn:
        out.append("a called function's float result arrives in ST0 and is stored to the stack to reach an "
                   "xmm register (fstp [esp]; movss): that is normal /arch:SSE code, not a flag miss.")
    return out


def cmd_next(args) -> int:
    done = registry()
    rows = [t for t in functions() if key_of(t["bin"], t["fva_int"]) not in done
            and (not args.bin or t["bin"] == args.bin) and args.min_size <= int(t["size"]) <= args.max_size]
    rows.sort(key=lambda t: (int(t["size"]), t["bin"], t["fva_int"]))
    score = {}
    if args.order == "similar":
        import similar as SIM
        if not SIM.RANKED.exists():
            sys.exit("Run `python portal/tools/similar.py rank` first (about a minute): it writes work/nearest_open.json.")
        ranked = json.loads(SIM.RANKED.read_text(encoding="utf-8"))
        score = {(r["bin"], int(r["va"], 16)): (r["score"], r["nearest"][0]["key"]) for r in ranked}
        rows = [t for t in rows if (t["bin"], t["fva_int"]) in score]
        rows.sort(key=lambda t: (-score[(t["bin"], t["fva_int"])][0], int(t["size"]), t["bin"], t["fva_int"]))
    waiting = {p.stem.lower() for p in TO_SUBMIT.glob("*.cpp")} if TO_SUBMIT.exists() else set()
    rows = [t for t in rows if f"{t['bin']}_{t['fva_int']:08x}" not in waiting]
    rows = spread(rows, args.who)
    print(f"{len(rows):,} open functions match. " + ("Most like a matched function first:" if score else "Smallest first:"))
    for t in rows[args.skip:args.skip + args.n]:
        near = score.get((t["bin"], t["fva_int"]))
        tail = f"   {near[0]:.2f} like {near[1]}" if near else ""
        print(f"  {t['bin']:<5} 0x{t['fva_int']:08X}  {int(t['size']):>5} B  {t.get('symbol', '')}{tail}")
    return 0


WINDOW = 40          # --who reorders within runs of this many, so the list keeps its order of priority


def spread(rows: list, who: str) -> list:
    """The same list in an order of this person's own: within each run of WINDOW, shuffled by their name.
    Several people (or their AIs) working from the same list then start on different functions instead of
    racing for the same ones, and everyone still works near the top of it."""
    if not who:
        return rows
    rng = random.Random(int(hashlib.sha256(who.strip().lower().encode()).hexdigest(), 16))
    out = []
    for i in range(0, len(rows), WINDOW):
        run = rows[i:i + WINDOW]
        rng.shuffle(run)
        out += run
    return out


# ---------------------------------------------------------------------------------------------------------
# Descriptions: no game files or compiler needed. The matched C++ is in the repository; an AI reads it (and
# what the functions it calls do) and writes one plain sentence per function.

DESCRIBE_RULES = """\
Write one plain sentence per function, at most 160 characters, saying what it does in the game's terms
("Turns the car's headlights on or off", "Returns the weapon the character is holding"). If you can't
tell what it is for, say what it returns or changes ("Clears the list at +0x20 and resets its count").
Don't restate the code (no sentence that is mostly sub_/DAT_ names and offsets), don't guess at names,
and skip a function rather than write a guess. Put them in work/descriptions_<who>.json:

  {"schema": "scarface_descriptions_v1", "by": "<the model> for <who>",
   "descriptions": {"xb:0x00012340": {"what": "...", "how": "read"}, ...}}

then: python portal/agent.py describe-keep work/descriptions_<who>.json"""
_CALL = re.compile(r"\b(sub_[0-9A-F]{8})\b")


def described_elsewhere() -> set:
    """Keys already described in a file waiting to be sent (work/ or reports/to_submit/)."""
    out = set()
    for folder in (WORK, TO_SUBMIT):
        for path in folder.glob("descriptions_*.json") if folder.exists() else ():
            try:
                out |= set((json.loads(path.read_text(encoding="utf-8")).get("descriptions") or {}))
            except (OSError, ValueError):
                continue
    return out


def describe_batch(entries: dict, names: dict, b: str, n: int, who: str = "", skip: set = frozenset(),
                   min_size: int = 16) -> list:
    """[(key, entry, [(callee key, its name, its description)])]: matched functions of b with no description,
    those whose calls are already explained first (so the batch reads bottom-up), smaller first."""
    rows = []
    for k, e in entries.items():
        if not k.startswith(b + ":") or (e.get("what") or "").strip() or e.get("excerpt") or k in skip \
                or int(e.get("size", 0)) < min_size:
            continue
        calls = []
        for sub in dict.fromkeys(_CALL.findall(e.get("code", ""))):
            ck = f"{b}:0x{sub[4:]}"
            if ck == k:
                continue
            ce = entries.get(ck) or {}
            calls.append((ck, (names.get(ck) or {}).get("name") or ce.get("symbol") or sub, (ce.get("what") or "").strip()))
        unknown = sum(1 for _, name, what in calls if not what and name.startswith("sub_"))
        known = len(calls) - unknown
        rows.append((unknown, -known, int(e.get("size", 0)), k, e, calls))
    rows.sort(key=lambda r: r[:4])
    return [(k, e, calls) for _, _, _, k, e, calls in spread(rows, who)[:n]]


def _code_only(code: str, limit: int = 120) -> str:
    """The C++ without the starter-code boilerplate comments at the top."""
    lines = [ln for ln in code.splitlines() if not re.match(r"^//\s*(bin|va|what|tool|spec|verify):", ln)
             and not re.search(r"Starter code written from the disassembly|retype them as you work|"
                               r"^// Same machine code as|^// its addresses and names were swapped", ln)]
    text = "\n".join(lines).strip()
    rows = text.splitlines()
    return text if len(rows) <= limit else "\n".join(rows[:limit]) + f"\n// ... {len(rows) - limit} more lines"


def cmd_describe(args) -> int:
    entries = registry()
    names = NAMES.load(ROOT / "reports" / "names.json").get("names", {})
    batch = describe_batch(entries, names, args.bin, args.n, args.who, described_elsewhere(), args.min_size)
    left = sum(1 for k, e in entries.items() if k.startswith(args.bin + ":") and not (e.get("what") or "").strip())
    print(f"{left:,} matched {args.bin} functions have no description yet. {len(batch)} of them:\n")
    print(DESCRIBE_RULES.replace("<who>", args.who or "yourname") + "\n")
    for k, e, calls in batch:
        own = (names.get(k) or {}).get("name")
        print(f"=== {k}  {own or e.get('symbol', '')}  ({e.get('size')} bytes)")
        for ck, name, what in calls[:12]:
            print(f"  calls {name}" + (f": {what}" if what else "") + ("" if name.startswith("sub_") else f"  ({ck})"))
        cls = e.get("symbol", "").rsplit("::", 1)[0] if "::" in e.get("symbol", "") else ""
        import descriptions as DESC
        mates = [(m.get("symbol"), m.get("what")) for mk, m in entries.items() if cls and mk != k
                 and mk.startswith(args.bin + ":") and m.get("symbol", "").startswith(cls + "::") and m.get("what")
                 and DESC.how_of(m) in ("human", "read")]
        for sym, what in mates[:3]:
            print(f"  same class: {sym}: {what}")
        print(_code_only(e.get("code", "")) + "\n")
    return 0


def check_descriptions(data: dict, entries: dict) -> tuple:
    """(the descriptions that can be sent, [(key, why not)]) for a descriptions file."""
    import descriptions as DESC
    if not isinstance(data, dict) or data.get("schema") != "scarface_descriptions_v1":
        return {}, [("file", 'its "schema" must be "scarface_descriptions_v1"')]
    if not str(data.get("by") or "").strip():
        return {}, [("file", 'say who wrote them in "by" (the model, for whom)')]
    good, bad = {}, []
    for k, d in (data.get("descriptions") or {}).items():
        what = re.sub(r"\s+", " ", str((d or {}).get("what") or "")).strip() if isinstance(d, dict) else ""
        e = entries.get(k)
        if not e:
            bad.append((k, "not a matched function (only matched functions are described)"))
        elif (e.get("what") or "").strip():
            bad.append((k, "already described"))
        elif DESC.problem(what):
            bad.append((k, DESC.problem(what)))
        else:
            good[k] = {"what": what, "how": DESC.normal_how(d.get("how") or "read")}
    return good, bad


def cmd_describe_keep(args) -> int:
    path = Path(args.file)
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError) as ex:
        sys.exit(f"Can't read {path}: {ex}")
    good, bad = check_descriptions(data, registry())
    for k, why in bad:
        print(f"  no   {k}: {why}")
    if not good:
        print("Nothing to keep.")
        return 1
    TO_SUBMIT.mkdir(parents=True, exist_ok=True)
    dest = TO_SUBMIT / ("descriptions_" + re.sub(r"[^A-Za-z0-9_-]+", "_", path.stem.replace("descriptions_", "")) + ".json")
    if dest.exists():
        old = json.loads(dest.read_text(encoding="utf-8"))
        good = dict(old.get("descriptions") or {}, **good)
    dest.write_text(json.dumps({"schema": "scarface_descriptions_v1", "by": str(data["by"])[:64], "descriptions": good},
                               indent=1, ensure_ascii=False) + "\n", encoding="utf-8")
    print(f"Kept {len(good)} in {dest.relative_to(ROOT)}. A maintainer sends them with "
          "python portal/scripts/submit_descriptions.py; anyone else posts the file in the Discord or a pull request.")
    return 0 if not bad else 1


def cmd_packet(args) -> int:
    import decompme as DME
    from disasm_synth import disassemble, synthesize_cpp
    b, va = args.bin, int(args.va, 16)
    t = find(b, va)
    size = int(t["size"])
    img = image(b)
    tb = img.read(va, size)
    if not tb:
        sys.exit(f"Could not read {size} bytes at {key_of(b, va)}.")
    done = registry()
    entry = done.get(key_of(b, va))
    try:
        relocs = DME.find_relocations(tb, va, img)
    except Exception:
        relocs = None
    lines = disassemble(tb)
    symbol = t.get("symbol") or f"sub_{va:08X}"
    label = f"{'PC ' if b == 'pc' else 'Proto ' if b == 'proto' else ''}0x{va:08X}"
    print(f"{symbol}  ({b} 0x{va:08X}, {size} bytes)" + ("   ALREADY MATCHED" if entry else ""))
    print(f"flags: {' | '.join(flags_for(t, tb))}")
    names = NAMES.load(ROOT / "reports" / "names.json").get("names", {})
    own = names.get(key_of(b, va))
    if isinstance(own, dict) and own.get("name"):
        print(f"name on record: {own['name']}  ({own.get('why', '')})")
    for hint in codegen_hints(b, tb):
        print("hint: " + hint)
    print("\ntarget bytes:\n  " + " ".join(f"{x:02X}" for x in tb[:512]) + (" ..." if size > 512 else ""))
    print("\ndisassembly:")
    for ln in lines:
        print("  " + ln)
    by_address = {a: n for n, a in known_names(b).items()}
    called = sorted({int(m, 16) for m in re.findall(r"0x([0-9a-fA-F]{5,8})", "\n".join(lines))} & set(by_address))
    if called:
        print("\nnames on record for addresses it uses (call them by name; the address is still checked):")
        for a in called:
            print(f"  0x{a:08X}  {by_address[a]}")
    cls = "::".join(symbol.split("::")[:-1])
    mates = [e for k, e in done.items() if cls and k.startswith(b + ":") and k != key_of(b, va)
             and e.get("symbol", "").startswith(cls + "::") and not e.get("excerpt")]
    mates.sort(key=lambda e: (READ.grade(e.get("code", ""))["left"], -int(e.get("size", 0))))
    for e in mates[:CLASSMATES]:
        print(f"\n--- already matched in the same class: {e['symbol']} ({e['va']}, {e['size']} bytes) ---")
        print(e.get("code", "").strip()[:5000])
    shown = {f"{e['bin']}:{e['va']}" for e in mates[:CLASSMATES] if e.get("bin") and e.get("va")}
    try:
        import similar as SIM
        near = SIM.nearest_for(b, va, size, k=NEAREST + len(shown), code=tb, floor=NEAREST_FLOOR)
    except Exception:
        near = []
    near = [(s, it) for s, it in near if it["key"] not in shown][:NEAREST]
    for s, it in near:
        e = done.get(it["key"], {})
        print(f"\n--- already matched, similar instructions ({s:.2f}): {e.get('symbol') or it['key']} "
              f"({it['key']}, {e.get('size', it['size'])} bytes) ---")
        print(e.get("code", "").strip()[:5000])
    WORK.mkdir(exist_ok=True)
    out = WORK / f"{b}_{va:08X}.cpp"
    if not out.exists() or args.force:
        body = entry["code"] if entry else synthesize_cpp(symbol, label, tb, lines, relocs=relocs)
        out.write_text(f"// bin: {b}\n// va: 0x{va:08X}\n// what: \n// tool: \n\n{body.rstrip()}\n", encoding="utf-8")
        print(f"\nstarter written to {out.relative_to(ROOT)}")
    else:
        print(f"\n{out.relative_to(ROOT)} is already there (kept; --force writes the starter again)")
    return 0


def header(text: str) -> dict:
    return {k: v.strip() for k, v in HEADER.findall(text)}


def selection(t: dict, text: str, match: str = "", flags: str = "") -> tuple:
    """(match, flag sets to try) for one check. Which compiled function is the target: --match, else the
    file's '// verify:' line, else the queue's own pick, else the address name (sub_XXXXXXXX), so an inline
    helper, <math.h> or a 'delete' that adds a second function to the object file doesn't hide it. The
    flags: --flags or the '// verify:' line (the function's own flags, fewer of them, or /arch:SSE), else
    the usual ones."""
    import msvc_verify as MV
    line = MV.verify_line_options(text)
    pick = match or line.get("match") or t.get("match_substr") or f"sub_{t['fva_int']:08X}"
    asked = flags or line.get("flags", "")
    if asked:
        bad = MV.allowed_flags(t.get("flags") or DEFAULT_FLAGS, asked)
        if bad:
            sys.exit(bad)
        return pick, [" ".join(asked.split())]
    return pick, None


def check(path: Path, match: str = "", flags: str = "") -> tuple:
    """(verified, result, task, text) for a work file. verified: exact bytes, every address checked, real C++."""
    import msvc_verify as MV
    text = path.read_text(encoding="utf-8")
    h = header(text)
    if h.get("bin") not in BINARIES or not re.fullmatch(r"0x[0-9A-Fa-f]{8}", h.get("va", "")):
        sys.exit(f"{path}: it needs '// bin: xb|pc|proto' and '// va: 0x........' lines at the top (`packet` writes them).")
    b, va = h["bin"], int(h["va"], 16)
    t = find(b, va)
    if not MV.find_msvc71_bin():
        sys.exit("The 2003 compiler is not installed here (python portal/scripts/setup_msvc71.py, see docs/CONTRIBUTING.md).")
    img = image(b)
    tb = img.read(va, int(t["size"]))
    pick, fixed = selection(t, text, match, flags)
    best = None
    for flags in fixed or flags_for(t, tb):
        r = MV.verify_submission(text, tb, flags, pick, fn_va=va, image=img,
                                 include_dirs=[ROOT / "reconstructed_src" / "include", ROOT / "reconstructed_src"],
                                 known_names=known_names(b))
        r["flags"] = flags
        if best is None or (r.get("ok") and r.get("matched_bytes", 0) > best.get("matched_bytes", -1)):
            best = r
        if r.get("ok") and r.get("is_exact"):
            break
    ok = bool(best.get("ok") and best.get("is_exact") and not best.get("hardcoded_addresses")
              and not best.get("reloc_unverified"))
    return ok, best, t, text


def report(r: dict) -> None:
    if not r.get("ok"):
        print("DID NOT COMPILE\n" + str(r.get("compiler_error") or r.get("error") or "")[:4000])
        return
    print(f"function : {r.get('compiled_sym')} ({r.get('compiled_size')} bytes), flags {r['flags']}")
    print(f"result   : {r['matched_bytes']}/{r['total_bytes']} bytes | addresses checked {r['reloc_checked']}, "
          f"unchecked {r['reloc_unverified']}")
    aligned = r["total_bytes"] - r["matched_bytes"] <= 4 * len(r.get("reloc_mismatch") or [])
    for line in (r.get("notes") or []) + ((r.get("reloc_mismatch") or []) if aligned else []) + \
            ["hard-coded address: " + x for x in r.get("hardcoded_addresses") or []]:
        print("  - " + line)
    wrong = [d for d in r.get("diff_details") or [] if d.get("status") == "diff"]
    for d in wrong[:16]:
        print(f"  +0x{d['idx']:X}: original {d['target']}  yours {d['compiled']}")
    if len(wrong) > 16:
        print(f"  ... and {len(wrong) - 16} more bytes differ")


def cmd_check(args) -> int:
    ok, r, _t, text = check(Path(args.file), args.match, args.flags)
    report(r)
    if ok:
        g = READ.grade(text)
        print("MATCH: byte for byte, every address checked."
              + (f" Still to name: {', '.join(g['stand_ins'][:8])}" if g["left"] else " Nothing left to name."))
        return 0
    if r.get("ok") and r.get("is_exact"):
        print("The bytes match, but it is not accepted yet: an address is hard-coded or could not be checked. "
              "Use sub_XXXXXXXX / DAT_XXXXXXXX names (or a name from reports/names.json) for what it calls and reads.")
    return 1


def cmd_keep(args) -> int:
    path = Path(args.file)
    ok, r, t, text = check(path, args.match, args.flags)
    report(r)
    if not ok:
        print("Not kept: it has to match byte for byte with every address checked.")
        return 1
    h = header(text)
    if len(h.get("what", "")) < 12 or not (h.get("tool") or h.get("spec")):
        print("Not kept yet: fill in '// what:' (one plain sentence on what the function does) and '// tool:' "
              "(what wrote the code, e.g. the model's name) at the top of the file.")
        return 1
    if key_of(t["bin"], t["fva_int"]) in registry():
        print("This function is already matched in the registry. A better version of it is made in the portal.")
        return 1
    TO_SUBMIT.mkdir(parents=True, exist_ok=True)
    dest = TO_SUBMIT / f"{t['bin']}_{t['fva_int']:08X}.cpp"
    import msvc_verify as MV
    if (args.match or args.flags) and not MV.verify_line_options(text):
        # say in the file how it was checked, so submit_matches.py and the portal check it the same way
        line = f"// verify: python portal/verify.py {dest.relative_to(ROOT).as_posix()} --va 0x{t['fva_int']:08X} --bin {t['bin']}"
        line += f" --match '{args.match}'" if args.match else ""
        line += f' --flags "{" ".join(args.flags.split())}"' if args.flags else ""
        dest.write_text(line + "\n" + text, encoding="utf-8")
    else:
        shutil.copyfile(path, dest)
    print(f"Kept: {dest.relative_to(ROOT)}. A person records it with: python portal/scripts/submit_matches.py")
    return 0


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("next", help="functions still open, smallest first")
    p.add_argument("--bin", choices=sorted(BINARIES))
    p.add_argument("--min-size", type=int, default=1)
    p.add_argument("--max-size", type=int, default=10 ** 9)
    p.add_argument("-n", type=int, default=20)
    p.add_argument("--skip", type=int, default=0)
    p.add_argument("--order", choices=("size", "similar"), default="size",
                   help="similar: those most like an already matched function first (portal/tools/similar.py rank)")
    p.add_argument("--who", default="", help="your name: an order of your own near the top of the list, so "
                   "several people's AIs don't all start on the same functions")
    p.set_defaults(fn=cmd_next)
    p = sub.add_parser("describe", help="matched functions with no description yet, to describe (no game files needed)")
    p.add_argument("--bin", choices=sorted(BINARIES), default="xb")
    p.add_argument("-n", type=int, default=15)
    p.add_argument("--min-size", type=int, default=16, help="skip smaller ones (mostly one-line getters)")
    p.add_argument("--who", default="", help="your name: a batch of your own, so people don't overlap")
    p.set_defaults(fn=cmd_describe)
    p = sub.add_parser("describe-keep", help="check a descriptions file and make it ready to send")
    p.add_argument("file")
    p.set_defaults(fn=cmd_describe_keep)
    p = sub.add_parser("packet", help="everything known about one function, and a starter file in work/")
    p.add_argument("bin", choices=sorted(BINARIES))
    p.add_argument("va")
    p.add_argument("--force", action="store_true")
    p.set_defaults(fn=cmd_packet)
    for name, fn, text in (("check", cmd_check, "compile a work file and compare it with the original"),
                           ("keep", cmd_keep, "put an exact match in reports/to_submit/ for a person to record")):
        p = sub.add_parser(name, help=text)
        p.add_argument("file")
        p.add_argument("--match", default="", help="part of the target's compiled symbol (a template "
                       "instantiation, a compiler helper), when the file's own name can't pick it")
        p.add_argument("--flags", default="", help="the function's own flags, fewer of them, or /arch:SSE "
                       "(e.g. a unit built without /EHsc)")
        p.set_defaults(fn=fn)
    args = ap.parse_args(argv)
    return args.fn(args)


if __name__ == "__main__":
    sys.exit(main())
