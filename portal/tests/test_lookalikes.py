"""Look-alikes (portal/tools/lookalikes.py): grouping functions with the same machine code, and rewriting a
matched function's C++ for the others."""
from conftest import FLAGS, ROOT, needs_compiler, needs_xbox
import decompme as DME
import lookalikes as L

R = DME.Reloc


def task(tid, va, symbol, match="", b="xb"):
    return {"id": tid, "bin": b, "fva_int": va, "va": f"0x{va:08X}", "symbol": symbol, "match_substr": match,
            "size": 6, "flags": FLAGS}


def test_names_are_only_paired_when_they_look_alike():
    plain = task("a", 0x1000, "sub_00001000", "sub_00001000")
    vf_a = task("b", 0x2000, "om::MetaType<audio::Mix>::vfunc_02", "vfunc_02@x")
    vf_b = task("c", 0x3000, "om::MetaType<audio::SeqEvent>::vfunc_02", "vfunc_02@y")
    other = task("d", 0x4000, "core::Thing::vfunc_02", "vfunc_02@z")
    assert L.name_pattern(plain) == "plain" and L.name_pattern(vf_a) == "I::I<I::I>::I"
    assert L.name_map(vf_a, vf_b) == {"Mix": "SeqEvent"}
    assert L.name_map(vf_a, other) is None and L.name_map(plain, vf_a) is None
    assert L.name_map(plain, task("e", 0x5000, "sub_00005000", "sub_00005000")) == {}


def test_addresses_must_line_up_one_to_one():
    a, b = task("a", 0x1000, "sub_00001000", "sub_00001000"), task("b", 0x2000, "sub_00002000", "sub_00002000")
    # swaps happen in one pass, so A->B and B->C never turn A into C
    assert L.rewrite("DAT_0000000A DAT_0000000B", {0xA: 0xB, 0xB: 0xC}, {}) == "DAT_0000000B DAT_0000000C"
    ra = [R(1, "_DAT_00400000", 6), R(7, "_DAT_00400000", 6), R(12, ".text", 6, 0x20)]
    rb = [R(1, "_DAT_00500000", 6), R(7, "_DAT_00500000", 6), R(12, ".text", 6, 0x20)]
    assert L.address_map(a, ra, b, rb) == {0x1000: 0x2000, 0x400000: 0x500000}
    two = [R(1, "_DAT_00500000", 6), R(7, "_DAT_00500004", 6), R(12, ".text", 6, 0x20)]
    assert L.address_map(a, ra, b, two) is None                 # one name would stand for two addresses
    moved = [R(1, "_DAT_00500000", 6), R(7, "_DAT_00500000", 6), R(12, ".text", 6, 0x24)]
    assert L.address_map(a, ra, b, moved) is None               # a jump table entry goes somewhere else
    assert L.address_map(a, ra, b, rb[:2]) is None


def test_port_rewrites_once_and_keeps_one_header():
    a = task("xb_00001000", 0x1000, "Foo::vfunc_00", "vfunc_00@Foo@@")
    b = task("xb_00002000", 0x2000, "Bar::vfunc_03", "vfunc_03@Bar@@")
    c = task("xb_00003000", 0x3000, "Baz::vfunc_01", "vfunc_01@Baz@@")
    ra, rb, rc = [R(1, "_DAT_00400000", 6)], [R(1, "_DAT_00500000", 6)], [R(1, "_DAT_00600000", 6)]
    cpp = ('extern "C" char DAT_00400000; // was at 0x00400000\n'
           "struct Foo { virtual void* vfunc_00(); };\n"
           "void* Foo::vfunc_00() { return &DAT_00400000; }  // Foo at 0x00001000\n")
    out = L.port_code(cpp, a, ra, b, rb)
    head, body = out.split("\n", 2)[:2], out.split("\n", 2)[2]
    assert "Foo::vfunc_00 (0x00001000)" in head[0]             # the header says where the code came from
    assert "DAT_00500000" in body and "0x00500000" in body and "00400000" not in body
    assert "0x00002000" in body and "00001000" not in body      # the function's own address too
    assert "struct Bar { virtual void* vfunc_03(); };" in body and "Bar::vfunc_03()" in body and "Foo" not in body
    again = L.port_code(out, b, rb, c, rc)
    assert again.count(L.PORT_HEADER) == 1 and "Bar::vfunc_03 (0x00002000)" in again and "Baz::vfunc_01()" in again
    assert "DAT_00600000" in again and "00500000" not in again


def test_signature_ignores_addresses_but_not_code():
    class Img:                       # just enough of BinaryImage for find_relocations
        image_base = 0x10000

        class S:
            def __init__(self, va, size, code):
                self.va, self.vsize, self.raw_size, self.is_code = va, size, size, code
        sections = [S(0x11000, 0x10000, True), S(0x400000, 0x10000, False)]

        def section_of(self, a):
            return next((s for s in self.sections if s.va <= a < s.va + s.vsize), None)

    img = Img()
    one = bytes.fromhex("B8 00 00 40 00 C3")          # mov eax, offset DAT_00400000 ; ret
    two = bytes.fromhex("B8 10 00 40 00 C3")          # same, another global
    ret = bytes.fromhex("B8 01 00 00 00 C3")          # mov eax, 1 ; ret  (a number, not an address)
    s1, r1 = L.signature(one, 0x11000, img)
    s2, _ = L.signature(two, 0x12000, img)
    s3, _ = L.signature(ret, 0x13000, img)
    assert s1 == s2 != s3 and r1 == [R(1, "_DAT_00400000", 6)]


@needs_xbox
def test_real_groups():
    from sf_binaries import BinaryImage
    img = BinaryImage(ROOT / "binaries" / "default.xbe")
    tasks = [task("xb_001CDC80", 0x001CDC80, "sub_001CDC80", "sub_001CDC80"),
             task("xb_000123B0", 0x000123B0, "CollisionBehaviourTypeGroup::vfunc_00", "vfunc_00@CollisionBehaviourTypeGroup@@"),
             task("xb_000173C0", 0x000173C0, "CollisionSurfaceType::vfunc_00", "vfunc_00@CollisionSurfaceType@@")]
    groups = L.annotate(tasks, {"xb": img})
    # all three are `mov eax, offset DAT; ret`, but only the two class methods are paired
    assert tasks[1]["lookalike_group"] == tasks[2]["lookalike_group"] != ""
    assert tasks[0]["lookalikes"] == 0 and tasks[1]["lookalikes"] == 1 and len(groups) == 1
    assert [t["lookalike_rep"] for t in tasks[1:]] == [True, False]


@needs_compiler
@needs_xbox
def test_a_port_compiles_to_the_look_alike():
    import msvc_verify as MV
    from sf_binaries import BinaryImage
    img = BinaryImage(ROOT / "binaries" / "default.xbe")
    src = task("xb_000123B0", 0x000123B0, "CollisionBehaviourTypeGroup::vfunc_00", "vfunc_00@CollisionBehaviourTypeGroup@@")
    dst = task("xb_000173C0", 0x000173C0, "CollisionSurfaceType::vfunc_00", "vfunc_00@CollisionSurfaceType@@")
    cpp = ('extern "C" char DAT_004191A0;\n'
           "struct CollisionBehaviourTypeGroup { virtual void* vfunc_00(); };\n"
           "void* CollisionBehaviourTypeGroup::vfunc_00() { return &DAT_004191A0; }\n")
    rs = L.signature(img.read(src["fva_int"], 6), src["fva_int"], img)[1]
    rd = L.signature(img.read(dst["fva_int"], 6), dst["fva_int"], img)[1]
    for t, code in ((src, cpp), (dst, L.port_code(cpp, src, rs, dst, rd))):
        res = MV.verify_submission(code, img.read(t["fva_int"], 6), FLAGS, t["match_substr"], fn_va=t["fva_int"], image=img)
        assert res["ok"] and res["is_exact"] and res["reloc_checked"] == 1 and not res["reloc_unverified"], res


def test_code_carried_to_another_virtual_slot_gets_its_class_list_made_again():
    """vfunc_08's code renamed for vfunc_03 left the class listing eight slots, the new name twice. The list is
    made again: a plain entry for each slot before the method's, then the method as it is defined."""
    renamed = ('extern "C" float DAT_003B2314;\n\nclass PedFlee\n{\npublic:\n'
               + "".join(f"    virtual void vfunc_{i:02d}();\n" for i in range(3))
               + "    virtual void vfunc_03();\n    virtual void vfunc_04();\n    virtual float vfunc_03();\n    char m_pad04[0x4];\n};\n\n"
               "// PedFlee::vfunc_03 (0x001095B0, 7 bytes)\nfloat PedFlee::vfunc_03()\n{\n    return DAT_003B2314;\n}\n")
    fixed = L.fit_slot(renamed, "PedFlee", "vfunc_03")
    body = fixed[fixed.index("public:"):fixed.index("};")]
    assert [l.strip() for l in body.splitlines() if "virtual" in l] == [
        "virtual void vfunc_00();", "virtual void vfunc_01();", "virtual void vfunc_02();", "virtual float vfunc_03();"]
    assert "char m_pad04[0x4];" in body and fixed.endswith("return DAT_003B2314;\n}\n")
    assert L.fit_slot(fixed, "PedFlee", "vfunc_03") == fixed                 # one of each already: left alone
    up = L.fit_slot("class A\n{\npublic:\n    virtual void vfunc_00();\n    virtual int vfunc_02(int);\n};\nint A::vfunc_02(int a)\n{\n    return a;\n}\n",
                     "A", "vfunc_02")
    assert "virtual void vfunc_01();\n    virtual int vfunc_02(int a);" in up     # a slot further on: the gap is filled
    assert L.fit_slot("int f() { return 1; }", "A", "vfunc_02") == "int f() { return 1; }"
    assert L.fit_slot(renamed, "PedFlee", "update") == renamed               # a named method: nothing to do
