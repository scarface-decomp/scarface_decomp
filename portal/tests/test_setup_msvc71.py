"""portal/scripts/setup_msvc71.py: telling the two Toolkit 2003 releases apart without running anything."""
import importlib.util
import struct

import conftest  # noqa: F401  (puts tools/ on the path)
import msvc_verify as MV

spec = importlib.util.spec_from_file_location("setup_msvc71", conftest.PORTAL / "scripts" / "setup_msvc71.py")
S = importlib.util.module_from_spec(spec)
spec.loader.exec_module(S)


def fake_program(tmp_path, major, minor, build):
    """A file holding just a VS_FIXEDFILEINFO block, the part of a Windows program's version resource that is read."""
    fixed = struct.pack("<IIII", 0xFEEF04BD, 0x00010000, (major << 16) | minor, build << 16)
    p = tmp_path / "cl.exe"
    p.write_bytes(b"MZ" + b"\0" * 200 + fixed + b"\0" * 40)
    return p


def test_reads_both_toolkit_builds(tmp_path):
    assert S.file_version(fake_program(tmp_path, 13, 10, 3052)) == "13.10.3052"
    assert S.file_version(fake_program(tmp_path, 13, 10, 3077)) == "13.10.3077"


def test_later_compilers_are_not_accepted(tmp_path):
    assert S.file_version(fake_program(tmp_path, 14, 0, 50727)) not in S.TOOLKIT_BUILDS     # Visual C++ 2005
    assert S.file_version(fake_program(tmp_path, 13, 10, 6030)) not in S.TOOLKIT_BUILDS     # VS .NET 2003 SP1


def test_setup_and_verifier_agree_on_the_builds():
    assert set(S.TOOLKIT_BUILDS) == set(MV.TOOLKIT_BUILDS) == {"13.10.3052", "13.10.3077"}


def test_msi_reader_names_and_folders():
    """The pieces of the Windows unpack (portal/tools/msi_reader.py) that need no installer."""
    import msi_reader as MR
    enc = "".join(chr(0x3800 + (MR.B64.index(a) | MR.B64.index(b) << 6)) for a, b in ("Da", "ta", "1.", "ca"))
    assert MR.decode_stream_name(enc + chr(0x4800 + MR.B64.index("b"))) == "Data1.cab"
    assert MR.decode_stream_name(chr(0x4840) + "x") == "!x"
    assert MR.long_name("MICROS~1|Microsoft Visual C++ Toolkit 2003") == "Microsoft Visual C++ Toolkit 2003"
    assert MR.long_name(".:PROGRA~1|program files") == "."
    dirs = MR.directory_paths([
        {"Directory": "TARGETDIR", "Directory_Parent": None, "DefaultDir": "SourceDir"},
        {"Directory": "ProgramFilesFolder", "Directory_Parent": "TARGETDIR", "DefaultDir": ".:PROGRA~1|program files"},
        {"Directory": "PRODUCT", "Directory_Parent": "ProgramFilesFolder", "DefaultDir": "MICROS~1|Microsoft Visual C++ Toolkit 2003"},
        {"Directory": "INSTALLDIR", "Directory_Parent": "PRODUCT", "DefaultDir": "."},
        {"Directory": "BIN", "Directory_Parent": "INSTALLDIR", "DefaultDir": "bin"},
        {"Directory": "LOOP", "Directory_Parent": "LOOP", "DefaultDir": "x"},
    ])
    assert str(dirs["BIN"]).replace("\\", "/") == "Microsoft Visual C++ Toolkit 2003/bin"
    assert str(dirs["LOOP"]) == "x"
    from pathlib import PurePosixPath as P
    assert MR._safe(P("a/b/cl.exe")) and not MR._safe(P("../evil.exe")) and not MR._safe(P("/etc/x"))


def test_the_launcher_sets_the_compiler_up_by_itself(tmp_path):
    """START_PORTAL runs --auto: with the installer left in the project folder, binaries/ or Downloads and no
    compiler yet, it is set up; otherwise nothing happens and nothing is said. It never stops the start."""
    mod = spec.loader.load_module() if False else __import__("importlib").util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    dest, proj, downloads = tmp_path / "msvc71", tmp_path / "project", tmp_path / "Downloads"
    proj.mkdir()
    downloads.mkdir()
    said, ran = [], []
    assert mod.auto(dest, [proj, downloads], ran.append, said.append) == 0 and not ran and not said     # no installer
    (downloads / "VCToolkitSetup.exe").write_bytes(b"x")
    assert mod.find_installer([proj, downloads]) == downloads / "VCToolkitSetup.exe"
    (proj / "VCToolkitSetup (1).exe").write_bytes(b"x")                    # the project folder comes first
    assert mod.find_installer([proj, downloads]).parent == proj
    assert mod.auto(dest, [proj, downloads], ran.append, said.append) == 0
    assert ran == [proj / "VCToolkitSetup (1).exe"] and "The compiler is ready" in said[-1]

    def fails(exe):
        raise SystemExit("not the Toolkit")
    assert mod.auto(dest, [proj], fails, said.append) == 0 and "not the Toolkit" in said[-1]
    (dest / "bin").mkdir(parents=True)
    (dest / "bin" / "cl.exe").write_bytes(b"x")
    ran.clear()
    n = len(said)
    assert mod.auto(dest, [proj], ran.append, said.append) == 0 and not ran and len(said) == n         # already set up
