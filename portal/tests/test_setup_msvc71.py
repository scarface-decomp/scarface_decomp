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
