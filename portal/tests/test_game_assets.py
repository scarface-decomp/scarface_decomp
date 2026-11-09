"""Copying the game's own files out (portal/tools/game_assets.py), with tiny made-up games: an Xbox
disc (XDVDFS), a PS2 disc (ISO 9660), the prototype's .zip and an installed PC folder. No game data."""
import shutil
import struct
import subprocess
import zipfile
from pathlib import Path

import pytest

import conftest  # noqa: F401  (puts tools/ on the path)
import game_assets as GA
import game_files as GF
from rcf import build_rcf

SECTOR = 2048
SOUND = b"RSD6RADP" + struct.pack("<3I", 1, 16, 24000) + bytes(range(256)) * 8       # Xbox and prototype
SOUND_PS2 = b"RSD4VAG " + struct.pack("<3I", 1, 16, 22050) + bytes(range(255, -1, -1)) * 8   # the PS2's form
CAR = b"P3D\xff" + b"retail car" * 300                     # the same on Xbox and PC
CAR_PROTO = b"P3D\xff" + b"prototype car" * 200
MOVIE = b"BIKi" + b"frames" * 900                          # Xbox: media/, prototype: art/movies/


# --------------------------------------------------------------------------- made-up discs

def _xentry(name, sector, size, attrs, right):
    raw = struct.pack("<HHIIBB", 0, right, sector, size, attrs, len(name)) + name.encode()
    return raw + b"\xff" * (-len(raw) % 4)


def _xtable(entries):
    """An XDVDFS directory table: the entries chained through their right links."""
    out = b""
    for i, (name, sector, size, attrs) in enumerate(entries):
        e = _xentry(name, sector, size, attrs, 0)
        if i + 1 < len(entries):
            e = _xentry(name, sector, size, attrs, (len(out) + len(e)) // 4)
        out += e
    return out


def xbox_disc(early_table=False, extra=()):
    """Root: default.xbe, cement.rcf, media/ (intro.bik and the same data again as copy.bik)."""
    rcf = build_rcf([("art\\sound\\hello.rsd", SOUND), ("art\\models\\car.p3d", CAR),
                     ("scriptc\\main.cso", b"\x01cso" * 50), ("..\\..\\escape.txt", b"no")] + list(extra))
    media_sector = 20 if early_table else 34              # 20 comes before the volume descriptor (32)
    files = {"default.xbe": (40, b"XBEH" + b"x" * 5000), "cement.rcf": (50, rcf), "intro.bik": (90, MOVIE)}
    media = _xtable([("intro.bik", 90, len(MOVIE), 0x20), ("copy.bik", 90, len(MOVIE), 0x20)])
    root = _xtable([("default.xbe", 40, len(files["default.xbe"][1]), 0x20),
                    ("cement.rcf", 50, len(rcf), 0x20),
                    ("media", media_sector, len(media), 0x10),
                    ("empty.txt", 0, 0, 0x20)])
    img = bytearray(100 * SECTOR + len(MOVIE) + SECTOR)
    vd = bytearray(SECTOR)
    vd[:20] = GF.XBOX_MAGIC
    struct.pack_into("<II", vd, 20, 33, len(root))
    vd[0x7EC:0x7EC + 20] = GF.XBOX_MAGIC
    img[32 * SECTOR:33 * SECTOR] = vd
    img[33 * SECTOR:33 * SECTOR + len(root)] = root
    img[media_sector * SECTOR:media_sector * SECTOR + len(media)] = media
    for sector, data in files.values():
        img[sector * SECTOR:sector * SECTOR + len(data)] = data
    return bytes(img)


def _irec(name: bytes, lba, size, is_dir):
    n = len(name)
    rec = bytearray(33 + n + (1 if n % 2 == 0 else 0))
    rec[0] = len(rec)
    struct.pack_into("<I", rec, 2, lba)
    struct.pack_into(">I", rec, 6, lba)
    struct.pack_into("<I", rec, 10, size)
    struct.pack_into(">I", rec, 14, size)
    rec[25] = 2 if is_dir else 0
    rec[32] = n
    rec[33:33 + n] = name
    return bytes(rec)


def ps2_disc():
    """Root: SLUS_211.11, CEMENT.RCF, MOVIES/ with INTRO.PSS."""
    rcf = build_rcf([("art\\sound\\hello.rsd", SOUND_PS2), ("scriptc\\main.cso", b"\x01cso" * 50)])
    movies = (_irec(b"\0", 21, SECTOR, True) + _irec(b"\1", 20, SECTOR, True)
              + _irec(b"INTRO.PSS;1", 60, 3000, False))
    root = (_irec(b"\0", 20, SECTOR, True) + _irec(b"\1", 20, SECTOR, True)
            + _irec(b"SLUS_211.11;1", 30, 4000, False) + _irec(b"CEMENT.RCF;1", 40, len(rcf), False)
            + _irec(b"MOVIES", 21, SECTOR, True))
    img = bytearray(80 * SECTOR + len(rcf))
    pvd = bytearray(SECTOR)
    pvd[0], pvd[1:6] = 1, b"CD001"
    pvd[8:40] = b"PLAYSTATION".ljust(32)
    pvd[156:156 + 34] = _irec(b"\0", 20, SECTOR, True)
    img[16 * SECTOR:17 * SECTOR] = pvd
    img[20 * SECTOR:20 * SECTOR + len(root)] = root
    img[21 * SECTOR:21 * SECTOR + len(movies)] = movies
    img[30 * SECTOR:30 * SECTOR + 4000] = b"ELF" + b"p" * 3997
    img[40 * SECTOR:40 * SECTOR + len(rcf)] = rcf
    img[60 * SECTOR:60 * SECTOR + 3000] = b"PSS" + b"m" * 2997
    return bytes(img)


def make_binaries(tmp_path, early_table=False):
    b = tmp_path / "binaries"
    b.mkdir()
    (b / "Scarface - The World Is Yours (USA, Europe).xiso.iso").write_bytes(xbox_disc(early_table))
    (b / "Scarface - The World Is Yours (ps2).iso").write_bytes(ps2_disc())
    with zipfile.ZipFile(b / "Scarface - The World Is Yours (Apr 20, 2006 prototype).zip", "w") as z:
        z.writestr("Scarface/game.xbe", b"XBEH" + b"proto" * 900)
        z.writestr("Scarface/art/sound/hello.rsd", SOUND)
        z.writestr("Scarface/art/models/car.p3d", CAR_PROTO)
        z.writestr("Scarface/art/cut/protoonly.p3d", b"P3D\xff cut scene")
        z.writestr("Scarface/art/movies/intro.bik", MOVIE)
        z.writestr("Scarface/../../evil.txt", b"must not leave the folder")
    pc = b / "Scarface PC"
    pc.mkdir()
    (pc / "Scarface.exe").write_bytes(b"MZ" + b"pc" * 2000)
    (pc / "cement.rcf").write_bytes(build_rcf([("art\\models\\car.p3d", CAR), ("art\\pc\\mouse.p3d", b"P3Dmouse")]))
    (b / "scripts_and_data").mkdir()                       # the portal's own folder: never a source
    return b


@pytest.fixture(autouse=True)
def small(monkeypatch):
    monkeypatch.setattr(GF, "MIN_DISC_IMAGE", 1)
    monkeypatch.setattr(GF, "XDVDFS_BASES", (0, 0x40000))
    monkeypatch.setattr(GA, "CHUNK", 1000)                # files cross many reads
    monkeypatch.setattr(GF, "_installed_pc_exe", lambda: None)


def read_all(out: Path):
    return {p.relative_to(out).as_posix(): p.read_bytes() for p in out.rglob("*")
            if p.is_file() and ".work" not in p.parts and not p.name.startswith(".")}


def rows(index, version):
    return {r[0]: r for r in index["versions"][version]["files"]}


# --------------------------------------------------------------------------- tests

def test_finds_every_version(tmp_path):
    b = make_binaries(tmp_path)
    found, notes = GA.find_sources(b)
    assert {v: s.kind for v, s in found.items()} == {"xbox": "disc", "ps2": "disc", "prototype": "zip", "pc": "folder"}
    assert found["xbox"].fs == "xdvdfs" and found["ps2"].fs == "iso"
    assert not notes


def test_an_unknown_disc_image_is_reported(tmp_path):
    b = tmp_path / "binaries"
    b.mkdir()
    img = bytearray(40 * SECTOR)
    img[16 * SECTOR] = 1
    img[16 * SECTOR + 1:16 * SECTOR + 6] = b"CD001"
    (b / "Some other game.iso").write_bytes(img)
    found, notes = GA.find_sources(b)
    assert found == {}
    assert any("not a Scarface disc" in n for n in notes) and any(n.startswith("PC: not found") for n in notes)


def test_no_duplicates_layout(tmp_path):
    b = make_binaries(tmp_path)
    index = GA.run(list(GA.VERSIONS), "unique", b, log=lambda m: None)
    out = b / "game_files"
    files = read_all(out)
    # the same bytes in several versions: written once, in Shared/, at the first version's place
    assert files["Shared/cement.rcf/art/sound/hello.rsd"] == SOUND
    assert files["Shared/cement.rcf/art/models/car.p3d"] == CAR
    assert files["Shared/media/intro.bik"] == MOVIE
    assert sum(1 for data in files.values() if data == SOUND) == 1
    # each version's folder: only what is its own
    assert files["Xbox 2006 prototype/art/models/car.p3d"] == CAR_PROTO
    assert "Xbox 2006 prototype/art/cut/protoonly.p3d" in files
    assert "Xbox 2006 prototype/art/sound/hello.rsd" not in files
    assert files["PS2/CEMENT.RCF/art/sound/hello.rsd"] == SOUND_PS2
    assert files["PS2/MOVIES/INTRO.PSS"].startswith(b"PSS")
    assert "Xbox/default.xbe" in files and "PC/Scarface.exe" in files and "PC/cement.rcf/art/pc/mouse.p3d" in files
    assert not any(k.startswith("Xbox/cement.rcf/art/sound") for k in files)
    # what each file is
    xb, ps2, proto = rows(index, "xbox"), rows(index, "ps2"), rows(index, "prototype")
    assert xb["cement.rcf/art/sound/hello.rsd"][3] == "shared"
    assert ps2["CEMENT.RCF/art/sound/hello.rsd"][3] == "changed"
    assert proto["art/models/car.p3d"][3] == "changed" and proto["art/cut/protoonly.p3d"][3] == "only"
    assert proto["art/movies/intro.bik"][3:5] == ["shared", "Shared/media/intro.bik"]
    # nothing escapes the folder, empty files and two names for the same data are kept
    assert not (tmp_path / "evil.txt").exists() and not (b / "evil.txt").exists()
    assert files["Xbox/cement.rcf/escape.txt"] == b"no"
    assert files["Shared/media/copy.bik"] == MOVIE
    assert files["Xbox/empty.txt"] == b""
    # what people read, and no work files left behind
    assert "Shared/" in files["README.txt"].decode() and "ONLY IN THIS VERSION" in files["INDEX - Xbox 2006 prototype.txt"].decode()
    assert not (out / ".work").exists()


def test_every_version_complete(tmp_path):
    b = make_binaries(tmp_path)
    GA.run(list(GA.VERSIONS), "every", b, log=lambda m: None)
    files = read_all(b / "game_files")
    assert files["Xbox/cement.rcf/art/sound/hello.rsd"] == SOUND
    assert files["Xbox 2006 prototype/art/sound/hello.rsd"] == SOUND
    assert files["PC/cement.rcf/art/models/car.p3d"] == CAR == files["Xbox/cement.rcf/art/models/car.p3d"]
    assert not any(k.startswith("Shared/") for k in files)


def test_changing_layout_reuses_the_files(tmp_path, monkeypatch):
    b = make_binaries(tmp_path)
    GA.run(list(GA.VERSIONS), "unique", b, log=lambda m: None)

    def must_not_read(*a, **k):
        raise AssertionError("the game was read again")
    monkeypatch.setattr(GA, "READERS", {k: must_not_read for k in GA.READERS})
    GA.run(list(GA.VERSIONS), "every", b, log=lambda m: None)
    files = read_all(b / "game_files")
    assert files["Xbox 2006 prototype/art/sound/hello.rsd"] == SOUND and not any(k.startswith("Shared/") for k in files)
    GA.run(list(GA.VERSIONS), "unique", b, log=lambda m: None)
    files = read_all(b / "game_files")
    assert files["Shared/cement.rcf/art/sound/hello.rsd"] == SOUND
    assert not any(k.startswith("Xbox/cement.rcf/art/sound") for k in files)


def test_an_edited_file_makes_its_version_be_read_again(tmp_path, monkeypatch):
    b = make_binaries(tmp_path)
    GA.run(["prototype", "pc"], "unique", b, log=lambda m: None)
    edited = b / "game_files" / "Xbox 2006 prototype" / "art" / "cut" / "protoonly.p3d"
    edited.write_bytes(b"my own mod")
    read = []
    real = dict(GA.READERS)
    monkeypatch.setattr(GA, "READERS", {k: (lambda *a, k=k, **kw: (read.append(k), real[k](*a, **kw))[1])
                                        for k in real})
    GA.run(["prototype", "pc"], "unique", b, log=lambda m: None)
    assert read == ["zip"]                     # the prototype again; the PC folder was reused
    out = b / "game_files"
    assert (out / "Xbox 2006 prototype" / "art" / "cut" / "protoonly.p3d").read_bytes() == b"P3D\xff cut scene"
    assert (out / "Changed by you" / "Xbox 2006 prototype" / "art" / "cut" / "protoonly.p3d").read_bytes() == b"my own mod"


def test_stopped_run_carries_on(tmp_path):
    b = make_binaries(tmp_path)
    calls = [0]

    def stop():
        calls[0] += 1
        return calls[0] > 25
    with pytest.raises(GA.Stopped):
        GA.run(list(GA.VERSIONS), "unique", b, stop=stop, log=lambda m: None)
    assert (b / "game_files" / ".work").is_dir()
    GA.run(list(GA.VERSIONS), "unique", b, log=lambda m: None)
    assert read_all(b / "game_files")["Shared/cement.rcf/art/sound/hello.rsd"] == SOUND


def test_a_directory_stored_before_the_disc_header_takes_a_second_pass(tmp_path):
    b = make_binaries(tmp_path, early_table=True)
    logs = []
    GA.run(["xbox"], "every", b, log=logs.append)
    files = read_all(b / "game_files")
    assert files["Xbox/media/intro.bik"] == MOVIE and files["Xbox/media/copy.bik"] == MOVIE
    assert any("pass 2" in m for m in logs)


def test_disc_inside_a_7z(tmp_path):
    seven = shutil.which("7z") or shutil.which("7za")
    if not seven:
        pytest.skip("the 7z program is needed to make the test archive")
    b = make_binaries(tmp_path)
    iso = b / "Scarface - The World Is Yours (USA, Europe).xiso.iso"
    subprocess.run([seven, "a", "-t7z", "-m0=LZMA2", str(b / "Scarface - The World Is Yours (USA, Europe).7z"), str(iso)],
                   check=True, capture_output=True)
    iso.unlink()
    found, _ = GA.find_sources(b)
    assert found["xbox"].member.endswith(".iso")
    GA.run(["xbox"], "every", b, log=lambda m: None)
    files = read_all(b / "game_files")
    assert files["Xbox/cement.rcf/art/sound/hello.rsd"] == SOUND and files["Xbox/media/intro.bik"] == MOVIE


def test_summary_and_lists(tmp_path):
    b = make_binaries(tmp_path)
    index = GA.run(list(GA.VERSIONS), "unique", b, log=lambda m: None)
    s = GA.summary(index)["versions"]
    assert s["prototype"]["only"] >= 2 and s["prototype"]["changed"] == 1 and s["prototype"]["shared"] == 2
    assert s["prototype"]["kinds"]["models"] == {"only": 1, "changed": 1}
    page = GA.list_files(index, "prototype", status="own", kind="models")
    assert {f["path"] for f in page["files"]} == {"art/models/car.p3d", "art/cut/protoonly.p3d"}
    assert GA.list_files(index, "prototype", query="CUT")["total"] == 1


def test_shared_place_taken_by_other_bytes_falls_back_to_the_version_folders():
    cats = {"xbox": [["a/x.p3d", 1, "A"]], "pc": [["a/x.p3d", 1, "B"]],
            "ps2": [["a/x.p3d", 1, "A"]], "prototype": [["a/X.P3D", 1, "B"]]}
    rows_, places = GA.plan(cats, "unique")
    assert ("A", "Shared/a/x.p3d") in places
    assert rows_["pc"][0][4] == "PC/a/x.p3d" and rows_["prototype"][0][4] == "PC/a/x.p3d"
    assert len(places) == 2


def test_compare_key_ignores_archives_and_case():
    assert GA.compare_key("cement.rcf/Art/x.p3d") == GA.compare_key("art/X.P3D") == "art/x.p3d"


def test_job_reports_and_refuses_a_second_run(tmp_path):
    b = make_binaries(tmp_path)
    job = GA.Job(b, log=lambda m: None)
    ov = job.overview()
    assert [v["found"] for v in ov["versions"]] == [True, True, True, True] and ov["summary"] is None
    assert job.start(["xbox"], "every") is None
    job._thread.join(30)
    job._thread = type("Busy", (), {"is_alive": lambda self: True})()
    assert "Already" in job.start(["xbox"], "every")
    job._thread = None
    ov = job.overview()
    assert ov["status"]["phase"] == "done" and ov["summary"]["versions"]["xbox"]["files"] > 3
    assert job.folder_for("xbox") == b / "game_files" / "Xbox" and job.folder_for("nope") is None


def test_an_empty_file_that_starts_where_the_next_one_does_keeps_its_name(tmp_path):
    """Like Overlays/FrontEnd/empty.txt on the PS2 disc: the empty file and the next file start at the same
    place, and the archive's directory (sorted by hash) lists the next one first."""
    import io
    from rcf import RcfArchive
    data = build_rcf([("a.txt", b"A" * 10), ("Overlays\\empty.txt", b""), ("Overlays\\next.bin", b"N" * 30976)])
    with RcfArchive(io.BytesIO(data)) as arc:
        assert {e.name: e.size for e in arc.entries} == {"a.txt": 10, "Overlays\\empty.txt": 0, "Overlays\\next.bin": 30976}
    (_u1, dir_off, _ds, names_off, names_size, _u2, count) = struct.unpack_from("<7I", data, 32)
    members = GA._rcf_members(data[dir_off:dir_off + 12 * count], data[names_off:names_off + names_size], count, len(data))
    assert [(n, s) for n, _o, s in members] == [("a.txt", 10), ("Overlays\\empty.txt", 0), ("Overlays\\next.bin", 30976)]
    folder = tmp_path / "binaries" / "Scarface PC"
    folder.mkdir(parents=True)
    (folder / "Scarface.exe").write_bytes(b"MZ")
    (folder / "cement.rcf").write_bytes(data)
    GA.run(["pc"], "every", tmp_path / "binaries", log=lambda m: None)
    out = tmp_path / "binaries" / "game_files" / "PC" / "cement.rcf" / "Overlays"
    assert (out / "empty.txt").read_bytes() == b"" and (out / "next.bin").read_bytes() == b"N" * 30976


# --------------------------------------------------------------------------- the PC disc, without installing

import ms_cab as CAB  # noqa: E402


class FakeMsi:
    """What portal/tools/msi_reader.py gives for the PC disc's SCARFACE.MSI (the real one is 6 MB)."""

    def __init__(self, data):
        assert data == b"MSI-PLACEHOLDER"
        self.streams = {}

    def table(self, name):
        return {
            "Directory": [{"Directory": "TARGETDIR", "Directory_Parent": None, "DefaultDir": "SourceDir"},
                          {"Directory": "ProgramFilesFolder", "Directory_Parent": "TARGETDIR", "DefaultDir": ".:PROGRA~1|program files"},
                          {"Directory": "RADICAL_GAMES", "Directory_Parent": "ProgramFilesFolder", "DefaultDir": "RADICA~1|Radical Games"},
                          {"Directory": "SCARFACE", "Directory_Parent": "RADICAL_GAMES", "DefaultDir": "Scarface"},
                          {"Directory": "INSTALLDIR", "Directory_Parent": "SCARFACE", "DefaultDir": "."},
                          {"Directory": "DOCS", "Directory_Parent": "INSTALLDIR", "DefaultDir": "DOCS~1|Read Me"}],
            "Component": [{"Component": "AllOtherFiles", "Directory_": "INSTALLDIR"},
                          {"Component": "Docs", "Directory_": "DOCS"}],
            "File": [{"File": "vorbisfile.dll", "Component_": "AllOtherFiles", "FileName": "VORBIS~1.DLL|vorbisfile.dll"},
                     {"File": "sound2.rcf", "Component_": "AllOtherFiles", "FileName": "sound2.rcf"},
                     {"File": "cement.rcf", "Component_": "AllOtherFiles", "FileName": "cement.rcf"},
                     {"File": "readme_1", "Component_": "Docs", "FileName": "README~1.TXT|Read me first.txt"}],
            "Media": [{"DiskId": 2, "Cabinet": "Data11.cab"}, {"DiskId": 1, "Cabinet": "Data1.cab"}],
        }.get(name, [])


PC_SOUND = build_rcf([("art\\sound\\rsd\\a\\a1.rsd", bytes(range(256)) * 400), ("art\\sound\\rsd\\b\\b2.rsd", b"RSD6PCM " * 9000)])
PC_CEMENT = build_rcf([("art\\models\\car.p3d", CAR), ("Overlays\\empty.txt", b""), ("Overlays\\next.bin", b"N" * 5000),
                       ("scriptc\\main.cso", b"\x01cso" * 50)])
PC_PATCH_RCF = build_rcf([("scriptc\\fix.cso", b"fixed!" * 40)])


def pc_cabinets(cement=None):
    files = [("vorbisfile.dll", b"MZ vorbis" * 300), ("sound2.rcf", PC_SOUND), ("cement.rcf", cement or PC_CEMENT),
             ("readme_1", b"Thanks for playing.\r\n")]
    return CAB.write_cabinets(files, split_in=1, cut=700)


def pc_disc(extra_lba=200):
    """Top folder: SCARFACE.MSI, DATA1.CAB, DATA11.CAB, SCARFACE.EXE and another folder."""
    data1, data11 = pc_cabinets()
    blobs = {"DATA1.CAB;1": data1, "DATA11.CAB;1": data11, "SCARFACE.EXE;1": b"MZ protected exe",
             "SCARFACE.MSI;1": b"MSI-PLACEHOLDER"}
    lba, where = 30, {}
    for name, data in blobs.items():
        where[name] = lba
        lba += (len(data) + SECTOR - 1) // SECTOR + 1
    assert lba < extra_lba
    root = _irec(b"\0", 20, SECTOR, True) + _irec(b"\1", 20, SECTOR, True)
    root += _irec(b"DIRECTX9", extra_lba, SECTOR, True)
    for name, data in blobs.items():
        root += _irec(name.encode(), where[name], len(data), False)
    img = bytearray((extra_lba + 2) * SECTOR)
    pvd = bytearray(SECTOR)
    pvd[0], pvd[1:6] = 1, b"CD001"
    pvd[40:72] = b"Scarface".ljust(32)
    pvd[156:156 + 34] = _irec(b"\0", 20, SECTOR, True)
    img[16 * SECTOR:17 * SECTOR] = pvd
    img[20 * SECTOR:20 * SECTOR + len(root)] = root
    for name, data in blobs.items():
        img[where[name] * SECTOR:where[name] * SECTOR + len(data)] = data
    extra = _irec(b"\0", extra_lba, SECTOR, True) + _irec(b"\1", 20, SECTOR, True) + _irec(b"DXSETUP.EXE;1", extra_lba + 1, 10, False)
    img[extra_lba * SECTOR:extra_lba * SECTOR + len(extra)] = extra
    return bytes(img), (extra_lba * SECTOR, (extra_lba + 2) * SECTOR)


def fake_patch(path):
    with zipfile.ZipFile(path, "w") as z:
        z.writestr("Scarface.exe", b"MZ 1.00.2")
        z.writestr("patch01.rcf", PC_PATCH_RCF)
        z.writestr("Patch.txt", b"readme")


@pytest.fixture
def pc_binaries(tmp_path, monkeypatch):
    monkeypatch.setattr(GA.MR, "Msi", FakeMsi)
    b = tmp_path / "binaries"
    b.mkdir()
    img, extra = pc_disc()
    (b / "Scarface-The-World-Is-Yours_Win_EN_ISO-Version.iso").write_bytes(img)
    fake_patch(b / "Scarface-The-World-Is-Yours_Patch_Win_EN_Patch-v1002.exe")
    return b, extra


def test_pc_disc_is_read_without_installing(pc_binaries, monkeypatch):
    b, _ = pc_binaries
    found, notes = GA.find_sources(b)
    pc = found["pc"]
    assert pc.kind == "pcdisc" and pc.extra.endswith("Patch-v1002.exe") and not notes
    assert "+ Scarface-The-World-Is-Yours_Patch_Win_EN_Patch-v1002.exe" in pc.name
    GA.run(["pc"], "every", b, log=lambda m: None)
    files = read_all(b / "game_files")
    assert files["PC/vorbisfile.dll"] == b"MZ vorbis" * 300
    assert files["PC/sound2.rcf/art/sound/rsd/b/b2.rsd"] == b"RSD6PCM " * 9000      # split over the two cabinets
    assert files["PC/cement.rcf/art/models/car.p3d"] == CAR
    assert files["PC/cement.rcf/Overlays/empty.txt"] == b"" and files["PC/cement.rcf/Overlays/next.bin"] == b"N" * 5000
    assert files["PC/Read Me/Read me first.txt"] == b"Thanks for playing.\r\n"      # named and placed by the installer
    assert files["PC/patch01.rcf/scriptc/fix.cso"] == b"fixed!" * 40                  # from the 1.00.2 patch


def test_pc_disc_shares_files_with_the_xbox(pc_binaries):
    b, _ = pc_binaries
    (b / "Scarface - The World Is Yours (USA, Europe).xiso.iso").write_bytes(xbox_disc())
    index = GA.run(["xbox", "pc"], "unique", b, log=lambda m: None)
    pc = rows(index, "pc")
    assert pc["cement.rcf/art/models/car.p3d"][3:5] == ["shared", "Shared/cement.rcf/art/models/car.p3d"]
    assert pc["cement.rcf/scriptc/main.cso"][3] == "shared" and pc["vorbisfile.dll"][3] == "only"


def test_a_copy_of_the_pc_disc_in_a_folder(pc_binaries, tmp_path, monkeypatch):
    b, _ = pc_binaries
    (b / "Scarface-The-World-Is-Yours_Win_EN_ISO-Version.iso").unlink()
    disc = b / "Scarface PC disc"
    disc.mkdir(parents=True)
    for name, data in zip(("Data1.cab", "Data11.cab"), pc_cabinets()):
        (disc / name).write_bytes(data)
    (disc / "Scarface.msi").write_bytes(b"MSI-PLACEHOLDER")
    (disc / "Scarface.exe").write_bytes(b"MZ protected exe")
    found, _ = GA.find_sources(b)
    assert found["pc"].kind == "pcdisc"
    GA.run(["pc"], "every", b, log=lambda m: None)
    assert read_all(b / "game_files")["PC/cement.rcf/art/models/car.p3d"] == CAR


def test_a_pc_disc_packed_in_an_archive_says_to_unpack_it(tmp_path):
    seven = shutil.which("7z") or shutil.which("7za")
    if not seven:
        pytest.skip("the 7z program is needed to make the test archive")
    b = tmp_path / "binaries"
    b.mkdir()
    img, _ = pc_disc()
    (tmp_path / "Scarface PC.iso").write_bytes(img)
    subprocess.run([seven, "a", "-t7z", str(b / "Scarface PC.7z"), str(tmp_path / "Scarface PC.iso")], check=True, capture_output=True)
    found, notes = GA.find_sources(b)
    assert "pc" not in found and any("unpack the .iso" in n for n in notes)


# --------------------------------------------------------------------------- sorting by type, and the best version

def chunk(cid, data=b"", children=()):
    kids = b"".join(children)
    return struct.pack("<III", cid, 12 + len(data), 12 + len(data) + len(kids)) + data + kids


def texture(name, w, h, bpp):
    return chunk(0x19000, bytes([len(name)]) + name + struct.pack("<IIIIIIIII", 14, w, h, bpp, 8, 1, 0, 0, 0))


def p3d(*children):
    return chunk(0xFF443350, b"", children)


def test_sniff_says_what_a_file_is_and_how_good():
    assert GA.sniff("a.rsd", b"RSD6OOGV" + struct.pack("<3I", 2, 16, 48000) + bytes(20)) == {"codec": "OOGV", "ch": 2, "rate": 48000}
    assert GA.sniff("m.bik", b"BIKi" + bytes(16) + struct.pack("<II", 1280, 720)) == {"w": 1280, "h": 720}
    model = p3d(chunk(0x10000, b"mesh"), texture(b"skin", 256, 128, 32))
    assert GA.sniff("art/car.p3d", model) == {"p3d": "models", "tex": 256 * 128, "bits": 256 * 128 * 32}
    assert GA.sniff("frontend/hud.p3d", p3d(texture(b"hud", 64, 64, 8)))["p3d"] == "textures"
    assert GA.sniff("nis/stream0.p3d", p3d(chunk(0x121000, b"anim")))["p3d"] == "animations"
    assert GA.sniff("art/subtitles/1/x.p3d", p3d(chunk(0x3000000, b"text")))["p3d"] == "scripts"
    assert GA.sniff("packages/z.p3d", p3d(chunk(0x3000000, b"data")))["p3d"] == "other"
    assert GA.sniff("broken.p3d", b"P3D\xff not chunks") is None            # sorted as a model by its name
    assert GA.kind_of("nis/stream0.p3d", {"p3d": "animations"}) == "animations" and GA.kind_of("x.p3d") == "models"


def best_catalogs():
    sound = "art/sound/rsd/a/x.rsd"
    return {
        "xbox": [["sound22.rcf/" + sound, 10, "s-xb", {"codec": "XADP", "ch": 1, "rate": 24000}],
                 ["sound9.rcf/art/sound/rsd/b/5.rsd", 10, "sur-xb", {"codec": "XADP", "ch": 6, "rate": 48000}],
                 ["movies.rcf/art/movies/intro.bik", 10, "v-xb", {"w": 720, "h": 480}],
                 ["cement.rcf/art/car.p3d", 10, "c-xb", {"p3d": "models", "tex": 1000, "bits": 32000}],
                 ["cement.rcf/scriptc/a.cso", 10, "a-xb", None],
                 ["cement.rcf/art/same_a.p3d", 10, "same", {"p3d": "models"}]],
        "pc": [["sound2.rcf/" + sound, 10, "s-pc", {"codec": "OOGV", "ch": 1, "rate": 48000}],
               ["sound2.rcf/art/sound/rsd/b/5.rsd", 10, "sur-pc", {"codec": "OOGV", "ch": 2, "rate": 48000}],
               ["movies.rcf/art/movies/intro.bik", 10, "v-pc", {"w": 1280, "h": 720}],
               ["cement.rcf/art/car.p3d", 10, "c-pc", {"p3d": "models", "tex": 1000, "bits": 4000}],
               ["cement.rcf/scriptc/a.cso", 10, "a-pc", None],
               ["patch01.rcf/scriptc/a.cso", 10, "a-patch", None],
               ["cement.rcf/art/same_b.p3d", 10, "same", {"p3d": "models"}]],
        "ps2": [["SOUND.RCF/" + sound, 10, "s-ps2", {"codec": "VAG", "ch": 1, "rate": 24000}]],
        "prototype": [["art/car.p3d", 10, "c-proto", {"p3d": "models", "tex": 5000, "bits": 160000}],
                      ["art/cut/only.p3d", 10, "o-proto", {"p3d": "models"}]],
    }


def picked(rows):
    return {r[0]: (v, r[4]) for v, rs in rows.items() for r in rs if r[6]}


def test_best_picks_the_highest_quality_of_each_file():
    rows, places = GA.plan(best_catalogs(), "best")
    got = picked(rows)
    assert got["sound2.rcf/art/sound/rsd/a/x.rsd"] == ("pc", "Best/art/sound/rsd/a/x.rsd")        # Ogg 48 kHz
    assert got["sound9.rcf/art/sound/rsd/b/5.rsd"][0] == "xbox"                                   # 5.1 surround
    assert got["movies.rcf/art/movies/intro.bik"][0] == "pc"                                       # 1280x720
    assert got["art/car.p3d"] == ("prototype", "Best/art/car.p3d")                                 # bigger textures
    assert got["patch01.rcf/scriptc/a.cso"] == ("pc", "Best/scriptc/a.cso")                        # the patched script
    assert got["art/cut/only.p3d"][0] == "prototype"
    assert all(place.startswith("Best/") for _sha, place in places)
    assert len(places) == len({place.lower() for _sha, place in places}) == 7     # the same bytes once
    # every version's rows say where the chosen copy is
    assert {r[0]: r[4] for r in rows["ps2"]} == {"SOUND.RCF/art/sound/rsd/a/x.rsd": "Best/art/sound/rsd/a/x.rsd"}


def test_best_by_type():
    _rows, places = GA.plan(best_catalogs(), "best", "type")
    names = {p for _s, p in places}
    assert {"Best/Sounds/art/sound/rsd/a/x.rsd", "Best/Videos/art/movies/intro.bik", "Best/Models/art/car.p3d",
            "Best/Scripts & text/scriptc/a.cso"} <= names


def test_by_type_folders_and_best_end_to_end(tmp_path):
    b = make_binaries(tmp_path)
    GA.run(list(GA.VERSIONS), "unique", b, log=lambda m: None, folders="type")
    files = read_all(b / "game_files")
    assert files["Shared/Sounds/cement.rcf/art/sound/hello.rsd"] == SOUND
    assert files["Xbox 2006 prototype/Models/art/models/car.p3d"] == CAR_PROTO
    assert files["Shared/Videos/media/intro.bik"] == MOVIE
    index = GA.run(list(GA.VERSIONS), "best", b, log=lambda m: None)
    files = read_all(b / "game_files")
    out = b / "game_files"
    assert files["Best/art/sound/hello.rsd"] == SOUND and "Best/art/models/car.p3d" in files
    assert not any(k.startswith(("Shared/", "Xbox/", "PC/")) for k in files)
    assert "from " in files["INDEX - Best.txt"].decode()
    summ = GA.summary(index)
    assert summ["best"]["files"] == sum(1 for k in files if k.startswith("Best/"))
    assert GA.list_files(index, "pc", status="picked")["total"] == summ["best"]["from"]["pc"]
    # back to every version complete: what Best left out is read again, and nothing is mistaken for an edit
    GA.run(list(GA.VERSIONS), "every", b, log=lambda m: None)
    files = read_all(out)
    assert not (out / "Changed by you").exists()
    assert files["Xbox/cement.rcf/art/sound/hello.rsd"] == SOUND and files["PS2/CEMENT.RCF/art/sound/hello.rsd"] == SOUND_PS2


# --------------------------------------------------------------------------- archives inside archives, sound names

def named_sound(name, codec=b"XADP", rate=24000, channels=1, body=b"\x11" * 3000, asf=None):
    """An .rsd as the game has them: header, the source name, then (WMA) an ASF header with the real format."""
    head = b"RSD6" + codec + struct.pack("<3I", channels, 16, rate) + b"****" + name.encode() + b"\0"
    head += bytes(-len(head) % 0x800)
    return head + (asf or b"") + body


def asf_wma(channels=2, rate=44100, kbps=96):
    stream = bytes.fromhex("9107DCB7B7A9CF118EE600C00C205365") + bytes(8 + 16 + 16 + 8 + 4 + 4 + 2 + 4)
    return bytes.fromhex("3026B2758E66CF11A6D900AA0062CE6C") + bytes(14) + stream + struct.pack(
        "<HHII", 0x0161, channels, rate, kbps * 1000 // 8)


VOICE = named_sound("d:\\scarface\\art\\sound\\localised\\english\\vocal\\tony\\hello_01.wav")
VOICE_PROTO = named_sound("d:\\scarface\\art\\sound\\localised\\english\\vocal\\tony\\hello_01.wav",
                          codec=b"RADP", body=b"\x22" * 2000)
DIALOGUE = build_rcf([("art\\sound\\rsd\\a\\a1b2c3d4e5f60718.rsd", VOICE), ("art\\subtitles\\a\\a1b2.p3d", b"P3D\xff")])


def test_sniff_reads_sound_names_and_the_real_wma_format():
    wma = GA.sniff("x.rsd", named_sound("c:\\scarface\\art\\sound\\music\\score\\story\\theme.wav",
                                         codec=b"WMA ", rate=48, channels=2, asf=asf_wma())[:GA.RSD_SNIFF])
    assert wma["rate"] == 44100 and wma["ch"] == 2 and wma["kbps"] == 96
    assert GA.sound_name(wma) == "art/sound/music/score/story/theme.rsd"
    assert GA.describe(wma) == "WMA 96 kbps, 44,100 Hz, stereo"
    assert GA.sound_name({"name": "..\\..\\evil.wav"}) == "" and GA.sound_name(None) == ""
    # a WMA sound whose header can't be read never beats a real sample rate
    assert GA.sniff("y.rsd", named_sound("c:\\scarface\\y.wav", codec=b"WMA ", rate=48))["rate"] == 0


def test_archives_inside_archives_are_opened_on_every_version(tmp_path, monkeypatch):
    monkeypatch.setattr(GA.MR, "Msi", FakeMsi)
    b = tmp_path / "binaries"
    b.mkdir()
    (b / "Scarface - The World Is Yours (USA, Europe).xiso.iso").write_bytes(xbox_disc(extra=[("snd_tony.rcf", DIALOGUE)]))
    with zipfile.ZipFile(b / "Scarface - The World Is Yours (Apr 20, 2006 prototype).zip", "w") as z:
        z.writestr("Scarface/game.xbe", b"XBEH")
        z.writestr("Scarface/art/sound/rsd/a/a1b2c3d4e5f60718.rsd", VOICE_PROTO)
    cement = build_rcf([("art\\models\\car.p3d", CAR), ("snd_tony.rcf", DIALOGUE)])
    img, _ = pc_disc()
    data1, data11 = pc_cabinets(cement)
    disc = b / "Scarface PC disc"                              # a copy of the PC disc in a folder
    disc.mkdir()
    for name, data in (("Data1.cab", data1), ("Data11.cab", data11), ("Scarface.msi", b"MSI-PLACEHOLDER")):
        (disc / name).write_bytes(data)
    index = GA.run(list(GA.VERSIONS), "every", b, log=lambda m: None)
    files = read_all(b / "game_files")
    inner = "snd_tony.rcf/art/sound/rsd/a/a1b2c3d4e5f60718.rsd"
    assert files["Xbox/cement.rcf/" + inner] == VOICE                       # from the disc, read in order
    assert files["PC/cement.rcf/" + inner] == VOICE                         # from the PC's cabinets
    assert "Xbox/cement.rcf/snd_tony.rcf" not in files and "PC/cement.rcf/snd_tony.rcf" not in files
    proto = rows(index, "prototype")["art/sound/rsd/a/a1b2c3d4e5f60718.rsd"]
    assert proto[3] == "changed"                                             # paired with the retail dialogue
    # and from an installed folder (read anywhere)
    folder = tmp_path / "b2" / "Scarface PC"
    folder.mkdir(parents=True)
    (folder / "Scarface.exe").write_bytes(b"MZ")
    (folder / "cement.rcf").write_bytes(cement)
    GA.run(["pc"], "every", tmp_path / "b2", log=lambda m: None)
    assert read_all(tmp_path / "b2" / "game_files")["PC/cement.rcf/" + inner] == VOICE


def test_by_type_names_sounds_by_their_original_names(tmp_path):
    b = tmp_path / "binaries"
    b.mkdir()
    (b / "Scarface - The World Is Yours (USA, Europe).xiso.iso").write_bytes(xbox_disc(extra=[("snd_tony.rcf", DIALOGUE)]))
    index = GA.run(["xbox"], "every", b, log=lambda m: None, folders="type")
    files = read_all(b / "game_files")
    assert files["Xbox/Sounds/art/sound/localised/english/vocal/tony/hello_01.rsd"] == VOICE
    listed = GA.list_files(index, "xbox", query="hello_01")
    assert listed["total"] == 1 and listed["files"][0]["name"] == "art/sound/localised/english/vocal/tony/hello_01.rsd"
    assert "[art/sound/localised/english/vocal/tony/hello_01.rsd]" in files["INDEX - Xbox.txt"].decode()
