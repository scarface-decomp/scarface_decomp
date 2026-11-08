"""
End-to-end tests for website_kit/index.html against tools/mock_portal_api.py, in headless Chrome.
Run:  python3 -m pytest -q tests/test_frontend_e2e.py
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


def reset(lease_sec=900, no_login=False, legacy_claim=False, dme_browser_fail=False, **delays):
    payload = {"delays": {"verify": 0.15, "ai": 0.25, "fast": 0.05, **delays}, "lease_sec": lease_sec,
               "no_login": no_login, "legacy_claim": legacy_claim, "dme_browser_fail": dme_browser_fail}
    req = urllib.request.Request(BASE + "__reset", data=json.dumps(payload).encode(),
                                 headers={"Content-Type": "application/json"}, method="POST")
    urllib.request.urlopen(req).read()


def calls(path=None):
    data = json.loads(urllib.request.urlopen(BASE + "__calls").read())
    return [c for c in data if path is None or c[0] == path]


@pytest.fixture(scope="module")
def browser(server):
    with playwright.sync_playwright() as p:
        b = launch_chromium(p)
        yield b
        b.close()


@pytest.fixture
def page(browser):
    reset()
    ctx = browser.new_context(viewport={"width": 1440, "height": 1000})
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
    yield pg
    assert not errors, errors
    ctx.close()


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
    ctx = browser.new_context(viewport={"width": 390, "height": 844})
    ctx.route("https://fonts.googleapis.com/**", lambda r: r.abort())
    ctx.route("https://fonts.gstatic.com/**", lambda r: r.abort())
    pg = ctx.new_page()
    errors = []
    pg.on("pageerror", lambda e: errors.append(str(e)))
    pg.goto(BASE)
    pg.wait_for_function("document.getElementById('server-status-text').textContent.includes('ONLINE')")
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
    """decomp_portal_server.py has no /api/login and answers ok:true to a claim it did not grant."""
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


def test_decompme_falls_back_to_the_server(page):
    reset(dme_browser_fail=True)
    page.reload()
    page.wait_for_function("document.getElementById('wb-title').textContent.includes('Func')")
    with page.context.expect_page() as info:
        page.click("#btn-decompme")
    info.value.wait_for_url("**/scratch/server1/claim?token=srv")
    assert [c for c in calls("/api/decompme") if c[1].get("create")]
