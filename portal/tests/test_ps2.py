"""The PS2 lane: the MIPS decoder, finding functions in a PS2 program, its assembly for decomp.me, checking
decomp.me's objects, the work queue and getting SLUS_211.11 off the disc. Everything here runs on small
programs and objects made for the tests; nothing needs the game, the compiler or the network."""
import base64
import json
import shutil
import struct
import subprocess
import zipfile

import pytest

from conftest import PORTAL

import ps2_binary as PB
import ps2_mips as M
import ps2_verify as PV

FIX = json.loads((PORTAL / "tests" / "fixtures" / "ps2_objects.json").read_text(encoding="utf-8"))


def obj(name: str) -> PV.ElfObject:
    return PV.parse_object(base64.b64decode(FIX[name]))


# --------------------------------------------------------------------------- decoder

@pytest.mark.parametrize("word,text", [
    (0x27BDFFD0, "addiu $sp, $sp, -0x30"),
    (0xFFBF0020, "sd $ra, 0x20($sp)"),
    (0x7FB10010, "sq $s1, 0x10($sp)"),
    (0x7BB00000, "lq $s0, 0x0($sp)"),
    (0x0080882D, "daddu $s1, $a0, $zero"),
    (0x03E00008, "jr $ra"),
    (0x00000000, "nop"),
    (0x001010C0, "sll $v0, $s0, 3"),
    (0x2A03001E, "slti $v1, $s0, 0x1E"),
    (0x00851018, "mult $v0, $a0, $a1"),
    (0x0085001A, "div $zero, $a0, $a1"),
    (0x4601001A, "mula.s $f0, $f1"),
    (0x4603101E, "madda.s $f2, $f3"),
    (0x4602081C, "madd.s $f0, $f1, $f2"),
    (0x46000024, "trunc.w.s $f0, $f0"),
    (0x46000004, "sqrt.s $f0, $f0"),
    (0x46020504, ".word 0x46020504"),         # sqrt.s reading $f2: GNU as can't write that, so it stays raw
    (0x44821000, "mtc1 $v0, $f2"),
    (0x70A40389, ".word 0x70A40389"),         # a parallel (MMI) instruction
    (0x3C06007A, "lui $a2, 0x7A"),
])
def test_decodes_to_gnu_syntax(word, text):
    assert M.decode(word, 0x00400000).text() == text


def test_branches_jumps_and_likely():
    b = M.decode(0x1480FFFA, 0x0041542C)                  # bnez $a0, back
    assert (b.kind, b.target) == ("branch", 0x00415418)
    assert b.text(lambda a: f".L{a:08X}") == "bne $a0, $zero, .L00415418"
    j = M.decode(0x0C105514, 0x0041541C)
    assert (j.kind, j.target) == ("call", 0x00415450)
    assert M.decode(0x54620003, 0).likely and not M.decode(0x14620003, 0).likely
    assert M.ends_path(M.decode(0x03E00008, 0)) and M.ends_path(M.decode(0x10000005, 0))
    assert not M.ends_path(M.decode(0x0C105514, 0))


def test_hi_lo_fields():
    lui = M.decode(0x3C06007A, 0)
    assert lui.hi_reg == 6 and lui.imm == 0x7A
    lo = M.decode(0x24C67BF0, 0)                          # addiu $a2, $a2, 0x7BF0
    assert lo.lo_base == 6 and lo.imm == 0x7BF0
    assert lo.text(reloc="%lo(D_007A7BF0)") == "addiu $a2, $a2, %lo(D_007A7BF0)"
    ld = M.decode(0x8C420004, 0)                          # lw $v0, 4($v0)
    assert ld.text(reloc="%lo(D_X)") == "lw $v0, %lo(D_X)($v0)"


# --------------------------------------------------------------------------- a small PS2 program

def asm_words(*words):
    return b"".join(struct.pack("<I", w) for w in words)


CODE_VA, DATA_VA, GP = 0x00100000, 0x00110000, 0x00117FF0
CODE = bytearray(0x100)
CODE[0x00:0x1C] = asm_words(
    0x3C040011,            # lui    $a0, 0x11
    0x24847FF0,            # addiu  $a0, $a0, 0x7FF0
    0x0080E02D,            # daddu  $gp, $a0, $zero
    0x0C040010,            # jal    0x00100040
    0x00000000,
    0x03E00008,            # jr     $ra
    0x00000000)
CODE[0x40:0x54] = asm_words(                       # f2: reads a global (%hi/%lo) and a small one ($gp)
    0x3C020011,            # lui    $v0, %hi(0x00110010)
    0x8C420010,            # lw     $v0, %lo(0x00110010)($v0)
    0x8F838010,            # lw     $v1, -0x7FF0($gp)  -> 0x00110000
    0x03E00008,
    0x00000000)
CODE[0x60:0x68] = asm_words(0x03E00008, 0x00000000)          # f3: only in the data (a vtable)
CODE[0x70:0x8C] = asm_words(                       # f4: nothing points at it; it follows f3
    0x27BDFFF0, 0xFFBF0000, 0x0C040010, 0x00000000, 0xDFBF0000, 0x03E00008, 0x27BD0010)
CODE[0x90:0xA4] = asm_words(                       # f5: a branch-likely: GCC-built library code
    0x14800002, 0x00000000, 0x54800001, 0x00000000, 0x03E00008)
DATA = bytearray(0x40)
DATA[0:4] = struct.pack("<I", CODE_VA + 0x60)
DATA[0x10:0x16] = b"hello\0"


def make_elf(path, code=bytes(CODE), data=bytes(DATA)):
    """A tiny ELF: an executable segment with the code, then a data segment."""
    ph_off, n = 52, 2
    code_off = 0x100
    data_off = code_off + len(code)
    hdr = bytearray(code_off)
    hdr[0:4] = b"\x7fELF"
    hdr[4], hdr[5], hdr[6] = 1, 1, 1
    struct.pack_into("<HHIIIIIHHHHHH", hdr, 16, 2, 8, 1, CODE_VA, ph_off, 0, 0, 52, 32, n, 40, 0, 0)
    struct.pack_into("<8I", hdr, ph_off, 1, code_off, CODE_VA, CODE_VA, len(code), len(code), 7, 0x10)
    struct.pack_into("<8I", hdr, ph_off + 32, 1, data_off, DATA_VA, DATA_VA, len(data), len(data), 6, 0x10)
    path.write_bytes(bytes(hdr) + code + data)
    return path


@pytest.fixture
def img(tmp_path):
    return PB.Ps2Image(make_elf(tmp_path / "SLUS_211.11"))


def test_reads_the_program(img):
    assert (img.entry, img.code_start, img.gp) == (CODE_VA, CODE_VA, GP)
    assert img.read(CODE_VA + 0x40, 4) == struct.pack("<I", 0x3C020011)
    assert img.read(0x00200000, 4) is None and img.in_image(DATA_VA + 0x10)


def test_finds_functions_and_their_sizes(img):
    f = PB.find_functions(img)
    assert {va - CODE_VA: x.size for va, x in f.items()} == {0x00: 0x1C, 0x40: 0x14, 0x60: 8, 0x70: 0x1C, 0x90: 0x18}
    assert f[CODE_VA + 0x40].called and "called" in f[CODE_VA + 0x40].how
    assert "data" in f[CODE_VA + 0x60].how and "after" in f[CODE_VA + 0x70].how
    assert f[CODE_VA + 0x90].library and not f[CODE_VA + 0x40].library


def test_address_fields_strings_and_assembly(img):
    refs = PB.references(img, CODE_VA + 0x40, 0x14)
    assert [(r.offset, r.kind, r.address) for r in refs] == [(0, "hi", 0x00110010), (4, "lo", 0x00110010),
                                                             (8, "gp", 0x00110000)]
    assert PB.strings_used(img, CODE_VA + 0x40, 0x14) == ["hello"]
    asm = PB.function_asm(img, CODE_VA + 0x40, 0x14)
    assert asm.splitlines() == ["glabel func_00100040", "    lui $v0, %hi(D_00110010)",
                                "    lw $v0, %lo(D_00110010)($v0)", "    lw $v1, %gp_rel(D_00110000)($gp)",
                                "    jr $ra", "    nop"]
    assert "    jal func_00100040" in PB.function_asm(img, CODE_VA + 0x70, 0x1C)
    shape_a = PB.signature(img, CODE_VA + 0x60, 8)[0]
    assert shape_a == PB.signature(img, CODE_VA + 0x60, 8)[0] != PB.signature(img, CODE_VA + 0x40, 0x14)[0]
    assert PB.address_named("func_00100040") == CODE_VA + 0x40 and PB.address_named("foo") is None


@pytest.mark.skipif(not shutil.which("mips-linux-gnu-as"), reason="GNU binutils for MIPS not installed")
def test_listing_reassembles_to_the_same_bytes(img, tmp_path):
    """What decomp.me does with the target: assemble it. Symbols are given their addresses at link time."""
    va, size = CODE_VA + 0x40, 0x14
    src = tmp_path / "f.s"
    src.write_text(".set noreorder\n.set noat\n.macro glabel label\n.global \\label\n\\label:\n.endm\n.text\n"
                   + PB.function_asm(img, va, size))
    ld = tmp_path / "f.ld"
    ld.write_text(f"SECTIONS {{ . = 0x{va:X}; .text : {{ *(.text) }} _gp = 0x{GP:X}; "
                  "/DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.gnu.attributes) } }\n"
                  "D_00110010 = 0x00110010; D_00110000 = 0x00110000;\n")
    subprocess.run(["mips-linux-gnu-as", "-EL", "-march=r5900", "-mabi=eabi", "-G0", "-o", str(tmp_path / "f.o"), str(src)], check=True)
    subprocess.run(["mips-linux-gnu-ld", "-EL", "-T", str(ld), "-e", "0", "-o", str(tmp_path / "f.elf"), str(tmp_path / "f.o")], check=True)
    subprocess.run(["mips-linux-gnu-objcopy", "-O", "binary", "-j", ".text", str(tmp_path / "f.elf"), str(tmp_path / "f.bin")], check=True)
    assert (tmp_path / "f.bin").read_bytes()[:size] == img.read(va, size)     # the section is padded after it


# --------------------------------------------------------------------------- checking decomp.me's objects

class FakeImage:
    """Just what the checker reads from the game: memory, $gp, the address range."""
    kind = "ps2"

    def __init__(self, mem, gp=0x0080E170):
        self.mem, self.gp = mem, gp

    def read(self, va, n):
        for base, data in self.mem.items():
            if base <= va and va + n <= base + len(data):
                return data[va - base:va - base + n]
        return None

    def in_image(self, va):
        return 0x00100000 <= va < 0x00900000


def patched(code: bytes, fields) -> bytes:
    """The compiled code with the linker's work done: {offset: (mask, value)}."""
    out = bytearray(code)
    for off, (mask, value) in fields.items():
        w = struct.unpack_from("<I", out, off)[0]
        struct.pack_into("<I", out, off, (w & ~mask & 0xFFFFFFFF) | (value & mask))
    return bytes(out)


def test_object_reader():
    o = obj("str")
    fn = o.functions()[0]
    assert o.name_of(fn) == "func_00397500" and len(fn.data) == 32
    assert [(off, t) for off, t, _ in fn.relocs] == [(4, PV.R_MIPS_HI16), (12, PV.R_MIPS_26), (16, PV.R_MIPS_LO16)]


def test_small_global_matches_and_its_name_is_checked():
    fn = obj("gp").functions()[0]
    target = patched(fn.data, {4: (0xFFFF, (0x00808920 - 0x0080E170) & 0xFFFF)})
    res = PV.compare(target, fn, obj("gp"), 0x00390320, FakeImage({}))
    assert res["is_exact"] and res["reloc_checked"] == 1 and not res["reloc_mismatch"]
    wrong = obj("wrong")
    res = PV.compare(target, wrong.functions()[0], wrong, 0x00390320, FakeImage({}))
    assert not res["is_exact"] and "named for 0x00808924" in res["reloc_mismatch"][0]


def test_a_number_in_place_of_a_name_does_not_count():
    hard = obj("hard")
    fn = hard.functions()[0]
    _fn, res = PV.best_function(fn.data, hard, 0x00390320, FakeImage({}))
    assert res["hardcoded_addresses"] and "0x00808920" in res["hardcoded_addresses"][0]


def test_string_literal_is_compared_with_the_game():
    o = obj("str")
    fn = o.functions()[0]
    va, text_at = 0x00397500, 0x007957E8
    hi = (text_at + 0x8000) >> 16
    target = patched(fn.data, {4: (0xFFFF, hi), 16: (0xFFFF, text_at & 0xFFFF),
                               12: (0x03FFFFFF, 0x00397530 >> 2)})
    good = PV.compare(target, fn, o, va, FakeImage({text_at: b"ABORTED\0"}))
    assert good["is_exact"] and good["reloc_checked"] == 2 and good["reloc_unverified"] == 0
    bad = PV.compare(target, fn, o, va, FakeImage({text_at: b"STOPPED\0"}))
    assert not bad["is_exact"] and "not what the original reads" in bad["reloc_mismatch"][0]
    elsewhere = patched(target, {12: (0x03FFFFFF, 0x00397540 >> 2)})
    res = PV.compare(elsewhere, fn, o, va, FakeImage({text_at: b"ABORTED\0"}))
    assert "named for 0x00397530" in res["reloc_mismatch"][0]


def test_different_code_is_not_a_match():
    o = obj("str")
    fn = o.functions()[0]
    res = PV.compare(bytes(len(fn.data)), fn, o, 0x00397500, FakeImage({}))
    assert not res["is_exact"] and res["matched_bytes"] < len(fn.data)
    short = PV.compare(fn.data[:12], fn, o, 0x00397500, FakeImage({}))
    assert not short["is_exact"] and any("12 bytes" in n for n in short["notes"])


def test_decompme_calls_without_network(monkeypatch):
    seen = []

    def fake(url, body, timeout=90):
        seen.append((url, body))
        if url.endswith("/compile"):
            return 200, {"success": True, "compiler_output": "", "right_object": FIX["gp"]}, ""
        return 201, {"slug": "AbC12", "claim_token": "t"}, ""
    monkeypatch.setattr(PV, "_post_json", fake)
    fields = PV.scratch_fields("x", "glabel f\n jr $ra\n nop\n", "void f() {}", preset="12")
    assert fields["platform"] == "ps2" and fields["compiler"] == PV.COMPILER and fields["preset"] == 12
    made = PV.create_scratch(fields)
    assert made["ok"] and made["slug"] == "AbC12" and made["claim_url"].endswith("/claim?token=t")
    got = PV.compile_on_decompme("AbC12", "void f() {}")
    assert got["ok"] and got["object"][:4] == b"\x7fELF"
    assert seen[1][1]["compiler_flags"] == PV.FLAGS and seen[1][1]["include_objects"] is True

    def down(url, body, timeout=90):
        raise OSError("no network")
    monkeypatch.setattr(PV, "_post_json", down)
    assert PV.compile_on_decompme("AbC12", "x")["unreachable"]


# --------------------------------------------------------------------------- queue and game files

def test_ps2_tasks_in_the_queue(tmp_path):
    import queue_builder as QB
    p = make_elf(tmp_path / "SLUS_211.11")
    tasks = QB.build_queue({"ps2": p}, None, {"ps2:0x00100060"})
    by = {t["fva_int"] - CODE_VA: t for t in tasks}
    assert set(by) == {0x00, 0x40, 0x70}                     # 0x60 verified already, 0x90 is library code
    t = by[0x40]
    assert (t["id"], t["bin"], t["lane"], t["symbol"], t["va"], t["size"]) == (
        "ps2_00100040", "ps2", "PS2 SLUS_211.11", "func_00100040", "PS2 0x00100040", 0x14)
    assert t["flags"] == PV.FLAGS and t["tier"] == "TIER_2_SMALL"


def iso_with(name: str, payload: bytes) -> bytes:
    S = 2048

    def rec(n: bytes, lba: int, size: int, flags: int) -> bytes:
        ln = 33 + len(n) + (1 - len(n) % 2)
        r = bytearray(ln)
        r[0] = ln
        struct.pack_into("<I", r, 2, lba)
        struct.pack_into("<I", r, 10, size)
        r[25], r[32] = flags, len(n)
        r[33:33 + len(n)] = n
        return bytes(r)
    root = rec(b"\0", 20, S, 2) + rec(b"\1", 20, S, 2) + rec(name.encode() + b";1", 21, len(payload), 0)
    img = bytearray(21 * S)
    pvd = bytearray(S)
    pvd[0], pvd[1:6] = 1, b"CD001"
    pvd[156:156 + 34] = rec(b"\0", 20, S, 2)
    img[16 * S:17 * S] = pvd
    img[20 * S:20 * S + len(root)] = root
    return bytes(img) + payload


def test_slus_comes_off_the_ps2_disc(tmp_path, monkeypatch):
    import game_files as GF
    prog = make_elf(tmp_path / "prog")
    want = prog.read_bytes()
    monkeypatch.setitem(GF.EXPECTED, "SLUS_211.11", ((GF.sha256_of(prog),), "PS2, US disc"))
    monkeypatch.setattr(GF, "MIN_DISC_IMAGE", 1)
    bins = tmp_path / "binaries"
    bins.mkdir()
    with zipfile.ZipFile(bins / "Scarface - The World Is Yours (ps2).zip", "w") as z:
        z.writestr("Scarface (USA).iso", iso_with("SLUS_211.11", want))
    log = []
    assert GF.startup(bins, log.append)
    assert (bins / "SLUS_211.11").read_bytes() == want and GF.check(bins / "SLUS_211.11") == "ok"
    assert any("SLUS_211.11" in line for line in log)
    (bins / "SLUS_211.11").unlink()
    loose = tmp_path / "b2"
    loose.mkdir()
    (loose / "Scarface (ps2).iso").write_bytes(iso_with("SLUS_211.11", want))
    assert GF.read_from_iso_file(loose / "Scarface (ps2).iso", "SLUS_211.11") == want
    assert GF.startup(loose, log.append) and (loose / "SLUS_211.11").read_bytes() == want


def test_other_ps2_programs_are_refused(tmp_path):
    import game_files as GF
    p = make_elf(tmp_path / "SLUS_211.11")
    msg = GF.refusal(p)
    assert msg and "PS2, US disc" in msg and "PlayStation 2 program" in msg


# --------------------------------------------------------------------------- the portal's PS2 verify

def test_portal_verifies_a_ps2_function_through_decomp_me(monkeypatch, tmp_path):
    import importlib
    import sys
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    fn = obj("gp").functions()[0]
    target = patched(fn.data, {4: (0xFFFF, (0x00808920 - 0x0080E170) & 0xFFFF)})
    img = FakeImage({0x00390320: target})
    img.is_code = lambda va: False
    img.is_game_code = lambda va: False
    monkeypatch.setattr(server, "image_for", lambda b: img if b == "ps2" else None)
    monkeypatch.setattr(server, "save_overlay", lambda t: None)
    monkeypatch.setattr(PB, "function_asm", lambda *a, **k: "glabel func_00390320\n")
    monkeypatch.setattr(PV, "create_scratch", lambda fields: {"ok": True, "slug": "S1", "url": "u", "claim_url": "u"})
    monkeypatch.setattr(PV, "compile_on_decompme", lambda slug, src, ctx="": {"ok": True, "object": base64.b64decode(FIX["gp"]), "output": ""})
    t = {"id": "ps2_00390320", "bin": "ps2", "fva_int": 0x00390320, "size": 8, "symbol": "func_00390320",
         "va": "PS2 0x00390320", "flags": PV.FLAGS}
    res = server.run_verify(t, 'extern unsigned char D_00808920;\nextern "C" unsigned char func_00390320() { return D_00808920; }\n')
    assert res["ok"] and res["verified"] and res["reloc_checked"] == 1 and t["decompme_slug"] == "S1"
    asm = server.run_verify(t, 'void f() { __asm__("nop"); }')
    assert not asm["ok"] and asm.get("policy_violation")
    monkeypatch.setattr(PV, "compile_on_decompme", lambda slug, src, ctx="": {"ok": False, "unreachable": True, "error": "403"})
    down = server.run_verify(t, "int x;")
    assert not down["ok"] and down["compiler_unavailable"] and "decomp.me" in down["compiler_error"]


# --------------------------------------------------------------------------- code overlays

OV_LOAD = 0x00200000


def make_overlay(name=b"PauseMenu.bin") -> bytes:
    """A CodeWarrior overlay (MWo3) for the little program above: 0x40 bytes of zeros, then a function that
    calls the program's f2 and the overlay's own second function, which reads a string in the overlay."""
    code = bytearray(0x40)
    code += asm_words(
        0x27BDFFF0, 0xFFBF0000,
        0x0C040010, 0x00000000,                          # jal 0x00100040 (the program's f2)
        0x0C080030, 0x00000000,                          # jal 0x002000C0 (below)
        0xDFBF0000, 0x03E00008, 0x27BD0010)
    code = code.ljust(0x80, b"\0")
    code += asm_words(0x3C020020, 0x24420100, 0x03E00008, 0x00000000)   # la $v0, 0x00200100; return
    code = code.ljust(0xC0, b"\0")
    data = b"pause\0".ljust(0x10, b"\0")
    head = b"MWo3" + struct.pack("<7I", 7, OV_LOAD, len(code), len(data), 0, 0, 0) + name.ljust(0x20, b"\0")
    return head + bytes(code) + data


def test_overlay_image_has_its_own_functions_and_the_programs_names(img):
    ov = PB.Ps2Image.with_overlay(img, make_overlay(), "PauseMenuOverlayf.bin")
    funcs = PB.find_functions(ov)
    assert {va: f.size for va, f in funcs.items()} == {OV_LOAD + 0x80: 0x24, OV_LOAD + 0xC0: 0x10}
    assert funcs[OV_LOAD + 0xC0].called and not funcs[OV_LOAD + 0x80].library
    assert ov.is_code(CODE_VA + 0x40) and ov.is_code(OV_LOAD + 0x80) and not ov.is_game_code(CODE_VA + 0x40)
    asm = PB.function_asm(ov, OV_LOAD + 0x80, 0x24)
    assert "jal func_00100040" in asm and "jal func_002000C0" in asm
    assert "%hi(D_00200100)" in PB.function_asm(ov, OV_LOAD + 0xC0, 0x10)
    assert ov.read(OV_LOAD, 4) == b"MWo3" and ov.gp == img.gp
    assert PB.find_functions(img).keys().isdisjoint(funcs)      # the program alone doesn't see them
    with pytest.raises(ValueError):
        PB.Ps2Image.with_overlay(img, b"ELF" + bytes(100))


def test_overlay_functions_get_their_own_lane(tmp_path):
    import queue_builder as QB
    slus = make_elf(tmp_path / "SLUS_211.11")
    ov = tmp_path / "PauseMenuOverlayf.bin"
    ov.write_bytes(make_overlay())
    tasks = QB.build_queue({"ps2": slus, "ps2pause": ov}, None, {f"ps2pause:0x{OV_LOAD + 0xC0:08X}"})
    mine = [t for t in tasks if t["bin"] == "ps2pause"]
    assert [t["fva_int"] for t in mine] == [OV_LOAD + 0x80]     # the other one is verified already
    t = mine[0]
    assert (t["id"], t["lane"], t["flags"]) == (f"ps2pause_{OV_LOAD + 0x80:08X}", "PS2 overlay: pause menu", PV.FLAGS)
    assert "pause menu overlay (PauseMenuOverlayf.bin)" in t["hint"]
    assert any(t["bin"] == "ps2" for t in tasks)                # the program's own are still there
    assert QB.build_queue({"ps2pause": ov}, None, set()) == []  # an overlay means nothing without the program


def test_overlay_copies_are_checked_and_counted_as_the_ps2(tmp_path, monkeypatch):
    import dataclasses
    import ps2_overlay as PO
    import registry_outputs as RO
    p = tmp_path / "PauseMenuOverlayf.bin"
    p.write_bytes(make_overlay())
    assert PO.refusal(p, "ps2pause") and "US PS2 disc" in PO.refusal(p, "ps2pause")
    monkeypatch.setitem(PO.BY_BIN, "ps2pause", dataclasses.replace(PO.BY_BIN["ps2pause"], sha256=PO.sha256_of(p)))
    assert PO.refusal(p, "ps2pause") is None and PO.refusal(tmp_path / "missing.bin", "ps2pause") is None
    assert PO.is_ps2("ps2") and PO.is_ps2("ps2games") and not PO.is_ps2("proto") and not PO.is_ps2(None)
    reg = {"entries": {"ps2:0x00100040": {"bin": "ps2", "size": 20, "va": "0x00100040"},
                       "ps2pause:0x00200080": {"bin": "ps2pause", "size": 36, "va": "0x00200080"},
                       "xb:0x00011000": {"bin": "xb", "size": 8, "va": "0x00011000"}}}
    queue = [{"bin": "ps2modals", "status": "UNCLAIMED"}, {"bin": "ps2", "status": "UNCLAIMED"}]
    s = RO.progress_summary(reg, queue, None)
    assert (s["verified"]["ps2"], s["verified"]["ps2_bytes"], s["verified"]["total"]) == (2, 56, 1)
    assert s["queue"]["ps2"] == 2
    assert "Plus 2 in the PS2 game" in RO.status_block(reg)
    assert RO.BIN_INFO["ps2pause"][0] == "Original_Binary_Order_PS2_PauseMenu.cpp"


def test_portal_reads_an_overlay_with_the_program(tmp_path, monkeypatch):
    import dataclasses
    import importlib
    import sys
    import ps2_overlay as PO
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    slus = make_elf(tmp_path / "SLUS_211.11")
    ov = tmp_path / "PauseMenuOverlayf.bin"
    ov.write_bytes(make_overlay())
    monkeypatch.setitem(PO.BY_BIN, "ps2pause", dataclasses.replace(PO.BY_BIN["ps2pause"], sha256=PO.sha256_of(ov)))
    monkeypatch.setitem(server.BINARIES, "ps2", slus)
    monkeypatch.setitem(server.BINARIES, "ps2pause", ov)
    monkeypatch.setattr(server.GF, "refusal", lambda p: None)
    monkeypatch.setattr(server, "_IMAGES", {})
    img = server.image_for("ps2pause")
    assert img is not None and img.read(OV_LOAD + 0x80, 4) == struct.pack("<I", 0x27BDFFF0)
    t = {"id": "ps2pause_00200080", "bin": "ps2pause", "fva_int": OV_LOAD + 0x80, "size": 0x24, "status": "UNCLAIMED",
         "symbol": "func_00200080", "va": "PS2 0x00200080", "flags": PV.FLAGS, "lane": "PS2 overlay: pause menu"}
    assert not server.in_default_queue(t)
    starter = server.ps2_starter(t)
    assert "pause menu overlay" in starter and 'extern "C" void func_00100040();' in starter
    live = server.live_task(t)
    assert live["disasm_lines"][0].startswith("00200080") and PV.COMPILER in live["compiler_label"]
    assert "pause menu overlay" in live["starter_cpp"]
    assert server.ps2_scratch_fields(t, starter)["target_asm"].startswith("glabel func_00200080")
    monkeypatch.setattr(server, "_IMAGES", {})
    monkeypatch.setitem(server.BINARIES, "ps2", tmp_path / "missing")
    assert server.image_for("ps2pause") is None                 # no program, no overlay
