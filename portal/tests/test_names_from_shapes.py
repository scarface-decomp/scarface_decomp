"""Names certain from the matched code's own shape (portal/scripts/names_from_shapes.py)."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scripts"))
import names_from_shapes as N  # noqa: E402


def fn(symbol, body):
    return {"symbol": symbol, "code": f"class X;\n\nint {symbol}(int a1)\n{body}\n"}


def entries():
    out = {}
    # ten ordinary deleting destructors make sub_00027600 the free routine
    for i in range(10):
        out[f"xb:0x0001{i:02X}00"] = fn(f"C{i}::vfunc_01", "{\n    sub_00011111();\n    if (a1 & 1) {\n"
                                        "        sub_00027600((int)this);\n    }\n    return this;\n}")
    out["xb:0x00020000"] = fn("Two::vfunc_01", "{\n    if (a1 & 1) {\n        sub_00027600((int)this);\n    }\n    return this;\n}")
    out["xb:0x00020100"] = fn("Two::vfunc_05", "{\n    if (a1 & 1) {\n        sub_00027600((int)this);\n    }\n    return this;\n}")
    out["xb:0x00020200"] = fn("Odd::vfunc_01", "{\n    if (a1 & 1) {\n        sub_00099999((int)this);\n    }\n    return this;\n}")
    # a class record and its getter; another class's getter returning someone else's record
    out["xb:0x00030000"] = fn("ConcreteClassRep<Car>::vfunc_02",
                              "{\n    sub_00070520(DAT_0041BDE0, DAT_00400020);\n    DAT_00400024 = (int)DAT_0041BDC0;\n}")
    out["xb:0x00030100"] = fn("Car::vfunc_00", "{\n    return DAT_00400000;\n}")
    out["xb:0x00030200"] = fn("Boat::vfunc_00", "{\n    return DAT_00400000;\n}")
    out["xb:0x00030300"] = fn("ConcreteClassRep<Car>::vfunc_01",
                              "{\n    int t2;\n    t2 = sub_000275B0(44, m_Field28);\n    if (t2) {\n"
                              "        return ((Object*)t2)->sub_001FF370(0, m_Field28);\n    }\n    return 0;\n}")
    out["xb:0x00030400"] = fn("Car::vfunc_09",                                   # same shape, not a class record
                              "{\n    int t2;\n    t2 = sub_000275B0(44, m_Field28);\n    if (t2) {\n"
                              "        return ((Object*)t2)->sub_001FF370(0, m_Field28);\n    }\n    return 0;\n}")
    out["xb:0x00030500"] = fn("fight::om::ArrayFixed<float,32>::vfunc_01", "{\n    if (a1 & 1) {\n"
                              "        sub_00027600((int)this);\n    }\n    return this;\n}")
    return out


def test_the_rules():
    found = {k: name for k, (name, _why) in N.find(entries()).items()}
    assert found["xb:0x00010000"] == "C0::~C0"
    assert "xb:0x00020000" not in found and "xb:0x00020100" not in found       # two candidates: not certain
    assert "xb:0x00020200" not in found                                        # a routine not used as a free
    assert found["xb:0x00030100"] == "Car::GetClassRep"
    assert "xb:0x00030200" not in found                                        # Car's record, not Boat's
    assert found["xb:0x00030300"] == "ConcreteClassRep<Car>::Create"
    assert "xb:0x00030400" not in found                                        # Create only in a class record
    assert found["xb:0x00030500"] == "fight::om::ArrayFixed<float,32>::~ArrayFixed"


def test_the_destructor_takes_the_class_name_without_namespace_or_arguments():
    assert N.short("fight::ConditionFactoryTemplate<fight::AndCondition>") == "ConditionFactoryTemplate"
    assert N.short("om::MetaType<audio::ListenerEffectXBox>") == "MetaType" and N.short("Car") == "Car"


def test_a_class_records_set_up_is_its_init():
    found = {k: name for k, (name, _why) in N.find(entries()).items()}
    assert found["xb:0x00030000"] == "ConcreteClassRep<Car>::Init"


class Image:
    """A program image with one class record: its vptr's locator names a type."""
    def __init__(self, records):
        import struct
        self.mem = {}
        for i, (at, type_name) in enumerate(records.items()):
            vt, col, td = 0x00500000 + i * 0x100, 0x00600000 + i * 0x100, 0x00700000 + i * 0x100
            self.mem[at] = struct.pack("<I", vt)
            self.mem[vt - 4] = struct.pack("<I", col)
            self.mem[col + 12] = struct.pack("<I", td)
            self.mem[td + 8] = type_name.encode() + b"\0"

    def read(self, at, n):
        return (self.mem.get(at, b"") + b"\0" * n)[:n]


def test_the_records_own_type_decides_a_getter():
    """With the program file: a getter whose record's type is ConcreteClassRep<its class> is named even when the
    record's set-up isn't matched; one returning another class's record is left alone."""
    es = entries()
    del es["xb:0x00030000"]                                                  # the set-up isn't matched here
    es["xb:0x00030600"] = fn("Boat::vfunc_00", "{\n    return DAT_00400100;\n}")
    img = Image({0x00400000: N.mangled_rep("Car"), 0x00400100: N.mangled_rep("ns::Ship")})
    found = {k: name for k, (name, _why) in N.find(es, {"xb": img}).items()}
    assert found["xb:0x00030100"] == "Car::GetClassRep"                     # its own record, by type
    assert "xb:0x00030200" not in found and "xb:0x00030600" not in found      # Car's and ns::Ship's records
    assert N.mangled_rep("ns::Ship") == ".?AV?$ConcreteClassRep@VShip@ns@@@@"
    assert "xb:0x00030100" not in {k for k in N.find(es)}                    # without the file: not certain
