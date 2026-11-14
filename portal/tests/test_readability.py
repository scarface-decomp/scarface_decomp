"""tools/readability.py: how much of a matched function is left to name."""
import sys

from conftest import PORTAL

sys.path.insert(0, str(PORTAL / "tools"))
import readability as R  # noqa: E402

STARTER = '''// ViceCopHUD::vfunc_02 (0x001B2250, 11 bytes)
// Calls and globals use their real addresses: sub_0BADF00D in a comment is not counted.
struct Object
{
    void sub_001B0920(int);
};
extern "C" int DAT_0045418C;

class ViceCopHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_02();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void ViceCopHUD::vfunc_02()
{
    int t1 = DAT_0045418C;
    ((Object*)(int)this + -104)->sub_001B0920(t1 + m_Field08);
}
'''

FINISHED = '''class HudPanel
{
public:
    void show(int layer);
};
extern "C" int g_currentLayer;

class ViceCopHUD
{
public:
    virtual void update();
    virtual void refresh();
    char m_pad04[0x4];
    HudPanel* m_panel;
};

void ViceCopHUD::refresh()
{
    m_panel->show(g_currentLayer);
}
'''


def test_a_starter_is_matched_and_a_named_function_is_readable():
    g = R.grade(STARTER)
    assert g["grade"] == "matched" and not R.is_readable(STARTER)
    assert set(g["stand_ins"]) == {"sub_001B0920", "DAT_0045418C", "vfunc_00", "vfunc_02", "m_Field08", "Object", "t1"}
    assert "sub_0BADF00D" not in g["stand_ins"]                      # only in a comment
    assert g["raw_addresses"] == 1 and g["left"] == 8                # (Object*)(int)this
    done = R.grade(FINISHED)
    assert done == {"grade": "readable", "stand_ins": [], "raw_addresses": 0, "left": 0} and R.is_readable(FINISHED)
    assert R.grade("")["grade"] == "readable" and R.advice(FINISHED) == ""


def test_padding_and_ordinary_names_are_not_stand_ins():
    code = "struct A { char m_pad04[4]; int field; int vfuncCount; float t; int data_1; };\nint A_get(A* a) { return a->field; }\n"
    assert R.grade(code)["left"] == 0
    assert R.grade("int f(char* p) { return *(int*)(p + 8); }")["raw_addresses"] == 1
    assert R.grade("int f(void* self) { return *(int*)((char*)self + 8); }")["raw_addresses"] == 1


def test_the_advice_says_what_is_left():
    line = R.advice(STARTER, limit=3)
    assert line.startswith("Still to do before it reads as finished C++: 7 stand-in names")
    assert "and 4 more" in line and "1 place that works on a raw address" in line


def test_the_progress_summary_counts_the_readable_ones():
    import registry_outputs as RO
    reg = {"entries": {"xb:0x1": {"bin": "xb", "size": 11, "code": STARTER}, "xb:0x2": {"bin": "xb", "size": 9, "code": FINISHED},
                       "proto:0x3": {"bin": "proto", "size": 9, "code": FINISHED}, "pc:0x4": {"bin": "pc", "size": 5, "code": STARTER}}}
    assert RO.progress_summary(reg, None, None)["readable"] == {"pc": 0, "xb": 1, "proto": 1, "ps2": 0, "total": 1}


def test_a_recorded_name_counts_for_the_function_itself():
    """The code has to keep sub_0011A060 so the portal can find the function. Once reports/names.json names
    that address, the stand-in isn't held against it; every other stand-in still is."""
    code = "void sub_0011A060(int count) { total = count; }"
    assert R.grade(code)["left"] == 1 and R.grade(code, ["sub_0011A060"])["grade"] == "readable"
    assert R.is_readable(code, ["sub_0011A060"]) and not R.is_readable(code)
    assert R.grade("void sub_0011A060() { sub_00011000(); }", ["sub_0011A060"])["stand_ins"] == ["sub_00011000"]
    assert R.own_stand_in("Weapon::vfunc_03") == "vfunc_03" and R.own_stand_in("sub_0011A060") == "sub_0011A060"
    assert R.own_stand_ins("Weapon::vfunc_03", "0x0011A060") == ["vfunc_03", "sub_0011A060"]       # matched before its class was known
    assert R.own_stand_ins("Weapon::vfunc_03", None) == ["vfunc_03"]
    import registry_outputs as RO
    e = {"bin": "xb", "va": "0x0011A060", "symbol": "sub_0011A060", "code": code, "size": "9"}
    assert RO.progress_summary({"entries": {"k": e}}, None, None)["readable"]["xb"] == 0
    assert RO.progress_summary({"entries": {"k": e}}, None, None, {"xb:0x0011A060": {"name": "SetTotal"}})["readable"]["xb"] == 1
