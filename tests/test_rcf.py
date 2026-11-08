"""tools/rcf.py and scripts/extract_scripts.py, on small archives built in the documented layout."""
import struct

import pytest

from conftest import ROOT

import rcf as R

FILES = [("scriptc\\startup.cso", b"\x01\x00\x00\x00startup"),
         ("scriptc\\ai\\gang.dso", b"\x01\x00\x00\x00" + bytes(range(256)) * 9),
         ("scriptc\\resources.dtr", b"DTR!"),
         ("art\\frontend.p3d", b"P3D\xff" * 100)]


def test_reads_names_sizes_and_data(tmp_path):
    p = tmp_path / "cement.rcf"
    p.write_bytes(R.build_rcf(FILES))
    arc = R.open_rcf(p)
    assert [(e.name, e.size) for e in arc.entries] == [(n, len(d)) for n, d in FILES]
    for e, (_n, d) in zip(arc.entries, FILES):
        assert arc.read(e) == d
    assert [e.name for e in arc.find()] == [n for n, _ in FILES[:3]]
    assert arc.entries[1].parts == ("scriptc", "ai", "gang.dso")


def test_rejects_other_files(tmp_path):
    p = tmp_path / "x.rcf"
    p.write_bytes(b"PK\x03\x04" + b"\0" * 200)
    with pytest.raises(R.RcfError):
        R.open_rcf(p)
    bad = bytearray(R.build_rcf(FILES))
    struct.pack_into("<I", bad, 32 + 24, 10_000_000)           # absurd file count
    p.write_bytes(bytes(bad))
    with pytest.raises(R.RcfError):
        R.open_rcf(p)


def test_unsafe_names_stay_inside_the_output(tmp_path):
    assert R.safe_output_path(tmp_path, "scriptc\\a.cso") == tmp_path / "scriptc" / "a.cso"
    for name in ("..\\..\\evil.cso", "C:\\Windows\\x.cso", "scriptc\\..\\..\\x.cso", ""):
        assert R.safe_output_path(tmp_path, name) is None, name


def test_extract_scripts_cli(tmp_path, capsys):
    import importlib.util
    spec = importlib.util.spec_from_file_location("extract_scripts", ROOT / "scripts" / "extract_scripts.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    p = tmp_path / "cement.rcf"
    p.write_bytes(R.build_rcf(FILES))
    out = tmp_path / "out"
    assert mod.main([str(p), "--out", str(out)]) == 0
    assert (out / "scriptc" / "ai" / "gang.dso").read_bytes() == FILES[1][1]
    assert not (out / "art").exists()                           # only scripts are copied
    assert "3 of them scripts" in capsys.readouterr().out
    assert mod.main([str(tmp_path / "missing.rcf")]) == 1


def tiny_iso(rcf: bytes) -> bytes:
    """A minimal ISO 9660 image holding one file, CEMENT.RCF, enough for find_in_iso."""
    S = 2048
    def rec(name: bytes, lba: int, size: int, flags: int) -> bytes:
        n = 33 + len(name) + (1 - len(name) % 2)
        r = bytearray(n)
        r[0] = n
        struct.pack_into("<I", r, 2, lba); struct.pack_into(">I", r, 6, lba)
        struct.pack_into("<I", r, 10, size); struct.pack_into(">I", r, 14, size)
        r[25] = flags; r[32] = len(name); r[33:33 + len(name)] = name
        return bytes(r)
    root = rec(b"\0", 20, S, 2) + rec(b"\1", 20, S, 2) + rec(b"CEMENT.RCF;1", 21, len(rcf), 0)
    img = bytearray(21 * S)
    pvd = bytearray(S); pvd[0] = 1; pvd[1:6] = b"CD001"; pvd[156:156 + 34] = rec(b"\0", 20, S, 2)
    img[16 * S:17 * S] = pvd
    img[20 * S:20 * S + len(root)] = root
    return bytes(img) + rcf


def test_reads_cement_rcf_inside_a_disc_image(tmp_path):
    p = tmp_path / "game.iso"
    p.write_bytes(tiny_iso(R.build_rcf(FILES)))
    arc = R.open_rcf(p)
    assert [e.name for e in arc.find()] == [n for n, _ in FILES[:3]]
    assert arc.read(arc.entries[1]) == FILES[1][1]
    empty = tmp_path / "other.iso"
    img = bytearray(tiny_iso(b""))
    img[20 * 2048 + 34 * 2 + 33:20 * 2048 + 34 * 2 + 43] = b"OTHER.RCF;"
    empty.write_bytes(bytes(img))
    with pytest.raises(R.RcfError, match="no CEMENT.RCF"):
        R.open_rcf(empty)
