"""Microsoft cabinet files (portal/tools/ms_cab.py): one cabinet or a set, stored or MSZIP, checked
against the cabextract program when it is installed."""
import io
import os
import random
import shutil
import subprocess

import pytest

import conftest  # noqa: F401  (puts tools/ on the path)
import ms_cab as CAB

R = random.Random(2006)
FILES = [("a.txt", b"hello " * 3000), ("big.rcf", bytes(R.getrandbits(8) for _ in range(90000)) + b"x" * 70000),
         ("empty.txt", b""), ("tail.dll", b"MZ" + b"tail" * 9000)]


def unpack(cabs):
    cs = CAB.CabSet([(io.BytesIO(c), 0, f"Data{i}.cab") for i, c in enumerate(cabs)][::-1])   # any order
    out = {}
    for folder in range(len(cs.pieces)):
        data = b"".join(cs.chunks(folder))
        for f in cs.folder_files(folder):
            out[f.name] = data[f.offset:f.offset + f.size]
    return out


@pytest.mark.parametrize("kind", [0, 1])
@pytest.mark.parametrize("split", [None, (1, 7), (1, 700), (0, 1)])
def test_reads_one_cabinet_or_a_set(kind, split):
    if split and split[0] == 0:
        files = [("first.bin", b"q" * 100_000)] + FILES
    else:
        files = FILES
    cabs = CAB.write_cabinets(files, *(split or (None, 0)), kind=kind)
    assert unpack(cabs) == dict(files)


def test_checksum_is_microsofts():
    assert CAB.checksum(b"") == 0
    assert CAB.checksum(b"\x01\x02\x03\x04") == 0x04030201
    assert CAB.checksum(b"\x01\x02\x03\x04\x05\x06\x07") == 0x04030201 ^ 0x050607
    assert CAB.checksum(b"\xAA", seed=0x100) == 0x1AA


def test_damage_is_found():
    cab = bytearray(CAB.write_cabinets(FILES)[0])
    cab[-100] ^= 0xFF
    with pytest.raises(CAB.CabError, match="checksum"):
        unpack([bytes(cab)])


def test_a_missing_cabinet_is_reported():
    first, second = CAB.write_cabinets(FILES, 1, 700)
    with pytest.raises(CAB.CabError, match="missing"):
        unpack([first])
    with pytest.raises(CAB.CabError, match="not the first"):
        unpack([second])


def test_lzx_is_reported_not_guessed():
    cab = bytearray(CAB.write_cabinets(FILES[:1])[0])
    folder_at = 36 + 8 - 8                          # no prev/next names: the folder entry follows the header
    cab[folder_at + 6] = 3                           # compression: LZX
    cs = CAB.CabSet([(io.BytesIO(bytes(cab)), 0, "x.cab")])
    with pytest.raises(CAB.CabError, match="LZX"):
        list(cs.chunks(0))


@pytest.mark.skipif(not shutil.which("cabextract"), reason="cabextract checks the test cabinets")
@pytest.mark.parametrize("kind", [0, 1])
def test_cabextract_agrees(tmp_path, kind):
    cabs = CAB.write_cabinets(FILES, 1, 700, kind=kind)
    for name, data in zip(("Data1.cab", "Data11.cab"), cabs):
        (tmp_path / name).write_bytes(data)
    for name in ("Data1.cab", "Data11.cab"):
        subprocess.run(["cabextract", "-q", "-d", str(tmp_path / "out"), str(tmp_path / name)], check=True, capture_output=True)
    assert {n: (tmp_path / "out" / n).read_bytes() for n, _ in FILES} == dict(FILES)
