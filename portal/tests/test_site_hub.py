"""
The website's hub pages and the files made for them: one name per person on the leaderboards
(portal/tools/contributors.py), the map of the code (docs/map.json, docs/explore.html), the progress badge
(docs/badge.svg) and the page for players and modders (docs/game.html).
"""
import json
import re
import shutil
from html.parser import HTMLParser
from pathlib import Path

import pytest

from conftest import ROOT, launch_chromium

import contributors
import registry_outputs as RO


# --------------------------------------------------------------------------- leaderboards

def test_aliases_add_up_under_one_name(tmp_path):
    f = tmp_path / "aliases.json"
    f.write_text(json.dumps({"aliases": {"Bob (typo)": "Bob", "B0b": "Bob (typo)"}}), encoding="utf-8")
    table = contributors.aliases(f)
    entries = [{"verified_by": "Bob"}, {"verified_by": "Bob (typo)"}, {"verified_by": "B0b"},
               {"verified_by": "Ann"}, {}]
    c = contributors.count(entries, table)
    assert c == {"Bob": 3, "Ann": 1}                     # a chain of spellings ends at the name used
    assert contributors.count(entries, table, unattributed="?")["?"] == 1


def test_alias_loop_and_bad_file_are_harmless(tmp_path):
    assert contributors.canonical("A", {"A": "B", "B": "A"}) in ("A", "B")
    bad = tmp_path / "bad.json"
    bad.write_text("{not json", encoding="utf-8")
    assert contributors.aliases(bad) == {}
    assert contributors.aliases(tmp_path / "missing.json") == {}


def test_the_founders_two_spellings_are_one_person():
    table = contributors.aliases()
    assert contributors.canonical("RRutherfordd (Founder)", table) == "RRutherrfordd (Founder)"
    prog = json.loads((ROOT / "reports" / "progress.json").read_text(encoding="utf-8"))
    assert "RRutherfordd (Founder)" not in prog["contributors"]


def test_progress_summary_uses_the_aliases():
    reg = {"entries": {"xb:0x00010000": {"bin": "xb", "va": "0x00010000", "size": 4, "verified_by": "RRutherfordd (Founder)"},
                       "xb:0x00010010": {"bin": "xb", "va": "0x00010010", "size": 4, "verified_by": "RRutherrfordd (Founder)"}}}
    out = RO.progress_summary(reg, None, None, picks=False)
    assert out["contributors"] == {"RRutherrfordd (Founder)": 2}


# --------------------------------------------------------------------------- map.json

def _known():
    def t(va, sym, size):
        return {"bin": "xb", "fva_int": va, "symbol": sym, "size": size}
    return {"xb": {0x10000: t(0x10000, "sub_00010000", 16), 0x10010: t(0x10010, "Car::vfunc_01", 32),
                   0x10040: t(0x10040, "sub_00010040", 8)}}


def test_site_map_packs_every_function_in_order():
    reg = {"entries": {"xb:0x00010010": {"bin": "xb", "va": "0x00010010", "size": 32, "symbol": "Car::Honk",
                                         "what": "Sounds the car's horn.", "verified_at": "2026-11-27 01:00:00"}}}
    names = {"xb:0x00010040": {"name": "Car::Stop"}}
    m = RO.site_map(reg, _known(), names)
    x = m["bins"]["xb"]
    vas, at = [], x["start"]
    for d in x["d"]:
        at += d
        vas.append(at)
    assert vas == [0x10000, 0x10010, 0x10040]
    assert x["s"] == [16, 32, 8]
    assert x["m"] == "010"
    assert x["names"] == {"1": "Car::Honk"}          # the matched name; sub_<its own address> is left out
    assert x["better"] == {"2": "Car::Stop"}
    assert x["what"] == {"1": "Sounds the car's horn."}
    assert m["updated_at"] == "2026-11-27 01:00:00"


def test_site_map_keeps_a_placeholder_for_another_address():
    known = {"xb": {0x10000: {"symbol": "sub_00020000", "size": 4}}}
    assert RO.site_map({"entries": {}}, known)["bins"]["xb"]["names"] == {"0": "sub_00020000"}


def test_write_site_map_keeps_the_committed_map_of_missing_programs(tmp_path):
    docs = tmp_path / "docs"
    docs.mkdir()
    (docs / "map.json").write_text(json.dumps({"bins": {"ps2": {"label": "old", "start": 0, "d": [0], "s": [4], "m": "0"}}}),
                                   encoding="utf-8")
    assert RO.write_site_map({"entries": {}}, docs, _known())
    m = json.loads((docs / "map.json").read_text(encoding="utf-8"))
    assert set(m["bins"]) == {"xb", "ps2"} and m["bins"]["ps2"]["label"] == "old"
    assert not RO.write_site_map({"entries": {}}, docs, _known())          # unchanged: not written again
    assert not RO.write_site_map({"entries": {}}, docs, {})                 # no function list: left alone


def test_committed_map_matches_the_address_order_files():
    """docs/map.json is what the committed files make (check_repo.py compares it too); its counts are the files'."""
    m = json.loads((ROOT / "docs" / "map.json").read_text(encoding="utf-8"))
    for b, (fname, _f, _l) in RO.BIN_INFO.items():
        if b not in RO.MAP_BINS:
            continue
        head = (ROOT / "reconstructed_src" / fname).read_text(encoding="utf-8", errors="replace")[:900]
        got = re.search(r"PROGRESS: ([\d,]+) of ([\d,]+) functions", head)
        assert got, fname
        done, total = (int(g.replace(",", "")) for g in got.groups())
        assert len(m["bins"][b]["s"]) == total and m["bins"][b]["m"].count("1") == done, b


# --------------------------------------------------------------------------- badge

def test_badge_shows_the_share_by_size():
    svg = RO.badge_svg({"verified": {"bytes": 250}, "queue": {"bytes": 750}})
    assert svg.startswith("<svg") and "25.0% of the code" in svg and 'role="img"' in svg
    assert "0.0% of the code" in RO.badge_svg({})


def test_committed_badge_matches_progress():
    prog = json.loads((ROOT / "reports" / "progress.json").read_text(encoding="utf-8"))
    assert (ROOT / "docs" / "badge.svg").read_text(encoding="utf-8") == RO.badge_svg(prog)


def test_sitemap_lists_the_hub_pages():
    xml = RO.sitemap_xml({"entries": {}})
    for page in ("game.html", "explore.html", "versions.html", "join.html"):
        assert RO.SITE + page in xml


# --------------------------------------------------------------------------- the pages' links

class Links(HTMLParser):
    def __init__(self):
        super().__init__()
        self.links, self.blank = [], []

    def handle_starttag(self, tag, attrs):
        a = dict(attrs)
        if tag == "a" and a.get("href"):
            self.links.append(a["href"])
            if a.get("target") == "_blank":
                self.blank.append(a.get("rel") or "")
        if tag in ("script", "img", "link") and (a.get("src") or a.get("href")):
            self.links.append(a.get("src") or a.get("href"))


@pytest.mark.parametrize("page", ["game.html", "explore.html", "index.html", "versions.html", "function.html", "404.html"])
def test_pages_link_only_to_files_that_exist(page):
    p = Links()
    p.feed((ROOT / "docs" / page).read_text(encoding="utf-8"))
    for href in p.links:
        if re.match(r"^(https?:|mailto:|#|data:)", href) or href in ("./", "/"):
            continue
        path = href.split("#", 1)[0].split("?", 1)[0].lstrip("/").lstrip("./")
        assert (ROOT / "docs" / path).exists(), f"{page}: {href}"
    for rel in p.blank:                                   # every new-tab link keeps the opener away
        assert "noopener" in rel, page


def test_hub_pages_have_no_inline_script():
    """The site's Content-Security-Policy refuses inline scripts and on*= handlers."""
    for page in ("game.html", "explore.html"):
        html = (ROOT / "docs" / page).read_text(encoding="utf-8")
        assert not re.search(r"<script(?![^>]*\bsrc=)[^>]*>", html), page
        assert not re.search(r"\son[a-z]+=", html), page


def test_every_page_links_the_hub():
    for page in ("index.html", "game.html", "explore.html", "versions.html", "function.html"):
        html = (ROOT / "docs" / page).read_text(encoding="utf-8")
        assert 'href="explore.html"' in html, page
    for page in ("index.html", "explore.html", "versions.html"):
        assert 'href="game.html"' in (ROOT / "docs" / page).read_text(encoding="utf-8"), page


# --------------------------------------------------------------------------- the Explore page in a browser

sync_api = pytest.importorskip("playwright.sync_api")
expect = sync_api.expect


@pytest.fixture(scope="module")
def explore_site(tmp_path_factory):
    from test_site_e2e import serve
    d = tmp_path_factory.mktemp("explore")
    for f in ("explore.html", "game.html", "function.html", "favicon.svg", "badge.svg", "_headers"):
        shutil.copy2(ROOT / "docs" / f, d / f)
    for a in ("js", "fonts"):
        shutil.copytree(ROOT / "docs" / a, d / a)
    reg = {"entries": {"xb:0x00010010": {"bin": "xb", "va": "0x00010010", "size": 32, "symbol": "Car::Honk",
                                         "what": "Sounds the car's horn."}}}
    known = _known()
    known["pc"] = {0x401000: {"symbol": "sub_00401000", "size": 64}}
    (d / "map.json").write_text(json.dumps(RO.site_map(reg, known, {"xb:0x00010040": {"name": "Car::Stop"}})),
                                encoding="utf-8")
    srv, url = serve(d)
    yield url
    srv.shutdown()


def test_explore_page_draws_searches_and_picks(explore_site):
    with sync_api.sync_playwright() as p:
        b = launch_chromium(p)
        page = b.new_page(viewport={"width": 1200, "height": 900})
        errors = []
        page.on("pageerror", lambda e: errors.append(str(e)))
        page.on("console", lambda m: errors.append(m.text) if m.type == "error" else None)
        page.goto(explore_site + "explore.html")
        page.wait_for_selector("#explore:not([hidden])")
        assert page.locator("#tabs .tab").count() == 2                       # Xbox and PC: only what the map has
        assert "1 of 3 functions" in page.inner_text("#stats")
        assert page.locator("#rows .row").count() == 3
        # the map is drawn: some red (rebuilt) pixels
        red = page.evaluate("""() => { const c = document.getElementById('map'), x = c.getContext('2d');
            const d = x.getImageData(0, 0, c.width, c.height).data; let n = 0;
            for (let i = 0; i < d.length; i += 4) if (d[i] === 234 && d[i+1] === 68) n++; return n; }""")
        assert red > 0
        # search by what it does, by a name from names.json, by an address inside a function
        page.fill("#q", "horn")
        expect(page.locator("#rows .row")).to_have_count(1)        # the page's CSP refuses eval: no wait_for_function
        assert "Car::Honk" in page.inner_text("#rows")
        assert "q=horn" in page.url
        page.fill("#q", "stop")
        expect(page.locator("#rows")).to_contain_text("Car::Stop")
        page.fill("#q", "0x10044")
        expect(page.locator("#rows .row")).to_have_count(1)
        assert "sub_00010040" in page.inner_text("#rows")
        page.fill("#q", "")
        page.select_option("#state", "0")
        expect(page.locator("#rows .row")).to_have_count(2)
        # a function still to do: the command that starts it
        page.click("#random")
        assert "python portal/agent.py packet xb 0x000100" in page.inner_text("#pick")
        # one square each, and a rebuilt function's link
        page.select_option("#state", "")
        page.click("#by-count")
        assert "map=count" in page.url
        page.locator("#rows .row button.loc").nth(1).click()
        assert "function.html?f=xb%3A0x00010010" in page.inner_html("#pick")
        # the address in the link comes back
        page.goto(explore_site + "explore.html?v=pc&f=0x00401000")
        page.wait_for_selector("#pick:not([hidden])")
        assert "0x00401000" in page.inner_text("#pick") and "agent.py packet pc" in page.inner_text("#pick")
        assert not errors, errors
        b.close()


def test_explore_page_says_when_the_map_is_missing(tmp_path):
    from test_site_e2e import serve
    for f in ("explore.html",):
        shutil.copy2(ROOT / "docs" / f, tmp_path / f)
    shutil.copytree(ROOT / "docs" / "js", tmp_path / "js")
    # the fallback is raw.githubusercontent.com, which a test can't reach: the page must still settle
    srv, url = serve(tmp_path)
    try:
        with sync_api.sync_playwright() as p:
            b = launch_chromium(p)
            page = b.new_page()
            page.route("https://raw.githubusercontent.com/**", lambda r: r.abort())
            page.goto(url + "explore.html")
            page.wait_for_selector("#missing:not([hidden])", timeout=15000)
            assert page.locator("#loading").is_hidden()
            b.close()
    finally:
        srv.shutdown()


def test_game_page_renders_on_a_phone(explore_site):
    with sync_api.sync_playwright() as p:
        b = launch_chromium(p)
        page = b.new_page(viewport={"width": 390, "height": 844})
        page.goto(explore_site + "game.html")
        # nothing wider than the screen
        assert page.evaluate("document.documentElement.scrollWidth") <= 390
        assert page.locator(".card").count() >= 18
        b.close()
