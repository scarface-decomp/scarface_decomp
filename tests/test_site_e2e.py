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

from conftest import ROOT, launch_chromium

sync_api = pytest.importorskip("playwright.sync_api")

# A fixed sample of verified functions (the live registry was reset to 0 on 2026-11-08 and starts empty).
FIX = ROOT / "tests" / "fixtures" / "site"
REG = json.loads((FIX / "verified_registry.json").read_text(encoding="utf-8"))
PROG = json.loads((FIX / "progress.json").read_text(encoding="utf-8"))


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
    for f in ("index.html", "404.html"):
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
    assert pg.get_attribute("a.gh", "href") == "https://github.com/scarface-decomp/scarface_decomp"
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
