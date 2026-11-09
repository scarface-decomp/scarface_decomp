"""decomp.me through the browser: decomp.me turns away scripts and its pages cut the link to windows opened from
other sites, so a decomp.me tab of the person's runs a bookmark that asks the portal for jobs and sends the
results back. Here the real portal server talks to a made-up decomp.me on another origin, in a real browser."""
import base64
import importlib
import json
import sys
import threading
import urllib.error
import urllib.request
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

import pytest

from conftest import PORTAL, launch_chromium

sys.path.insert(0, str(PORTAL))
server = importlib.import_module("decomp_portal_server")
playwright = pytest.importorskip("playwright.sync_api")


# --------------------------------------------------------------------------- the job hand-over

def test_bridge_hands_jobs_over_and_back():
    b = server.Bridge()
    got = {}

    def tab():
        job = b.next(wait=5)
        got["job"] = job
        assert b.result({"id": job["id"], "ok": True, "slug": "abc"})

    th = threading.Thread(target=tab)
    th.start()
    res = b.run({"compile": {"source_code": "int x;"}}, timeout=5)
    th.join()
    assert res == {"id": got["job"]["id"], "ok": True, "slug": "abc"}
    assert got["job"]["compile"] == {"source_code": "int x;"}
    assert b.connected()


def test_bridge_gives_up_and_ignores_strays():
    b = server.Bridge()
    assert b.next(wait=0.05) is None                         # nothing to do
    assert b.run({"compile": {}}, timeout=0.2)["ok"] is False   # nobody answered
    assert b.jobs == [] and b.taken == {}
    assert not b.result({"id": 99, "ok": True})               # not a job anyone is waiting for
    assert not b.result({"id": "1", "ok": True})


# --------------------------------------------------------------------------- the real server, a fake decomp.me

class FakeDecompMe(BaseHTTPRequestHandler):
    calls = []

    def log_message(self, *a):
        pass

    def _send(self, code, body, ctype="application/json"):
        data = body if isinstance(body, bytes) else json.dumps(body).encode()
        self.send_response(code)
        self.send_header("Content-Type", ctype)
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    def do_GET(self):
        self._send(200, b"<!doctype html><title>decomp.me</title><body>fake decomp.me</body>", "text/html")

    def do_POST(self):
        raw = self.rfile.read(int(self.headers.get("Content-Length") or 0))
        if self.path == "/api/scratch":
            body = json.loads(raw) if self.headers.get("Content-Type", "").startswith("application/json") else {"multipart": len(raw)}
            FakeDecompMe.calls.append(("create", body))
            return self._send(201, {"slug": "Fake1", "claim_token": "tok1"})
        if self.path == "/api/scratch/Fake1/compile":
            body = json.loads(raw)
            FakeDecompMe.calls.append(("compile", body))
            ok = "error" not in body["source_code"]
            return self._send(200, {"success": ok, "compiler_output": "" if ok else "line 1: error",
                                    "right_object": base64.b64encode(b"\x7fELF-object").decode() if ok else ""})
        self._send(404, {"detail": "not found"})


def _serve(handler, host):
    srv = ThreadingHTTPServer((host, 0), handler)
    threading.Thread(target=srv.serve_forever, daemon=True).start()
    return srv


@pytest.fixture(scope="module")
def sites():
    mp = pytest.MonkeyPatch()
    fake = _serve(FakeDecompMe, "127.0.0.1")
    fake_origin = f"http://localhost:{fake.server_address[1]}"       # another origin than the portal's
    mp.setattr(server, "DME_BRIDGE_ORIGIN", fake_origin)
    mp.setattr(server, "BRIDGE_POLL_SECONDS", 1)
    mp.setattr(server, "BRIDGE", server.Bridge())
    portal = _serve(server.Handler, "127.0.0.1")
    yield {"portal": f"http://127.0.0.1:{portal.server_address[1]}", "fake": fake_origin}
    portal.shutdown()
    fake.shutdown()
    mp.undo()


def _req(url, method="GET", origin=None, body=None):
    headers = {"Content-Type": "application/json"}
    if origin:
        headers["Origin"] = origin
    req = urllib.request.Request(url, data=json.dumps(body).encode() if body is not None else None,
                                 headers=headers, method=method)
    try:
        with urllib.request.urlopen(req, timeout=10) as r:
            return r.status, dict(r.headers), r.read()
    except urllib.error.HTTPError as e:
        return e.code, dict(e.headers), e.read()


def test_only_decomp_me_may_take_jobs(sites):
    p = sites["portal"]
    code, headers, _ = _req(p + "/api/dme-bridge/next", "OPTIONS", origin=sites["fake"])
    assert code == 204 and headers["Access-Control-Allow-Origin"] == sites["fake"]
    assert headers["Access-Control-Allow-Private-Network"] == "true"
    assert _req(p + "/api/dme-bridge/next", "OPTIONS", origin="https://evil.example")[0] == 403
    assert _req(p + "/api/dme-bridge/next", origin="https://evil.example")[0] == 403
    assert _req(p + "/api/dme-bridge/next")[0] == 403                                   # no Origin: not a page
    code, _, body = _req(p + "/api/dme-bridge/result", "POST", origin="https://evil.example", body={"id": 1, "ok": True})
    assert code == 403
    code, _, body = _req(p + "/api/dme-bridge/run", "POST", origin=sites["fake"], body={"job": {"compile": {}}})
    assert code == 403                                                                  # decomp.me can't give jobs
    code, _, body = _req(p + "/api/dme-bridge/run", "POST", body={"job": {"compile": {"source_code": "x"}}})
    assert json.loads(body)["not_connected"]


def test_a_decomp_me_tab_compiles_for_the_portal(sites):
    FakeDecompMe.calls.clear()
    with playwright.sync_playwright() as pw:
        browser = launch_chromium(pw)
        try:
            ctx = browser.new_context()
            ctx.route("https://fonts.googleapis.com/**", lambda r: r.abort())
            portal = ctx.new_page()
            portal.goto(sites["portal"] + "/")
            mark = portal.evaluate("dmeBookmarklet()")
            assert sites["portal"] in mark

            tab = ctx.new_page()
            tab.goto(sites["fake"] + "/")
            tab.evaluate(mark)                      # what clicking the bookmark does
            tab.wait_for_function("document.title === 'Scarface: connected'", timeout=10000)
            assert portal.evaluate("dmeConnected()") is True

            job = {"create": {"json": {"compiler": "mwcps2-3.0.1b103-040528", "target_asm": "glabel f\n"}},
                   "compile": {"compiler": "mwcps2-3.0.1b103-040528", "source_code": "int f() { return 0; }",
                               "include_objects": True}}
            r = portal.evaluate("(job) => dmeRun(job)", job)
            assert r["ok"] and r["slug"] == "Fake1" and r["claim_token"] == "tok1" and r["success"]
            assert base64.b64decode(r["right_object"]) == b"\x7fELF-object"
            assert [c[0] for c in FakeDecompMe.calls] == ["create", "compile"]
            assert FakeDecompMe.calls[0][1]["target_asm"] == "glabel f\n"

            bad = portal.evaluate("(job) => dmeRun(job)", {"slug": "Fake1", "compile": {"source_code": "error here"}})
            assert bad["ok"] and not bad["success"] and bad["compiler_output"] == "line 1: error"

            # A second bookmark click doesn't start a second loop.
            tab.evaluate(mark)
            assert tab.evaluate("document.querySelectorAll('body > div').length") == 1
        finally:
            browser.close()
    # the tab polled recently
    assert server.BRIDGE.connected()
