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
    wait_until_loaded(pg)
    yield pg
    assert not errors, errors
    ctx.close()


def wait_until_loaded(pg):
    """The startup screen covers the page (and makes it inert) until the first data is in."""
    pg.wait_for_function("!document.querySelector('.app-shell').hasAttribute('inert')")


def fresh_page(browser, viewport=None):
    ctx = browser.new_context(viewport=viewport or {"width": 1440, "height": 1000})
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
    prompts = []
    replies = ["int bad(", "int good() { return 1; }", "int worse() { }", "int good() { return 1; }", "int good() { return 1; }"]

    def ai(route):
        prompts.append(json.loads(route.request.post_data)["prompt"])
        code = replies[min(len(prompts), len(replies)) - 1]
        route.fulfill(json={"ok": True, "reply": "```cpp\n" + code + "\n```", "used_model": "m"})

    def verify(route):
        code = json.loads(route.request.post_data)["cpp_code"]
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
    page.wait_for_function("document.getElementById('verify-status').textContent.includes('Best after')", timeout=30000)
    assert len(prompts) == 5
    assert "did not compile. It was:" in prompts[1] and "int bad(" in prompts[1] and "C2059" in prompts[1]
    assert "The current best C++ (attempt 2) compiled and matched 8/12" in prompts[2]
    assert "int good() { return 1; }" in prompts[2].split("Current best C++")[1]
    assert "Attempt 3 matched only 4/12 bytes" in prompts[3] and "The current best C++ (attempt 2)" in prompts[3]
    assert "int good() { return 1; }" in page.input_value("#wb-editor")


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


def test_game_files_stop(page):
    page.goto(BASE + "#gamefiles")
    page.wait_for_selector("#gf-versions .gf-ver")
    page.click("#gf-start")
    page.wait_for_selector("#gf-stop:not([hidden])")
    page.click("#gf-stop")
    page.wait_for_function("document.getElementById('gf-progress-text').textContent.startsWith('Stopped')", timeout=10000)
    assert page.is_enabled("#gf-start") and page.is_hidden("#gf-stop")


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
