"""Sending prepared matches to the portal (portal/scripts/submit_matches.py)."""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scripts"))
import submit_matches as S  # noqa: E402

FILE = '''// bin: xb
// va: 0x00243FA0
// what: The game's name key.
// spec: docs/cleanroom/SPEC-006 section 5
// tool: Claude
// a comment that is not a field: it stays in the code
extern "C" int f(void);
// va: 0x00000001
'''


def test_a_proposal_says_which_function_it_is():
    fields, code = S.read_proposal(FILE)
    assert fields == {"bin": "xb", "va": "0x00243FA0", "what": "The game's name key.",
                      "spec": "docs/cleanroom/SPEC-006 section 5", "tool": "Claude"}       # not the line after the code began
    assert code == FILE and S.task_id(fields) == "xb_00243FA0"
    assert S.task_id({"va": "0x10"}) is None and S.task_id({"bin": "xb", "va": "what"}) is None


def test_one_proposal_goes_through_claim_and_verify(tmp_path, monkeypatch):
    path = tmp_path / "xb_00243FA0.cpp"
    path.write_text(FILE, encoding="utf-8")
    asked = []
    answers = {"/api/task?id=xb_00243FA0": {"ok": True, "task": {"status": "UNCLAIMED"}}, "/api/claim": {"ok": True},
               "/api/verify": {"ok": True, "verified": True, "total_bytes": 75}}

    def call(base, where, body=None):
        asked.append((where, body))
        return answers[where]
    monkeypatch.setattr(S, "call", call)
    assert S.submit("http://x", "me", "1234", path) == (True, "verified, 75 bytes")
    assert [a[0] for a in asked] == ["/api/task?id=xb_00243FA0", "/api/claim", "/api/verify"]
    sent = asked[2][1]
    assert sent["id"] == "xb_00243FA0" and sent["what"] == "The game's name key." and sent["tool_used"] == "Claude"
    answers["/api/verify"] = {"ok": True, "verified": False, "matched_bytes": 70, "total_bytes": 75}
    answers["/api/cancel"] = {"ok": True}
    assert S.submit("http://x", "me", "1234", path) == (False, "not a match: 70 of 75 bytes")
    assert asked[-1][0] == "/api/cancel"                                       # the claim is given back
    answers["/api/task?id=xb_00243FA0"] = {"ok": False, "error": "Function not found."}
    assert S.submit("http://x", "me", "1234", path)[0] is False


def test_the_waiting_matches_are_well_formed():
    for path in sorted((Path(__file__).resolve().parents[2] / "reports" / "to_submit").glob("*.cpp")):
        fields, _code = S.read_proposal(path.read_text(encoding="utf-8"))
        assert S.task_id(fields) == path.stem, path.name                        # named after its function
        assert fields.get("what") and len(fields["what"]) <= 160, path.name
        # where it came from: a spec, or the tool that wrote it (agent.py keep's own rule); a look-alike
        # names the already matched function it copies
        assert fields.get("spec") or fields.get("tool"), path.name
        if "look-alike" in fields.get("tool", ""):
            assert re.search(r"look-alike of (\w+ )?0x[0-9A-F]{8}", fields["tool"]), path.name


def test_a_verify_line_says_which_function_and_flags():
    text = ("// bin: xb\n// va: 0x00025400\n// verify: python portal/verify.py x.cpp --va 0x00025400 --bin xb "
            "--match '??_I' --flags \"/O2 /Ot /Oy /G6 /Gd /GR /Zp4\"   (built without /EHsc)\nint x;\n")
    assert S.verify_options(text) == {"match": "??_I", "flags": "/O2 /Ot /Oy /G6 /Gd /GR /Zp4"}
    assert S.verify_options("// bin: xb\nint x;\n") == {}
