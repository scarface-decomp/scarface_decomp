"""portal/tools/sevenzip.py: reading .7z files with nothing but Python, checked against 7-Zip's own archives."""
import os
import random
import shutil
import subprocess
import sys
from pathlib import Path

import pytest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import sevenzip  # noqa: E402

SEVEN = shutil.which("7z") or shutil.which("7za")
pytestmark = pytest.mark.skipif(not SEVEN, reason="the 7z program is needed to make the test archives")


@pytest.fixture(scope="module")
def files(tmp_path_factory):
    d = tmp_path_factory.mktemp("src")
    r = random.Random(1983)
    (d / "sub").mkdir()
    out = {
        "disc.iso": bytes(r.getrandbits(8) for _ in range(200_000)) + b"\0" * 1_500_000 + os.urandom(50_000),
        "readme.txt": b"hello\n" * 1000,
        "sub/code.exe": bytes.fromhex("558BEC83EC10E8000000008B45088B4D0C03C15DC3") * 9000,
    }
    for name, data in out.items():
        (d / name).write_bytes(data)
    (d / "empty.txt").write_bytes(b"")
    return d, out


@pytest.mark.parametrize("switches", [
    ["-m0=LZMA2"], ["-m0=LZMA"], ["-mf=BCJ", "-m0=LZMA2"], ["-mx0"], ["-m0=Deflate"], ["-m0=BZip2"],
    ["-ms=off"], ["-mhc=off"], ["-m0=Delta:4", "-m1=LZMA2"],
])
def test_reads_what_7zip_writes(tmp_path, files, switches):
    src, want = files
    arc = tmp_path / "t.7z"
    subprocess.run([SEVEN, "a", "-t7z", *switches, str(arc), *[str(p) for p in src.iterdir()]],
                   check=True, capture_output=True)
    with sevenzip.SevenZip(arc) as z:
        names = dict(z.members())
        assert names["disc.iso"] == len(want["disc.iso"]) and "sub/code.exe" in names
        for name, data in want.items():
            assert z.read(name) == data
        with z.open("disc.iso") as f:                  # streamed in odd-sized pieces
            parts = []
            while True:
                piece = f.read(77_777)
                if not piece:
                    break
                parts.append(piece)
        assert b"".join(parts) == want["disc.iso"]


def test_unusual_compression_is_reported_not_guessed(tmp_path, files):
    src, _want = files
    arc = tmp_path / "ppmd.7z"
    subprocess.run([SEVEN, "a", "-t7z", "-m0=PPMd", str(arc), str(src / "readme.txt")], check=True, capture_output=True)
    with pytest.raises(sevenzip.Unsupported):
        with sevenzip.SevenZip(arc) as z:
            z.read("readme.txt")


def test_not_a_7z(tmp_path):
    (tmp_path / "x.7z").write_bytes(b"PK\3\4 not a 7z")
    with pytest.raises(sevenzip.Unsupported):
        sevenzip.SevenZip(tmp_path / "x.7z")
