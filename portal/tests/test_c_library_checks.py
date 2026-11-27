"""What the checker needed for the public C libraries inside the engine (zlib, libpng)."""
import sys
from pathlib import Path
from types import SimpleNamespace

PORTAL = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PORTAL / "tools"))

import msvc_verify as MV  # noqa: E402


def test_the_c_librarys_underscore_names():
    """The compiler puts an underscore in front of every C name, so `_iob` comes out as `__iob`: a name
    from reports/names.json can then be found for it and its address still checked."""
    assert MV.underscore_name("__iob") == "_iob" and MV.underscore_name("__setjmp3") == "_setjmp3"
    assert MV.underscore_name("__ftol2") == "_ftol2" and MV.underscore_name("__CIpow") == "_CIpow"
    for other in ("_png_error", "__real@3727c5ac", "__imp__CloseHandle@4", "?f@@YAXXZ"):
        assert MV.underscore_name(other) is None, other
    assert MV.qualified_name("_png_error") == "png_error" and MV.qualified_name("__iob") is None


def compare(target: bytes, code: bytes):
    fn = MV.ObjFunction("_f", 1, 0, len(code), code, [])
    return MV.compare_function(target, fn, SimpleNamespace(symbols={}, sections=[]))


def test_padding_after_a_function_with_no_return_is_not_the_functions():
    """A function that ends in a call that never comes back has no `ret`; the padding byte after it was
    measured as its last instruction. libpng's png_error and png_chunk_error end this way."""
    body = bytes.fromhex("56 8b 74 24 08 56 5e")                 # ends in `pop esi`, no return
    r = compare(body + b"\xCC", body)
    assert r.is_exact and r.total == len(body) and any("padding" in n for n in r.notes)
    assert not compare(body + b"\x90", body).is_exact            # any other extra byte is a difference
    assert not compare(body + b"\xCC\xCC", body).is_exact        # and only one byte is ever left out
    ends = bytes.fromhex("56 5e c3")
    assert MV.ends_in_return(ends) and MV.ends_in_return(bytes.fromhex("5e c2 08 00")) and not MV.ends_in_return(body)
    assert not compare(ends + b"\xCC", ends).is_exact            # a function with a return is its own size
    assert compare(ends, ends).is_exact


def test_a_global_named_in_the_data_section_can_be_used_by_name():
    sys.path.insert(0, str(PORTAL / "tools"))
    import names as NAMES
    data = {"names": {"xb:0x002C6800": {"name": "png_error", "by": "x", "why": "y"}},
            "data": {"xb:0x00465480": {"name": "_iob", "by": "x", "why": "y"},
                     "pc:0x00465480": {"name": "_iob", "by": "x", "why": "y"},
                     "xb:0x00465490": {"name": "png_error", "by": "x", "why": "a second address"}}}
    assert NAMES.addresses(data, "xb") == {"_iob": 0x465480}              # a name on two addresses is left out
    assert NAMES.addresses({"names": data["names"]}, "xb") == {"png_error": 0x2C6800}
