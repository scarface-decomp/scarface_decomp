"""SPEC-013 §3 items 1-4: compile the Xbox game's functions under other compiler switches, per library.

    verified   every verified function of 24 bytes or more (not the compiler-made start-up and shutdown
               stubs): its recorded C++ with its own flags, with /Ob1 added, with /arch:SSE added or
               taken away, and without /EHsc; does it still match?
    failing    every open library function of up to 160 bytes: the starter code's candidates (and the
               same with __cdecl for __stdcall) under the same four flag sets; does any switch make one match?
    gamefloat  open game-code functions of up to 160 bytes with x87 float code but none of the instructions
               that need /arch:SSE: the same test.

Each function is put in a library by its class (the call graph, the registry, reports/names.json): game
code is everything below 0x002331C0. Results go to work/flag_study_<mode>_<part>.jsonl, one function a line;
split the work over processes with PART NPARTS:

    python portal/scripts/flag_study.py verified 0 2 &  python portal/scripts/flag_study.py verified 1 2
"""
import bisect
import json
import random
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal")); sys.path.insert(0, str(ROOT / "portal" / "tools"))
import agent as A  # noqa: E402
import msvc_verify as MV  # noqa: E402

GAME_END = 0x002335F0  # examiner Q38: 0x233340 is still game code
STUBS = (0x00311860, 0x00329430)          # static initializers and atexit stubs: compiler-made, left out
SSE = "/arch:SSE"


def labels():
    """{va: library} from the classes the call graph, the registry and names.json give."""
    reg = json.load(open(ROOT / "reports/verified_registry.json"))["entries"]
    names = json.load(open(ROOT / "reports/names.json"))["names"]
    cg = json.load(open(ROOT / "reports/callgraph_xb.json"))["functions"]
    lab = {}
    for k, v in cg.items():
        if v.get("class"):
            lab[int(k, 16)] = v["class"]
    for k, e in reg.items():
        if k.startswith("xb:") and "::" in (e.get("symbol") or ""):
            lab.setdefault(int(e["va"], 16), e["symbol"].rsplit("::", 1)[0])
    for k, v in names.items():
        if k.startswith("xb:") and "::" in v["name"] and not v["name"].startswith("Script::"):
            lab.setdefault(int(k.split(":")[1], 16), v["name"].rsplit("::", 1)[0])

    def lib(cls):
        top = cls.split("::")[0]
        if top == "pure3d":
            sub = cls.split("::")[1] if "::" in cls else ""
            return "backend" if sub.startswith(("d3d", "pddi")) else "frontend" if sub == "frontend" else "drawing"
        return {"core": "core", "math": "math", "audio": "sound", "movie": "movie", "ravenphysics": "physics",
                "content": "content", "fight": "fight", "om": "om"}.get(top)
    return {va: lib(c) for va, c in lab.items() if lib(c)}


def library_of(va, lab, starts):
    if va < GAME_END:
        return "game"
    if va in lab:
        return lab[va]
    i = bisect.bisect_left(starts, va)
    left = next((lab[starts[j]] for j in range(i - 1, max(i - 40, -1), -1) if starts[j] in lab), None)
    right = next((lab[starts[j]] for j in range(i + 1, min(i + 40, len(starts))) if starts[j] in lab), None)
    return left if left and left == right else None


def variants(flags):
    base = flags
    out = {"default": base, "+/Ob1": base + " /Ob1",
           "SSE toggled": base.replace(" " + SSE, "") if SSE in base else base + " " + SSE}
    if "/EHsc" in base:
        out["-/EHsc"] = base.replace(" /EHsc", "")
    return out


def run_one(code, tb, va, img, flags, names, match=""):
    r = MV.verify_submission(code, tb, flags, match, fn_va=va, image=img,
                             include_dirs=[ROOT / "reconstructed_src" / "include", ROOT / "reconstructed_src"],
                             known_names=names)
    return bool(r.get("ok") and r.get("is_exact") and not r.get("hardcoded_addresses")
                and not r.get("reloc_unverified")), r.get("matched_bytes", 0) if r.get("ok") else -1


def main():
    mode, part, nparts = sys.argv[1], int(sys.argv[2]), int(sys.argv[3])
    limit = int(sys.argv[4]) if len(sys.argv) > 4 else 0
    img = A.image("xb")
    names = A.known_names("xb")
    lab = labels()
    q = json.load(open(ROOT / "reports/full_remaining_queue.json"))
    reg = json.load(open(ROOT / "reports/verified_registry.json"))["entries"]
    starts = sorted({t["fva_int"] for t in q if t["bin"] == "xb"} | {int(e["va"], 16) for k, e in reg.items() if k.startswith("xb:")})
    out = open(ROOT / "work" / f"flag_study_{mode}_{part}.jsonl", "a")
    if mode == "verified":
        rows = [(int(e["va"], 16), e) for k, e in reg.items() if k.startswith("xb:") and int(e.get("size", 0)) >= 24
                and not (STUBS[0] <= int(e["va"], 16) < STUBS[1])]
        by = {}
        for va, e in rows:
            by.setdefault(library_of(va, lab, starts), []).append((va, e))
        random.seed(13)
        pick = []
        for l, rs in sorted(by.items(), key=lambda x: str(x[0])):
            if l is None:
                continue
            rs.sort()
            if limit and len(rs) > limit:
                rs = sorted(random.sample(rs, limit))
            pick += [(l, va, e) for va, e in rs]
        pick = [p for k, p in enumerate(pick) if k % nparts == part]
        for l, va, e in pick:
            tb = img.read(va, int(e["size"]))
            res = {}
            for name, fl in variants(e.get("flags") or "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4").items():
                res[name] = run_one(e["code"], tb, va, img, fl, names, e.get("match") or "")
            out.write(json.dumps({"va": f"0x{va:08X}", "lib": l, "size": int(e["size"]),
                                  "recorded": e.get("flags", ""), "res": res}) + "\n")
            out.flush()
    else:
        from disasm_synth import disassemble, synthesize_all  # noqa: E401
        import decompme as DME
        if mode == "gamefloat":
            from capstone import CS_ARCH_X86, CS_MODE_32, Cs
            md = Cs(CS_ARCH_X86, CS_MODE_32)
            rows = []
            for t in q:
                if t["bin"] != "xb" or t["fva_int"] >= GAME_END or int(t["size"]) > 160:
                    continue
                tb = img.read(t["fva_int"], int(t["size"]))
                if not MV.uses_sse(tb) and any(i.mnemonic.startswith("f") for i in md.disasm(tb, 0)):
                    rows.append(t)
        else:
            rows = [t for t in q if t["bin"] == "xb" and int(t["size"]) <= 160 and t["fva_int"] >= GAME_END
                    and not (STUBS[0] <= t["fva_int"] < STUBS[1])]
        rows = [(library_of(t["fva_int"], lab, starts), t) for t in rows]
        rows = [(lb, t) for lb, t in rows if lb]
        rows = [r for k, r in enumerate(sorted(rows, key=lambda r: r[1]["fva_int"])) if k % nparts == part]
        for l, t in rows:
            va, size = t["fva_int"], int(t["size"])
            tb = img.read(va, size)
            try:
                relocs = DME.find_relocations(tb, va, img)
            except Exception:
                relocs = None
            try:
                cands = synthesize_all(t.get("symbol") or f"sub_{va:08X}", f"0x{va:08X}", tb, disassemble(tb), relocs=relocs)
            except Exception:
                cands = []
            cands = list(dict.fromkeys([c.replace("__stdcall", "__cdecl") for c in cands[:2]] + cands[:2]))
            res = {}
            for name, fl in variants(t.get("flags") or "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4").items():
                best = (False, -1)
                for c in cands:
                    text = f"// bin: xb\n// va: 0x{va:08X}\n\n{c}"
                    r = run_one(text, tb, va, img, fl, names)
                    best = max(best, r)
                    if r[0]:
                        break
                res[name] = best
            out.write(json.dumps({"va": f"0x{va:08X}", "lib": l, "size": size, "res": res}) + "\n")
            out.flush()


if __name__ == "__main__":
    main()
