"""
Microsoft library functions' names from another game's linker map (portal/scripts/names_from_xdk_map.py).
The map and programs here are made up; the real ones are never in the repository.
"""
import importlib.util
import struct

from conftest import ROOT, make_xbe

spec = importlib.util.spec_from_file_location("names_from_xdk_map", ROOT / "portal" / "scripts" / "names_from_xdk_map.py")
XM = importlib.util.module_from_spec(spec)
spec.loader.exec_module(XM)

MAP = """ theirs

 Start         Length     Name                   Class
 0001:00000000 00000100H .text                   CODE

  Address         Publics by Value              Rva+Base     Lib:Object

 0001:00000000       ?Run@Game@@QAEXXZ          00401000 f   game:main.obj
 0001:00000040       _XMemAlloc@8               00401040 f   xapilib:xmem.obj
 0001:00000080       _memset                    00401080 f   LIBCMT:memset.obj
 0001:000000c0       _twice                     004010c0 f   LIBCMT:twice.obj
 0001:00000100       __data_thing               00401100     LIBCMT:data.obj
 0002:00000000       _D3D_Clear@4               00402000 f   d3d8:clear.obj
 0002:00000030       _D3D_Next@0                00402030 f   d3d8:next.obj
"""


def body(seed: int, call_to: int, at: int, data_at: int) -> bytes:
    """A function: fixed bytes, a call (its distance depends on where both are), a data address, a ret."""
    fixed = bytes((seed * 7 + i * 13) % 251 or 1 for i in range(30))
    code = bytearray(b"\x55\x8B\xEC" + fixed)
    code += b"\xE8" + struct.pack("<i", call_to - (at + len(code) + 5))
    code += b"\xA1" + struct.pack("<I", data_at)
    return bytes(code + b"\x5D\xC3")


def programs(tmp_path):
    def text(base, order, data_at):
        blob = bytearray(b"\xCC" * 0x140)
        for slot, seed in order:
            b = body(seed, base + 0x130, base + slot, data_at)
            blob[slot:slot + len(b)] = b
        return bytes(blob)
    # theirs: game code, XMemAlloc, memset, twice. ours: memset first, then XMemAlloc, and "twice" two times
    theirs = make_xbe(tmp_path / "theirs.xbe", [(".text", 0x11000, text(0x11000, [(0x00, 1), (0x40, 2), (0x80, 3), (0xC0, 4)], 0x30000), 6),
                                                ("D3D", 0x20000, body(5, 0x20100, 0x20000, 0x30000) + b"\xCC" * 8, 6),
                                                (".data", 0x30000, bytes(64), 7)])
    ours = make_xbe(tmp_path / "ours.xbe", [(".text", 0x15000, text(0x15000, [(0x00, 3), (0x40, 2), (0x80, 4), (0xC0, 4)], 0x50000), 6),
                                            ("D3D", 0x40000, b"\xCC" * 16 + body(5, 0x40200, 0x40010, 0x50000), 6),
                                            (".data", 0x50000, bytes(64), 7)])
    return theirs.read_bytes(), ours.read_bytes()


def test_linker_symbols_become_ordinary_names():
    assert XM.plain_name("_memcpy") == "memcpy"
    assert XM.plain_name("_XMemAlloc@8") == "XMemAlloc"
    assert XM.plain_name("@fast@4") == "fast"
    assert XM.plain_name("?Set@CompMask@XGRAPHICS@@QAEXH@Z") == "XGRAPHICS::CompMask::Set"
    assert XM.plain_name("??0Foo@NS@@QAE@XZ") == "NS::Foo::Foo"
    assert XM.plain_name("??1Foo@@UAE@XZ") == "Foo::~Foo"
    assert XM.plain_name("??BCompMask@X@@QBEHXZ") is None                     # an operator
    assert XM.plain_name("?f@?$vector@H@std@@QAEXXZ") is None                 # a template
    assert XM.plain_name("__real@3f800000") is None or XM.plain_name("__real@3f800000") == "_real"
    assert XM.plain_name("_sub_00401000") is None                             # a default name says nothing


def test_the_map_is_read_with_each_symbols_library():
    got = XM.parse_map(MAP)
    assert (1, 0x40, "_XMemAlloc@8", "xapilib", True) in got and (2, 0, "_D3D_Clear@4", "d3d8", True) in got
    assert (1, 0x100, "__data_thing", "LIBCMT", False) in got and len(got) == 7


def test_library_functions_are_found_by_their_bytes_whatever_the_addresses(tmp_path):
    theirs, ours = programs(tmp_path)
    found = XM.find(XM.parse_map(MAP), theirs, ours)
    assert found == {0x15040: ("_XMemAlloc@8", "xapilib", 45, ".text"),       # moved, calls and data elsewhere
                     0x15000: ("_memset", "libcmt", 45, ".text"),
                     0x40010: ("_D3D_Clear@4", "d3d8", 45, "D3D")}
    # the game's own function isn't looked for; "twice" is in ours two times, so it names neither; the
    # map's last function has no next one to end at


def test_too_little_to_compare_is_left_alone():
    assert XM.pattern(b"\x55\x8B\xEC" + bytes(10) + b"\xC3", 0x11000, 0x11000, 0x40000) is None      # too short
    starts_with_address = struct.pack("<I", 0x11004)[:3] + bytes(range(1, 40))
    assert XM.pattern(b"\xA1" + struct.pack("<I", 0x30000) + bytes(range(1, 40)), 0x11000, 0x11000, 0x40000) is None
    assert starts_with_address and XM.pattern(bytes(range(1, 60)), 0x11000, 0x11000, 0x40000) is not None


def test_library_functions_among_the_games_code_are_not_queued(tmp_path):
    import queue_builder as QB
    one = bytes.fromhex("55 8B EC 8B 45 08 03 45 0C 5D C3")                                        # two small functions
    two = bytes.fromhex("55 8B EC 8B 45 08 2B 45 0C 5D C3")
    caller = bytes.fromhex("E8") + struct.pack("<i", 0x20 - 5) + bytes.fromhex("E8") + struct.pack("<i", 0x40 - 10) + b"\xC3"
    text = caller + b"\xCC" * (0x20 - len(caller)) + one + b"\xCC" * (0x20 - len(one)) + two + b"\xCC" * 8
    p = make_xbe(tmp_path / "default.xbe", [(".text", 0x11000, text, 6)])
    every = {t["fva_int"] for t in QB.build_queue({"xb": p})}
    assert {0x11020, 0x11040} <= every
    left = {t["fva_int"] for t in QB.build_queue({"xb": p}, library={"xb": ["0x00011040"]})}
    assert left == every - {0x11040}


def test_a_verified_function_keeps_its_matched_size_in_the_queue(tmp_path):
    """A short verified function that ends in a jump to another function: the scanner alone can measure it
    past its end and hide the function after it. With the registry's sizes that function is queued."""
    import queue_builder as QB
    tail = bytes.fromhex("8B 0D 00 20 01 00 E9") + struct.pack("<i", 0x60 - (0x20 + 11))             # mov ecx, [x]; jmp 0x11060
    hidden = bytes.fromhex("55 8B EC 8B 45 08 03 45 0C 5D C3")                                     # reached only through data
    last = bytes.fromhex("55 8B EC 8B 45 08 2B 45 0C 5D C3")
    caller = bytes.fromhex("E8") + struct.pack("<i", 0x20 - 5) + b"\xC3"
    text = (caller + b"\xCC" * (0x20 - len(caller)) + tail + b"\xCC" * (0x10 - len(tail)) + hidden
            + b"\xCC" * (0x30 - len(hidden)) + last + b"\xCC" * 8)
    p = make_xbe(tmp_path / "default.xbe", [(".text", 0x11000, text, 6)])
    extra = {"xb": ["0x00011030"]}
    with_sizes = {t["fva_int"]: t for t in QB.build_queue({"xb": p}, None, {"xb:0x00011020": 11}, extra_starts=extra)}
    assert 0x11030 in with_sizes and with_sizes[0x11030]["size"] == len(hidden) and 0x11020 not in with_sizes
    assert "/EHsc" not in with_sizes[0x11030]["flags"]                                              # no exception frame
