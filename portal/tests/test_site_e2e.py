"""
The public website (docs/index.html) in a real browser, served the way Cloudflare Pages serves it:
the page plus data/ copied from reports/. Also checks the fallbacks: no data/ folder, and a host that
answers unknown paths with the HTML page (single-page-app routing).
"""
import json
import shutil
import threading
from functools import partial
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer

import pytest

from conftest import PORTAL, ROOT, launch_chromium

sync_api = pytest.importorskip("playwright.sync_api")

# A fixed sample of verified functions (the live registry was reset to 0 on 2026-11-08 and starts empty).
FIX = PORTAL / "tests" / "fixtures" / "site"
REG = json.loads((FIX / "verified_registry.json").read_text(encoding="utf-8"))
PROG = json.loads((FIX / "progress.json").read_text(encoding="utf-8"))


# Everything the Cloudflare build serves from docs/ besides data/.
STATIC = ("index.html", "404.html", "versions.html", "feed.xml", "favicon.svg", "favicon-32.png", "apple-touch-icon.png", "og.jpg",
          "robots.txt", "sitemap.xml")
SITE_URL = "https://scarface-decomp.pages.dev/"


class Quiet(SimpleHTTPRequestHandler):
    def log_message(self, *a):
        pass


class Cors(Quiet):
    """Like raw.githubusercontent.com: any origin may read the files."""

    def end_headers(self):
        self.send_header("Access-Control-Allow-Origin", "*")
        super().end_headers()


class SpaFallback(Quiet):
    """Unknown paths get index.html with 200, as single-page-app hosting does."""

    def send_error(self, code, message=None, explain=None):
        if code == 404:
            body = (self.directory_path / "index.html").read_bytes()
            self.send_response(200)
            self.send_header("Content-Type", "text/html")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)
            return
        super().send_error(code, message, explain)


def serve(directory, handler=Quiet):
    h = partial(handler, directory=str(directory))
    if handler is SpaFallback:
        SpaFallback.directory_path = directory
    srv = ThreadingHTTPServer(("127.0.0.1", 0), h)
    threading.Thread(target=srv.serve_forever, daemon=True).start()
    return srv, f"http://127.0.0.1:{srv.server_address[1]}/"


@pytest.fixture(scope="module")
def site(tmp_path_factory):
    """docs/ + data/ as the Cloudflare build produces it."""
    d = tmp_path_factory.mktemp("site")
    for f in STATIC:
        shutil.copy2(ROOT / "docs" / f, d / f)
    (d / "data").mkdir()
    for f in ("progress.json", "verified_registry.json"):
        shutil.copy2(FIX / f, d / "data" / f)
    srv, url = serve(d)
    yield d, url
    srv.shutdown()


@pytest.fixture(scope="module")
def browser():
    with sync_api.sync_playwright() as p:
        b = launch_chromium(p)
        yield b
        b.close()


def open_page(browser, url, viewport=(1280, 900)):
    ctx = browser.new_context(viewport={"width": viewport[0], "height": viewport[1]})
    ctx.route("https://fonts.googleapis.com/**", lambda r: r.abort())
    ctx.route("https://fonts.gstatic.com/**", lambda r: r.abort())
    pg = ctx.new_page()
    errors = []
    pg.on("pageerror", lambda e: errors.append(str(e)))
    pg.on("console", lambda m: errors.append(m.text) if m.type == "error" and "fonts.g" not in m.text
          and "Failed to load resource" not in m.text else None)
    pg.goto(url)
    pg.errors = errors
    return ctx, pg


def test_scoreboard_and_progress(site, browser):
    _, url = site
    ctx, pg = open_page(browser, url)
    pg.wait_for_function("document.getElementById('data-status').textContent.includes('latest deploy')")
    v = PROG["verified"]
    total = v["total"] + PROG["queue"]["total"]
    assert pg.text_content("#sb-verified") == f"{v['total']:,}"
    assert pg.text_content("#sb-total") == f"{total:,}"
    share = v["total"] / total * 100
    assert pg.text_content("#claim") == f"The world is {share:.1f}% yours." if share >= 10 else \
        pg.text_content("#claim") == f"The world is {share:.2f}% yours."
    assert pg.text_content("#sb-pc") == f"{v['pc']:,}" and pg.text_content("#sb-xb") == f"{v['xb']:,}"
    assert "13.10.3052" in pg.text_content("#sb-compiler")
    assert pg.locator("#buckets .bucket").count() == len(PROG["size_buckets"])
    assert pg.get_attribute("a.gh[data-repo-link]", "href") == "https://github.com/scarface-decomp/scarface_decomp"
    assert pg.get_attribute("a.gh:not([data-repo-link])", "href").startswith("https://discord.gg/")
    assert not pg.errors, pg.errors
    ctx.close()


def test_function_browser_search_filter_and_code(site, browser):
    _, url = site
    ctx, pg = open_page(browser, url)
    pg.wait_for_selector("#fn-list .fn")
    assert pg.text_content("#count").startswith(f"{len(REG['entries']):,} functions")
    assert pg.locator("#fn-list .fn").count() == 40                     # first page
    pg.click("#more")
    assert pg.locator("#fn-list .fn").count() == 80

    pg.fill("#q", "DriveThread::vfunc_00")
    pg.wait_for_function("document.getElementById('count').textContent.startsWith('1 function')")
    assert not pg.is_visible("#more")                                   # nothing more to show
    pg.click("#fn-list .fn-head")
    code = pg.text_content("#fn-list .fn pre")
    assert "DriveThread::vfunc_00" in code and "ResolveDescA" in code
    link = pg.get_attribute("#fn-list .fn-links a", "href")
    assert link.startswith("https://github.com/scarface-decomp/scarface_decomp/blob/main/reconstructed_src/")

    pg.fill("#q", "")
    pg.select_option("#bin", "pc")
    pg.wait_for_function(f"document.getElementById('count').textContent.startsWith('{PROG['verified']['pc']:,} functions')")
    pg.select_option("#sort", "size")
    first_size = pg.text_content("#fn-list .fn .fn-size")
    assert first_size == f"{max(e['size'] for e in REG['entries'].values() if e['bin'] == 'pc')} B"

    pg.fill("#q", "no-such-function-xyz")
    pg.wait_for_selector("#fn-list .empty")
    assert not pg.errors, pg.errors
    ctx.close()


def test_code_is_shown_as_text_not_html(site, browser):
    """Code contains < > & (templates, comparisons, address-of); it must never be parsed as HTML."""
    _, url = site
    key, entry = next((k, e) for k, e in REG["entries"].items() if "&DAT_" in e["code"])
    ctx, pg = open_page(browser, url)
    pg.wait_for_selector("#fn-list .fn")
    pg.fill("#q", entry["va"].lower())
    pg.wait_for_function("document.getElementById('count').textContent.startsWith('1 function')")
    pg.click("#fn-list .fn-head")
    assert pg.text_content("#fn-list .fn pre") == entry["code"].strip()
    assert pg.locator("#fn-list .fn pre *").count() == 0
    ctx.close()


def test_mobile_layout(site, browser):
    _, url = site
    ctx, pg = open_page(browser, url, viewport=(375, 812))
    pg.wait_for_selector("#fn-list .fn")
    width = pg.evaluate("document.documentElement.scrollWidth")
    assert width <= 376, f"page scrolls sideways on a phone ({width}px)"
    assert pg.is_visible("a.gh")
    pg.fill("#q", "DriveThread::vfunc_00")
    pg.wait_for_function("document.getElementById('count').textContent.startsWith('1 function')")
    pg.click("#fn-list .fn-head")
    box = pg.locator("#fn-list .fn-links a").bounding_box()
    assert box["x"] + box["width"] <= 375, "the GitHub link runs off the screen"
    ctx.close()


def test_falls_back_when_data_folder_is_missing(tmp_path, browser):
    """Without data/, the page goes to the next source. ?data= stands in for raw.githubusercontent.com
    here (it is only honoured on localhost)."""
    page_dir = tmp_path / "page"
    page_dir.mkdir()
    shutil.copy2(ROOT / "docs" / "index.html", page_dir / "index.html")
    data_dir = tmp_path / "data_src"
    data_dir.mkdir()
    for f in ("progress.json", "verified_registry.json"):
        shutil.copy2(FIX / f, data_dir / f)
    srv_page, page_url = serve(page_dir, SpaFallback)          # data/ answers with HTML + 200
    srv_data, data_url = serve(data_dir, Cors)
    local = page_url.replace("127.0.0.1", "localhost")
    try:
        # 1) SPA-style host, no data/: the HTML answer is not taken for data; with no other source it says so
        ctx, pg = open_page(browser, local + "?data=" + local + "data/")
        pg.wait_for_function("document.getElementById('data-status').classList.contains('err')")
        ctx.close()
        # 2) a working second source is used
        ctx, pg = open_page(browser, local + "?data=" + data_url)
        pg.wait_for_function("document.getElementById('data-status').textContent.includes('on GitHub')")
        assert pg.text_content("#sb-verified") == f"{PROG['verified']['total']:,}"
        ctx.close()
    finally:
        srv_page.shutdown()
        srv_data.shutdown()


def test_data_param_ignored_off_localhost(site, browser):
    """?data= must not let a link make the public site show someone else's numbers."""
    _, url = site
    ctx, pg = open_page(browser, url + "?data=https://example.invalid/")
    # served from 127.0.0.1 (not "localhost"): the parameter is ignored and data/ is used
    pg.wait_for_function("document.getElementById('data-status').textContent.includes('latest deploy')")
    ctx.close()


def test_live_reports_and_empty_start(tmp_path, browser):
    """The real reports/ files as the Cloudflare build copies them. Right after the reset that is 0%:
    the page must say so plainly and point newcomers at the help section."""
    reg = json.loads((ROOT / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    prog = json.loads((ROOT / "reports" / "progress.json").read_text(encoding="utf-8"))
    d = tmp_path / "site"
    (d / "data").mkdir(parents=True)
    shutil.copy2(ROOT / "docs" / "index.html", d / "index.html")
    for f in ("progress.json", "verified_registry.json"):
        shutil.copy2(ROOT / "reports" / f, d / "data" / f)
    srv, url = serve(d)
    try:
        ctx, pg = open_page(browser, url)
        pg.wait_for_function("document.getElementById('data-status').textContent.includes('latest deploy')")
        assert pg.text_content("#sb-verified") == f"{prog['verified']['total']:,}"
        assert pg.text_content("#sb-total") == f"{prog['verified']['total'] + prog['queue']['total']:,}"
        if not reg["entries"]:
            assert pg.text_content("#claim") == "The world is 0% yours."
            assert "Nothing rebuilt yet" in pg.text_content("#fn-list .empty")
            assert pg.get_attribute("#fn-list .empty a", "href") == "#help"
            assert "Your name could be first" in pg.text_content("#contrib-note")
        assert pg.evaluate("document.getElementById('claim').classList.contains('on')")
        assert not pg.errors, pg.errors
        ctx.close()
    finally:
        srv.shutdown()


def test_faq_opens_and_needs_no_script(site, browser):
    _, url = site
    ctx, pg = open_page(browser, url)
    q = pg.locator("#questions details").first
    assert not q.evaluate("d => d.open")
    q.locator("summary").click()
    assert q.evaluate("d => d.open") and pg.locator("#questions details[open] p").first.is_visible()
    ctx.close()


@pytest.mark.parametrize("width", [1280, 820, 375])
def test_table_of_contents(site, browser, width):
    """The contents bar lists every section at every width, its links land on the sections below the
    sticky bar, and it marks the section being read."""
    _, url = site
    ctx, pg = open_page(browser, url, viewport=(width, 800))
    pg.wait_for_selector("#fn-list .fn")
    links = pg.eval_on_selector_all("#toc a", "as => as.map(a => a.getAttribute('href'))")
    assert links == ["#how", "#progress", "#help", "#questions", "#functions", "#reference"]
    for href in links:
        assert pg.evaluate(f"!!document.getElementById('{href[1:]}')")
    assert pg.evaluate("document.documentElement.scrollWidth") <= width + 1
    pg.evaluate("document.documentElement.style.scrollBehavior = 'auto'")
    for href in ("#questions", "#progress"):
        pg.locator(f'#toc a[href="{href}"]').scroll_into_view_if_needed()
        pg.click(f'#toc a[href="{href}"]')
        pg.wait_for_function(f"document.querySelector('#toc a[href=\"{href}\"]').getAttribute('aria-current') === 'true'")
        bar = pg.evaluate("document.querySelector('.topbar').getBoundingClientRect().bottom")
        top = pg.evaluate(f"document.getElementById('{href[1:]}').getBoundingClientRect().top")
        assert bar - 2 <= top <= bar + 40, (href, bar, top)      # just below the bar, not hidden under it
    assert pg.errors == []
    ctx.close()


def _jpeg_size(data):
    """Width and height from a JPEG's start-of-frame marker (no imaging library needed)."""
    i = 2
    while i < len(data):
        marker, length = data[i + 1], int.from_bytes(data[i + 2:i + 4], "big")
        if marker in (0xC0, 0xC1, 0xC2):
            return int.from_bytes(data[i + 7:i + 9], "big"), int.from_bytes(data[i + 5:i + 7], "big")
        i += 2 + length
    raise AssertionError("no frame header in the JPEG")


def test_share_preview_icons_and_crawler_files(site, browser):
    """Links shared on Discord, Reddit or X show the preview image; icons and crawler files exist."""
    d, url = site
    ctx, pg = open_page(browser, url)
    meta = pg.evaluate("""() => Object.fromEntries(Array.from(document.querySelectorAll('meta[property], meta[name]'))
        .map(m => [m.getAttribute('property') || m.getAttribute('name'), m.content]))""")
    assert meta["og:url"] == SITE_URL
    assert pg.get_attribute('link[rel="canonical"]', "href") == SITE_URL
    assert meta["twitter:card"] == "summary_large_image"
    for key in ("og:image", "twitter:image"):
        assert meta[key].startswith(SITE_URL)
        name = meta[key][len(SITE_URL):]
        assert (d / name).exists(), name
    img = (d / meta["og:image"][len(SITE_URL):]).read_bytes()
    assert _jpeg_size(img) == (int(meta["og:image:width"]), int(meta["og:image:height"])) == (1200, 630)
    icons = pg.eval_on_selector_all('link[rel="icon"], link[rel="apple-touch-icon"]', "ls => ls.map(l => l.href)")
    assert len(icons) == 3
    for href in icons:
        r = pg.request.get(href)
        assert r.ok, href
    robots = (d / "robots.txt").read_text()
    assert f"Sitemap: {SITE_URL}sitemap.xml" in robots
    assert f"<loc>{SITE_URL}</loc>" in (d / "sitemap.xml").read_text()
    ctx.close()


def test_skip_link_moves_focus_to_the_content(site, browser):
    _, url = site
    ctx, pg = open_page(browser, url)
    pg.keyboard.press("Tab")
    assert pg.evaluate("document.activeElement.className") == "skip"
    box = pg.locator("a.skip").bounding_box()
    assert box["y"] >= 0, "the skip link stays off screen when focused"
    pg.keyboard.press("Enter")
    pg.wait_for_function("document.activeElement.id === 'top'")
    ctx.close()


def test_404_page(site, browser):
    _, url = site
    ctx, pg = open_page(browser, url + "404.html")
    assert "Ocean Drive" in pg.text_content("h1")
    assert pg.get_attribute("a.btn.primary", "href") == "/"
    assert pg.get_attribute('meta[name="robots"]', "content") == "noindex"
    assert pg.evaluate("document.documentElement.scrollWidth") <= 1281
    assert not pg.errors, pg.errors
    ctx.close()


@pytest.mark.parametrize("motion", ["no-preference", "reduce"])
def test_rage_mode_easter_egg(site, browser, motion):
    """Up up down down left right left right B A: a four-second neon sign, then the page is as it was."""
    _, url = site
    ctx = browser.new_context(viewport={"width": 1280, "height": 800}, reduced_motion=motion)
    ctx.route("https://fonts.g*/**", lambda r: r.abort())
    pg = ctx.new_page()
    errors = []
    pg.on("pageerror", lambda e: errors.append(str(e)))
    pg.goto(url)
    pg.wait_for_selector("#fn-list .fn")
    for k in ("ArrowUp", "ArrowUp", "ArrowDown", "ArrowDown", "ArrowLeft", "ArrowRight", "ArrowLeft", "ArrowRight", "b", "a"):
        pg.keyboard.press(k)
    pg.wait_for_selector(".rage-sign.on")
    assert "RAGE" in pg.text_content(".rage-sign")
    shaking = pg.evaluate("getComputedStyle(document.querySelector('main')).animationName")
    assert (shaking == "none") == (motion == "reduce")
    pg.wait_for_selector(".rage-sign", state="detached", timeout=7000)
    assert not pg.evaluate("document.querySelector('main').classList.contains('shake')")
    # typing the same letters in the search box must not set it off
    pg.click("#q")
    for k in ("ArrowUp", "ArrowUp", "ArrowDown", "ArrowDown", "ArrowLeft", "ArrowRight", "ArrowLeft", "ArrowRight", "b", "a"):
        pg.keyboard.press(k)
    pg.wait_for_timeout(300)
    assert pg.locator(".rage-sign").count() == 0
    assert not errors, errors
    ctx.close()


def test_reference_section_and_versions_page(tmp_path, browser):
    """The Reference section links the formats guide, the names, the versions page and the scripts; the
    versions page shows the comparison (from a made-up report), or how to make it when there is none."""
    d = tmp_path / "site"
    d.mkdir()
    for f in STATIC:
        shutil.copy2(ROOT / "docs" / f, d / f)
    srv, url = serve(d)
    try:
        ctx, pg = open_page(browser, url)
        refs = pg.eval_on_selector_all("#reference .refs a", "as => as.map(a => a.getAttribute('href'))")
        assert refs[2] == "versions.html" and any(h.endswith("docs/FORMATS.md") for h in refs)
        assert any(h.endswith("docs/NAMES.md") for h in refs)
        pg.goto(url + "versions.html")
        pg.wait_for_selector("#missing:not([hidden])")               # no report on this made-up site yet
        assert "version_report.py --scan" in pg.text_content("#missing")

        report = {"schema": "scarface_versions_v1", "generated": "2026-11-10",
                  "kinds": {"sounds": "Sounds", "models": "Models", "videos": "Videos", "other": "Other"},
                  "versions": [{"id": "xbox", "label": "Xbox", "files": 3, "bytes": 3000, "only": 1, "changed": 1, "shared": 1, "kinds": {}},
                               {"id": "ps2", "label": "PS2", "files": 2, "bytes": 2048, "only": 1, "changed": 1, "shared": 0, "kinds": {}}],
                  "only": {"xbox": [["media/intro.bik", 1000, "videos", "640x480 video"]],
                           "ps2": [["MOVIES/INTRO.PSS", 2000, "other", ""]]},
                  "changed_file": "versions-changed.json"}
        changed = {"schema": "scarface_versions_v1", "generated": "2026-11-10",
                   "changed": [["art/sound/rsd/1/hello.rsd", "sounds", "art/sound/music/hello.rsd",
                                [["xbox", 900, "Xbox ADPCM, 44,100 Hz, 5.1 surround"], ["ps2", 48, "PS2 ADPCM, 22,050 Hz, mono"]]]]}
        (d / "versions.json").write_text(json.dumps(report), encoding="utf-8")
        (d / "versions-changed.json").write_text(json.dumps(changed), encoding="utf-8")
        pg.goto(url + "versions.html?again#ps2")          # a new load (a hash alone would not reload)
        pg.wait_for_selector("#report:not([hidden]) .row")
        assert pg.eval_on_selector_all("#summary th", "ths => ths.map(t => t.textContent)") == ["Xbox", "PS2"]
        assert pg.text_content("#rows .row .p") == "MOVIES/INTRO.PSS"           # the tab from the address
        pg.click(".tab:has-text('Xbox')")
        assert pg.text_content("#rows .row .p") == "media/intro.bik" and "640x480" in pg.text_content("#rows .row .d")
        pg.select_option("#what", "changed")
        pg.wait_for_selector("#rows .row ul")
        assert "PS2: 48 bytes, PS2 ADPCM" in pg.text_content("#rows .row ul")
        assert pg.text_content("#rows .row .d") == "art/sound/music/hello.rsd"
        pg.fill("#q", "music/hello")
        pg.wait_for_function("document.getElementById('count').textContent.startsWith('1 file')")
        pg.fill("#q", "nothing like this")
        pg.wait_for_function("document.getElementById('count').textContent.startsWith('0 files')")
        assert not pg.errors, pg.errors
        ctx.close()
    finally:
        srv.shutdown()


def test_good_first_functions_on_the_site(tmp_path, browser):
    """Start helping lists a few good first functions from progress.json; without any, nothing shows."""
    d = tmp_path / "site"
    d.mkdir()
    for f in STATIC:
        shutil.copy2(ROOT / "docs" / f, d / f)
    (d / "data").mkdir()
    prog = dict(PROG, good_first=[{"id": "xb_00011170", "bin": "xb", "va": "0x00011170", "symbol": "sub_00011170", "size": 1,
                                   "why": "it was matched before the reset, so it can be done", "kind": "matched_before"},
                                  {"id": "pc_006DE000", "bin": "pc", "va": "PC 0x006DE000", "symbol": "Obj::vfunc_02", "size": 6,
                                   "why": "the game's class information names it", "kind": "named"}])
    (d / "data" / "progress.json").write_text(json.dumps(prog), encoding="utf-8")
    shutil.copy2(FIX / "verified_registry.json", d / "data" / "verified_registry.json")
    srv, url = serve(d)
    try:
        ctx, pg = open_page(browser, url)
        pg.wait_for_selector("#good-first-box:not([hidden]) li")
        rows = pg.eval_on_selector_all("#good-first li", "ls => ls.map(l => l.innerText.replace(/\\s+/g, ' ').trim())")
        assert rows[0].startswith("sub_00011170 Xbox, 1 byte it was matched before") and "PC, 6 bytes" in rows[1]
        assert pg.get_attribute('link[rel="alternate"]', "href") == "feed.xml"
        assert pg.request.get(url + "feed.xml").ok
        ctx.close()
        ctx, pg = open_page(browser, url.replace("127.0.0.1", "localhost"))   # the fixture has no list
        (d / "data" / "progress.json").write_text(json.dumps(PROG), encoding="utf-8")
        pg.reload()
        pg.wait_for_selector("#fn-list .fn")
        assert pg.is_hidden("#good-first-box")
        assert not pg.errors, pg.errors
        ctx.close()
    finally:
        srv.shutdown()
