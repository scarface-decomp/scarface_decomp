"""Good first functions, the Discord announcements and the feed of new matches. Nothing here reaches Discord."""
import json
import xml.dom.minidom

import pytest

import discord_feed as D
import good_first as G
import registry_outputs as RO


def task(i, size=8, bin="xb", status="UNCLAIMED", group="", others=0, rep=False, hint="", symbol=None):
    return {"id": f"{bin}_{i:08X}", "bin": bin, "va": f"0x{i:08X}" if bin == "xb" else f"PC 0x{i:08X}",
            "fva_int": i, "symbol": symbol or f"sub_{i:08X}", "size": size, "status": status, "claimed_by": None,
            "lookalike_group": group, "lookalikes": others, "lookalike_rep": rep, "hint": hint}


QUEUE = [
    task(0x100, size=12, group="g1", status="VERIFIED"),              # matched: its look-alike gets the head start
    task(0x110, size=20, group="g1"),
    task(0x120, size=14, group="g1"),                                # same group: only one is listed
    task(0x130, size=6, hint="Matched before the 2026-11-08 reset; 6 bytes."),
    task(0x140, size=4, group="g2", rep=True, others=12),
    task(0x150, size=2, symbol="Weapon::vfunc_03"),
    task(0x160, size=2),                                             # no head start
    task(0x170, size=200, symbol="Big::vfunc_01"),                   # too big
    task(0x180, size=3, bin="ps2", symbol="A::b"),                   # not a main version
    task(0x190, size=3, symbol="C::d", status="CLAIMED"),
    task(0x1A0, size=5, bin="pc", symbol="Pc::vfunc_00"),
]


def test_rank_puts_the_best_head_starts_first():
    picks = G.rank(QUEUE)
    assert [p["id"] for p in picks] == ["xb_00000120", "xb_00000130", "xb_00000140", "xb_00000150", "pc_000001A0"]
    assert [p["kind"] for p in picks] == ["lookalike_matched", "matched_before", "group", "named", "named"]
    assert "12 look-alikes" in picks[2]["why"]
    assert len(G.rank(QUEUE, 2)) == 2


def test_site_list_mixes_kinds_and_drops_what_got_matched(monkeypatch):
    monkeypatch.setattr(G, "PER_KIND", 1)
    reg = {"entries": {"xb:0x00000150": {}}}
    picks = G.for_site(QUEUE, reg, None, n=4)
    assert [p["kind"] for p in picks] == ["lookalike_matched", "matched_before", "group", "named"]
    assert all(p["id"] != "xb_00000150" for p in picks) and picks[-1]["id"] == "pc_000001A0"
    later = G.for_site(None, {"entries": {"pc:0x000001A0": {}}}, picks)        # no queue here: the last list, minus matches
    assert [p["id"] for p in later] == [p["id"] for p in picks[:3]]


def test_progress_carries_the_list():
    prog = RO.progress_summary({"entries": {}}, QUEUE, None)
    assert prog["good_first"][0]["id"] == "xb_00000120"
    again = RO.progress_summary({"entries": {}}, None, prog)
    assert again["good_first"] == prog["good_first"]


# --------------------------------------------------------------------------- Discord

URL = "https://discord.com/api/webhooks/123456/abc_DEF-ghi"


def test_webhook_only_from_this_computer_and_only_discord(tmp_path, monkeypatch):
    monkeypatch.delenv(D.ENV, raising=False)
    assert D.webhook_url(tmp_path) is None
    (tmp_path / "portal" / "private").mkdir(parents=True)
    (tmp_path / D.URL_FILE).write_text(URL + "\n")
    assert D.webhook_url(tmp_path) == URL
    monkeypatch.setenv(D.ENV, "https://evil.example/api/webhooks/1/x")
    assert D.webhook_url(tmp_path) is None                          # not a Discord address: never used
    monkeypatch.setenv(D.ENV, "https://canary.discord.com/api/webhooks/9/Zz")
    assert D.webhook_url(tmp_path) == "https://canary.discord.com/api/webhooks/9/Zz"


def entry(i, who="Alice", size=8):
    return {"bin": "xb", "va": f"0x{i:08X}", "symbol": f"Obj::vfunc_{i:02d}", "size": size, "verified_by": who,
            "verified_at": f"2026-11-10 10:{i % 60:02d}:00"}


def test_message_is_plain_and_short():
    text = D.message([entry(1, who="@everyone **boss**"), entry(2, size=1)], 10, 100, G.rank(QUEUE, 3))
    assert text.startswith("**2 new matches** on GitHub. The released game is now 10 of 100 functions (10.00%).")
    assert "@​everyone \\*\\*boss\\*\\*" in text and "@everyone" not in text
    assert "(Xbox 0x00000002, 1 byte) by Alice" in text and "Good first functions: `sub_00000120`" in text
    many = D.message([entry(i, who="x" * 60) for i in range(200)], 1, 2, [])
    assert len(many) <= D.LIMIT and "…and 185 more." in many


def test_announce_only_new_matches(tmp_path, monkeypatch):
    monkeypatch.setenv(D.ENV, URL)
    sent = []
    send = lambda url, text: (sent.append((url, text)) or (True, ""))        # noqa: E731
    reg = {"entries": {"xb:0x00000001": entry(1)}}
    assert D.announce_new(tmp_path, reg, 1, 10, [], send)["skipped"].startswith("first run")
    assert sent == []                                                  # the first time only notes what exists
    reg["entries"]["xb:0x00000002"] = entry(2, who="Bob")
    assert D.announce_new(tmp_path, reg, 2, 10, [], send) == {"posted": 1}
    assert sent[0][0] == URL and "Obj::vfunc_02" in sent[0][1] and "Obj::vfunc_01" not in sent[0][1]
    assert D.announce_new(tmp_path, reg, 2, 10, [], send) == {"skipped": "nothing new"}
    reg["entries"]["xb:0x00000003"] = entry(3)
    assert D.announce_new(tmp_path, reg, 3, 10, [], lambda u, t: (False, "HTTP 404"))["skipped"] == "HTTP 404"
    assert D.announce_new(tmp_path, reg, 3, 10, [], send) == {"posted": 1}          # tried again next time
    monkeypatch.delenv(D.ENV)
    assert D.announce_new(tmp_path, reg, 3, 10, [], send) == {"skipped": "no webhook set up"}


def test_portal_announces_after_a_push(monkeypatch):
    import importlib
    import sys
    from conftest import PORTAL
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    seen = {}
    monkeypatch.setattr(server, "ALL_TASKS", QUEUE)
    monkeypatch.setattr(server, "REGISTRY", {"entries": {"xb:0x00000100": entry(1)}})
    monkeypatch.setattr(server.DISCORD, "announce_new",
                        lambda base, reg, done, total, good: seen.update(done=done, total=total, good=good, n=len(reg["entries"])) or {"posted": 1})
    assert server.announce_on_discord() == {"posted": 1}
    assert seen["done"] == 1 and seen["total"] == 10 and seen["n"] == 1 and len(seen["good"]) == 3
    monkeypatch.setattr(server.DISCORD, "announce_new", lambda *a: 1 / 0)
    assert server.announce_on_discord()["skipped"].startswith("error")           # never breaks a push


# --------------------------------------------------------------------------- the feed

def test_feed_of_new_matches():
    reg = {"entries": {f"xb:0x{i:08X}": dict(entry(i), symbol=f"A<int>::f{i}&") for i in range(60)}}
    text = RO.feed_xml(reg)
    doc = xml.dom.minidom.parseString(text)
    entries = doc.getElementsByTagName("entry")
    assert len(entries) == RO.FEED_ENTRIES
    first = entries[0]
    assert first.getElementsByTagName("title")[0].firstChild.data == "A<int>::f59& (Xbox, 8 bytes) by Alice"
    assert first.getElementsByTagName("updated")[0].firstChild.data == "2026-11-10T10:59:00Z"
    assert first.getElementsByTagName("link")[0].getAttribute("href").startswith(RO.REPO + "/blob/main/reconstructed_src/xbox/")
    assert doc.getElementsByTagName("updated")[0].firstChild.data == "2026-11-10T10:59:00Z"
    assert "<entry>" not in RO.feed_xml({"entries": {}})


@pytest.mark.parametrize("name", ["feed.xml"])
def test_the_repository_feed_is_current(name):
    from conftest import ROOT
    reg = json.loads((ROOT / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    assert (ROOT / "docs" / name).read_text(encoding="utf-8").replace("\r\n", "\n") == RO.feed_xml(reg)
