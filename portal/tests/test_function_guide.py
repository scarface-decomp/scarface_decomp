"""The function guide (docs/function_guide.json) in the portal, and what the website says about it."""
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def test_the_guide_is_well_formed():
    guide = json.loads((ROOT / "docs" / "function_guide.json").read_text(encoding="utf-8"))["functions"]
    assert len(guide) > 500
    seen = set()
    for e in guide:
        assert e["bin"] in ("xb", "pc") and int(e["va"], 16) > 0 and e["what_it_does"].strip(), e
        assert e["status"] in ("open", "matched"), e
        assert (ROOT / e["spec"].split("#")[0]).is_file(), e["spec"]            # it points at a spec that exists
        assert (e["bin"], e["va"]) not in seen, e                                # one entry per function
        seen.add((e["bin"], e["va"]))


def test_the_portal_shows_a_functions_guide_entry():
    import importlib
    import sys
    from conftest import PORTAL
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    server._GUIDE = None
    note = server.guide_note({"bin": "xb", "va": "0x00243FA0"})
    assert note and "name key" in note["what_it_does"] and note["spec"].startswith("docs/cleanroom/SPEC-006")
    assert note["low_confidence"] is False
    assert server.guide_note({"bin": "xb", "va": "0x00000001"}) is None
    assert server.guide_note({"bin": "xb", "va": "not a number"}) is None
    low = next(e for e in json.loads((ROOT / "docs" / "function_guide.json").read_text(encoding="utf-8"))["functions"]
               if e.get("confidence") == "low")
    assert server.guide_note({"bin": low["bin"], "va": low["va"]})["low_confidence"] is True


def test_the_website_points_at_what_the_project_knows():
    page = (ROOT / "docs" / "index.html").read_text(encoding="utf-8")
    for needle in ("docs/cleanroom", "function_guide.json", "CLEAN_ROOM.md", "Can I watch the game's cutscenes?",
                   "FORMATS.md#cutscenes-artnis"):
        assert needle in page, needle
    portal = (ROOT / "portal" / "website_kit" / "index.html").read_text(encoding="utf-8")
    assert 'id="wb-guide"' in portal and "Use as the description" in portal
