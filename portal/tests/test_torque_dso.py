"""portal/tools/torque_dso.py: Scarface's compiled TorqueScript must come apart and go back together exactly."""

import pytest

from conftest import ROOT

import torque_dso as TD

SCRIPTS = ROOT / "binaries" / "scripts_and_data"


def sample() -> bytes:
    s = TD.CompiledScript(
        version=1,
        global_strings=b"init\0Tony\0$money\0",
        global_floats=[1.5, -0.25],
        function_strings=b"%x\0",
        function_floats=[3.0],
        codes=[0x00, 0x12, 0x2A, 0xCDCD, 0x00FE, 0x0100, 0xFFFF, 0x0D],
        idents=[(0, [3]), (5, [5, 6])],
    )
    return TD.build(s)


def test_build_parse_round_trip():
    raw = sample()
    s = TD.parse(raw)
    assert s.version == 1 and s.global_floats == [1.5, -0.25] and s.function_floats == [3.0]
    assert s.codes == [0x00, 0x12, 0x2A, 0xCDCD, 0xFE, 0x100, 0xFFFF, 0x0D]
    assert s.idents == [(0, [3]), (5, [5, 6])]
    assert TD.CompiledScript.strings(s.global_strings) == {0: "init", 5: "Tony", 10: "$money"}
    assert TD.build(s) == raw and TD.round_trip(raw) == (True, "rebuilt byte for byte")
    # one byte for codes below 0xFF, 0xFF + u16 otherwise
    assert b"\xfe" in raw and b"\xff\x00\x01" in raw and b"\xff\xcd\xcd" in raw


def test_the_smallest_real_shape():
    # scriptc/templates/props.cso from the game: empty tables, two codes, no identifiers
    raw = bytes.fromhex("01000000" + "00000000" * 4 + "02000000" + "0dffcdcd" + "00000000")
    assert TD.round_trip(raw)[0] and TD.parse(raw).codes == [0x0D, 0xCDCD]


@pytest.mark.parametrize("cut", [3, 9, 30, 50])
def test_truncated_files_are_errors(cut):
    with pytest.raises(TD.DsoError):
        TD.parse(sample()[:cut])


def test_extra_bytes_and_odd_escapes_are_errors():
    with pytest.raises(TD.DsoError, match="unexpected bytes"):
        TD.parse(sample() + b"\0")
    odd = bytes.fromhex("01000000" + "00000000" * 4 + "01000000" + "ff0500" + "00000000")
    with pytest.raises(TD.DsoError, match="escaped"):
        TD.parse(odd)


def test_listing_is_text_about_the_file():
    text = TD.listing(sample(), "x.cso")
    assert "x.cso" in text and "'Tony'" in text and "Exact round trip: yes" in text


def test_portal_scripts_tab_uses_it():
    import cso_dso_dtr_decompiler as C
    # sample() has the right layout but its codes are not a program: shown as tables, not as exact text
    r = C.verify_and_decompile_cso_dso(sample(), "x.cso")
    assert r["ok"] and not r["roundtrip_exact"] and r["opcode_count"] == 8
    assert "could not be decompiled" in r["decompiled_code"] and "'Tony'" in r["decompiled_code"]
    assert not C.verify_and_decompile_cso_dso(b"\x01\x02\x03\x04" * 10, "t.cso")["ok"]


@pytest.mark.skipif(not any(SCRIPTS.rglob("*.cso")) if SCRIPTS.exists() else True,
                    reason="no game scripts in binaries/scripts_and_data (portal/scripts/extract_scripts.py)")
def test_every_extracted_game_script_round_trips():
    files = [p for p in SCRIPTS.rglob("*") if p.suffix.lower() in (".cso", ".dso")]
    bad = [(p.name, msg) for p in files for ok, msg in [TD.round_trip(p.read_bytes())] if not ok]
    assert not bad, bad[:5]
