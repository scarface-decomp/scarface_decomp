"""
tools/decompme.py: the target object sent to decomp.me must look exactly like the object MSVC writes
for the same function, relocations included, or a correct guess would not score 100% there.
"""
import base64
import struct

import pytest

from conftest import FLAGS, ROOT, make_xbe, needs_compiler, needs_pc, needs_xbox

import decompme as D
import msvc_verify as MV
from sf_binaries import BinaryImage

FN = 0x11000           # function under test
OTHER = 0x11100        # another function in .text
DATA = 0x30000         # a global in .data


def _code() -> bytes:
    c = bytearray()
    c += bytes.fromhex("A1") + struct.pack("<I", DATA)                       # +0  mov eax, [DATA]
    c += bytes.fromhex("68") + struct.pack("<I", DATA + 8)                   # +5  push DATA+8
    rel = OTHER - (FN + len(c) + 5)
    c += bytes.fromhex("E8") + struct.pack("<i", rel)                        # +10 call OTHER
    c += bytes.fromhex("83 C4 04")                                           # +15 add esp, 4
    c += bytes.fromhex("B8") + struct.pack("<I", FN)                         # +18 mov eax, FN (own address)
    c += bytes.fromhex("83 F9 01 77 0A")                                     # +23 cmp ecx,1 / ja +10
    c += bytes.fromhex("FF 24 8D") + struct.pack("<I", FN + 0x28)            # +28 jmp [ecx*4 + table]
    c += bytes.fromhex("C3")                                                 # +35 ret
    c += bytes.fromhex("8D 49 00 90")                                        # +36 padding to 0x28
    c += struct.pack("<II", FN + 0x23, FN + 0x23)                            # +40 jump table (2 entries)
    return bytes(c)


@pytest.fixture
def image(tmp_path):
    text = bytearray(b"\xCC" * 0x200)
    code = _code()
    text[0:len(code)] = code
    text[0x100] = 0xC3
    p = make_xbe(tmp_path / "t.xbe", [(".text", 0x11000, bytes(text), 0x6), (".data", 0x30000, b"\0" * 16, 0x7)])
    return BinaryImage(p)


def test_relocations_are_found_and_named(image):
    code = _code()
    rel = {r.offset: r for r in D.find_relocations(code, FN, image)}
    assert rel[1] == D.Reloc(1, "_DAT_00030000", D.IMAGE_REL_I386_DIR32)
    assert rel[6] == D.Reloc(6, "_DAT_00030008", D.IMAGE_REL_I386_DIR32)
    assert rel[11] == D.Reloc(11, "_sub_00011100", D.IMAGE_REL_I386_REL32)
    assert rel[19] == D.Reloc(19, D.SELF_SYMBOL, D.IMAGE_REL_I386_DIR32)
    assert rel[31] == D.Reloc(31, ".text", D.IMAGE_REL_I386_DIR32, 0x28)       # the jump table's address
    assert rel[40] == D.Reloc(40, ".text", D.IMAGE_REL_I386_DIR32, 0x23)       # its entries
    assert rel[44] == D.Reloc(44, ".text", D.IMAGE_REL_I386_DIR32, 0x23)
    assert 27 not in rel                                                        # the internal `ja` stays as it is
    assert len(rel) == 7


def test_object_is_a_valid_msvc_style_coff(image):
    code = _code()
    relocs = D.find_relocations(code, FN, image)
    obj = D.build_target_object(code, relocs, "MyClass::LongFunctionName")
    coff = MV.CoffObject(obj)
    (fn,) = coff.functions()
    assert fn.name == "MyClass::LongFunctionName" and fn.size == len(code)
    names = {off: coff.symbols[si].name for off, si, _t in fn.relocs}
    assert names[1] == "_DAT_00030000" and names[11] == "_sub_00011100" and names[19] == fn.name
    assert names[40] == ".text"
    # Fields hold what MSVC leaves there: 0 for symbols, the offset for places inside the function.
    assert struct.unpack_from("<I", fn.code, 1)[0] == 0
    assert struct.unpack_from("<I", fn.code, 40)[0] == 0x23
    # Everything outside the fields is the game's bytes.
    fields = {o + k for o, _s, _t in fn.relocs for k in range(4)}
    assert all(fn.code[i] == code[i] for i in range(len(code)) if i not in fields)


def test_prepare_fills_the_scratch_form(image, tmp_path):
    (tmp_path / "inc").mkdir()
    (tmp_path / "inc" / "engine.h").write_text("#pragma once\nstruct Foo { int a; };\n")
    obj, fields = D.prepare(image, FN, len(_code()), "core::Foo::Bar", FLAGS,
                            '#include "engine.h"\nvoid Foo_Bar() {}\n', [tmp_path / "inc"])
    assert obj[:2] == b"\x4c\x01"
    # /TP: decomp.me compiles as C without it (checked live: `extern "C"` is then a syntax error)
    assert fields["compiler"] == "msvc7.1" and fields["platform"] == "win32" and fields["compiler_flags"] == "/TP " + FLAGS
    assert "struct Foo" in fields["context"] and "#pragma once" not in fields["context"]
    assert '#include "engine.h"' not in fields["source_code"] and "void Foo_Bar()" in fields["source_code"]
    assert "100%" in fields["source_code"]          # the beginner instructions are in the scratch


def test_multipart_body_carries_the_object():
    body, ctype = D._multipart({"compiler": "msvc7.1"}, {"target_obj": ("target.obj", b"\x4c\x01\x00\xff")})
    boundary = ctype.split("boundary=")[1]
    assert body.startswith(f"--{boundary}\r\n".encode()) and body.endswith(f"--{boundary}--\r\n".encode())
    assert b'name="target_obj"; filename="target.obj"' in body and b"\x4c\x01\x00\xff" in body


def test_unreachable_decomp_me_is_a_clear_error():
    res = D.create_scratch(b"\x4c\x01", {"compiler": "msvc7.1"}, base_url="http://127.0.0.1:9", timeout=3)
    assert res["ok"] is False and "Could not reach decomp.me" in res["error"]


def _same_as_msvc(img, va, size, flags, src):
    cr = MV.compile_cpp(src, flags)
    assert cr.ok, cr.error
    compiled = MV.CoffObject(cr.obj).functions()[0]
    msvc = MV.CoffObject(cr.obj)
    want = [(o, t, msvc.symbols[si].name) for o, si, t in compiled.relocs]
    obj, _fields = D.prepare(img, va, size, "", flags, src)
    ours = MV.CoffObject(obj)
    fn = ours.functions()[0]
    got = [(o, t, ours.symbols[si].name) for o, si, t in fn.relocs]
    assert got == want
    assert fn.code == compiled.code


@needs_compiler
@needs_xbox
def test_matches_msvc_xbox_global():
    img = BinaryImage(ROOT / "binaries" / "default.xbe")
    _same_as_msvc(img, 0x0001EF60, 7, FLAGS,
                  'extern "C" const float DAT_00471508; float __cdecl sub_0001EF60(void) { return DAT_00471508; }')


@needs_compiler
@needs_pc
def test_matches_msvc_pc_calls():
    img = BinaryImage(ROOT / "binaries" / "Scarface.exe")
    _same_as_msvc(img, 0x006E6730, 39, FLAGS.replace("/G6", "/G7"), '''
extern "C" void sub_006DCAD0(void);
extern "C" void sub_006DEFA0(int);
struct CementLibrary { char pad[0x20]; int m_State20; void vfunc_05(); };
void CementLibrary::vfunc_05() { while (m_State20 == 0) { sub_006DCAD0(); sub_006DEFA0(0); } }
''')


def test_create_scratch_posts_the_form_and_returns_the_claim_link():
    import json
    import threading
    from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
    seen = {}

    class Fake(BaseHTTPRequestHandler):
        def log_message(self, *a):
            pass

        def do_POST(self):
            seen["path"] = self.path
            seen["ctype"] = self.headers.get("Content-Type", "")
            seen["body"] = self.rfile.read(int(self.headers["Content-Length"]))
            out = json.dumps({"slug": "Ab12x", "claim_token": "tok", "score": 0, "max_score": 200}).encode()
            self.send_response(201)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(out)))
            self.end_headers()
            self.wfile.write(out)

    srv = ThreadingHTTPServer(("127.0.0.1", 0), Fake)
    threading.Thread(target=srv.serve_forever, daemon=True).start()
    try:
        base = f"http://127.0.0.1:{srv.server_address[1]}"
        res = D.create_scratch(b"\x4c\x01obj", D.scratch_fields("n", FLAGS, "void f(){}", ""), base_url=base)
    finally:
        srv.shutdown()
    assert seen["path"] == "/api/scratch" and seen["ctype"].startswith("multipart/form-data; boundary=")
    assert b'name="compiler"\r\n\r\nmsvc7.1\r\n' in seen["body"] and b"\x4c\x01obj" in seen["body"]
    assert res == {"ok": True, "slug": "Ab12x", "url": f"{base}/scratch/Ab12x",
                   "claim_url": f"{base}/scratch/Ab12x/claim?token=tok", "score": 0, "max_score": 200}
