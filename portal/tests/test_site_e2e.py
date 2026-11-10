"""
The public website (docs/index.html) in a real browser, served the way Cloudflare Pages serves it:
the page plus data/ copied from reports/. Also checks the fallbacks: no data/ folder, and a host that
answers unknown paths with the HTML page (single-page-app routing).
"""
import json
import re
import shutil
import threading
import time
from functools import partial
from pathlib import Path
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer

import pytest

from conftest import PORTAL, ROOT, launch_chromium

import registry_outputs as RO

sync_api = pytest.importorskip("playwright.sync_api")

# A fixed sample of verified functions (the live registry was reset to 0 on 2026-11-08 and starts empty).
FIX = PORTAL / "tests" / "fixtures" / "site"
REG = json.loads((FIX / "verified_registry.json").read_text(encoding="utf-8"))
PROG = json.loads((FIX / "progress.json").read_text(encoding="utf-8"))


# Everything the Cloudflare build serves from docs/ besides data/.
STATIC = ("index.html", "404.html", "versions.html", "function.html", "feed.xml", "favicon.svg", "favicon-32.png", "apple-touch-icon.png", "og.jpg",
          "robots.txt", "sitemap.xml")
# Folders and files every page needs beside it: its script, the fonts, and the headers Cloudflare adds.
ASSETS = ("js", "fonts", "_headers")
SITE_URL = "https://scarface-decomp.pages.dev/"


def copy_docs(d, names=STATIC, headers=True):
    """docs/ files into d, with the script and fonts folders. headers=False leaves out _headers, for tests
    that read data from a stand-in address the site's Content-Security-Policy (rightly) doesn't allow."""
    for f in names:
        shutil.copy2(ROOT / "docs" / f, d / f)
    for a in ASSETS if headers else ASSETS[:2]:
        src = ROOT / "docs" / a
        if src.is_dir():
            shutil.copytree(src, d / a, dirs_exist_ok=True)
        else:
            shutil.copy2(src, d / a)


def put_list(d, reg):
    """functions.json beside the page, as registry_outputs.py makes it from this registry: no code, and each
    function's file and lines on GitHub."""
    gen = d.parent / (d.name + "-generated")
    (gen / "reconstructed_src").mkdir(parents=True, exist_ok=True)
    RO.write_outputs(reg, gen / "reconstructed_src")
    shutil.copy2(gen / "docs" / "functions.json", d / "functions.json")


def cloudflare_headers(directory, path):
    """The headers docs/_headers gives this path, the way Cloudflare Pages applies them."""
    f = directory / "_headers"
    if not f.exists():
        return []
    out, rule = [], None
    for line in f.read_text(encoding="utf-8").splitlines():
        if not line.strip() or line.lstrip().startswith("#"):
            continue
        if not line[0].isspace():
            rule = line.strip()
            continue
        pat = rule.rstrip("*")
        if rule == path or (rule.endswith("*") and path.startswith(pat)):
            k, v = line.strip().split(":", 1)
            out.append((k.strip(), v.strip()))
    return out


class Quiet(SimpleHTTPRequestHandler):
    def log_message(self, *a):
        pass

    def end_headers(self):
        for k, v in cloudflare_headers(Path(self.directory), self.path.split("?", 1)[0]):
            if k.lower() != "strict-transport-security":
                self.send_header(k, v)
        super().end_headers()


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
    copy_docs(d)
    (d / "data").mkdir()
    shutil.copy2(FIX / "progress.json", d / "data" / "progress.json")
    put_list(d, REG)
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
    # Playwright's wait_for_function() runs its check with eval, which the site's policy (rightly) refuses, so
    # these tests set the policy aside; test_security_headers_hold_on_every_page checks every page under it.
    ctx = browser.new_context(viewport={"width": viewport[0], "height": viewport[1]}, bypass_csp=True)
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
    assert pg.locator("#fn-list .fn pre").count() == 0                     # the code is on GitHub, not here
    link = pg.get_attribute("#fn-list .fn-links a.code-link", "href")
    assert re.match(r"^https://github\.com/scarface-decomp/scarface_decomp/blob/main/reconstructed_src/pc/core/DriveThread\.cpp#L\d+-L\d+$", link), link

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


def test_the_list_has_no_code_and_points_at_each_functions_lines(tmp_path):
    """docs/functions.json, the site's list: every rebuilt function, none of their code (that stays on GitHub), and
    for each the file and lines its block takes in the generated sources, which is where the site links."""
    d = tmp_path / "site"
    d.mkdir()
    put_list(d, REG)
    data = json.loads((d / "functions.json").read_text(encoding="utf-8"))
    assert set(data["entries"]) == set(REG["entries"])
    assert not any("code" in e or "match" in e for e in data["entries"].values())
    gen = tmp_path / "site-generated"
    for key, e in list(data["entries"].items())[:40]:
        lines = (gen / e["file"]).read_text(encoding="utf-8").split("\n")
        first, last = e["lines"]
        block = lines[first - 1:last]
        assert block[0].startswith("// =====") and block[1] == f"// [VERIFIED] {REG['entries'][key]['symbol']} ({e['va']}, {e['size']} B)"
        assert block[-1].strip() == REG["entries"][key]["code"].strip().split("\n")[-1].strip()
    sym = next(e for e in data["entries"].values() if e["symbol"] == "CollisionBehaviourTypeGroup::vfunc_00")
    assert sym["refs"] == ["DAT_004191A0"]                                    # what its code uses, not itself
    assert len((d / "functions.json").read_bytes()) < len((FIX / "verified_registry.json").read_bytes())


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
    box = pg.locator("#fn-list .fn-links a:not(.own)").bounding_box()
    assert box["x"] + box["width"] <= 375, "the GitHub link runs off the screen"
    ctx.close()


def test_falls_back_when_data_folder_is_missing(tmp_path, browser):
    """Without data/, the page goes to the next source. ?data= stands in for raw.githubusercontent.com
    here (it is only honoured on localhost)."""
    page_dir = tmp_path / "page"
    page_dir.mkdir()
    copy_docs(page_dir, ("index.html",), headers=False)
    data_dir = tmp_path / "data_src"
    data_dir.mkdir()
    shutil.copy2(FIX / "progress.json", data_dir / "progress.json")
    put_list(data_dir, REG)
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
    copy_docs(d, ("index.html",))
    shutil.copy2(ROOT / "reports" / "progress.json", d / "data" / "progress.json")
    shutil.copy2(ROOT / "docs" / "functions.json", d / "functions.json")          # the committed list
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


SITE_PAGES = ("index.html", "function.html", "versions.html", "404.html")


def test_pages_have_no_inline_script_or_google_fonts():
    """The Content-Security-Policy in docs/_headers runs only the site's own script files, so a <script>
    with code in it, or an onclick= attribute, would silently stop working on the live site."""
    for page in SITE_PAGES:
        html = (ROOT / "docs" / page).read_text(encoding="utf-8")
        assert not re.search(r"<script(?![^>]*\bsrc=)[^>]*>", html), f"{page}: inline <script> (move it to docs/js/)"
        assert not re.search(r"<[a-zA-Z][^>]*\son[a-z]+\s*=", html), f"{page}: inline event handler (use addEventListener)"
        assert "fonts.googleapis" not in html and "fonts.gstatic" not in html, f"{page}: fonts come from docs/fonts/"
        for src in re.findall(r'<script[^>]*\bsrc="([^"]+)"', html):
            assert (ROOT / "docs" / src.lstrip("/")).is_file(), f"{page}: {src} is missing"
    css = (ROOT / "docs" / "fonts" / "fonts.css").read_text(encoding="utf-8")
    for name in re.findall(r"url\(([^)]+)\)", css):
        assert (ROOT / "docs" / "fonts" / name).read_bytes()[:4] == b"wOF2", name
    for lic in ("OFL-anton.txt", "OFL-josefin-sans.txt", "OFL-marcellus.txt"):
        assert "SIL OPEN FONT LICENSE" in (ROOT / "docs" / "fonts" / lic).read_text(encoding="utf-8")


def test_security_headers_hold_on_every_page(site, browser):
    """Served with docs/_headers applied, as Cloudflare does: each page works with nothing refused by the
    policy, the fonts load from the site itself, and nothing is fetched from Google."""
    d, url = site
    rules = dict(cloudflare_headers(d, "/index.html"))
    csp = rules["Content-Security-Policy"]
    for part in ("default-src 'self'", "script-src 'self';", "frame-ancestors 'none'", "object-src 'none'",
                 "base-uri 'none'", "connect-src 'self' https://raw.githubusercontent.com"):
        assert part in csp, part
    assert "unsafe-inline" not in csp.split("script-src", 1)[1].split(";", 1)[0]
    assert rules["X-Frame-Options"] == "DENY" and rules["X-Content-Type-Options"] == "nosniff"
    key = next(iter(REG["entries"]))
    for page in ("", "function.html?f=" + key.replace("_", ":0x", 1).upper().replace("0X", "0x"), "versions.html", "404.html"):
        ctx = browser.new_context()
        outside = []
        ctx.on("request", lambda r: outside.append(r.url) if not r.url.startswith(url) and not r.url.startswith("data:") else None)
        ctx.add_init_script("window.__refused = []; document.addEventListener('securitypolicyviolation',"
                            " e => window.__refused.push(e.violatedDirective + ' ' + e.blockedURI));")
        pg = ctx.new_page()
        errors = []
        pg.on("pageerror", lambda e: errors.append(str(e)))
        resp = pg.goto(url + page)
        assert "frame-ancestors 'none'" in resp.headers.get("content-security-policy", "")
        pg.wait_for_load_state("networkidle")
        if page == "":                                     # the script ran: the numbers are on the page
            for _ in range(50):
                if "latest deploy" in (pg.text_content("#data-status") or ""):
                    break
                time.sleep(0.1)
            assert pg.text_content("#sb-verified") == f"{PROG['verified']['total']:,}"
        fams = pg.evaluate("document.fonts.ready.then(() => [...document.fonts].filter(f => f.status === 'loaded').map(f => f.family))")
        assert pg.evaluate("window.__refused") == [], (page, pg.evaluate("window.__refused"))
        assert not errors, (page, errors)
        assert not [u for u in outside if "fonts.g" in u], outside
        assert any("Josefin Sans" in f for f in fams), (page, fams)
        ctx.close()


def test_site_refuses_to_be_framed(site, browser):
    """Another site can't show these pages inside a frame of its own (clickjacking, look-alike pages)."""
    _, url = site
    ctx = browser.new_context()
    pg = ctx.new_page()
    pg.set_content(f'<iframe src="{url}" width="800" height="600"></iframe>')
    pg.wait_for_timeout(500)
    child = pg.frames[1]
    assert not child.url.startswith(url) or "Scarface" not in (child.evaluate("document.title") if child.url.startswith(url) else "")
    ctx.close()


@pytest.mark.parametrize("motion", ["no-preference", "reduce"])
def test_rage_mode_easter_egg(site, browser, motion):
    """Up up down down left right left right B A: a four-second neon sign, then the page is as it was."""
    _, url = site
    ctx = browser.new_context(viewport={"width": 1280, "height": 800}, reduced_motion=motion, bypass_csp=True)
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
    copy_docs(d)
    srv, url = serve(d)
    try:
        ctx, pg = open_page(browser, url)
        refs = pg.eval_on_selector_all("#reference .refs a", "as => as.map(a => a.getAttribute('href'))")
        assert refs[2] == "versions.html" and any(h.endswith("docs/FORMATS.md") for h in refs)
        assert any(h.endswith("docs/NAMES.md") for h in refs)
        assert any(h.endswith("docs/FORMATS.md#maps") for h in refs) and any(h.endswith("#exporting-to-blender") for h in refs)
        ctx.route("https://raw.githubusercontent.com/**", lambda r: r.abort())   # nor in the repository
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
    copy_docs(d)
    (d / "data").mkdir()
    prog = dict(PROG, good_first=[{"id": "xb_00011170", "bin": "xb", "va": "0x00011170", "symbol": "sub_00011170", "size": 1,
                                   "why": "it was matched before the reset, so it can be done", "kind": "matched_before"},
                                  {"id": "pc_006DE000", "bin": "pc", "va": "PC 0x006DE000", "symbol": "Obj::vfunc_02", "size": 6,
                                   "why": "the game's class information names it", "kind": "named"}])
    (d / "data" / "progress.json").write_text(json.dumps(prog), encoding="utf-8")
    put_list(d, REG)
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


def test_matched_over_time_chart(tmp_path, browser):
    """Progress: a line per version with matches, from the restart to today, read by hovering, by the
    arrow keys, or as a table."""
    d = tmp_path / "site"
    d.mkdir()
    copy_docs(d)
    (d / "data").mkdir()
    reg = {"schema": REG["schema"], "reset": {"date": "2026-11-01"}, "entries": {}}
    for i, (b, day) in enumerate([("xb", 1), ("xb", 2), ("pc", 2), ("ps2", 3), ("xb", 3), ("proto", 1)]):
        reg["entries"][f"{b}:0x{i:08X}"] = {"bin": b, "va": f"0x{i:08X}", "size": 8, "symbol": f"sub_{i:08X}",
                                             "code": "void f() {}", "flags": "/O2", "verified_at": f"2026-11-0{day} 12:00:00"}
    put_list(d, reg)
    (d / "data" / "progress.json").write_text(json.dumps(PROG), encoding="utf-8")
    srv, url = serve(d)
    try:
        ctx, pg = open_page(browser, url)
        pg.wait_for_selector("#history:not([hidden]) path")
        assert pg.locator("#history-svg path").count() == 3
        assert pg.eval_on_selector_all("#history-legend li", "ls => ls.map(l => l.textContent)") == \
            ["Released game (Xbox + PC)", "PS2", "Xbox prototype"]
        pg.focus("#history-svg")
        pg.keyboard.press("Home")
        assert pg.text_content("#history-live") == "1 Nov 2026, Released game (Xbox + PC): 1, PS2: 0, Xbox prototype: 1"
        pg.keyboard.press("ArrowRight")
        pg.keyboard.press("ArrowRight")
        assert pg.text_content("#history-live") == "3 Nov 2026, Released game (Xbox + PC): 4, PS2: 1, Xbox prototype: 1"
        assert pg.is_visible("#history-tip")
        rows = pg.eval_on_selector_all("#history-table tbody tr", "rs => rs.map(r => [...r.cells].map(c => c.textContent))")
        assert rows[-1] == ["1 Nov 2026", "1", "0", "1"] and ["3 Nov 2026", "4", "1", "1"] in rows
        ticks = pg.eval_on_selector_all("#history-svg .tick", "ts => ts.map(t => t.textContent)")
        assert ticks[:5] == ["0", "1", "2", "3", "4"]                                # whole functions only
        assert not pg.errors, pg.errors
        ctx.close()
    finally:
        srv.shutdown()


def test_function_pages(site, browser):
    """Each rebuilt function has its own page: what's known about it, a link to its C++ on GitHub (its exact lines),
    what it uses, its neighbours, and a link from the main page's list."""
    _, url = site
    ctx, pg = open_page(browser, url)
    pg.wait_for_selector("#fn-list .fn")
    pg.fill("#q", "CollisionBehaviourTypeGroup::vfunc_00")
    pg.wait_for_function("document.getElementById('count').textContent.startsWith('1 function')")
    pg.click("#fn-list .fn-head")
    assert pg.get_attribute("#fn-list .fn-links a.own", "href") == "function.html?f=xb%3A0x000123B0"
    pg.click("#fn-list .fn-links a.own")
    pg.wait_for_selector("#fn:not([hidden])")
    assert pg.text_content("#name") == "vfunc_00" and pg.text_content("#cls") == "CollisionBehaviourTypeGroup::"
    assert pg.title().startswith("CollisionBehaviourTypeGroup::vfunc_00 (Xbox)")
    facts = dict(pg.eval_on_selector_all("#facts div", "ds => ds.map(d => [d.querySelector('dt').textContent, d.querySelector('dd').textContent])"))
    assert facts["Address"] == "0x000123B0" and facts["Size"] == "6 bytes" and facts["Version"] == "Xbox (default.xbe)"
    link = pg.get_attribute("#code-link", "href")
    assert re.match(r"^https://github\.com/scarface-decomp/scarface_decomp/blob/main/reconstructed_src/xbox/\w+/CollisionBehaviourTypeGroup\.cpp#L\d+-L\d+$", link), link
    assert re.match(r"^In reconstructed_src/xbox/\w+/CollisionBehaviourTypeGroup\.cpp, lines \d+\u2013\d+\.$", pg.text_content("#code-where"))
    assert pg.locator("#code").count() == 0                                  # no code on the site
    assert pg.text_content("#uses li code") == "DAT_004191A0"
    nxt = pg.get_attribute("#pager a.next", "href")
    assert nxt.startswith("function.html?f=xb%3A")
    pg.click("#pager a.next")
    pg.wait_for_function("document.getElementById('name').textContent !== 'vfunc_00'")
    pg.goto(url + "function.html?f=xb:0xDEADBEEF")
    pg.wait_for_selector("#missing:not([hidden])")
    assert not pg.errors, pg.errors
    ctx.close()
    ctx, pg = open_page(browser, url + "function.html?f=xb%3A0x000123B0", viewport=(375, 800))
    pg.wait_for_selector("#fn:not([hidden])")
    assert pg.evaluate("document.documentElement.scrollWidth") <= 376                 # nothing wider than a phone
    ctx.close()


def test_what_it_does_on_the_site(tmp_path, browser):
    """A function's plain-English line leads its page, shows in the list, and can be searched for."""
    d = tmp_path / "site"
    d.mkdir()
    copy_docs(d)
    (d / "data").mkdir()
    reg = json.loads(json.dumps(REG))
    reg["entries"]["xb:0x000123B0"].update(what="Says which collision group <b>this</b> is", what_by="Alice")
    put_list(d, reg)
    shutil.copy2(FIX / "progress.json", d / "data" / "progress.json")
    srv, url = serve(d)
    try:
        ctx, pg = open_page(browser, url)
        pg.wait_for_selector("#fn-list .fn")
        pg.fill("#q", "collision group")
        pg.wait_for_function("document.getElementById('count').textContent.startsWith('1 function')")
        pg.click("#fn-list .fn-head")
        assert pg.text_content("#fn-list .fn-what") == "Says which collision group <b>this</b> is"     # text, never HTML
        pg.goto(url + "function.html?f=xb%3A0x000123B0")
        pg.wait_for_selector("#fn:not([hidden])")
        assert pg.text_content("#what") == "Says which collision group <b>this</b> isIn plain English, by Alice"
        assert pg.get_attribute('meta[name="description"]', "content") == "Says which collision group <b>this</b> is"
        assert not pg.errors, pg.errors
        ctx.close()
    finally:
        srv.shutdown()
