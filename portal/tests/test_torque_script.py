"""portal/tools/torque_script.py: compiled TorqueScript -> readable TorqueScript -> the identical bytes.

The game's own scripts are not in the repository, so most tests compile small scripts written here (in
the form the decompiler prints), decompile the result and check both the text and the bytes. With the
game's scripts in binaries/scripts_and_data/, the last test checks every one of them."""
import struct
import textwrap

import pytest

from conftest import ROOT

import torque_dso as TD
import torque_script as TS
from torque_names import PARENT_KEY, compiled_name, name_key, recover, candidates, stx

SCRIPTS = ROOT / "binaries" / "scripts_and_data"

# Every construct the decompiler writes, in the form it writes them. With names=None the compiled
# file stores them hashed and the decompiler prints the hashes, so these tests give it the names.
SOURCE = textwrap.dedent("""\
    $Version = 96919;
    $Money[3] = "lots";
    function Tony::buy(%this, %item, %count)
    {
        %total = 0;
        for (%i = 0; %i < %count; %i++)
        {
            %total += %item.price * 2;
            if (%total > 1000)
            {
                break;
            }
        }
        if (%item.name $= "Yayo" && !%this.busy)
        {
            %this.busy = 1;
        }
        else if (%count >= 5 || %count <= -1)
        {
            echo("bulk" SPC %count TAB "x" NL %item @ "!");
        }
        else
        {
            Parent::buy(%this, %item, %count);
        }
        while (%count != 0)
        {
            %count--;
            continue;
        }
        do
        {
            %total = %total / 2;
        } while (%total >= 1.5);
        $Money[%i, %count] = %total;
        %this.stash[%count] -= 2;
        %this.stash[%count] = %item !$= "" ? %item : 'tagged';
        return %total;
    }

    function noBody() {}

    package Testing
    {
        function Gun::fire(%this)
        {
            return ~%this.ammo | 4 & 7 ^ 1 << 2 >> 1 % 3;
        }
    };

    %obj = new ScriptObject(Gun : Base, 1, "two")
    {
        damage = 10;
        slots[2] = %obj;
        new ScriptObject("Bullet") {};
    };
    datablock Weapon(Pistol) {};
    Utils::reset();
    %obj.fire();
    """)

WORDS = ["Version", "$Version", "Money", "$Money", "Tony", "buy", "%this", "%item", "%count", "%total", "%i",
         "price", "name", "busy", "echo", "Parent", "noBody", "Testing", "Gun", "fire", "ammo", "ScriptObject",
         "Base", "damage", "slots", "Weapon", "Pistol", "Utils", "reset", "%obj", "stash"]
NAMES = {name_key(w): w for w in WORDS}


def test_names_are_radicals_hash():
    # The game stores "Parent" (case does not matter) as stxipcpjjln: checked against the retail scripts.
    assert compiled_name("Parent") == compiled_name("parent") == "stxipcpjjln"
    assert compiled_name("Parent", "ste") == "ste3684299512"          # the April 2006 prototype
    assert name_key("stxipcpjjln") == name_key("ste3684299512") == PARENT_KEY
    assert compiled_name("%this") != compiled_name("this")             # variables keep their % or $
    assert stx(name_key("stxabcdefgh")) == "stxabcdefgh"


def test_recover_names_from_candidate_words():
    wanted = {name_key("%this"), name_key("FindObject"), name_key("neverMentioned")}
    got = recover(wanted, candidates([b"\0FindObject\0this is text\0"], ["%this"]))
    assert got == {name_key("%this"): "%this", name_key("FindObject"): "FindObject"}


def test_compile_decompile_compile_is_exact():
    raw = TS.compile_text(SOURCE)
    text = TS.decompile(raw, NAMES)
    assert text == SOURCE
    assert TS.compile_text(text) == raw
    assert TS.check(raw, NAMES)[1:] == (True, "compiles back byte for byte")


def test_hashed_names_round_trip_too():
    raw = TS.compile_text(SOURCE)
    text = TS.decompile(raw)                                   # no names: every name stays hashed
    assert "stx" in text and "Tony" not in text
    assert TS.compile_text(text) == raw
    proto = TS.compile_text(SOURCE, "ste")
    assert TS.check(proto)[1] and b"ste" in proto and b"stx" not in proto


def test_layout_details_the_game_uses():
    s = TD.parse(TS.compile_text("$a = 1;\n"))
    assert len(s.codes) % 2 == 0 and s.codes[-1] == 0xCDCD     # padded to an even count with MSVC's fill
    s = TD.parse(TS.compile_text("function f()\n{\n    return 'x';\n}\n"))
    assert s.function_strings == b"x\0" + b"\xcd" * 5          # tagged strings get 7 bytes
    # a word that is not a number turns into NaN when compared as a number, and NaNs are never merged
    s = TD.parse(TS.compile_text('$a = $b == "nan" || $b == "nan";\n'))
    assert s._gf_raw == bytes.fromhex("0000c0ff") * 2


def test_bad_text_is_an_error_not_a_guess():
    with pytest.raises(TS.ScriptError):
        TS.compile_text("function f( {")
    with pytest.raises(TS.ScriptError):
        TS.decompile(b"\x01\x02\x03\x04" * 10)


def test_command_line(tmp_path, capsys):
    cso = tmp_path / "scripts" / "tony.cso"
    cso.parent.mkdir()
    cso.write_bytes(TS.compile_text(SOURCE))
    assert TS.main(["decompile", str(cso.parent), "--out", str(tmp_path / "out"), "--bin", str(tmp_path)]) == 0
    out = (tmp_path / "out" / "tony.cso.cs").read_text(encoding="latin-1")
    assert out.startswith("// tony.cso: decompiled") and "compiles back byte for byte" in out
    assert "1 of 1 scripts" in capsys.readouterr().out
    assert TS.main(["compile", str(tmp_path / "out" / "tony.cso.cs"), "-o", str(tmp_path / "again.cso")]) == 0
    assert (tmp_path / "again.cso").read_bytes() == cso.read_bytes()


def test_portal_scripts_tab_shows_the_text():
    import cso_dso_dtr_decompiler as C
    r = C.verify_and_decompile_cso_dso(TS.compile_text(SOURCE), "tony.cso", NAMES)
    assert r["ok"] and r["roundtrip_exact"] and "byte for byte" in r["format"]
    assert "function Tony::buy(%this, %item, %count)" in r["decompiled_code"]
    assert "FUNC_DECL" in r["disasm"] and "Tony" in r["disasm"]


def _game_scripts():
    if not SCRIPTS.exists():
        return []
    return sorted(p for p in SCRIPTS.rglob("*") if p.suffix.lower() in (".cso", ".dso"))


@pytest.mark.skipif(not _game_scripts(), reason="no game scripts in binaries/scripts_and_data "
                                                 "(portal/scripts/extract_scripts.py)")
def test_every_game_script_decompiles_exactly():
    files = _game_scripts()
    names = TS.names_for(files, ROOT / "binaries")
    bad = []
    for p in files:
        try:
            ok = TS.check(p.read_bytes(), names)[1]
        except TS.ScriptError as e:
            ok = False
            print(p, e)
        if not ok:
            bad.append(p.relative_to(SCRIPTS).as_posix())
    assert not bad, f"{len(bad)} of {len(files)} not exact: {bad[:10]}"


def test_prototype_padding_is_kept():
    # The April 2006 prototype's compiler padded the code with leftover memory, not 0xCDCD.
    text = "// compiler padding: 0x00F0\n$a = 1;\n"
    raw = TS.compile_text(text, "ste")
    assert TD.parse(raw).codes[-1] == 0xF0
    again = TS.decompile(raw)
    assert again.startswith("// compiler padding: 0x00F0\n") and TS.compile_text(again, "ste") == raw
    assert TD.parse(TS.compile_text("$a = 1;\n")).codes[-1] == 0xCDCD


def test_the_prototype_compiler_differs_a_little():
    """The April 2006 prototype's compiler put the right side of a comparison or && into the tables
    first, and left zeros (not 0xCD) in unused bytes. Both checked against the prototype's scripts."""
    src = "function f()\n{\n    return $first < $second;\n}\n\nfunction g()\n{\n    return 'a';\n}\n"
    retail, proto = TD.parse(TS.compile_text(src)), TD.parse(TS.compile_text(src, "ste"))
    def first_of(s, style):
        names = list(s.strings(s.global_strings).values())
        a, b = names.index(compiled_name("$first", style)), names.index(compiled_name("$second", style))
        return "$first" if a < b else "$second"
    assert first_of(retail, "stx") == "$first" and first_of(proto, "ste") == "$second"
    assert retail.function_strings.endswith(b"a\0" + b"\xcd" * 5) and proto.function_strings.endswith(b"a\0" + b"\0" * 5)
