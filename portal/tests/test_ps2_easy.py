"""The PS2 easy pass: C++ written from the smallest functions' instructions, compiled through decomp.me (the
person's tab), with each compiled object reused and decomp.me used lightly."""
import base64
import importlib
import json
import sys

import pytest

from conftest import PORTAL

import ps2_shapes as PSH

sys.path.insert(0, str(PORTAL))
server = importlib.import_module("decomp_portal_server")

JR_RA = 0x03E00008


# --------------------------------------------------------------------------- C++ from two or three instructions

def test_empty_function_and_member_getters():
    assert PSH.sources((JR_RA, 0)) == ["// Does nothing.\nvoid Nothing()\n{\n}\n"]
    (as_int, as_unsigned) = PSH.sources((JR_RA, 0x8C8200D0))            # lw v0, 0xD0(a0)
    assert "char m_pad00[0xD0];" in as_int and "int m_FieldD0; // +0xD0" in as_int and "return m_FieldD0;" in as_int
    assert "unsigned int Object::Get()" in as_unsigned
    first = PSH.sources((JR_RA, 0x8C820000))[0]                         # lw v0, 0(a0): no padding before it
    assert "m_pad" not in first and "int m_Field0; // +0x0" in first
    assert "float Object::Get()" in PSH.sources((JR_RA, 0xC4800008))[0]    # lwc1 f0, 8(a0)
    assert [("unsigned char" in s, "bool" in s) for s in PSH.sources((JR_RA, 0x90820004))] == [(True, False), (False, True)]
    assert "short Object::Get()" in PSH.sources((JR_RA, 0x84820002))[0]    # lh v0, 2(a0)


def test_setters_constants_and_this():
    assert "void Object::Set(int value)" in PSH.sources((JR_RA, 0xAC850010))[0]       # sw a1, 0x10(a0)
    assert "void Object::Set(float value)" in PSH.sources((JR_RA, 0xE48C0010))[0]     # swc1 f12, 0x10(a0)
    assert "return &m_Field20;" in PSH.sources((JR_RA, 0x24820020))[0]                # addiu v0, a0, 0x20
    assert "return this;" in PSH.sources((JR_RA, 0x0080102D))[0]                      # daddu v0, a0, zero
    assert "return 0;" in PSH.sources((JR_RA, 0x0000102D))[0]
    yes = PSH.sources((JR_RA, 0x24020001))                                            # li v0, 1
    assert "return 1;" in yes[0] and "return true;" in yes[1]
    assert "return -1;" in PSH.sources((JR_RA, 0x2402FFFF))[0]


def test_globals_are_named_for_their_addresses():
    by_gp = PSH.sources((JR_RA, 0x8F828010), gp=0x0080E170)             # lw v0, -0x7FF0(gp)
    assert "extern int D_00806180;" in by_gp[0] and "return D_00806180;" in by_gp[0]
    assert PSH.sources((JR_RA, 0x8F828010)) == []                       # no small-data pointer known: no guess
    as_array, plain = PSH.sources((0x3C020080, JR_RA, 0x8C428920))      # lui v0, 0x80; jr ra; lw v0, -0x76E0(v0)
    assert "extern int D_007F8920[];" in as_array and "return D_007F8920[0];" in as_array
    assert "extern int D_007F8920;" in plain
    assert "extern char D_00800010[];" in PSH.sources((0x3C020080, JR_RA, 0x24420010))[0]


def test_other_code_gets_no_guess():
    assert PSH.sources((JR_RA, 0x8CA20000)) == []                       # lw v0, 0(a1): not a member of its object
    assert PSH.sources((0x27BDFFF0, JR_RA, 0x27BD0010)) == []
    assert PSH.sources((JR_RA, 0, 0, 0)) == []


def test_shape_text_passes_the_source_policy():
    from msvc_verify import check_genuine_cpp
    for words in ((JR_RA, 0), (JR_RA, 0x8C8200D0), (JR_RA, 0xAC850010), (0x3C020080, JR_RA, 0x8C428920)):
        for text in PSH.sources(words, gp=0x0080E170):
            assert check_genuine_cpp(text) == []
    assert check_genuine_cpp(server.PS2_PRELUDE + "int f() { return 1; }\n") == []


# --------------------------------------------------------------------------- compiling through the tab, once per text

class FakeBridge:
    def __init__(self, answer, connected=True):
        self.answer, self.is_connected, self.jobs = answer, connected, []

    def connected(self):
        return self.is_connected

    def wait_connected(self, timeout):
        return self.is_connected

    def run(self, job, timeout=None):
        self.jobs.append(job)
        return dict(self.answer)


@pytest.fixture
def through_tab(monkeypatch):
    monkeypatch.setattr(server.PV, "local_compiler", lambda: None)
    monkeypatch.setitem(server.PS2_DIRECT, "blocked", True)
    monkeypatch.setattr(server, "PS2_OBJECTS", {})

    def use(answer, connected=True):
        b = FakeBridge(answer, connected)
        monkeypatch.setattr(server, "BRIDGE", b)
        return b
    return use


TASK = {"id": "ps2_0037E020", "bin": "ps2", "symbol": "func_0037E020", "va": "PS2 0x0037E020", "fva_int": 0x0037E020,
        "size": 8, "status": "UNCLAIMED", "claimed_by": "", "flags": "-O3 -lang c++ -str readonly"}


def test_the_tab_compiles_and_the_object_is_reused(through_tab):
    b = through_tab({"ok": True, "success": True, "right_object": base64.b64encode(b"\x7fELFobject").decode(), "slug": "abcde"})
    res = server.ps2_compile(dict(TASK), "int f() { return 1; }\r\n", through="abcde")
    assert res["ok"] and res["object"] == b"\x7fELFobject" and res["slug"] == "abcde" and not res.get("cached")
    job = b.jobs[0]
    assert job["slug"] == "abcde" and "create" not in job                    # compiled in the shared scratch
    assert job["compile"]["compiler"] == server.PV.COMPILER and job["compile"]["source_code"] == "int f() { return 1; }"
    again = server.ps2_compile(dict(TASK), "int f() { return 1; }\n", through="abcde")
    assert again["ok"] and again["cached"] and len(b.jobs) == 1               # the same text: decomp.me is not asked again
    other = server.ps2_compile(dict(TASK), "int f() { return 2; }\n", through="abcde")
    assert other["ok"] and len(b.jobs) == 2


def test_compiler_errors_and_a_missing_tab_are_told_apart(through_tab):
    through_tab({"ok": True, "success": False, "compiler_output": "code.c:1: undefined identifier", "slug": "abcde"})
    res = server.ps2_compile(dict(TASK), "int f() { return g; }", through="abcde")
    assert not res["ok"] and "undefined identifier" in res["compiler_error"]
    b = through_tab({"ok": True}, connected=False)
    res = server.ps2_compile(dict(TASK), "int f() { return 3; }", through="abcde")
    assert not res["ok"] and res["unreachable"] and "compiler_error" not in res and b.jobs == []
    through_tab({"ok": False, "error": "your decomp.me tab didn't answer in time"})
    res = server.ps2_compile(dict(TASK), "int f() { return 4; }", through="abcde")
    assert not res["ok"] and res["unreachable"] and "answer in time" in res["error"]


# --------------------------------------------------------------------------- the pass

def key_of(code):
    """The key the pass looks a compiled object up by."""
    return server._ps2_key(*server.DME._inline_project_includes(code, [server.INCLUDE_DIR]))


@pytest.fixture
def pass_env(monkeypatch, tmp_path):
    tasks = [dict(TASK), dict(TASK, id="ps2_0037E030", fva_int=0x0037E030, va="PS2 0x0037E030", symbol="func_0037E030"),
             dict(TASK, id="xb_00011000", bin="xb", fva_int=0x11000)]
    recorded, calls = [], []
    monkeypatch.setattr(server, "ALL_TASKS", tasks)
    monkeypatch.setattr(server, "PS2_EASY_JSON", tmp_path / "ps2_easy_pass.json")
    monkeypatch.setattr(server, "PS2_EASY_PAUSE", 0)
    monkeypatch.setattr(server, "PS2_EASY_WAIT", 0)
    monkeypatch.setattr(server, "BRIDGE", FakeBridge({}, connected=False))
    monkeypatch.setattr(server, "PS2_OBJECTS", {})
    monkeypatch.setattr(server, "ps2_easy_codes", lambda t: ["// first\nint a();\n", "// second\nint b();\n"])
    monkeypatch.setattr(server, "ps2_family", lambda t: "")
    monkeypatch.setattr(server, "_held_by_someone_else", lambda t, user: False)
    monkeypatch.setattr(server, "record_verified", lambda t, code, user, tool, res, **k: recorded.append((t["id"], code, user, tool)))
    for name in ("save_overlay", "save_registry", "append_audit"):
        monkeypatch.setattr(server, name, lambda *a, **k: None)
    monkeypatch.setitem(server.PS2EASY, "stop", False)
    return tasks, recorded, calls


def test_pass_records_matches_and_remembers_what_it_tried(pass_env, monkeypatch):
    tasks, recorded, calls = pass_env

    def verify(t, code, object_b64="", slug="", through=""):
        calls.append((t["id"], code.split("\n")[0], through))
        server.PS2_OBJECTS[key_of(code)] = b"o"          # as a real compile would leave it
        t["decompme_slug"] = "abcde"
        ok = t["id"] == "ps2_0037E020" and "second" in code
        return {"ok": True, "verified": ok, "reloc_unverified": 0}
    monkeypatch.setattr(server, "run_verify_ps2", verify)
    st = server.ps2_easy_pass("Alice")
    assert recorded == [("ps2_0037E020", "// second\nint b();\n", "Alice", server.PS2_EASY_TOOL)]
    assert tasks[0]["status"] == "VERIFIED" and tasks[1]["status"] == "UNCLAIMED" and tasks[2]["status"] == "UNCLAIMED"
    assert st["matched"] == 1 and st["tried"] == 2 and st["compiles"] == 2 and not st["running"]
    assert [c[0] for c in calls] == ["ps2_0037E020", "ps2_0037E020", "ps2_0037E030", "ps2_0037E030"]   # never the Xbox one
    assert calls[0][2] == "" and calls[1][2] == "abcde"                    # the first scratch made serves every later compile
    state = json.loads(server.PS2_EASY_JSON.read_text(encoding="utf-8"))
    assert state["slug"] == "abcde" and state["tried"] == {"ps2:0x0037E030": server.PS2_EASY_VERSION}
    calls.clear()
    st = server.ps2_easy_pass("Alice")                                     # again: nothing left that wasn't tried
    assert calls == [] and st["total"] == 0


def test_pass_stops_when_the_tab_is_gone_and_at_its_cap(pass_env, monkeypatch):
    tasks, recorded, calls = pass_env
    monkeypatch.setattr(server, "run_verify_ps2", lambda t, code, **k: {"ok": False, "compiler_unavailable": True})
    st = server.ps2_easy_pass("Alice")
    assert "decomp.me tab isn't connected" in st["last"] and st["tried"] == 0 and recorded == []
    assert json.loads(server.PS2_EASY_JSON.read_text(encoding="utf-8"))["tried"] == {}     # nothing counted as tried

    def verify(t, code, **k):
        server.PS2_OBJECTS[key_of(code)] = b"o"
        return {"ok": True, "verified": False}
    monkeypatch.setattr(server, "run_verify_ps2", verify)
    monkeypatch.setattr(server, "PS2_EASY_MAX", 1)
    st = server.ps2_easy_pass("Alice")
    assert st["compiles"] == 1 and "light user" in st["last"]
    assert json.loads(server.PS2_EASY_JSON.read_text(encoding="utf-8"))["tried"] == {}     # cut short: tried again next run


def test_pass_will_not_start_without_a_way_to_compile(monkeypatch):
    monkeypatch.setattr(server, "image_for", lambda b: object())
    monkeypatch.setattr(server.PV, "local_compiler", lambda: None)
    monkeypatch.setattr(server, "BRIDGE", FakeBridge({}, connected=False))
    monkeypatch.setitem(server.PS2EASY, "running", False)
    monkeypatch.setattr(server, "PS2_EASY_WAIT", 0)
    res = server.start_ps2_easy_pass("Alice")
    assert not res["ok"] and res["not_connected"] and "bookmark" in res["error"]


def test_the_tab_gets_time_to_check_in():
    b = server.Bridge()
    assert not b.wait_connected(0.05)                       # nobody there
    import threading
    threading.Timer(0.2, lambda: b.next(wait=0.01)).start() # the tab asks for a job a moment later
    assert b.wait_connected(3)


def test_a_pass_goes_on_when_the_tab_comes_back(pass_env, monkeypatch):
    tasks, recorded, calls = pass_env
    back = FakeBridge({}, connected=True)
    monkeypatch.setattr(server, "BRIDGE", back)
    answers = iter([{"ok": False, "compiler_unavailable": True}])

    def verify(t, code, **k):
        server.PS2_OBJECTS[key_of(code)] = b"o"
        return next(answers, {"ok": True, "verified": True, "reloc_unverified": 0})
    monkeypatch.setattr(server, "run_verify_ps2", verify)
    st = server.ps2_easy_pass("Alice")
    assert st["matched"] == 2 and "isn't connected" not in st["last"]


# --------------------------------------------------------------------------- three and four instructions

def test_three_instruction_shapes():
    setter = PSH.sources((0xE48C0010, JR_RA, 0x24020001))              # swc1 f12, 0x10(a0); jr ra; li v0, 1
    assert "bool Object::Set(float value)" in setter[0] and "return true;" in setter[0] and "int Object::Set" in setter[1]
    const = PSH.sources((0x24030001, JR_RA, 0xA0830022))               # li v1, 1; jr ra; sb v1, 0x22(a0)
    assert "m_Field22 = 1;" in const[0] and "char m_Field22" in const[0] and "m_Field22 = true;" in const[1]
    through = PSH.sources((0x8C820008, JR_RA, 0x8C420004))[0]          # lw v0, 8(a0); jr ra; lw v0, 4(v0)
    assert "Inner* m_Field8;" in through and "return m_Field8->m_Field4;" in through
    assert "return m_FieldB0 != 0;" in PSH.sources((0x8C8200B0, JR_RA, 0x0002102B))[0]
    assert "return 0x7FFFFFFF;" in PSH.sources((0x3C027FFF, JR_RA, 0x3442FFFF))[0]
    both = PSH.sources((0xAC800004, JR_RA, 0xAC800000))                # sw zero, 4(a0); jr ra; sw zero, 0(a0)
    assert len(both) == 2 and both[0].index("m_Field4 = 0;") < both[0].index("m_Field0 = 0;")
    assert both[1].index("m_Field0 = 0;") < both[1].index("m_Field4 = 0;")
    assert "return 0.0f;" in PSH.sources((0x44800000, JR_RA, 0))[0]
    assert "D_00808918 = 1;" in PSH.sources((0x24030001, JR_RA, 0xA383A7A8), gp=0x0080E170)[0]
    assert "extern int D_007F8920[];" in PSH.sources((0x3C020080, JR_RA, 0x8C428920))[0]      # the first shapes still win


def test_four_instruction_shapes():
    assert "return 1.0f;" in PSH.sources((0x3C023F80, 0x44820000, JR_RA, 0))[0]              # lui v0, 0x3F80; mtc1 v0, f0
    assert "return 0.5f;" in PSH.sources((0x3C023F00, 0x44820000, JR_RA, 0))[0]
    step = PSH.sources((0x8C830008, 0x24630001, JR_RA, 0xAC830008))[0]                       # lw v1, 8(a0); addiu; jr ra; sw
    assert "m_Field8 += 1;" in step
    assert "m_Field8 -= 1;" in PSH.sources((0x8C830008, 0x2463FFFF, JR_RA, 0xAC830008))[0]
    assert PSH.sources((0x8C830008, 0x24630001, JR_RA, 0xAC83000C)) == []                    # stored somewhere else: no guess


def test_members_are_padded_to_their_places():
    text = PSH._class([(4, "int"), (0, "short")], "void Clear()")
    assert text.index("short m_Field0;") < text.index("char m_pad02[0x2];") < text.index("int m_Field4;")
    assert "m_pad" not in PSH._class([(0, "int"), (4, "float")], "void f()")


# --------------------------------------------------------------------------- functions that end in a jump

def test_tail_call_shapes():
    gp = 0x0080E170
    two = PSH.sources((0x2784ADE0, 0x081B8C40, 0x2785ADE4), 0x003EB610, gp)[0]     # addiu a0, gp; j; addiu a1, gp
    assert 'extern "C" void func_006E3100(int*, int*);' in two and "func_006E3100(&D_00808F50, &D_00808F54);" in two
    moved = PSH.sources((0x0080282D, 0x081477F0, 0x2784AE88), 0x0040BA60, gp)[0]   # move a1, a0; j; addiu a0, gp
    assert "void Forward(void* p0)" in moved and "func_0051DFC0(&D_00808FF8, p0);" in moved
    members = PSH.sources((0x8CA5000C, 0x0818E1A8, 0x8C840004), 0x00644840, gp)[0]  # lw a1, 0xC(a1); j; lw a0, 4(a0)
    assert "void Forward(Arg0* p0, Arg1* p1)" in members and "func_006386A0(p0->m_Field4, p1->m_FieldC);" in members
    chain = PSH.sources((0x8C820000, 0x081B110C, 0x8C440028), 0x00484820, gp)[0]    # lw v0, 0(a0); j; lw a0, 0x28(v0)
    assert "Inner* m_Field0;" in chain and "func_006C4430(p0->m_Field0->m_Field28);" in chain
    far = PSH.sources((0x3C010082, 0x0811FBBC, 0x8C24DFE8), 0x0038EC30, gp)[0]      # lui at; j; lw a0, lo(at)
    assert "extern int D_0081DFE8[];" in far and "func_0047EEF0(D_0081DFE8[0]);" in far
    text = PSH.sources((0x3C040079, 0x0810E1A4, 0x24845890), 0x00398F90, gp)[0]     # lui a0; j; addiu a0, a0, lo
    assert "extern char D_00795890[];" in text and "func_00438690(D_00795890);" in text
    assert PSH.sources((0x2785ADE4, 0x081B8C40, 0), 0x003EB610, gp) == []           # only a1 set: not this shape
    assert PSH.family((0x2784ADE0, 0x081B8C40, 0x2785ADE4)) == "tail call" and PSH.family((JR_RA, 0)) == ""


def test_virtual_forward_shapes():
    own = PSH.sources((0x8C990000, 0x8F3900E4, 0x03200008, 0))                      # lw t9, 0(a0); lw t9, 0xE4(t9); jr t9
    assert "virtual void Method55();" in own[0] and "    Method55();" in own[0] and "Method56" not in own[0]
    assert "    Method57();" in own[1]                                              # the other reading of the table
    member = PSH.sources((0x8C840020, 0x8C990000, 0x8F390028, 0x03200008, 0))
    assert "Inner* m_Field20;" in member[0] and "m_Field20->Method8();" in member[0]
    assert PSH.family((0x8C990000, 0x8F3900E4, 0x03200008, 0)) == "virtual forward"
    assert PSH.sources((0x8C990000, 0x8F3900E6, 0x03200008, 0)) == []               # not a table slot


def test_a_family_on_trial_is_dropped_when_it_never_matches(pass_env, monkeypatch):
    tasks, recorded, calls = pass_env
    more = [dict(TASK, id=f"ps2_{0x00400000 + 16 * i:08X}", fva_int=0x00400000 + 16 * i, symbol=f"func_{0x00400000 + 16 * i:08X}",
                 size=12) for i in range(10)]
    monkeypatch.setattr(server, "ALL_TASKS", more)
    monkeypatch.setattr(server, "ps2_family", lambda t: "tail call")
    monkeypatch.setattr(server, "ps2_easy_codes", lambda t: [f"// {t['id']}\nint a();\n"])

    def verify(t, code, **k):
        calls.append(t["id"])
        server.PS2_OBJECTS[key_of(code)] = b"o"
        return {"ok": True, "verified": False}
    monkeypatch.setattr(server, "run_verify_ps2", verify)
    st = server.ps2_easy_pass("Alice")
    assert len(calls) == server.PS2_FAMILY_TRIES and st["compiles"] == server.PS2_FAMILY_TRIES
    assert "tail call" in st["last"] and "left alone" in st["last"]
    tried = json.loads(server.PS2_EASY_JSON.read_text(encoding="utf-8"))["tried"]
    assert len(tried) == server.PS2_FAMILY_TRIES                # the rest were not touched: tried again when the shape is fixed


# --------------------------------------------------------------------------- probing other optimisation flags

def test_only_optimisation_words_may_be_probed():
    PV = server.PV
    for good in ("-O4,p -lang c++ -str readonly", "-O3 -opt speed -lang c++ -str readonly", "-O2 -lang c -str readonly",
                 "-O3 -inline auto -sdatathreshold 8"):
        assert PV.probe_flags_ok(good), good
    for bad in ("", "-O3 -I /etc", "-O3 -o out.o", "-prefix evil.h", "-O3 -D X=1", "-O3 ; rm", "-O9"):
        assert not PV.probe_flags_ok(bad), bad


class FakeRequest:
    """Enough of the portal's request handler to call one of its POST methods."""
    def __init__(self):
        self.sent = None

    def _auth(self, body):
        return body.get("user")

    def _json(self, data, code=200):
        self.sent = (code, data)


def test_probe_tries_each_build_and_flag_set_and_records_nothing(monkeypatch, tmp_path):
    seen, recorded = [], []
    monkeypatch.setattr(server, "TASK_BY_ID", {"ps2_0037E020": dict(TASK), "xb_00011000": dict(TASK, bin="xb")})
    monkeypatch.setattr(server, "PS2_EASY_JSON", tmp_path / "none.json")
    monkeypatch.setattr(server, "PS2_EASY_PAUSE", 0)
    monkeypatch.setattr(server, "PS2_OBJECTS", {})
    monkeypatch.setattr(server, "record_verified", lambda *a, **k: recorded.append(a))

    def verify(t, code, through="", flags="", compiler="", **k):
        seen.append((compiler, flags))
        if "-O2" in flags:
            return {"ok": False, "compiler_error": "code.c:1: something"}
        exact = "b87" in compiler
        return {"ok": True, "bytes_exact": exact, "verified": exact, "reloc_unverified": 0, "matched_bytes": 12 if exact else 1,
                "total_bytes": 12, "compiled_size": 12 if exact else 32, "compiled_hex": "08 00 E0 03"}
    monkeypatch.setattr(server, "run_verify_ps2", verify)
    lane = "-O3 -lang c++ -str readonly"
    tries = [{"flags": lane}, {"compiler": "mwcps2-3.0.1b87-031208", "flags": lane}, {"flags": "-O2 -lang c++ -str readonly"}]
    r = FakeRequest()
    server.Handler.post_ps2_probe(r, {"user": "Alice", "id": "ps2_0037E020", "cpp_code": "void f() {}\n", "tries": tries})
    code, data = r.sent
    assert code == 200 and data["ok"] and recorded == []
    assert seen == [(server.PV.COMPILER, lane), ("mwcps2-3.0.1b87-031208", lane), (server.PV.COMPILER, "-O2 -lang c++ -str readonly")]
    assert [(x["compiled"], x["exact"], x["verified"]) for x in data["rows"]] == [(True, False, False), (True, True, True), (False, False, False)]
    assert data["rows"][1]["compiler"] == "mwcps2-3.0.1b87-031208" and "something" in data["rows"][2]["error"]

    for body, want in (({"id": "xb_00011000", "cpp_code": "x", "tries": tries}, 404),              # not a PS2 function
                       ({"id": "ps2_0037E020", "cpp_code": "x", "tries": [{"flags": "-O3 -I /etc"}]}, 400),
                       ({"id": "ps2_0037E020", "cpp_code": "x", "tries": [{"compiler": "gcc-evil", "flags": lane}]}, 400),
                       ({"id": "ps2_0037E020", "cpp_code": "x", "tries": [{"flags": lane}] * 13}, 400),
                       ({"id": "ps2_0037E020", "cpp_code": "", "tries": tries}, 400)):
        r = FakeRequest()
        server.Handler.post_ps2_probe(r, dict(body, user="Alice"))
        assert r.sent[0] == want and not r.sent[1]["ok"]


def test_probe_stops_when_the_tab_is_gone(monkeypatch, tmp_path):
    monkeypatch.setattr(server, "TASK_BY_ID", {"ps2_0037E020": dict(TASK)})
    monkeypatch.setattr(server, "PS2_EASY_JSON", tmp_path / "none.json")
    monkeypatch.setattr(server, "run_verify_ps2", lambda *a, **k: {"ok": False, "compiler_unavailable": True})
    r = FakeRequest()
    server.Handler.post_ps2_probe(r, {"user": "Alice", "id": "ps2_0037E020", "cpp_code": "void f() {}",
                                     "tries": [{"flags": "-O3 -lang c++ -str readonly"}]})
    assert not r.sent[1]["ok"] and r.sent[1]["not_connected"] and r.sent[1]["rows"] == []


def test_the_probes_own_lists_are_ones_the_portal_accepts():
    import importlib.util
    spec = importlib.util.spec_from_file_location("ps2_flag_probe", PORTAL / "scripts" / "ps2_flag_probe.py")
    P = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(P)
    assert tuple(P.BUILDS) == server.PV.BUILDS and P.LANE_COMPILER == server.PV.COMPILER and P.LANE_FLAGS == server.PV.FLAGS
    tries = P.default_tries()
    assert len(tries) == 17 and {x["compiler"] for x in tries} == {P.LANE_COMPILER} and tries[0]["flags"] == P.LANE_FLAGS
    every = P.default_tries(all_builds=True)
    assert len(every) == 39 and len({(x["compiler"], x["flags"]) for x in every}) == 39
    assert all(x["compiler"] in server.PV.BUILDS and server.PV.probe_flags_ok(x["flags"]) for x in every)
    assert server.PV.probe_flags_ok("-O3 -opt noschedule") and not server.PV.probe_flags_ok("-O3 -schedule off")
    assert not server.PV.probe_flags_ok("-O3 -o x.o") and not server.PV.probe_flags_ok("-O3 -prefix a.h")
    assert P.CHUNK <= server.PS2_PROBE_MAX
    assert P.words("F0 FF BD 27 08 00 E0 03") == "27BDFFF0 03E00008"


def test_the_probe_repeats_every_hit_at_the_end_and_saves_what_it_printed(tmp_path, capsys):
    import importlib.util
    spec = importlib.util.spec_from_file_location("ps2_flag_probe", PORTAL / "scripts" / "ps2_flag_probe.py")
    P = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(P)
    row = {"compiler": "mwcps2-3.0.1b87-031208", "flags": "-O3 -lang c++ -str readonly", "compiled": True,
           "verified": False, "exact": True, "matched_bytes": 12, "total_bytes": 12, "compiled_size": 12,
           "compiled_hex": "0C 00 8C E4 08 00 E0 03 01 00 02 24", "error": ""}
    miss = dict(row, compiler="mwcps2-3.0.1b103-040528", exact=False, matched_bytes=6)
    broken = dict(row, compiled=False, exact=False, error="### mwccps2.exe Usage Error:\nmore")
    hits = P.show([miss, row, broken])
    assert hits == [("3.0.1b87-031208 -O3 -lang c++ -str readonly", "same bytes, an address unchecked")]
    assert P.show([dict(row, verified=True)])[0][1] == "MATCH"
    lines = P.summary([(0x00392940, *hits[0])])
    assert lines[0] == "Gave the game's bytes:" and "0x00392940  3.0.1b87-031208 -O3" in lines[1]
    assert P.summary([])[0].startswith("Nothing gave the game's bytes")
    assert P.save(tmp_path / "work" / "p.txt")
    saved = (tmp_path / "work" / "p.txt").read_text()
    assert "did not compile: ### mwccps2.exe Usage Error:" in saved and "E48C000C 03E00008 24020001" in saved
    assert saved.splitlines() == capsys.readouterr().out.splitlines()


def test_flags_are_part_of_what_a_compiled_object_is_kept_under(through_tab):
    b = through_tab({"ok": True, "success": True, "right_object": base64.b64encode(b"\x7fELFo").decode(), "slug": "abcde"})
    server.ps2_compile(dict(TASK), "int f() { return 1; }", through="abcde")
    server.ps2_compile(dict(TASK), "int f() { return 1; }", through="abcde", flags="-O4,p -lang c++ -str readonly")
    assert len(b.jobs) == 2                                     # other flags: another compile, not the kept object
    assert b.jobs[0]["compile"]["compiler_flags"] == server.PV.FLAGS
    assert b.jobs[1]["compile"]["compiler_flags"] == "-O4,p -lang c++ -str readonly"
    server.ps2_compile(dict(TASK), "int f() { return 1; }", through="abcde", flags="-O4,p -lang c++ -str readonly")
    assert len(b.jobs) == 2
    server.ps2_compile(dict(TASK), "int f() { return 1; }", through="abcde", compiler="mwcps2-3.0.1b87-031208")
    assert len(b.jobs) == 3 and b.jobs[2]["compile"]["compiler"] == "mwcps2-3.0.1b87-031208"      # another build too


def test_a_lookalike_recorded_without_compiling_carries_its_sources_flags(monkeypatch):
    src = dict(TASK)
    monkeypatch.setattr(server, "REGISTRY", {"entries": {server.task_key(src): {"flags": server.PV.FLAGS_BEFORE}}})
    assert server.recorded_flags(src) == server.PV.FLAGS_BEFORE          # matched before the flags changed
    monkeypatch.setattr(server, "REGISTRY", {"entries": {}})
    assert server.recorded_flags(src) == server.PV.FLAGS


def test_the_lane_compiles_with_exceptions_off():
    assert server.PV.FLAGS == server.PV.FLAGS_BEFORE + " -Cpp_exceptions off" and server.PV.probe_flags_ok(server.PV.FLAGS)
    import queue_builder
    assert queue_builder.PS2_FLAGS == server.PV.FLAGS
    assert server.PS2_EASY_VERSION == 4                  # every open function is tried again with the new flags


def test_the_probes_round_is_one_the_portal_takes():
    import importlib.util
    spec = importlib.util.spec_from_file_location("ps2_flag_probe", PORTAL / "scripts" / "ps2_flag_probe.py")
    P = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(P)
    tries = [x for _, _, _, ts in P.ROUND for x in ts]
    assert len(tries) == 29 and all(x["compiler"] in server.PV.BUILDS and x["flags"] == server.PV.FLAGS for x in tries)
    assert {va for va, _, _, _ in P.ROUND} == {0x003EB610, 0x00392940, 0x0066DFF0}
    for _, what, code, _ in P.ROUND:
        assert not server.check_genuine_cpp(code), what           # a #pragma that sets an optimisation is allowed
    whats = [what for _, what, _, _ in P.ROUND]
    assert len(set(whats)) == len(whats)                              # the closing list tells the cases apart by these
    assert P.pragma("usefloatacc on", "fastmath on") == "#pragma usefloatacc on\n#pragma fastmath on\n\n"
