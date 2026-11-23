"""What a push to main posts to the Discord (portal/tools/discord_feed.py, .github/workflows/discord.yml)."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import discord_feed as D  # noqa: E402

PROGRESS = {"verified": {"total": 10}, "queue": {"total": 90}, "described": {"total": 3}, "good_first": []}


def reg(**entries):
    return {"entries": {k: dict({"bin": "xb", "va": "0x" + k[5:], "size": 8, "symbol": "sub_" + k[5:]}, **e)
                        for k, e in entries.items()}}


def test_a_push_says_what_it_brought():
    old = reg(**{"xb:0x00011000": {}, "xb:0x00011100": {"what": "Old words."}})
    new = reg(**{"xb:0x00011000": {"what": "Turns the lights on."}, "xb:0x00011100": {"what": "Old words."},
                 "xb:0x00011200": {"verified_by": "bob @everyone"}})
    names = {"names": {"xb:0x00011000": {"name": "Car::Lights"}}}
    text = D.push_message(old, new, {"names": {}}, names, PROGRESS)
    assert text.startswith("**1 new match** on GitHub. The released game is now 10 of 100 functions (10.00%).")
    assert "`sub_00011200`" in text and "@​everyone" in text                 # nobody gets pinged
    assert "**1** function got a one-line description (3 of the released game's" in text
    assert "**1** got a real name" in text


def test_a_push_of_descriptions_only_and_one_with_nothing_new():
    old = reg(**{"xb:0x00011000": {}})
    new = reg(**{"xb:0x00011000": {"what": "Turns the lights on."}})
    text = D.push_message(old, new, {}, {}, PROGRESS)
    assert text.startswith("**1** function got a one-line description") and D.SITE in text
    assert D.push_message(new, new, {}, {}, PROGRESS) is None


def test_the_command_posts_only_with_a_webhook(tmp_path, monkeypatch, capsys):
    old = tmp_path / "old.json"
    old.write_text('{"entries": {}}', encoding="utf-8")
    monkeypatch.delenv(D.ENV, raising=False)
    monkeypatch.setattr(D, "webhook_url", lambda base: None)
    monkeypatch.setattr(D, "post", lambda *a, **k: (_ for _ in ()).throw(AssertionError("posted")))
    assert D.main(["--old-registry", str(old)]) == 0
    out = capsys.readouterr().out
    assert "No Discord webhook set up" in out or "Nothing new" in out
