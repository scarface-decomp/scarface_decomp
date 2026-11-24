import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import callgraph as C  # noqa: E402

capstone = __import__("pytest").importorskip("capstone")


class FakeImage:
    def __init__(self, mem):
        self.mem = mem

    def read(self, va, n):
        for base, b in self.mem.items():
            if base <= va and va + n <= base + len(b):
                return b[va - base:va - base + n]
        return None


class FakeImg(C.Img):
    def __init__(self, mem):
        self.img = FakeImage(mem)
        self.code = [(0x1000, 0x2000)]
        self.data = self.raw = [(0x5000, 0x6000)]


class FakeRtti:
    def __init__(self):
        self.vtables = {0x5100: ("A", 0, [0x1100, 0x1200, 0x1300]), 0x5200: ("A", 8, [0x1400])}
        self.of_class = {("A", 0): 0x5100, ("A", 8): 0x5200}


def run(code: bytes, cls="A", td_names=None, dyn_cast=None):
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    img = FakeImg({0x1000: code + b"\xc3" * 16, 0x5000: b"\0" * 0x1000})
    return C.analyse(md, img, FakeRtti(), 0x1000, len(code), cls, {0x1000, 0x1100, 0x1200, 0x1300, 0x1400},
                     td_names or {}, dyn_cast)


def test_dynamic_cast_gives_from_and_to():
    # push 0; mov eax, 0x5800 (to); push eax; push 0x5900 (from); push 0; push esi; call 0x1100
    code = bytes.fromhex("6a00" "b800580000" "50" "6800590000" "6a00" "56" "e8eb000000")
    a = run(code, cls=None, td_names={0x5800: "CharacterObject", 0x5900: "ScriptObject"}, dyn_cast=0x1100)
    assert a["casts"] == [("ScriptObject", "CharacterObject")]


def test_own_class_vcall():
    # mov esi, ecx; mov eax, [esi]; call [eax+8]
    a = run(bytes.fromhex("8bf1" "8b06" "ff5008"))
    assert a["virtual"] == [(0x1300, "own")] and a["unresolved"] == 0


def test_base_part_vcall():
    # lea ecx, [ecx+8]; mov eax, [ecx]; call [eax]
    a = run(bytes.fromhex("8d4908" "8b01" "ff10"))
    assert a["virtual"] == [(0x1400, "base")]


def test_constructed_object_vcall_and_unknown_object():
    # mov dword ptr [esi], 0x5100; mov eax, [esi]; call [eax+4]; mov eax, [edi]; call [eax]
    a = run(bytes.fromhex("c70600510000" "8b06" "ff5004" "8b07" "ff10"), cls=None)
    assert a["virtual"] == [(0x1200, "ctor")] and a["unresolved"] == 1


def test_a_call_forgets_this_in_ecx():
    # call 0x1100; mov eax, [ecx]; call [eax]
    a = run(bytes.fromhex("e8fb000000" "8b01" "ff10"))
    assert a["calls"] == [0x1100] and a["unresolved"] == 1


def test_tarjan_leaves_first():
    edges = {1: [2], 2: [3], 3: [2, 4], 4: []}
    assert C.tarjan([1, 2, 3, 4], edges) == [[4], [2, 3], [1]]


def test_plain():
    assert C.plain(".?AVIRefCount@core@@") == "core::IRefCount"
    assert C.plain(".?AVScriptObject@@") == "ScriptObject"


def test_describe_puts_script_commands_first_and_adds_vcalls():
    import agent as A
    e = lambda code, what="": {"code": code, "size": 40, "what": what, "symbol": "s"}  # noqa: E731
    entries = {"xb:0x00011000": e("int f() { return 1; }"), "xb:0x00011100": e("int g() { return 2; }"),
               "xb:0x00012000": e("int h() { return 3; }", "Returns three.")}
    graph = {"functions": {"0x00011100": {"virtual": [["0x00012000", "own"]]}},
             "order": [["0x00011000"], ["0x00011100"]]}
    batch = A.describe_batch(entries, {}, "xb", 10, graph=graph, commands={"xb:0x00011100": "Cmd"})
    assert [k for k, _, _ in batch] == ["xb:0x00011100", "xb:0x00011000"]
    assert batch[0][2] == [("xb:0x00012000", "s", "Returns three.")]
