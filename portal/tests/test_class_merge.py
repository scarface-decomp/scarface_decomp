"""
One declaration per class, merged from each matched function's own copy (portal/tools/class_merge.py).

The merge itself only reads text; whether a merged class is right is decided by recompiling every
function with it (portal/scripts/merge_classes.py --verify), which the last test does when the
compiler is there.
"""
import pytest

from conftest import FLAGS, needs_compiler

import class_merge as CM
import msvc_verify as MV

GETTER = """// Foo::vfunc_01
class Foo
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

int Foo::vfunc_01()
{
    return m_Field10;
}
"""

SETTER = """// Foo::vfunc_02
class Foo
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(float a1);
    void sub_00011100(int);
    char m_pad04[0x4];
    float m_speed; // +0x08
    char m_pad0C[0x10];
    unsigned char : 1;
    unsigned char m_Field1C_bit1 : 1; // +0x1C, bit 1
};

void Foo::vfunc_02(float a1)
{
    m_speed = a1;
}
"""

RENAMED = GETTER.replace("m_Field10", "m_count").replace("Foo::vfunc_01\n", "Foo::vfunc_01 again\n")


def copies(*codes_symbols):
    return [CM.parse_class(code, symbol) for code, symbol in codes_symbols]


def test_a_copy_is_read_with_its_offsets():
    d = CM.parse_class(SETTER, "Foo::vfunc_02")
    assert [(m.name, m.off, m.size, m.bit) for m in d.members] == [("m_speed", 8, 4, None), ("m_Field1C_bit1", 0x1C, 1, 1)]
    assert [v.name for v in d.virtuals] == ["vfunc_00", "vfunc_01", "vfunc_02"] and d.own == "vfunc_02"
    assert [f.name for f in d.methods] == ["sub_00011100"] and d.size == 0x1D
    assert SETTER[d.start:d.end].startswith("class Foo") and SETTER[d.start:d.end].endswith("};")


def test_two_copies_become_one_class():
    decls = copies((GETTER, "Foo::vfunc_01"), (SETTER, "Foo::vfunc_02"))
    mg = CM.merge(decls, [])
    assert not mg.conflicts and not mg.notes
    text = CM.render(mg)
    assert "virtual int vfunc_01();" in text and "virtual void vfunc_02(float a1);" in text    # each from its definer
    assert "float m_speed; // +0x08" in text and "int m_Field10; // +0x10" in text
    assert "char m_pad04[0x4];" in text and "char m_pad0C[0x4];" in text and "char m_pad14[0x8];" in text
    assert "unsigned char : 1;" in text and "unsigned char m_Field1C_bit1 : 1;" in text
    again = CM.parse_class(text + "\n", "Foo::vfunc_01")
    assert [(m.name, m.off) for m in again.members] == [(m.name, m.off) for m in mg.members]


def test_a_real_name_wins_and_the_other_copy_is_renamed():
    decls = copies((GETTER, "Foo::vfunc_01"), (RENAMED, "Foo::vfunc_01"))
    mg = CM.merge(decls, [])
    assert not mg.conflicts and "int m_count; // +0x10" in CM.render(mg)
    code = CM.with_class(GETTER, decls[0], mg, 0)
    assert "return m_count;" in code and "m_Field10" not in code and code.startswith("// Foo::vfunc_01\nclass Foo\n{")


def test_copies_that_cannot_both_be_right_are_a_conflict():
    wide = GETTER.replace("int m_Field10;", "short m_Field10;")
    assert any("+0x10" in c for c in CM.merge(copies((GETTER, "Foo::vfunc_01"), (wide, "Foo::vfunc_01")), []).conflicts)
    other = GETTER.replace("virtual int vfunc_01();", "virtual float vfunc_01();").replace("int Foo::", "float Foo::")
    two = CM.merge(copies((GETTER, "Foo::vfunc_01"), (other, "Foo::vfunc_01"), (GETTER, "Foo::vfunc_01")), [])
    assert not two.conflicts and any("slot 1" in n for n in two.notes) and "virtual int vfunc_01();" in CM.render(two)
    overlap = GETTER.replace("char m_pad04[0xC];\n    int m_Field10;", "char m_pad04[0xA];\n    short m_Field0E;\n    int m_Field10;") \
                    .replace("int m_Field10; // +0x10", "int m_Field10;")
    odd = GETTER.replace("char m_pad04[0xC];", "char m_pad04[0x9];\n    char m_pad0D[3];").replace("int m_Field10", "int m_Field10")
    assert not CM.merge(copies((overlap, "Foo::vfunc_01"), (odd, "Foo::vfunc_01")), []).conflicts
    clash = GETTER.replace("char m_pad04[0xC];\n    int m_Field10; // +0x10", "char m_pad04[0xA];\n    char m_Field0E[4];")
    assert any("overlaps" in c for c in CM.merge(copies((GETTER, "Foo::vfunc_01"), (clash, "Foo::vfunc_01")), []).conflicts)


def test_a_differing_type_of_the_same_size_is_a_noted_choice():
    as_ptr = GETTER.replace("int m_Field10;", "char* m_Field10;").replace("return m_Field10;", "return (int)m_Field10;")
    mg = CM.merge(copies((GETTER, "Foo::vfunc_01"), (as_ptr, "Foo::vfunc_01"), (as_ptr, "Foo::vfunc_01")), [])
    assert not mg.conflicts and any("+0x10" in n for n in mg.notes) and "char* m_Field10;" in CM.render(mg)


TEMPLATE = """class Thing;

namespace ns {
template <class T0> class Rep
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};
}

template <> int ns::Rep<Thing>::vfunc_01()
{
    return m_Field08;
}
"""


def test_every_instance_of_a_template_shares_the_template():
    other = TEMPLATE.replace("Thing", "Other").replace("virtual void vfunc_00();", "virtual T0* vfunc_00();") \
                    .replace("char m_pad04[0x4];\n    int m_Field08; // +0x08", "short m_Field04;")
    assert CM.class_key("ns::Rep<Thing>::vfunc_01") == CM.class_key("ns::Rep<a::b<int>, Other*>::vfunc_00") == "ns::Rep"
    decls = copies((TEMPLATE, "ns::Rep<Thing>::vfunc_01"), (other, "ns::Rep<Other>::vfunc_01"))
    assert decls[0].params == ["T0"] and TEMPLATE[decls[0].start:].startswith("template <class T0> class Rep")
    mg = CM.merge(decls, ["ns"])
    text = CM.render(mg)
    assert not mg.conflicts and text.startswith("template <class T0> class Rep\n{")       # T0 is not declared as a class
    assert "virtual T0* vfunc_00();" in text and "short m_Field04; // +0x04" in text and "int m_Field08; // +0x08" in text
    code = CM.with_class(TEMPLATE, decls[0], mg, 0)
    assert code.count("template <class T0>") == 1 and "template <> int ns::Rep<Thing>::vfunc_01()" in code
    with pytest.raises(CM.Unreadable, match="inside a template"):
        CM.split_class("Outer<int>::Inner::f")


@pytest.mark.parametrize("change,why", [
    (lambda c: c.replace("class Foo\n", "class Foo : public Base\n"), "base class"),
    (lambda c: c.replace("int m_Field10;", "Thing m_Field10;"), "member of type Thing"),
    (lambda c: c.replace("class Foo\n", "template <class T> class Foo\n"), "template"),
    (lambda c: c.replace("class Foo\n", "class Bar\n"), "no declaration"),
    (lambda c: c.replace("int m_Field10;", "enum { A } m_Field10;"), "nested"),
])
def test_what_the_parser_does_not_read_is_said_plainly(change, why):
    with pytest.raises(CM.Unreadable, match=why):
        CM.parse_class(change(GETTER), "Foo::vfunc_01")
    with pytest.raises(CM.Unreadable):
        CM.parse_class(GETTER, "ns::Tmpl<int>::vfunc_01")


@needs_compiler
def test_each_function_compiles_to_the_same_code_with_the_merged_class():
    pairs = ((GETTER, "Foo::vfunc_01"), (SETTER, "Foo::vfunc_02"))
    decls = copies(*pairs)
    mg = CM.merge(decls, [])
    for i, (code, symbol) in enumerate(pairs):
        before, after = MV.compile_cpp(code, FLAGS), MV.compile_cpp(CM.with_class(code, decls[i], mg, i), FLAGS)
        assert before.ok and after.ok, after.error
        name = symbol.split("::")[1]
        f0, _ = MV.select_function(MV.CoffObject(before.obj).functions(), name)
        f1, _ = MV.select_function(MV.CoffObject(after.obj).functions(), name)
        assert f0.code == f1.code


def test_the_script_groups_member_functions_by_game_and_class():
    import importlib.util
    from conftest import ROOT
    spec = importlib.util.spec_from_file_location("merge_classes", ROOT / "portal" / "scripts" / "merge_classes.py")
    MC = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(MC)
    entries = {
        "xb:0x00011000": {"bin": "xb", "va": "0x00011000", "symbol": "Foo::vfunc_01", "code": GETTER},
        "xb:0x00011100": {"bin": "xb", "va": "0x00011100", "symbol": "Foo::vfunc_02", "code": SETTER},
        "xb:0x00011200": {"bin": "xb", "va": "0x00011200", "symbol": "Foo::vfunc_03", "code": GETTER.replace("class Foo\n", "class Foo : public B\n")},
        "proto:0x00011000": {"bin": "proto", "va": "0x00011000", "symbol": "Foo::vfunc_01", "code": GETTER},
        "xb:0x00012000": {"bin": "xb", "va": "0x00012000", "symbol": "sub_00012000", "code": "void sub_00012000() {}"},
    }
    g = MC.groups(entries)
    assert sorted(g) == [("proto", "Foo"), ("xb", "Foo")] and len(g[("xb", "Foo")]) == 3
    assert list(MC.groups(entries, "proto")) == [("proto", "Foo")]
    good, bad = MC.read_copies(entries, g[("xb", "Foo")])
    assert [k for k, _d in good] == ["xb:0x00011000", "xb:0x00011100"] and "base class" in bad["xb:0x00011200"]
    assert MC.header_path("xb", "pure3d::d3dContext").name == "pure3d__d3dContext.h"
    text = MC.header_text("xb", "ns::Foo", CM.merge([d for _k, d in good], ["ns"]), [{}, {}])
    assert "namespace ns {" in text and "Proven for 2 functions" in text and text.rstrip().endswith("}")
