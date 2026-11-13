"""
End-to-end tests for portal/website_kit/index.html against portal/tools/mock_portal_api.py, in headless Chrome.
Run:  python3 -m pytest -q portal/tests/test_frontend_e2e.py
"""
import json
import os
import sys
import threading
import time
import urllib.request
from http.server import ThreadingHTTPServer

import pytest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools"))
import mock_portal_api as mock  # noqa: E402
from conftest import launch_chromium  # noqa: E402

playwright = pytest.importorskip("playwright.sync_api")

PORT = 8799
BASE = f"http://127.0.0.1:{PORT}/"


@pytest.fixture(scope="module")
def server():
    srv = ThreadingHTTPServer(("127.0.0.1", PORT), mock.Handler)
    th = threading.Thread(target=srv.serve_forever, daemon=True)
    th.start()
    yield
    srv.shutdown()


GF_FLAGS = ("gf_missing", "gf_interrupted", "no_blender", "no_ffmpeg", "model_error", "partial_city", "cant_show", "bad_glb",
            "porting", "no_fog")


def reset(lease_sec=900, no_login=False, legacy_claim=False, dme_browser_fail=False, **delays):
    flags = {k: delays.pop(k) for k in GF_FLAGS if k in delays}
    payload = {"delays": {"verify": 0.15, "ai": 0.25, "fast": 0.05, **delays}, "lease_sec": lease_sec,
               "no_login": no_login, "legacy_claim": legacy_claim, "dme_browser_fail": dme_browser_fail, **flags}
    req = urllib.request.Request(BASE + "__reset", data=json.dumps(payload).encode(),
                                 headers={"Content-Type": "application/json"}, method="POST")
    urllib.request.urlopen(req).read()


def calls(path=None):
    data = json.loads(urllib.request.urlopen(BASE + "__calls").read())
    return [c for c in data if path is None or c[0] == path]


def wait_for_calls(path, timeout=5.0):
    """The calls to path, waiting up to timeout seconds for the first: for requests the browser makes on its own
    time, such as an <audio> element fetching its sound after it appears."""
    end = time.monotonic() + timeout
    while True:
        found = calls(path)
        if found or time.monotonic() > end:
            return found
        time.sleep(0.05)


@pytest.fixture(scope="module")
def browser(server):
    with playwright.sync_playwright() as p:
        b = launch_chromium(p)
        yield b
        b.close()


@pytest.fixture
def page(browser):
    reset()
    ctx = browser.new_context(viewport={"width": 1440, "height": 1000}, bypass_csp=True)   # see test_page_runs_under_its_policy
    # No internet in CI: block Google Fonts so failures don't pollute the console.
    ctx.route("https://fonts.googleapis.com/**", lambda r: r.abort())
    ctx.route("https://fonts.gstatic.com/**", lambda r: r.abort())
    pg = ctx.new_page()
    errors = []
    pg.on("pageerror", lambda e: errors.append(str(e)))
    pg.on("console", lambda m: errors.append(m.text) if m.type == "error" and "fonts.g" not in m.text and "ERR_FAILED" not in m.text and "Failed to load resource" not in m.text else None)
    pg.errors = errors
    pg.goto(BASE + "#workbench")
    pg.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    wait_until_loaded(pg)
    yield pg
    assert not errors, errors
    ctx.close()


def wait_until_loaded(pg):
    """The startup screen covers the page (and makes it inert) until the first data is in."""
    pg.wait_for_function("!document.querySelector('.app-shell').hasAttribute('inert')")


def fresh_page(browser, viewport=None):
    ctx = browser.new_context(viewport=viewport or {"width": 1440, "height": 1000}, bypass_csp=True)
    ctx.route("https://fonts.googleapis.com/**", lambda r: r.abort())
    ctx.route("https://fonts.gstatic.com/**", lambda r: r.abort())
    pg = ctx.new_page()
    pg.errors = []
    pg.on("pageerror", lambda e: pg.errors.append(str(e)))
    return ctx, pg


def sign_in(pg, user="Tester", pin="1234"):
    pg.fill("#contrib-name", user)
    pg.fill("#contrib-pin", pin)
    pg.click("#auth-form-row button[type=submit]")
    pg.wait_for_selector("#auth-signed-in-row", state="visible")


def status(pg):
    return pg.text_content("#verify-status")


# --------------------------------------------------------------------------- #

def test_boot_header_and_links(page):
    assert "PORTAL ONLINE" in page.text_content("#server-status")
    assert page.text_content("#top-verified-value").startswith("0 / 200")
    page.wait_for_function("document.querySelector('a[data-repo-link]').href.includes('example-org')")
    hrefs = page.eval_on_selector_all("a[href]", "els => els.map(e => e.getAttribute('href'))")
    assert all(not h.startswith("[") for h in hrefs), hrefs
    assert any(h == "https://github.com/example-org/scarface_decomp" for h in hrefs)   # from /api/state repo_url
    assert any(h == "https://github.com/example-org/scarface_decomp/tree/main/reconstructed_src" for h in hrefs)
    icon = page.get_attribute("link[rel=icon]", "href")
    assert "xmlns='http://www.w3.org/2000/svg'" in icon
    assert page.text_content("#cnt-t1") == "50"


def test_no_founder_default_and_signin_required(page):
    assert page.input_value("#contrib-name") == ""
    assert page.is_enabled("#btn-step1-claim")
    page.click("#btn-step1-claim")
    assert "Sign in" in status(page)
    assert not calls("/api/claim")


def test_pin_never_in_localstorage(page):
    sign_in(page)
    ls = page.evaluate("JSON.stringify(localStorage)")
    ss = page.evaluate("JSON.stringify(sessionStorage)")
    assert "1234" not in ls
    assert "1234" in ss
    assert page.text_content("#auth-user-label") == "Tester"


def test_claim_keeps_editor_edits(page):
    sign_in(page)
    page.fill("#wb-editor", "// my own work\nint keep_me = 1;")
    page.click("#btn-step1-claim")
    page.wait_for_function("document.getElementById('btn-step1-claim').textContent.includes('Claimed by You')")
    assert "keep_me" in page.input_value("#wb-editor")
    assert page.is_enabled("#btn-step3-verify")


def test_verify_partial_and_compile_error(page):
    sign_in(page)
    page.click("#btn-step1-claim")
    page.wait_for_function("document.getElementById('btn-step1-claim').textContent.includes('Claimed by You')")
    page.fill("#wb-editor", "void f() { COMPILE_ERROR }")
    page.click("#btn-step3-verify")
    page.wait_for_selector("#compiler-err", state="visible")
    assert "C2143" in page.text_content("#compiler-err")
    page.fill("#wb-editor", "void f() { int a; }")
    page.click("#btn-step3-verify")
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('bytes matched')")
    assert page.is_visible("#diff-panel")
    assert "mismatch" in page.text_content("#wb-diff-summary")


def test_exact_match_promotes(page):
    sign_in(page)
    page.click("#btn-step1-claim")
    page.wait_for_function("document.getElementById('btn-step1-claim').textContent.includes('Claimed by You')")
    page.fill("#wb-editor", "void f() { /* MATCH_ALL */ }")
    page.focus("#wb-editor")
    page.keyboard.press("Control+Enter")
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('VERIFIED')")
    page.wait_for_function("document.getElementById('top-verified-value').textContent.startsWith('1 / 200')")
    assert "VERIFIED" in page.text_content(".queue-item.selected .status-pill")


def test_what_it_does(page):
    """A one-line plain-English description goes with the match, and a rebuilt function's can be changed."""
    sign_in(page)
    page.click("#btn-step1-claim")
    page.wait_for_function("document.getElementById('btn-step1-claim').textContent.includes('Claimed by You')")
    assert page.is_hidden("#wb-what-save") and "when it verifies" in page.text_content("#wb-what-note")
    page.fill("#wb-what", "  Turns the   headlights on ")
    page.fill("#wb-editor", "void f() { /* MATCH_ALL */ }")
    page.click("#btn-step3-verify")
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('VERIFIED')")
    assert [c for c in calls("/api/verify")][-1][1]["what"] == "Turns the   headlights on"
    page.wait_for_function("document.getElementById('wb-what-note').textContent.startsWith('Written by Tester')")
    assert page.input_value("#wb-what") == "Turns the headlights on"
    assert page.is_visible("#wb-what-save") and page.is_disabled("#wb-what-save")
    page.fill("#wb-what", "Turns the car's headlights on or off")
    assert page.is_enabled("#wb-what-save")
    page.click("#wb-what-save")
    page.wait_for_function("document.getElementById('verify-status').textContent.startsWith('Saved.')")
    assert calls("/api/describe")[-1][1]["what"] == "Turns the car's headlights on or off"
    assert page.is_disabled("#wb-what-save")


def test_switching_with_unsaved_edits_asks_first(page):
    page.fill("#wb-editor", "// unsaved")
    first_title = page.text_content("#wb-title")
    msgs = []
    page.once("dialog", lambda d: (msgs.append(d.message), d.dismiss()))
    page.click(".queue-item:nth-child(2)")
    page.wait_for_timeout(300)
    assert msgs and "unsaved" in msgs[0]
    assert page.text_content("#wb-title") == first_title
    assert page.input_value("#wb-editor") == "// unsaved"
    page.once("dialog", lambda d: d.accept())
    page.click(".queue-item:nth-child(2)")
    page.wait_for_function("!document.getElementById('wb-title').textContent.includes('Func0000')")


def test_paging_does_not_replace_loaded_function(page):
    page.fill("#wb-editor", "// work in progress")
    title = page.text_content("#wb-title")
    page.click("#btn-next-page")
    page.wait_for_function("document.getElementById('page-info').textContent.startsWith('Page 2')")
    page.wait_for_timeout(200)
    assert page.text_content("#wb-title") == title
    assert page.input_value("#wb-editor") == "// work in progress"


def test_search_is_debounced_and_ordered(page):
    before = len(calls("/api/queue"))
    page.click("#search-filter")
    page.keyboard.type("EasyFunc000", delay=20)
    page.wait_for_function("document.getElementById('queue-count').textContent === '4'")
    after = len(calls("/api/queue"))
    assert after - before <= 2, after - before
    syms = page.eval_on_selector_all(".q-sym-text", "els => els.map(e => e.textContent)")
    assert syms and all("EasyFunc000" in s for s in syms)


def test_ai_run_then_stop_mid_flight(page):
    reset(ai=1.5)
    page.reload()
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    sign_in(page)
    page.fill("#ai-key", "test-key")
    # pick a Hard function so the AI keeps going
    page.fill("#search-filter", "HardFunc0001")
    page.wait_for_function("document.getElementById('queue-count').textContent === '1'")
    page.once("dialog", lambda d: d.accept())
    page.click(".queue-item")
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('HardFunc0001')")
    page.click("#btn-step2-ai")
    page.wait_for_function("document.getElementById('btn-step2-ai').textContent.includes('AI Attempt')")
    page.click("#btn-step4-cancel")      # Stop & Save Now
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('Released claim')")
    assert page.is_enabled("#btn-step1-claim")
    assert "ai attempt" not in page.input_value("#wb-editor")   # no half-tested candidate left behind
    time.sleep(1.6)                      # let the aborted AI request's server side finish
    assert "Released claim" in status(page)
    assert len(calls("/api/cancel")) == 1


def test_batch_run_processes_whole_page(page):
    reset(ai=0.02, verify=0.02)
    page.reload()
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    sign_in(page)
    page.fill("#ai-key", "test-key")
    page.fill("#search-filter", "Func000")          # 10 functions: 0000-0009 (4 Easy, 6 Hard)
    page.wait_for_function("document.getElementById('queue-count').textContent === '10'")
    page.on("dialog", lambda d: d.accept())
    page.click("#btn-autopilot")
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('Batch finished')", timeout=60000)
    txt = status(page)
    assert "4 of 10" in txt, txt
    cancels = calls("/api/cancel")
    assert len(cancels) == 6, cancels                 # every unsolved function was released
    assert page.text_content("#btn-autopilot") == "Batch Run"


def test_hash_routing_and_back_button(page):
    page.click("#nav-leaderboard")
    assert page.evaluate("location.hash") == "#leaderboard"
    assert page.is_visible("#view-leaderboard")
    page.go_back()
    page.wait_for_function("document.getElementById('view-workbench').classList.contains('active')")
    assert page.get_attribute("#nav-workbench", "aria-current") == "page"


def test_mobile_drawer(browser):
    reset()
    ctx = browser.new_context(viewport={"width": 390, "height": 844}, bypass_csp=True)
    ctx.route("https://fonts.googleapis.com/**", lambda r: r.abort())
    ctx.route("https://fonts.gstatic.com/**", lambda r: r.abort())
    pg = ctx.new_page()
    errors = []
    pg.on("pageerror", lambda e: errors.append(str(e)))
    pg.goto(BASE)
    pg.wait_for_function("document.getElementById('server-status-text').textContent.includes('ONLINE')")
    wait_until_loaded(pg)
    assert not pg.is_visible("#nav-dashboard")
    pg.click("#nav-toggle")
    pg.wait_for_selector("#nav-dashboard", state="visible")
    pg.click("#nav-how")
    pg.wait_for_selector("#view-how", state="visible")
    pg.wait_for_timeout(300)
    assert not pg.is_visible("#nav-dashboard")
    width = pg.evaluate("document.documentElement.scrollWidth")
    assert width <= 392, width                       # no horizontal overflow
    assert not errors, errors
    ctx.close()


def test_script_upload_same_file_twice(page, tmp_path):
    f = tmp_path / "test.cso"
    f.write_bytes(b"\x01\x02\x03\x04" * 10)
    page.click("#nav-scripts")
    for n in (1, 2):
        page.set_input_files("#local-script-input", str(f))
        deadline = time.time() + 10
        while len(calls("/api/upload-script")) < n and time.time() < deadline:
            time.sleep(0.05)
        page.wait_for_function("document.getElementById('script-meta-title').textContent.includes('test.cso')")
    ups = calls("/api/upload-script")
    assert len(ups) == 2
    assert page.input_value("#local-script-input") == ""


def test_api_key_not_remembered_by_default(page):
    page.fill("#ai-key", "secret-key")
    assert "secret-key" not in page.evaluate("JSON.stringify(localStorage)")
    page.check("#ai-remember-key")
    assert "secret-key" in page.evaluate("JSON.stringify(localStorage)")


def post(path, body):
    req = urllib.request.Request(BASE + path.lstrip("/"), data=json.dumps(body).encode(),
                                 headers={"Content-Type": "application/json"}, method="POST")
    return json.loads(urllib.request.urlopen(req).read())


def test_lease_expiry_fires_once_and_keeps_code(page):
    reset(lease_sec=2)
    page.reload()
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    sign_in(page)
    page.click("#btn-step1-claim")
    page.wait_for_function("document.getElementById('btn-step1-claim').textContent.includes('Claimed by You')")
    page.fill("#wb-editor", "// typed during lease")
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('claim expired')", timeout=8000)
    n1 = len(calls("/api/task"))
    page.wait_for_timeout(3000)
    n2 = len(calls("/api/task"))
    assert n2 - n1 <= 1, (n1, n2)                     # no once-per-second polling
    assert page.input_value("#wb-editor") == "// typed during lease"
    assert page.is_enabled("#btn-step1-claim")


def test_claimed_by_someone_else_locks_buttons(page):
    post("/api/login", {"user": "Alice", "pin": "9"})
    post("/api/claim", {"id": "t0000", "user": "Alice", "pin": "9"})
    page.reload()
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func0000')")
    sign_in(page, "Bob", "7")
    assert "Claimed by Alice" in page.text_content("#btn-step1-claim")
    assert not page.is_enabled("#btn-step2-ai")
    assert not page.is_enabled("#btn-step3-verify")
    assert not page.is_enabled("#btn-step4-cancel")
    assert "Alice" in page.text_content(".queue-item.selected .status-pill")


def test_works_with_server_that_has_no_login_route(page):
    """portal/decomp_portal_server.py has no /api/login and answers ok:true to a claim it did not grant."""
    reset(no_login=True, legacy_claim=True)
    post("/api/claim", {"id": "t0001", "user": "Alice", "pin": "9"})
    page.reload()
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    sign_in(page, "Bob", "7")
    assert "checked when you claim" in page.text_content("#auth-status-msg")
    page.click("#btn-step1-claim")                                   # t0000 is free
    page.wait_for_function("document.getElementById('btn-step1-claim').textContent.includes('Claimed by You')")
    page.once("dialog", lambda d: d.accept())
    page.click(".queue-item:nth-child(2)")                           # t0001 belongs to Alice
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func0001')")
    assert not page.is_enabled("#btn-step1-claim")
    assert "Alice" in page.text_content("#btn-step1-claim")


def test_wrong_pin_signs_out(page):
    reset(no_login=True)
    post("/api/claim", {"id": "t0005", "user": "Carol", "pin": "1111"})   # registers Carol's PIN
    page.reload()
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    sign_in(page, "Carol", "2222")                                    # device-only sign-in succeeds
    page.click("#btn-step1-claim")
    page.wait_for_selector("#auth-form-row", state="visible")          # server rejected the PIN -> signed out
    assert "locked with a PIN" in page.text_content("#verify-status")


def test_decompme_button_creates_scratch_then_reopens_it(page):
    # No sign-in needed: anyone can look at a function on decomp.me.
    with page.context.expect_page() as info:
        page.click("#btn-decompme")
    tab = info.value
    tab.wait_for_url("**/scratch/mock1/claim?token=tokmock1")
    assert len(mock.SCRATCHES) == 1
    sent = mock.SCRATCHES[0]
    assert sent["compiler"] == "msvc7.1" and sent["platform"] == "win32" and sent["has_target_obj"]
    assert "starter for t0000" in sent["source_code"]
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('Opened on decomp.me')")
    page.wait_for_function("document.getElementById('btn-decompme').textContent.includes('My decomp.me')")
    assert [c for c in calls("/api/decompme") if c[1].get("slug") == "mock1"]
    tab.close()
    with page.context.expect_page() as info:                 # second click: same scratch, nothing new created
        page.click("#btn-decompme")
    info.value.wait_for_url("**/scratch/mock1")
    assert len(mock.SCRATCHES) == 1


def test_suggest_a_name_link(page):
    """Under the function's name: a GitHub issue with the function filled in, for suggesting a name."""
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    href = page.get_attribute("#wb-name a", "href")
    assert "/issues/new?" in href and "labels=name" in href
    from urllib.parse import parse_qs, urlparse
    q = parse_qs(urlparse(href).query)
    title = page.text_content("#wb-title")
    assert q["title"][0].startswith("Name for ") and q["title"][0].split()[-1] in title
    assert "Suggested name:" in q["body"][0]
    assert page.get_attribute("#wb-name a", "target") == "_blank"


def test_good_first_functions_list(page):
    """The queue's "Good first functions" choice lists small ones with a head start, and says why."""
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    page.select_option("#lane-filter", "GOOD_FIRST")
    page.wait_for_function("document.querySelectorAll('#queue-list .q-why').length > 0")
    syms = page.eval_on_selector_all("#queue-list .q-sym-text", "els => els.map(e => e.textContent)")
    assert syms and all("Easy" in s for s in syms)
    assert page.text_content("#queue-list .q-why").startswith("Good first: ")
    assert calls("/api/queue")[-1][1]["lane"] == "GOOD_FIRST"


def test_decompme_falls_back_to_the_server(page):
    reset(dme_browser_fail=True)
    page.reload()
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    with page.context.expect_page() as info:
        page.click("#btn-decompme")
    info.value.wait_for_url("**/scratch/server1/claim?token=srv")
    assert [c for c in calls("/api/decompme") if c[1].get("create")]


def test_scripts_by_game_version(page):
    """Pick a version, search, open a file; prototype files say how they compare with retail."""
    page.click("#nav-scripts")
    page.wait_for_selector("#script-file-list .script-row")
    opts = page.eval_on_selector_all("#script-version option", "os => os.map(o => o.value)")
    assert opts[:3] == ["ALL", "xbox", "prototype"]          # plus "uploads" if another test loaded a file
    assert page.input_value("#script-version") == "xbox"
    assert page.locator("#script-file-list .script-row").count() == 2
    page.wait_for_function("document.getElementById('script-meta-title').textContent.includes('xbox/scriptc/init.cso')")
    page.select_option("#script-version", "prototype")
    rows = page.locator("#script-file-list .script-row")
    assert rows.count() == 3
    tags = page.eval_on_selector_all("#script-file-list .script-tag", "ts => ts.map(t => t.textContent)")
    assert sorted(t for t in tags if t) == ["Changed from retail", "Only in this version", "Same as retail"]
    assert "only here" in page.text_content("#script-list-count")
    page.fill("#script-search", "editor")
    assert rows.count() == 1
    rows.first.click()
    page.wait_for_function("document.getElementById('script-decompiled-view').textContent.includes('cut from retail')")
    assert "only in this version" in page.text_content("#script-meta-title")
    total = page.text_content("#script-version option[value=ALL]")
    assert f"({page.text_content('#side-scripts-count')} files)" in total
    page.fill("#script-search", "nothing-like-this")
    assert "No scripts match" in page.text_content("#script-file-list")


def test_startup_screen_stays_until_the_data_is_in(browser):
    """While the queue is still loading, a startup screen covers the page and ticks off each step."""
    reset()
    ctx, pg = fresh_page(browser)
    held, gate = [], {"open": False}
    pg.route("**/api/queue*", lambda r: r.continue_() if gate["open"] else held.append(r))
    pg.goto(BASE)
    pg.wait_for_function("document.querySelector('#boot-steps li[data-step=state]').classList.contains('is-done')")
    assert pg.is_visible("#boot-screen")
    assert "not everything has loaded yet" in pg.text_content("#boot-sub")
    assert "is-active" in pg.get_attribute("#boot-steps li[data-step=queue]", "class")
    assert pg.evaluate("document.querySelector('.app-shell').hasAttribute('inert')")
    assert held
    gate["open"] = True
    for r in held:
        r.continue_()
    pg.wait_for_selector("#boot-screen", state="detached")
    assert not pg.evaluate("document.querySelector('.app-shell').hasAttribute('inert')")
    assert "Func" in pg.text_content("#wb-title")
    assert not pg.errors, pg.errors
    ctx.close()


def test_startup_screen_says_when_the_portal_does_not_answer(browser):
    reset()
    ctx, pg = fresh_page(browser)
    pg.route("**/api/state", lambda r: r.abort())
    pg.goto(BASE)
    pg.wait_for_selector("#boot-retry", state="visible")
    assert "Can't reach the portal" in pg.text_content("#boot-hint")
    assert "is-fail" in pg.get_attribute("#boot-steps li[data-step=state]", "class")
    pg.wait_for_timeout(400)
    assert pg.is_visible("#boot-screen")                       # stays up: the user decides
    pg.click("#boot-skip")
    pg.wait_for_selector("#boot-screen", state="detached")
    assert "OFFLINE" in pg.text_content("#server-status-text")
    ctx.close()


def test_still_loading_note_while_scripts_are_checked(browser):
    """The game-script check runs after the portal starts; the top bar says so until it's done."""
    reset()
    ctx, pg = fresh_page(browser)
    n = {"calls": 0}

    def state(route):
        resp = route.fetch()
        body = resp.json()
        n["calls"] += 1
        running = n["calls"] <= 2
        body["scripts"] = {"running": running, "versions": [
            {"id": "xbox", "label": "Retail", "compiled": 10, "checked": 3 if running else 10, "exact": 3 if running else 10}]}
        route.fulfill(response=resp, json=body)

    pg.route("**/api/state", state)
    pg.goto(BASE)
    wait_until_loaded(pg)
    pg.wait_for_selector("#bg-work", state="visible")
    assert "STILL LOADING" in pg.text_content("#bg-work-text") and "3 / 10" in pg.text_content("#bg-work-text")
    pg.wait_for_selector("#bg-work", state="hidden", timeout=15000)
    pg.wait_for_function("document.getElementById('toast').textContent.includes('Everything is loaded')")
    assert "10 of 10" in pg.text_content("#toast")
    assert not pg.errors, pg.errors
    ctx.close()


def test_ai_feedback_always_describes_the_code_it_shows(page):
    """Each AI prompt shows the best code so far. A failed attempt's errors come with that attempt's own code,
    and a worse attempt is reported as dropped, with what is still wrong in the best code."""
    sign_in(page)
    prompts, compiled = [], []
    # The AI decides how many tries it takes: here five, the fourth a repeat of the second, then it gives up.
    replies = ["int bad(", "int good() { return 1; }", "int worse() { }", "int good() { return 1; }", "GIVE UP: I can't get closer."]

    def ai(route):
        prompts.append(json.loads(route.request.post_data)["prompt"])
        code = replies[min(len(prompts), len(replies)) - 1]
        reply = code if code.startswith("GIVE UP") else "```cpp\n" + code + "\n```"
        route.fulfill(json={"ok": True, "reply": reply, "used_model": "m"})

    def verify(route):
        code = json.loads(route.request.post_data)["cpp_code"]
        compiled.append(code)
        if "bad(" in code:
            return route.fulfill(json={"ok": False, "compiler_error": "error C2059: syntax error"})
        got = 8 if "good" in code else 4
        route.fulfill(json={"ok": True, "is_exact": False, "matched_bytes": got, "total_bytes": 12, "match_percent": got / 12 * 100,
                            "diff_details": [{"idx": 9, "status": "diff", "target": "C3", "compiled": "90"}],
                            "compiled_hex": "90 90"})

    page.route("**/api/fast-synthesize", lambda r: r.fulfill(json={"ok": False}))
    page.route("**/api/ai-proxy", ai)
    page.route("**/api/verify", verify)
    page.fill("#ai-key", "test-key")
    page.click("#btn-step2-ai")
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('The AI stopped')", timeout=30000)
    assert len(prompts) == 5 and len(compiled) == 3            # the repeated code wasn't compiled again
    assert 'The AI stopped after 4 tries: "I can\'t get closer."' in status(page)
    assert "There is no limit (this is try 1)" in prompts[0] and "GIVE UP:" in prompts[0]
    assert "Attempt 4 was exactly the code of attempt 2, which matched 8/12 bytes" in prompts[4]
    assert "did not compile. It was:" in prompts[1] and "int bad(" in prompts[1] and "C2059" in prompts[1]
    assert "The current best C++ (attempt 2) compiled and matched 8/12" in prompts[2]
    assert "int good() { return 1; }" in prompts[2].split("Current best C++")[1]
    assert "Attempt 3 matched only 4/12 bytes" in prompts[3] and "The current best C++ (attempt 2)" in prompts[3]
    assert "int good() { return 1; }" in page.input_value("#wb-editor")


def test_ai_run_stops_at_the_persons_limit(page):
    """With "Stop after" set, a run ends there even if the AI would go on."""
    sign_in(page)
    prompts = []

    def ai(route):
        prompts.append(json.loads(route.request.post_data)["prompt"])
        route.fulfill(json={"ok": True, "reply": "```cpp\nint f() { return %d; }\n```" % len(prompts), "used_model": "m"})

    page.route("**/api/fast-synthesize", lambda r: r.fulfill(json={"ok": False}))
    page.route("**/api/ai-proxy", ai)
    page.route("**/api/verify", lambda r: r.fulfill(json={"ok": True, "is_exact": False, "matched_bytes": 2, "total_bytes": 12,
                                                           "match_percent": 16.7, "diff_details": [], "compiled_hex": "90"}))
    page.fill("#ai-key", "test-key")
    page.fill("#ai-max-tries", "2")
    page.click("#btn-step2-ai")
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('your limit')", timeout=30000)
    assert len(prompts) == 2 and "other than the 2 the person set (this is try 2)" in prompts[1]
    assert "Best after 2 tries (your limit)" in status(page)
    page.reload()
    assert page.input_value("#ai-max-tries") == "2"            # kept for next time
    page.fill("#ai-max-tries", "")


def test_ai_run_ends_when_new_code_gets_no_closer(page):
    """No limit on tries, and new code every time: but twelve tries in a row that match no more bytes end the run,
    or it would go on, and cost, for ever."""
    sign_in(page)
    prompts = []

    def ai(route):
        prompts.append(json.loads(route.request.post_data)["prompt"])
        route.fulfill(json={"ok": True, "reply": "```cpp\nint f() { return %d; }\n```" % len(prompts), "used_model": "m"})

    page.route("**/api/fast-synthesize", lambda r: r.fulfill(json={"ok": False}))
    page.route("**/api/ai-proxy", ai)
    page.route("**/api/verify", lambda r: r.fulfill(json={"ok": True, "is_exact": False, "matched_bytes": 2, "total_bytes": 12,
                                                           "match_percent": 16.7, "diff_details": [], "compiled_hex": "90"}))
    page.fill("#ai-key", "test-key")
    page.fill("#ai-max-tries", "")
    page.click("#btn-step2-ai")
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('without getting any closer')", timeout=60000)
    assert len(prompts) == 13                                   # the first got closer (0 to 2 bytes), then twelve that didn't
    assert "ends by itself after 12 tries in a row" in prompts[0] and "(11 so far)" in prompts[-1]
    assert "Best: 2/12 B" in status(page)


def test_ai_run_ends_when_the_ai_sends_no_new_code(page):
    """No limit on tries, but a model that only repeats itself isn't trying any more."""
    sign_in(page)
    prompts = []

    def ai(route):
        prompts.append(1)
        route.fulfill(json={"ok": True, "reply": "```cpp\nint f() { return 1; }\n```", "used_model": "m"})

    page.route("**/api/fast-synthesize", lambda r: r.fulfill(json={"ok": False}))
    page.route("**/api/ai-proxy", ai)
    page.route("**/api/verify", lambda r: r.fulfill(json={"ok": True, "is_exact": False, "matched_bytes": 2, "total_bytes": 12,
                                                           "match_percent": 16.7, "diff_details": [], "compiled_hex": "90"}))
    page.fill("#ai-key", "test-key")
    page.click("#btn-step2-ai")
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('no new code')", timeout=30000)
    assert len(prompts) == 6                                    # one compiled, then five repeats


def _match_one(pg):
    pg.click("#btn-step1-claim")
    pg.wait_for_function("document.getElementById('btn-step1-claim').textContent.includes('Claimed by You')")
    pg.fill("#wb-editor", "void f() { /* MATCH_ALL */ }")
    pg.focus("#wb-editor")
    pg.keyboard.press("Control+Enter")
    pg.wait_for_function("document.getElementById('verify-status').textContent.includes('VERIFIED')")


def test_submit_your_work_gives_contributors_a_file(page):
    """Anyone can submit: the button is always there, the workbench says when there is something to send,
    and a contributor gets one file to post, with plain next steps."""
    sign_in(page)
    assert page.is_visible("#btn-git-sync") and "Submit your work" in page.text_content("#btn-git-sync")
    assert not page.is_visible("#submit-strip") and not page.is_visible("#btn-import")
    page.click("#btn-git-sync")
    page.wait_for_function("document.getElementById('toast').textContent.includes('already on GitHub')")

    _match_one(page)
    assert "Submit your work" in page.text_content("#verify-status")
    page.wait_for_selector("#submit-strip", state="visible")
    assert "1 new match" in page.text_content("#submit-strip") and "1 new match" in page.text_content("#submit-note")
    with page.expect_download() as dl:
        page.click("#submit-strip button")
    assert dl.value.suggested_filename == "scarface-submission-Tester.json"
    page.wait_for_selector("#submit-dialog[open]")
    body = page.text_content("#submit-dialog")
    assert "ready to send" in body and "Downloads" in body and "under your name" in body and "never loses" in body
    hrefs = page.eval_on_selector_all("#sd-actions a", "els => els.map(e => e.href)")
    assert any("discord.gg" in h for h in hrefs) and any("/issues/new?title=" in h for h in hrefs)
    page.click("#sd-actions button")
    page.wait_for_selector("#submit-dialog[open]", state="detached")


def test_maintainers_push_and_import(page, tmp_path):
    sign_in(page, user="Founder")
    page.wait_for_selector("#btn-import", state="visible")
    _match_one(page)
    page.click("#btn-git-sync")
    page.wait_for_selector("#submit-dialog[open]")
    assert "Sent to GitHub" in page.text_content("#sd-title")
    page.click("#sd-actions button")

    sub = tmp_path / "sub.json"
    sub.write_text(json.dumps({"format": "scarface-decomp-submission", "submitted_by": "Alice",
                               "entries": {"a": {"code": "x"}, "b": {"code": "y"}}}))
    page.set_input_files("#import-input", str(sub))
    page.wait_for_function("document.getElementById('sd-title').textContent.includes('Submission imported')")
    text = page.text_content("#sd-body")
    assert "Added 1 function from Alice" in text and "core::Bad" in text and "Submit your work" in text


def test_the_ai_key_is_hidden_but_not_a_password_field(page):
    """Browsers offered to save the key (and the search box) as a login; it is masked text instead."""
    assert page.get_attribute("#ai-key", "type") == "text"
    assert page.evaluate("getComputedStyle(document.getElementById('ai-key')).webkitTextSecurity") == "disc"
    assert page.eval_on_selector_all("input[type=password]", "els => els.map(e => e.id)") == ["contrib-pin"]


def test_downloads_from_each_section(page):
    """Functions, game scripts and source files can each be downloaded, everything or verified only,
    as a .zip in the original layout or as one .txt."""
    page.click("#btn-dl-functions")
    page.wait_for_selector("#submit-dialog[open]")
    assert "address" in page.text_content("#sd-body")
    page.select_option("#sd-body select[name=build]", "xb")
    page.check("#sd-body input[name=only][value=verified]")
    page.check("#sd-body input[name=format][value=txt]")
    with page.expect_download() as dl:
        page.click("#sd-actions .btn.primary")
    assert dl.value.suggested_filename == "scarface-functions-verified-xb.txt"
    page.wait_for_selector("#submit-dialog[open]", state="detached")
    assert any(c[0] == "/download/functions" and c[1] == {"build": "xb", "only": "verified", "format": "txt"} for c in calls())

    page.goto(BASE + "#scripts")
    page.click("#btn-dl-scripts")
    opts = page.eval_on_selector_all("#sd-body select[name=version] option", "els => els.map(e => e.value)")
    assert opts[0] == "all" and "xbox" in opts
    with page.expect_download() as dl:
        page.click("#sd-actions .btn.primary")
    assert dl.value.suggested_filename == "scarface-scripts-all.zip"

    page.click("#btn-dl-scripts")
    page.select_option("#sd-body select[name=version]", "prototype")
    page.check("#sd-body input[name=only][value=verified]")
    page.click("#sd-actions .btn.primary")
    page.wait_for_function("document.getElementById('dl-note').textContent.includes('No script files match')")
    page.click("#sd-actions .btn:not(.primary)")

    page.goto(BASE + "#sources")
    page.click("#btn-dl-sources")
    with page.expect_download() as dl:
        page.click("#sd-actions .btn.primary")
    assert dl.value.suggested_filename == "scarface-sources-all.zip"


def test_game_files_copy_and_browse(page):
    """Game files: the versions found are ticked, the PC says how to add it, a copy runs with progress,
    then each version's own files can be listed and filtered."""
    page.click("#nav-gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    assert page.eval_on_selector_all("input[name=gf-version]", "els => els.map(e => [e.value, e.checked, e.disabled])") == [
        ["xbox", True, False], ["pc", True, False], ["ps2", True, False], ["prototype", True, False]]
    assert "_ISO-Version.iso + " in page.text_content("#gf-versions")          # the PC disc, read without installing
    assert page.text_content("#gf-notes") == ""
    assert "Needs up to" in page.text_content("#gf-space") and "free on this drive" in page.text_content("#gf-space")
    assert page.is_hidden("#gf-result")

    page.uncheck("input[name=gf-version][value=ps2]")
    page.uncheck("input[name=gf-version][value=pc]")
    page.check("input[name=gf-mode][value=every]")
    page.click("#gf-start")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Reading')")
    assert page.is_disabled("#gf-start") and page.is_visible("#gf-stop")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Done')", timeout=10000)
    start = [c for c in calls("/api/game-files/start")][-1][1]
    assert start == {"versions": ["xbox", "prototype"], "mode": "every", "folders": "game"}

    page.wait_for_selector("#gf-result:not([hidden]) .gf-tab")
    assert page.eval_on_selector_all(".gf-tab", "els => els.map(e => e.textContent)") == ["Xbox", "PC", "PS2", "Xbox 2006 prototype"]
    page.wait_for_function("document.querySelectorAll('#gf-list .gf-row').length > 0")
    assert all(s == "only here" for s in page.eval_on_selector_all("#gf-list .st", "els => els.map(e => e.textContent)"))
    page.click(".gf-tab:has-text('Xbox 2006 prototype')")
    page.wait_for_function("document.querySelector('#gf-list .p').textContent.startsWith('art/')")
    page.click(".gf-kind:has-text('Sounds')")
    page.wait_for_function("[...document.querySelectorAll('#gf-list .p')].every(e => e.textContent.endsWith('.rsd'))")
    page.select_option("#gf-status", "changed")
    page.wait_for_function("[...document.querySelectorAll('#gf-list .st')].every(e => e.textContent === 'different')")
    page.fill("#gf-search", "prototype_010")
    page.wait_for_function("document.getElementById('gf-count').textContent === '1 file'")
    page.click("#gf-open-version")
    page.wait_for_timeout(200)
    assert calls("/api/game-files/open")[-1][1] == {"folder": "prototype"}


def test_game_files_previews(page):
    """A copied sound plays in the page and a .p3d shows its pictures; both toggle closed again."""
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.click("#gf-start")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Done')", timeout=10000)
    page.wait_for_selector("#gf-result:not([hidden]) .gf-tab")
    page.wait_for_function("document.querySelectorAll('#gf-list .gf-row').length > 0")
    buttons = page.eval_on_selector_all("#gf-list .gf-row", "rows => rows.map(r => [r.querySelector('.p').firstChild.textContent.split('.').pop(), (r.querySelector('.a button') || {}).textContent || ''])")
    assert dict(buttons) == {"rsd": "Play", "p3d": "Open", "bik": "Watch", "cso": "", "dat": ""}
    # sorted by what they are, under a heading for each kind with how many there are
    heads = page.eval_on_selector_all("#gf-list .gf-group", "hs => hs.map(h => h.firstChild.textContent)")
    assert heads == ["Sounds", "Models & textures", "Videos", "Scripts & text", "Other"]
    assert page.text_content("#gf-list .gf-group span").endswith(" files")
    page.select_option("#gf-kind-pick", "videos")
    page.wait_for_function("document.querySelectorAll('#gf-list .gf-group').length === 1")
    assert calls("/api/game-files/list")[-1][1]["kind"] == "videos"
    assert page.get_attribute(".gf-kind[aria-pressed=true]", "title") == "Show only videos"
    page.select_option("#gf-kind-pick", "")
    page.wait_for_function("document.querySelectorAll('#gf-list .gf-group').length === 5")

    page.click("#gf-list .gf-row:has-text('.rsd') .a button")
    page.wait_for_selector("#gf-list .gf-prev audio")
    page.wait_for_selector("#gf-list .gf-prev .gf-line")                     # the words, from its subtitles
    assert page.text_content("#gf-list .gf-prev .gf-line") == "Say hello to my little friend!"
    page.wait_for_function("document.querySelector('#gf-list .gf-prev audio').readyState >= 1")
    assert page.eval_on_selector("#gf-list .gf-prev audio", "a => a.duration") == pytest.approx(0.2, abs=0.01)
    assert page.get_attribute("#gf-list .gf-row:has-text('.rsd') .a button", "aria-expanded") == "true"
    page.click("#gf-list .gf-row:has-text('.rsd') .a button")
    assert page.query_selector("#gf-list .gf-prev") is None

    page.click("#gf-list .gf-row:has-text('_006.p3d') .a button")
    page.wait_for_selector("#gf-list .gf-prev .gf-what")
    assert page.text_content("#gf-list .gf-prev .gf-what") == "1 model; 2 pictures."
    assert page.eval_on_selector_all("#gf-list .gf-prev .gf-bl button", "bs => bs.map(b => b.textContent)") == ["View here", 
        "Open in Blender", "Download .glb"]
    page.wait_for_function("[...document.querySelectorAll('#gf-list .gf-pic img')].length === 2 && [...document.querySelectorAll('#gf-list .gf-pic img')].every(i => i.complete && i.naturalWidth > 0)")
    assert page.eval_on_selector_all("#gf-list .gf-pic img", "els => els.map(e => e.naturalWidth)") == [8, 16]
    assert page.eval_on_selector_all("#gf-list .gf-pic figcaption", "els => els.map(e => e.textContent)") == ["wall.bmp · 8×8", "sign.tga · 16×8"]
    sound = [c for c in calls("/api/game-files/sound")][-1][1]
    assert set(sound) == {"version", "path"} and sound["path"].endswith(".rsd")


def test_game_files_in_blender(page):
    """Copied .p3d files get a Blender download; the In Blender box downloads a whole map area and exports the
    city, then opens its folder."""
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    assert page.is_visible("#gfb-need") and page.is_hidden("#gfb-tools")      # nothing copied yet: copy first
    page.click("#gf-start")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Done')", timeout=10000)
    page.wait_for_selector("#gfb-tools:not([hidden])")
    assert page.is_hidden("#gfb-need")
    page.wait_for_function("document.querySelectorAll('#gf-list .gf-row').length > 0")
    page.click("#gf-list .gf-row:has-text('_006.p3d') .a button")
    page.wait_for_selector("#gf-list .gf-prev .gf-bl")
    with page.expect_download() as dl:
        page.click("#gf-list .gf-prev .gf-bl button:has-text('Download .glb')")
    assert dl.value.suggested_filename.endswith(".glb")
    assert calls("/api/game-files/model")[-1][1]["path"].endswith("_006.p3d")
    assert "File > Import > glTF 2.0" in page.text_content("#gf-list .gf-prev p[role=status]")
    page.click("#gf-list .gf-prev .gf-bl button:has-text('Open in Blender')")
    page.wait_for_function("document.querySelector('#gf-list .gf-prev p[role=status]').textContent.startsWith('Blender is opening it')")
    assert "Opened/" in page.text_content("#gf-list .gf-prev p[role=status]")
    assert "Blender 4.2" in page.text_content("#gfb-app")
    page.wait_for_function("document.querySelectorAll('#gfb-area option').length === 3")
    assert page.eval_on_selector_all("#gfb-area optgroup", "gs => gs.map(g => g.label)") == ["The city", "Interiors"]
    page.select_option("#gfb-area", "azones/donutshop_01")
    with page.expect_download() as dl:
        page.click("#gfb-area-dl")
    assert dl.value.suggested_filename == "donutshop_01.glb" or dl.value.suggested_filename.endswith(".glb")
    assert calls("/api/game-files/model")[-1][1]["area"] == "azones/donutshop_01"
    page.click("#gfb-area-open")
    page.wait_for_function("document.getElementById('gfb-area-status').textContent.startsWith('Blender is opening it')")
    assert calls("/api/game-files/open-in-blender")[-1][1]["area"] == "azones/donutshop_01"
    assert page.is_hidden("#gfb-city-blender")                               # nothing exported yet
    page.click("#gfb-city")
    page.wait_for_selector("#gfb-city-stop:not([hidden])")
    page.wait_for_function("document.getElementById('gfb-city-status').textContent.includes('3 areas written')",
                           timeout=10000)
    assert page.is_visible("#gfb-city-open") and page.is_enabled("#gfb-city")
    page.click("#gfb-city-blender")                                            # the whole city, joined up
    page.wait_for_function("document.getElementById('gfb-city-bl-status').textContent.includes('bringing in 3 areas')")
    assert calls("/api/game-files/open-in-blender")[-1][1]["city"] is True
    page.click("#gfb-city-open")
    page.wait_for_timeout(200)
    tab = [c[1] for c in calls("/api/game-files/blender") if "version" in (c[1] or {})][-1]["version"]
    assert calls("/api/game-files/open")[-1][1] == {"folder": "blender:" + tab}


def _gf_copied(page):
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.click("#gf-start")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Done')", timeout=10000)
    page.wait_for_function("document.querySelectorAll('#gf-list .gf-row').length > 0")


def test_game_files_blender_not_found_asks_where_it_is(page):
    reset(no_blender=True)
    _gf_copied(page)
    page.click("#gf-list .gf-row:has-text('_006.p3d') .a button")
    page.click("#gf-list .gf-prev .gf-bl button:has-text('Open in Blender')")
    page.wait_for_selector("#gf-list .gf-prev .gf-where")
    status = "#gf-list .gf-prev p[role=status]"
    assert "Couldn't find Blender" in page.text_content(status)
    page.fill("#gf-list .gf-where input", "C:\\Games\\notepad.exe")
    page.click("#gf-list .gf-where button")
    page.wait_for_function(f"document.querySelector('{status}').textContent.startsWith(\"That isn't Blender\")")
    page.fill("#gf-list .gf-where input", "D:\\Tools\\Blender\\blender.exe")
    page.click("#gf-list .gf-where button")
    page.wait_for_function(f"document.querySelector('{status}').textContent.startsWith('Blender is opening it')")
    assert page.query_selector("#gf-list .gf-where") is None
    assert calls("/api/game-files/blender-path")[-1][1] == {"path": "D:\\Tools\\Blender\\blender.exe"}


def test_game_files_a_failed_export_says_why_on_the_page(page):
    reset(model_error=True)
    _gf_copied(page)
    page.click("#gf-list .gf-row:has-text('_006.p3d') .a button")
    page.click("#gf-list .gf-prev .gf-bl button:has-text('Download .glb')")
    page.wait_for_function("document.querySelector('#gf-list .gf-prev p[role=status]').textContent.startsWith('Nothing to show')")
    assert page.eval_on_selector("#gf-list .gf-prev p[role=status]", "p => p.classList.contains('err')")


def test_a_model_opens_in_the_portals_own_3d_view(page):
    """View here: the same .glb Blender would get, drawn in the page. The picture really is the model (its red
    texture is on screen), the mouse turns it, and Esc closes it and frees the graphics memory."""
    import media
    reset()
    _gf_copied(page)
    page.click("#gf-list .gf-row:has-text('_006.p3d') .a button")
    page.click("#gf-list .gf-prev .gf-bl button:has-text('View here')")
    page.wait_for_function("!document.getElementById('viewer').hidden && document.getElementById('viewer-info').textContent.includes('triangles')")
    assert page.text_content("#viewer-info").startswith("2 parts · 2 triangles")
    page.wait_for_timeout(300)
    w, h, rgba = media.decode_png(page.locator("#viewer-canvas").screenshot())
    px = [rgba[i:i + 3] for i in range(0, len(rgba), 4 * 7)]
    red = sum(1 for r, g, b in px if r > 150 and g < 110 and b < 110)
    assert red > len(px) * 0.02, "the textured triangle isn't on screen"
    box = page.locator("#viewer-canvas").bounding_box()
    page.mouse.move(box["x"] + box["width"] / 2, box["y"] + box["height"] / 2)
    page.mouse.down()
    page.mouse.move(box["x"] + box["width"] / 2 + 260, box["y"] + box["height"] / 2, steps=4)
    page.mouse.up()
    page.wait_for_timeout(200)
    assert media.decode_png(page.locator("#viewer-canvas").screenshot())[2] != rgba        # it turned
    page.keyboard.press("Escape")
    assert page.is_hidden("#viewer")
    # a map area has the button too
    page.wait_for_function("document.querySelectorAll('#gfb-area option').length > 0")
    page.click("#gfb-area-view")
    page.wait_for_function("!document.getElementById('viewer').hidden && document.getElementById('viewer-info').textContent.includes('triangles')")
    page.click("#viewer-close")
    assert page.is_hidden("#viewer")


def test_the_3d_view_says_so_when_it_cant_show_a_file(page):
    reset(bad_glb=True)
    _gf_copied(page)
    page.click("#gf-list .gf-row:has-text('_006.p3d') .a button")
    page.click("#gf-list .gf-prev .gf-bl button:has-text('View here')")
    page.wait_for_function("document.querySelector('#gf-list .gf-prev p[role=status]').textContent.includes('Open in Blender still works')")
    assert page.is_hidden("#viewer")


def test_blender_version_is_picked_beside_the_tools_and_says_what_each_has(page):
    """The Blender tools have their own version picker (the same choice as the tabs). When the copy kept only
    what one version has, the others say how little of the city they hold, and a version with none of it
    doesn't offer to export it."""
    reset(partial_city=True)
    _gf_copied(page)
    page.wait_for_function("document.querySelectorAll('#gfb-version option').length > 1")
    labels = page.eval_on_selector_all("#gfb-version option", "os => os.map(o => o.textContent)")
    values = page.eval_on_selector_all("#gfb-version option", "os => os.map(o => o.value)")
    assert "the whole city, 3 areas" in labels[0] and "only 1 area of its own" in labels[1]
    assert page.input_value("#gfb-version") == "pc"                         # the PC's tab is the one it opens on
    page.select_option("#gfb-version", values[0])
    page.wait_for_function("document.getElementById('gfb-version-note').textContent.includes('pick PC here')")
    assert page.is_visible("#gfb-city")
    page.select_option("#gfb-version", values[1])                              # the same as pressing its tab
    page.wait_for_function("document.getElementById('gfb-version-note').textContent.includes('not its whole city')")
    assert page.eval_on_selector("#gf-tabs .gf-tab[aria-selected=true]", "b => b.textContent") in labels[1]
    assert "Every version complete" in page.text_content("#gfb-version-note") and page.is_visible("#gfb-city")
    if len(values) > 2:
        page.select_option("#gfb-version", values[2])
        page.wait_for_function("document.getElementById('gfb-version-note').textContent.includes('no city to export here')")
        assert page.is_hidden("#gfb-city")


def test_the_city_at_a_time_of_day_in_a_weather(page):
    """Beside Export the city: a time of day (As stored, or a whole hour from midnight to midnight) and a weather.
    As stored sends no hour; the status says the time and weather, with the export's notes (no fog, and why);
    the choice is kept for next time; and a city exported at another time says that Open opens it that way."""
    reset(no_fog=True)
    _gf_copied(page)
    page.wait_for_selector("#gfb-tools:not([hidden])")
    hours = page.eval_on_selector_all("#gfb-city-hour option", "os => os.map(o => [o.value, o.textContent])")
    assert hours[0] == ["", "As stored"] and [v for v, _t in hours[1:]] == [str(h) for h in range(25)]
    named = dict(hours)
    assert (named["6"], named["12"], named["18"], named["23"]) == ("6 a.m.", "noon", "6 p.m.", "11 p.m.")
    assert named["0"].startswith("midnight") and named["24"].startswith("midnight") and named["0"] != named["24"]
    assert page.eval_on_selector_all("#gfb-city-weather option", "os => os.map(o => [o.value, o.textContent])") == \
        [["clear", "Clear"], ["rain", "Rain"]]
    assert page.input_value("#gfb-city-hour") == "" and page.input_value("#gfb-city-weather") == "clear"
    assert "Export the city again after changing these" in page.text_content("#gfb-city-look-note")

    def export():
        page.click("#gfb-city")
        page.wait_for_selector("#gfb-city-stop:not([hidden])")
        page.wait_for_function("document.getElementById('gfb-city-status').textContent.includes('3 areas written')",
                               timeout=10000)
        return [c[1] for c in calls("/api/game-files/blender") if "version" in (c[1] or {})][-1]

    sent = export()                                                            # as before: no hour
    assert "hour" not in sent and sent["weather"] == "clear"
    status = page.text_content("#gfb-city-status")
    assert status.endswith("MB), with the sky as stored, in clear weather.") and "No fog" not in status
    assert page.text_content("#gfb-city-made") == ""

    page.select_option("#gfb-city-hour", "18")
    page.select_option("#gfb-city-weather", "rain")
    page.wait_for_timeout(200)
    kept = calls("/api/game-files/speed")[-1][1]                               # kept with the other settings
    assert (kept["city_hour"], kept["city_weather"]) == (18, "rain")
    assert page.text_content("#gfb-city-made") == (
        "The city was exported with the sky as stored, in clear weather, and Open the whole city in Blender opens it "
        "that way. To have it at 6 p.m. in the rain, press Export the city again.")
    page.click("#gfb-city")
    page.wait_for_function("document.getElementById('gfb-city-status').textContent.startsWith('Exporting')")
    assert " at 6 p.m. in the rain: " in page.text_content("#gfb-city-status")
    assert page.text_content("#gfb-city-made") == ""                           # nothing to open while it runs
    page.wait_for_function("document.getElementById('gfb-city-status').textContent.includes('3 areas written')",
                           timeout=10000)
    sent = [c[1] for c in calls("/api/game-files/blender") if "version" in (c[1] or {})][-1]
    assert sent["hour"] == 18 and sent["weather"] == "rain"
    status = page.text_content("#gfb-city-status")
    assert "MB), at 6 p.m. in the rain. No fog: the game's script scriptc/graphanims.cso isn't among the copied files." \
        in status
    assert page.text_content("#gfb-city-made") == ""                           # the city is as picked

    page.reload()                                                              # next visit: the same choice
    wait_until_loaded(page)
    page.wait_for_function("document.getElementById('gfb-city-hour').value === '18'")
    assert page.input_value("#gfb-city-weather") == "rain"
    page.wait_for_function("document.getElementById('gfb-city-status').textContent.includes('at 6 p.m. in the rain')")
    page.select_option("#gfb-city-hour", "0")                                  # midnight is an hour too: sent
    page.wait_for_function("document.getElementById('gfb-city-made').textContent.includes('To have it at midnight in the rain')")
    assert "exported at 6 p.m. in the rain" in page.text_content("#gfb-city-made")
    sent = export()
    assert sent["hour"] == 0 and sent["weather"] == "rain"
    assert "at midnight in the rain" in page.text_content("#gfb-city-status")
    page.select_option("#gfb-city-hour", "")
    page.wait_for_timeout(200)
    assert calls("/api/game-files/speed")[-1][1]["city_hour"] is None
    assert "To have it with the sky as stored, in the rain" in page.text_content("#gfb-city-made")
    page.click("#gfb-city-blender")                                            # opens what is in the folder
    page.wait_for_function("document.getElementById('gfb-city-bl-status').textContent.includes('bringing in 3 areas')")
    assert set(calls("/api/game-files/open-in-blender")[-1][1]) == {"version", "city"}


def test_no_blender_button_for_a_file_this_copy_cant_show(page):
    reset(cant_show=True)
    _gf_copied(page)
    page.click("#gf-list .gf-row:has-text('_006.p3d') .a button")
    page.wait_for_function("document.querySelector('#gf-list .gf-prev').textContent.includes('nothing to show from the Xbox')")
    assert page.query_selector("#gf-list .gf-prev .gf-bl") is None             # no button that could only fail


def test_new_matches_say_when_lookalikes_are_still_being_tried(page):
    """The count of new matches keeps rising after a batch while each match is tried on the functions with the
    same code. The page says so, so it doesn't look like something is stuck."""
    reset(porting=41)
    page.goto(BASE)
    page.wait_for_function("document.getElementById('submit-note').textContent.includes('still trying 41 look-alikes')")
    reset()
    page.reload()
    page.wait_for_function("document.getElementById('submit-note').textContent.length > 0")
    assert "look-alike" not in page.text_content("#submit-note")


def test_game_files_subtitles_and_their_sound(page):
    _gf_copied(page)
    page.click("#gf-list .gf-row:has-text('_021.p3d') .a button")
    page.wait_for_selector("#gf-list .gf-prev .gf-line")
    assert page.text_content("#gf-list .gf-prev .gf-what").startswith("Subtitles")
    assert page.query_selector("#gf-list .gf-prev .gf-bl") is None            # nothing for Blender
    page.click("#gf-list .gf-prev button:has-text('Play the sound')")
    page.wait_for_selector("#gf-list .gf-prev audio")
    assert wait_for_calls("/api/game-files/sound")[-1][1]["path"].endswith("sounds/pc_020.rsd")


def test_game_files_movies_play_in_the_page(page):
    _gf_copied(page)
    page.click("#gf-list .gf-row:has-text('.bik') .a button")
    page.wait_for_function("document.querySelector('#gf-list .gf-prev p[role=status]').textContent.includes('%')",
                           timeout=5000)
    page.wait_for_selector("#gf-list .gf-prev video", timeout=10000)
    assert "/api/game-files/movie?" in page.get_attribute("#gf-list .gf-prev video", "src")
    assert "kept for next time" in page.text_content("#gf-list .gf-prev p[role=status]")


def test_game_files_movies_without_ffmpeg_say_how_to_get_it(page):
    reset(no_ffmpeg=True)
    _gf_copied(page)
    page.click("#gf-list .gf-row:has-text('.bik') .a button")
    page.wait_for_selector("#gf-list .gf-prev .gf-where")
    assert "FFmpeg" in page.text_content("#gf-list .gf-prev p[role=status]")
    page.fill("#gf-list .gf-where input", "C:\\ffmpeg\\bin\\ffmpeg.exe")
    page.click("#gf-list .gf-where button")
    page.wait_for_selector("#gf-list .gf-prev video", timeout=10000)


def test_ffmpeg_installs_with_one_click(page):
    """Install FFmpeg starts Windows' own installer in its own window; when it is done, Try again plays the movie."""
    reset(no_ffmpeg=True)
    _gf_copied(page)
    page.click("#gf-list .gf-row:has-text('.bik') .a button")
    page.click("#gf-list .gf-prev button:has-text('Install FFmpeg')")
    page.wait_for_function("document.querySelector('#gf-list .gf-prev p[role=status]').textContent.includes('installing FFmpeg')")
    assert calls("/api/game-files/ffmpeg-install")
    page.click("#gf-list .gf-prev button:has-text('Try again')")
    page.wait_for_selector("#gf-list .gf-prev video", timeout=10000)


def test_game_files_every_texture(page):
    _gf_copied(page)
    page.wait_for_selector("#gf-textures:not([hidden])")
    page.click("#gft-start")
    page.wait_for_function("document.getElementById('gft-status').textContent.startsWith('The PC')")
    assert page.is_visible("#gft-stop")
    page.wait_for_function("document.getElementById('gft-status').textContent.startsWith('Done')", timeout=10000)
    assert "7 sharper from another version, 172 that only other versions have" in page.text_content("#gft-status")
    page.click("#gft-open")
    page.wait_for_timeout(200)
    assert calls("/api/game-files/open")[-1][1] == {"folder": "textures"}


def test_game_files_speed(page):
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-speed:not([hidden])")
    assert "Use all 8 processor cores" in page.text_content("#gf-cores-text")
    assert "NVIDIA" in page.text_content("#gf-gpu-text")
    assert page.is_checked("#gf-use-cores") and page.is_checked("#gf-use-gpu")
    page.uncheck("#gf-use-cores")
    page.wait_for_timeout(200)
    assert calls("/api/game-files/speed")[-1][1] == {"use_cores": False, "use_gpu": True, "xbox_look": False, "fps": 30,
                                                     "city_hour": None, "city_weather": "clear"}


def test_game_files_stop(page):
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.click("#gf-start")
    page.wait_for_selector("#gf-stop:not([hidden])")
    page.click("#gf-stop")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Stopped')", timeout=10000)
    assert page.is_enabled("#gf-start") and page.is_hidden("#gf-stop")


def _gf_text(page, sel):
    return page.text_content(sel).strip()


def _gf_done(page):
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Done')", timeout=10000)


def test_game_files_no_copying_twice(page):
    """Copied once with these choices: the button says so and can't copy again; other choices take a second
    press; Stop can't cut the move into place in half."""
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.check("input[name=gf-mode][value=unique]")           # not the quick button's choices
    page.click("#gf-start")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Putting')"
                           " && document.getElementById('gf-stop').disabled", timeout=10000)
    assert "can’t be stopped" in _gf_text(page, "#gf-progress-text")
    _gf_done(page)
    assert _gf_text(page, "#gf-start") == "Copied ✓" and page.is_disabled("#gf-start")
    assert "Already copied like this" in _gf_text(page, "#gf-space")
    assert page.is_enabled("#gf-quick-start") and page.is_visible("#gf-check")
    page.click("#gf-check")                                     # every file there: nothing to do
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Already copied: every file')",
                           timeout=10000)
    assert len(calls("/api/game-files/start")) == 2 and page.is_disabled("#gf-start")
    page.check("input[name=gf-mode][value=every]")
    assert _gf_text(page, "#gf-start") == "Copy again with these choices" and page.is_hidden("#gf-check")
    page.click("#gf-start")
    assert _gf_text(page, "#gf-start") == "Press again to replace your copy"
    assert "stays as it is until the new one is ready" in _gf_text(page, "#gf-progress-text")
    assert len(calls("/api/game-files/start")) == 2
    page.click("#gf-start")
    _gf_done(page)
    assert calls("/api/game-files/start")[-1][1]["mode"] == "every" and _gf_text(page, "#gf-start") == "Copied ✓"
    page.click("#gf-quick-start")                               # a copy exists: the quick button asks too
    assert _gf_text(page, "#gf-quick-start") == "Press again to replace your copy"
    page.check("input[name=gf-folders][value=type]")            # changing a choice takes the question back
    assert _gf_text(page, "#gf-quick-start") == "Copy everything, PC first"
    assert len(calls("/api/game-files/start")) == 3


def test_game_files_missing_files_are_put_back(page):
    reset(gf_missing=True)
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.click("#gf-start")
    _gf_done(page)
    page.click("#gf-check")
    page.wait_for_selector("#gf-stop:not([hidden])")
    _gf_done(page)
    assert len(calls("/api/game-files/start")) == 2


def test_game_files_a_cut_off_copy_can_be_finished(page):
    reset(gf_interrupted=True)
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('The last copy was cut off')")
    assert _gf_text(page, "#gf-start") == "Finish the copy" and page.is_enabled("#gf-start")
    assert _gf_text(page, "#gf-quick-start") == "Finish the copy"
    page.click("#gf-start")
    _gf_done(page)
    assert _gf_text(page, "#gf-start") == "Copied ✓"


def test_game_files_one_click_for_blender(page):
    """"Copy everything, PC first": every version found, the PC-first layout, as in the game, in one click."""
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.wait_for_selector("#gf-quick:not([hidden])")
    page.uncheck("input[name=gf-version][value=ps2]")
    page.check("input[name=gf-mode][value=best]")
    page.check("input[name=gf-folders][value=type]")
    page.click("#gf-quick-start")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Done')", timeout=10000)
    assert calls("/api/game-files/start")[-1][1] == {"versions": ["xbox", "pc", "ps2", "prototype"], "mode": "pc",
                                                      "folders": "game"}
    assert page.is_checked("input[name=gf-mode][value=pc]")


def test_game_files_pc_first(page):
    """The PC first, then what only the others have: the choice reaches the server, PC/ and Not on the PC/ can be
    opened, and the other versions only offer their exclusives."""
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.check("input[name=gf-mode][value=pc]")
    page.click("#gf-start")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Done')", timeout=10000)
    assert calls("/api/game-files/start")[-1][1]["mode"] == "pc"
    page.wait_for_selector("#gf-result:not([hidden]) .gf-tab")
    sub = page.text_content("#gf-result-sub")
    assert "The PC first" in sub and "PC/ has the PC's" in sub and "came from Xbox" in sub
    assert page.is_visible("#gf-open-notpc") and page.is_hidden("#gf-open-best")
    page.click(".gf-tab:has-text('PC')")
    assert page.is_visible("#gf-open-version") and page.is_hidden("#gf-open-only")
    page.select_option("#gf-status", "picked")
    page.wait_for_function("[...document.querySelectorAll('#gf-list .st')].length > 0 && [...document.querySelectorAll('#gf-list .st')].every(e => e.textContent === 'copied')")
    page.click("#gf-open-notpc")
    page.wait_for_timeout(200)
    assert calls("/api/game-files/open")[-1][1] == {"folder": "notpc"}
    page.click(".gf-tab:has-text('PS2')")
    assert page.is_hidden("#gf-open-version")


def test_game_files_best_version_by_type(page):
    """The best version of each file, sorted by type: the choice reaches the server, then Best/ can be
    opened and each version's picks listed."""
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.check("input[name=gf-mode][value=best]")
    page.check("input[name=gf-folders][value=type]")
    page.click("#gf-start")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Done')", timeout=10000)
    assert calls("/api/game-files/start")[-1][1] == {"versions": ["xbox", "pc", "ps2", "prototype"], "mode": "best", "folders": "type"}
    page.wait_for_selector("#gf-result:not([hidden]) .gf-tab")
    assert "Best/ has" in page.text_content("#gf-result-sub") and "from PC" in page.text_content("#gf-result-sub")
    assert page.is_visible("#gf-open-best") and page.is_hidden("#gf-open-shared")
    page.click(".gf-tab:has-text('PC')")
    page.select_option("#gf-status", "picked")
    page.wait_for_function("[...document.querySelectorAll('#gf-list .st')].length > 0 && [...document.querySelectorAll('#gf-list .st')].every(e => e.textContent === 'best')")
    page.click("#gf-open-best")
    page.wait_for_timeout(200)
    assert calls("/api/game-files/open")[-1][1] == {"folder": "best"}
    assert page.is_hidden("#gf-open-version")                  # Best has no per-version folder, only exclusives
    page.click("#gf-open-only")
    page.wait_for_timeout(200)
    assert calls("/api/game-files/open")[-1][1] == {"folder": "only:pc"}


def test_page_runs_under_its_policy(browser):
    """The portal's Content-Security-Policy (tools/web_security.py) with nothing set aside: the page loads, its
    views and the workbench work, and the browser refuses nothing. (The other tests set the policy aside because
    Playwright's wait_for_function runs its check with eval, which the policy refuses.)"""
    reset()
    ctx = browser.new_context(viewport={"width": 1440, "height": 1000})
    ctx.add_init_script("window.__refused = []; document.addEventListener('securitypolicyviolation',"
                        " e => window.__refused.push(e.violatedDirective + ' ' + e.blockedURI));")
    outside = []
    ctx.on("request", lambda r: outside.append(r.url) if not r.url.startswith(BASE) and not r.url.startswith(("data:", "blob:")) else None)
    pg = ctx.new_page()
    errors = []
    pg.on("pageerror", lambda e: errors.append(str(e)))
    resp = pg.goto(BASE)
    csp = resp.headers["content-security-policy"]
    assert "frame-ancestors 'none'" in csp and "object-src 'none'" in csp and resp.headers["x-frame-options"] == "DENY"
    for _ in range(100):
        if "ONLINE" in (pg.text_content("#server-status-text") or "") and "Func" in (pg.text_content("#wb-title") or ""):
            break
        time.sleep(0.1)
    assert "Func" in pg.text_content("#wb-title")
    for view in ("dashboard", "scripts", "leaderboard", "how", "gamefiles", "sources", "workbench"):
        pg.click("#nav-" + view)
        time.sleep(0.3)
    fams = pg.evaluate("document.fonts.ready.then(() => [...document.fonts].filter(f => f.status === 'loaded').map(f => f.family))")
    assert any("Josefin Sans" in f for f in fams), fams
    assert pg.evaluate("window.__refused") == [], pg.evaluate("window.__refused")
    assert not errors, errors
    assert not [u for u in outside if "fonts.g" in u], outside
    ctx.close()


def test_other_sites_cant_frame_or_read_the_portal(browser):
    reset()
    ctx = browser.new_context()
    pg = ctx.new_page()
    pg.set_content(f'<iframe src="{BASE}" width="800" height="600"></iframe>')
    time.sleep(0.6)
    assert not pg.frames[1].url.startswith(BASE.rstrip("/"))        # refused: the browser shows its error page
    with urllib.request.urlopen(BASE + "api/state") as r:           # nor embed its answers in their pages
        assert r.headers["Cross-Origin-Resource-Policy"] == "same-origin" and r.headers["X-Frame-Options"] == "DENY"
        assert "default-src 'none'" in r.headers["Content-Security-Policy"]
    ctx.close()


def test_the_dashboard_lists_what_is_set_up_and_what_is_missing(page):
    page.click(".side-btn:has-text('Dashboard')")
    page.wait_for_selector("#setup-card:not([hidden])")
    assert page.text_content("#setup-stat") == "2 of 3 ready"
    rows = page.locator("#setup-list li")
    assert rows.count() == 3 and "ok" in rows.nth(0).get_attribute("class")
    last = rows.nth(2)
    assert "todo" in last.get_attribute("class") and "Blender" in last.text_content()
    assert "blender.org" in last.text_content() and "Missing" in last.text_content()


def test_functions_the_specs_describe_have_their_own_list(page):
    page.click(".side-btn:has-text('Workbench')")
    page.select_option("#lane-filter", "IN_GUIDE")
    wait_for_calls("/api/queue")
    page.wait_for_function("!Array.from(document.querySelectorAll('#view-workbench .sym, #view-workbench code'))"
                           ".some((e) => e.textContent.includes('EasyFunc'))")
    assert calls("/api/queue")[-1][1].get("lane") == "IN_GUIDE"


def test_the_pc_first_layout_is_the_default(page):
    assert page.is_checked("input[name=gf-mode][value=pc]")
    assert "Recommended" in page.text_content("label.gf-mode:has(input[value=pc]) b")
    assert page.evaluate("document.querySelector('input[name=gf-mode]').value") == "pc"      # and it comes first


def test_finding_a_cutscene_by_name(page):
    page.evaluate("""() => { GF_SCENES = [{name: 'NIS_01_intro', then: ['NIS_01_part2']}, {name: 'NIS_07_bank'},
                                          {name: 'NIS_12_boat'}]; fillGfScenes(); }""")
    assert page.locator("#gfb-scene option").count() == 3 and page.text_content("#gfb-scene-count") == "3 cutscenes"
    page.evaluate("() => { const f = document.getElementById('gfb-scene-find'); f.value = 'BANK'; fillGfScenes(); }")
    assert page.locator("#gfb-scene option").all_text_contents() == ["NIS_07_bank"]
    assert page.text_content("#gfb-scene-count") == "1 of 3 cutscenes"
    page.evaluate("() => { const f = document.getElementById('gfb-scene-find'); f.value = 'part2'; fillGfScenes(); }")
    assert page.locator("#gfb-scene option").all_text_contents() == ["NIS_01_intro, then NIS_01_part2"]
    page.evaluate("() => { const f = document.getElementById('gfb-scene-find'); f.value = 'zzz'; fillGfScenes(); }")
    assert page.locator("#gfb-scene option").all_text_contents() == ["No cutscene with that in its name"]
    assert page.is_disabled("#gfb-scene-open")


def test_game_files_open_on_the_pc_and_say_how_many_of_each_kind_there_are(page):
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.click("#gf-start")
    _gf_done(page)
    page.wait_for_selector("#gf-tabs .gf-tab")
    assert page.text_content("#gf-tabs .gf-tab[aria-selected=true]") == "PC"          # not just the first tab
    tiles = page.eval_on_selector_all("#gf-kinds .gf-kind", "els => els.map(e => e.innerText.replace(/\\s+/g, ' '))")
    assert tiles and all(" only in this version" in t for t in tiles)
    assert not any(t.startswith("0 ") for t in tiles)                                 # the big number is how many it has
    page.click("#gf-tabs .gf-tab:has-text('Xbox')")
    page.wait_for_function("document.getElementById('gfb-version-note').textContent.includes('pick PC here')")


def test_a_cutscenes_pieces_are_one_row_until_asked_for(page):
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.click("#gf-start")
    _gf_done(page)
    page.wait_for_selector("#gf-list .gf-row")
    rows = [{"path": f"cement.rcf/art/nis/MNIS_AMB_Tony_Beaten_by_Cops/stream{i}.p3d", "kind": "animations", "size": 1000,
             "status": "changed", "placed": "PC", "picked": False} for i in range(4)]
    rows.append({"path": "cement.rcf/art/nis/MNIS_Bank/stream0.p3d", "kind": "animations", "size": 500,
                 "status": "changed", "placed": "PC", "picked": False})
    rows.append({"path": "cement.rcf/art/other/walk.p3d", "kind": "animations", "size": 10, "status": "changed",
                 "placed": "PC", "picked": False})
    page.route("**/api/game-files/list*", lambda r: r.fulfill(json={"ok": True, "files": rows, "total": len(rows),
                                                                     "kinds": {"animations": len(rows)}}))
    page.evaluate("loadGfList()")
    page.wait_for_selector("#gf-list .gf-scene")
    shown = page.locator("#gf-list .gf-row:visible")
    assert shown.count() == 3                                       # one for each cutscene, one for the other file
    lead = page.locator("#gf-list .gf-scene").first
    assert "in 4 files that belong together" in lead.text_content()
    assert lead.locator(".p").text_content().startswith("cement.rcf/art/nis/MNIS_AMB_Tony_Beaten_by_Cops/")
    assert "stream0" not in lead.locator(".p").inner_text() and lead.locator(".z").text_content() == "4 KB"
    assert page.locator("#gf-list .gf-scene").nth(1).locator(".gf-pieces").is_hidden()   # a cutscene in one file
    lead.locator(".gf-pieces").click()
    assert page.locator("#gf-list .gf-row:visible").count() == 6 and lead.locator(".gf-pieces").text_content() == "Hide the files"
    lead.locator(".gf-pieces").click()
    assert page.locator("#gf-list .gf-row:visible").count() == 3
    page.unroute("**/api/game-files/list*")

