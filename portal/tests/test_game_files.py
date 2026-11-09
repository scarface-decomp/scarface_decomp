"""Getting the game files out of the downloads people actually have (synthetic images, no game data)."""
import hashlib
import struct
import sys
import zipfile
from pathlib import Path

import pytest

PORTAL = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(PORTAL / "tools"))
import game_files as gf  # noqa: E402

XBE = b"XBEH" + bytes(range(256)) * 300          # stand-in for default.xbe
PROTO = b"XBEH" + b"prototype" * 5000            # stand-in for game.xbe
SECTOR = gf.SECTOR


def entry(name, sector, size, attrs=0x20, left=0, right=0):
    raw = struct.pack("<HHIIBB", left, right, sector, size, attrs, len(name)) + name.encode()
    return raw + b"\xff" * (-len(raw) % 4)


def disc_image(base=0, root_sector=40, file_sector=60, pad_to=None, data=XBE, name="default.xbe"):
    """A tiny XDVDFS image: volume descriptor, a root directory with three entries, the file."""
    # a three-entry binary tree: 'default.xbe' at 0, left -> 'audio' dir, right -> 'media'
    first = entry(name, file_sector, len(data))
    left = entry("audio", 90, SECTOR, attrs=0x10)
    right = entry("media", 91, SECTOR, attrs=0x10)
    first = struct.pack("<HH", len(first) // 4, (len(first) + len(left)) // 4) + first[4:]
    table = first + left + right
    size = max(file_sector * SECTOR + len(data), root_sector * SECTOR + len(table), 34 * SECTOR)
    assert root_sector * SECTOR + len(table) <= file_sector * SECTOR or file_sector * SECTOR + len(data) <= root_sector * SECTOR
    img = bytearray(pad_to or (base + size + SECTOR))
    vd = bytearray(SECTOR)
    vd[:20] = gf.XBOX_MAGIC
    struct.pack_into("<II", vd, 20, root_sector, len(table))
    vd[0x7EC:0x7EC + 20] = gf.XBOX_MAGIC
    img[base + 32 * SECTOR:base + 33 * SECTOR] = vd
    img[base + root_sector * SECTOR:base + root_sector * SECTOR + len(table)] = table
    img[base + file_sector * SECTOR:base + file_sector * SECTOR + len(data)] = data
    return bytes(img)


@pytest.fixture(autouse=True)
def small_images(monkeypatch):
    monkeypatch.setattr(gf, "MIN_DISC_IMAGE", 1)
    monkeypatch.setattr(gf, "CHUNK", 64 * 1024)
    monkeypatch.setattr(gf, "XDVDFS_BASES", (0, 0x40000))
    monkeypatch.setattr(gf, "EXPECTED", {
        "default.xbe": ((hashlib.sha256(XBE).hexdigest(),), "Xbox retail game"),
        "Scarface.exe": (("0" * 64,), "PC game, US version 1.00.2"),
        "game.xbe": ((hashlib.sha256(PROTO).hexdigest(),), "Xbox prototype"),
    })


@pytest.mark.parametrize("base", [0, 0x40000])
def test_reads_default_xbe_from_a_loose_disc_image(tmp_path, base):
    iso = tmp_path / "game.iso"
    iso.write_bytes(disc_image(base=base))
    assert gf.read_from_disc_file(iso) == XBE


@pytest.mark.parametrize("kind", ["zip", "7z"])
@pytest.mark.parametrize("layout", [dict(), dict(base=0x40000), dict(root_sector=100, file_sector=50)])
def test_streams_default_xbe_out_of_a_packed_disc_image(tmp_path, kind, layout):
    """Never unpacks the image to disk; a file stored before its directory takes a second pass."""
    img = disc_image(**layout)
    arc = tmp_path / f"Xbox.{kind}"
    if kind == "zip":
        with zipfile.ZipFile(arc, "w", zipfile.ZIP_DEFLATED) as z:
            z.writestr("readme.txt", "hi")
            z.writestr("Game (USA, Europe).iso", img)
    else:
        py7zr = pytest.importorskip("py7zr")
        with py7zr.SevenZipFile(arc, "w") as z:
            z.writestr("hi", "readme.txt")
            z.writestr(img, "Game (USA, Europe).iso")
    logs = []
    assert gf._disc_in_archive(arc, "Game (USA, Europe).iso", len(img), "default.xbe", logs.append) == XBE
    assert not list(tmp_path.glob("*.iso")), "the disc image must not be written out"


def test_stops_reading_once_the_file_is_in_hand(tmp_path):
    img = disc_image(pad_to=8 << 20)
    stream = gf.DiscStream("default.xbe")
    fed = 0
    with pytest.raises(gf._Done):
        for i in range(0, len(img), 65536):
            stream.feed(img[i:i + 65536])
            fed = i
    assert stream.result == XBE and fed < 1 << 20


def test_not_an_xbox_image_gives_up_cleanly(tmp_path):
    iso = tmp_path / "other.iso"
    iso.write_bytes(bytes(200 * SECTOR))
    assert gf.read_from_disc_file(iso) is None
    stream = gf.DiscStream("default.xbe")
    with pytest.raises(gf._Done):
        stream.feed(bytes(200 * SECTOR))
    assert stream.result is None and not stream.missed


def test_prepare_unpacks_the_usual_downloads(tmp_path):
    """The folder a new contributor ends up with: Xbox .7z, prototype .zip, PC .iso, patch .exe."""
    py7zr = pytest.importorskip("py7zr")
    b = tmp_path / "binaries"
    b.mkdir()
    with py7zr.SevenZipFile(b / "Scarface - The World Is Yours (XBOX).7z", "w") as z:
        z.writestr("x", "readme.txt")
        z.writestr(disc_image(base=0x40000), "Scarface - The World Is Yours (USA, Europe).iso")
    with zipfile.ZipFile(b / "Scarface (Apr 20, 2006 prototype).zip", "w") as z:
        z.writestr("Scarface/", "")
        z.writestr("Scarface/art/thing.p3d", b"p3d")
        z.writestr("Scarface/game.xbe", PROTO)
    pc = bytearray(0x9000)
    pc[0x8001:0x8006] = b"CD001"
    (b / "Scarface_Win_EN_ISO-Version.iso").write_bytes(pc)
    (b / "Scarface 1.00.2 US Patch.exe").write_bytes(b"MZ")
    logs = []
    status = gf.prepare(b, logs.append)
    text = "\n".join(logs)
    assert status == {"default.xbe": "ok", "game.xbe": "ok", "Scarface.exe": "missing"}
    assert (b / "default.xbe").read_bytes() == XBE and (b / "game.xbe").read_bytes() == PROTO
    # a stand-in patch with nothing inside it: the portal says to install and patch instead
    assert "couldn't be read out of Scarface 1.00.2 US Patch.exe" in text and "run the patch" in text
    assert not list(b.glob("*.part"))
    # the downloads are left alone, and a second run has nothing to do
    assert len(list(b.iterdir())) == 6
    logs.clear()
    assert gf.prepare(b, logs.append)["default.xbe"] == "ok"
    assert not any("unpacking" in l or "reading" in l for l in logs)


def test_prepare_copies_a_file_from_a_subfolder_and_flags_other_builds(tmp_path):
    b = tmp_path / "binaries"
    (b / "Scarface").mkdir(parents=True)
    (b / "Scarface" / "game.xbe").write_bytes(PROTO)
    (b / "default.xbe").write_bytes(b"XBEH some other region")
    logs = []
    status = gf.prepare(b, logs.append)
    assert status["game.xbe"] == "ok" and status["default.xbe"] == "different"
    assert any("NOT USED" in l for l in logs) and gf.refusal(b / "default.xbe")


def test_prepare_with_nothing_says_what_to_add(tmp_path):
    b = tmp_path / "binaries"
    b.mkdir()
    (b / "README.md").write_text("x")
    logs = []
    status = gf.prepare(b, logs.append)
    assert set(status.values()) == {"missing"}
    assert any("No game files yet" in l for l in logs)


def test_patch_that_cannot_be_read_says_to_install_it(tmp_path, monkeypatch):
    """An unpatched Scarface.exe stays refused next to a patch file the portal can't read; it says what to do."""
    b = tmp_path / "binaries"
    b.mkdir()
    (b / "Scarface.exe").write_bytes(b"MZ unpatched 1.00")
    (b / "Scarface 1.00.2 US Patch-10-1-00-2-US.exe").write_bytes(b"MZ installer")
    assert gf.check(b / "Scarface.exe") == "different"
    msg = gf.refusal(b / "Scarface.exe")
    assert "Scarface 1.00.2 US Patch" in msg and "can't be read directly" in msg and "run it" in msg
    # no Scarface.exe yet, only the patch and the PC disc: the portal says what to do at start
    (b / "Scarface.exe").unlink()
    pc = bytearray(0x9000)
    pc[0x8001:0x8006] = b"CD001"
    (b / "Scarface_Win_EN.iso").write_bytes(pc)
    monkeypatch.setattr(gf, "_installed_pc_exe", lambda: None)
    logs = []
    gf.pc_help(b, logs.append)
    text = "\n".join(logs)
    assert "couldn't be read out of Scarface 1.00.2 US Patch" in text and "Install the game" in text
    assert not (b / "Scarface.exe").exists()


def test_installed_patched_game_is_picked_up(tmp_path, monkeypatch):
    b = tmp_path / "binaries"
    b.mkdir()
    (b / "Scarface 1.00.2 US Patch.exe").write_bytes(b"MZ installer")
    installed = tmp_path / "Program Files" / "Scarface" / "Scarface.exe"
    installed.parent.mkdir(parents=True)
    installed.write_bytes(b"patched")
    monkeypatch.setitem(gf.EXPECTED, "Scarface.exe", ((__import__("hashlib").sha256(b"patched").hexdigest(),), "PC 1.00.2"))
    monkeypatch.setattr(gf, "_installed_pc_exe", lambda: installed)
    gf.pc_help(b, lambda m: None)
    assert (b / "Scarface.exe").read_bytes() == b"patched"


def test_portal_start_unpacks_the_xbox_disc_once_and_is_quiet_after(tmp_path):
    b = tmp_path / "binaries"
    b.mkdir()
    with zipfile.ZipFile(b / "Scarface (Xbox).zip", "w") as z:
        z.writestr("Scarface - The World Is Yours (USA, Europe).iso", disc_image())
    logs = []
    gf.startup(b, logs.append)
    assert (b / "default.xbe").read_bytes() == XBE
    assert logs and "only needed once" in logs[0]
    logs.clear()
    gf.startup(b, logs.append)          # default.xbe is there now; only the optional prototype is missing
    assert logs == []


def test_portal_start_says_nothing_when_there_is_nothing_to_unpack(tmp_path):
    b = tmp_path / "binaries"
    b.mkdir()
    (b / "README.md").write_text("x")
    logs = []
    gf.startup(b, logs.append)
    assert logs == []


def fake_patch(path: Path, exe: bytes) -> Path:
    """A stand-in for the official 1.00.2 patch: a program with a zip of the update inside it."""
    import io
    buf = io.BytesIO()
    with zipfile.ZipFile(buf, "w") as z:
        z.writestr("Patch.txt", "readme")
        z.writestr("Scarface.exe", exe)
    path.write_bytes(b"MZ" + b"\0" * 4000 + buf.getvalue())
    return path


def test_portal_start_takes_scarface_exe_out_of_the_patch(tmp_path, monkeypatch):
    b = tmp_path / "binaries"
    b.mkdir()
    good = b"MZ the 1.00.2 game"
    monkeypatch.setitem(gf.EXPECTED, "Scarface.exe", ((hashlib.sha256(good).hexdigest(),), "PC 1.00.2"))
    monkeypatch.setattr(gf, "_installed_pc_exe", lambda: None)
    fake_patch(b / "scarface_update_en_1001_1002.exe", good)
    (b / "default.xbe").write_bytes(XBE)
    (b / "game.xbe").write_bytes(PROTO)
    logs = []
    assert gf.startup(b, logs.append)
    assert (b / "Scarface.exe").read_bytes() == good
    logs.clear()
    assert not gf.startup(b, logs.append) and logs == []        # done; nothing to say next time


def test_a_wrong_scarface_exe_is_moved_aside_when_the_patch_has_the_right_one(tmp_path, monkeypatch):
    b = tmp_path / "binaries"
    b.mkdir()
    good = b"MZ the 1.00.2 game"
    monkeypatch.setitem(gf.EXPECTED, "Scarface.exe", ((hashlib.sha256(good).hexdigest(),), "PC 1.00.2"))
    monkeypatch.setattr(gf, "_installed_pc_exe", lambda: None)
    (b / "Scarface.exe").write_bytes(b"MZ unpatched 1.00")
    fake_patch(b / "update.exe", good)
    assert "right Scarface.exe inside" in gf.refusal(b / "Scarface.exe")
    gf.startup(b, lambda m: None)
    assert (b / "Scarface.exe").read_bytes() == good
    assert (b / "Scarface.exe.not-used").read_bytes() == b"MZ unpatched 1.00"   # kept, never deleted


def test_xbox_disc_in_a_7z_needs_nothing_installed(tmp_path, monkeypatch):
    """The .7z is read by our own reader: no py7zr, no 7-Zip program."""
    import shutil
    import subprocess
    seven = shutil.which("7z") or shutil.which("7za")
    if not seven:
        pytest.skip("the 7z program is needed to make the test archive")
    b = tmp_path / "binaries"
    b.mkdir()
    (tmp_path / "Scarface - The World Is Yours (USA, Europe).iso").write_bytes(disc_image(base=0x40000))
    subprocess.run([seven, "a", "-t7z", "-m0=LZMA", str(b / "Scarface (USA, Europe).7z"),
                    str(tmp_path / "Scarface - The World Is Yours (USA, Europe).iso")], check=True, capture_output=True)
    monkeypatch.setattr(gf, "_seven_zip_program", lambda: None)
    monkeypatch.setattr(gf, "_py7zr", lambda: (_ for _ in ()).throw(RuntimeError("py7zr must not be needed")))
    gf.startup(b, lambda m: None)
    assert (b / "default.xbe").read_bytes() == XBE
