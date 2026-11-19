"""
Compiling recorded matches again (portal/scripts/recheck_matches.py): what it picks and how it judges one.
The compiler is stood in for here; the real run needs portal/tools/msvc71.
"""
import importlib.util

from conftest import ROOT

spec = importlib.util.spec_from_file_location("recheck_matches", ROOT / "portal" / "scripts" / "recheck_matches.py")
RM = importlib.util.module_from_spec(spec)
spec.loader.exec_module(RM)


class Image:
    def read(self, va, size):
        return bytes(size) if va < 0x1000 else None


def entry(va="0x00000100", size=4, flags="/O2 /G6"):
    return {"bin": "pc", "va": va, "size": size, "flags": flags, "code": "int f(){return 0;}", "match": "f"}


def test_the_pick_is_the_same_for_a_seed_and_skips_other_versions():
    entries = {f"pc:0x{i:08X}": dict(entry(), bin="pc") for i in range(50)}
    entries.update({f"ps2:0x{i:08X}": dict(entry(), bin="ps2") for i in range(5)})
    a = RM.pick(entries, ["pc"], 10, 7)
    assert a == RM.pick(entries, ["pc"], 10, 7) and len(a) == 10 and all(k.startswith("pc:") for k in a)
    assert len(RM.pick(entries, ["pc"], None, 7)) == 50


def test_a_match_is_the_same_only_with_every_byte_and_no_hard_coded_address():
    seen = []

    def verify(code, target, flags, match, **kw):
        seen.append(flags)
        return {"ok": True, "is_exact": flags == "/O2 /G7", "matched_bytes": 4 if flags == "/O2 /G7" else 3,
                "total_bytes": 4, "hardcoded_addresses": []}
    options = lambda b, flags, target: [flags, "/O2 /G7"]
    assert RM.check_one(entry(), Image(), {}, verify, options) == (True, "/O2 /G7")     # the other flags it may need
    assert seen == ["/O2 /G6", "/O2 /G7"]
    near = lambda *a, **k: {"ok": True, "is_exact": False, "matched_bytes": 3, "total_bytes": 4, "hardcoded_addresses": []}
    assert RM.check_one(entry(), Image(), {}, near, lambda *a: []) == (False, "3/4 bytes the same")
    pinned = lambda *a, **k: {"ok": True, "is_exact": True, "matched_bytes": 4, "total_bytes": 4,
                              "hardcoded_addresses": ["0x00419E48"]}
    assert RM.check_one(entry(), Image(), {}, pinned, lambda *a: []) == (False, "hard-coded address: 0x00419E48")
    broken = lambda *a, **k: {"ok": False, "compiler_error": "t.cpp(1): error C2065: 'x' : undeclared"}
    assert RM.check_one(entry(), Image(), {}, broken, lambda *a: [])[1].startswith("does not compile: t.cpp(1)")
    assert RM.check_one(entry(va="0x00002000"), Image(), {}, verify, options) == (
        False, "the game's bytes at that address could not be read")
