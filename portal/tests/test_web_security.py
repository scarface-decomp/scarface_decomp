"""The portal's security headers and its refusal of other sites (tools/web_security.py), on the real server's
request handler: no game files or compiler needed."""
import importlib
import sys
import threading
import urllib.error
import urllib.request
from http.server import ThreadingHTTPServer

import pytest

import conftest

sys.path.insert(0, str(conftest.PORTAL / "tools"))
import web_security as WS  # noqa: E402


@pytest.fixture(scope="module")
def base():
    sys.path.insert(0, str(conftest.PORTAL))
    S = importlib.import_module("decomp_portal_server")
    srv = ThreadingHTTPServer(("127.0.0.1", 0), S.Handler)
    threading.Thread(target=srv.serve_forever, daemon=True).start()
    yield f"http://127.0.0.1:{srv.server_address[1]}"
    srv.shutdown()


def get(url, **headers):
    try:
        with urllib.request.urlopen(urllib.request.Request(url, headers=headers), timeout=30) as r:
            return r.status, dict(r.headers), r.read()
    except urllib.error.HTTPError as e:
        return e.code, dict(e.headers), e.read()


def test_the_page_gets_its_policy_and_cant_be_framed(base):
    code, h, body = get(base + "/")
    assert code == 200 and b"/fonts/fonts.css" in body and b"fonts.googleapis" not in body
    csp = h["Content-Security-Policy"]
    for part in ("frame-ancestors 'none'", "object-src 'none'", "base-uri 'none'", "form-action 'self'",
                 "connect-src 'self' https://decomp.me", "font-src 'self'"):
        assert part in csp, part
    assert h["X-Frame-Options"] == "DENY" and h["X-Content-Type-Options"] == "nosniff"
    assert h["Referrer-Policy"] == "no-referrer" and h["Cross-Origin-Resource-Policy"] == "same-origin"
    assert list(h).count("X-Content-Type-Options") == 1


def test_files_that_arent_the_page_run_nothing(base):
    code, h, _ = get(base + "/favicon.svg")
    assert code in (200, 204) and h["Content-Security-Policy"].startswith("default-src 'none'")


def test_the_fonts_come_from_the_portal(base):
    code, h, css = get(base + "/fonts/fonts.css")
    assert code == 200 and h["Content-Type"].startswith("text/css") and b"@font-face" in css
    code, h, data = get(base + "/fonts/josefin-sans-latin-400-normal.woff2")
    assert code == 200 and h["Content-Type"] == "font/woff2" and data[:4] == b"wOF2"
    for bad in ("/fonts/../decomp_portal_server.py", "/fonts/OFL-anton.txt", "/fonts/missing.woff2", "/fonts/%2e%2e%2fx.css"):
        assert get(base + bad)[0] in (403, 404), bad


def test_other_sites_cant_start_work_with_a_get(base):
    """The browser tells the portal where a request comes from (Sec-Fetch-Site). From another site, only opening
    the page itself is allowed, and decomp.me's own page using the bridge."""
    code, _, body = get(base + "/api/health", **{"Sec-Fetch-Site": "cross-site", "Sec-Fetch-Mode": "no-cors"})
    assert code == 403 and b"other websites" in body
    code, _, _ = get(base + "/", **{"Sec-Fetch-Site": "cross-site", "Sec-Fetch-Mode": "navigate"})
    assert code == 200
    code, _, _ = get(base + "/download/ai-handoff", **{"Sec-Fetch-Site": "cross-site", "Sec-Fetch-Mode": "navigate"})
    assert code == 403
    for site in ("same-origin", "none", ""):                      # the portal's own page, a typed address, old browsers
        assert get(base + "/api/health", **({"Sec-Fetch-Site": site} if site else {}))[0] == 200, site


def test_the_bridge_is_left_open_to_decomp_me_only():
    assert not WS.refuse_cross_site_get("GET", "/api/dme-bridge/next", "cross-site", "cors", bridge_ok=True)
    assert WS.refuse_cross_site_get("GET", "/api/dme-bridge/next", "cross-site", "cors", bridge_ok=False)
    assert dict(WS.headers("application/json", "x", shared=True)).get("Cross-Origin-Resource-Policy") is None


def test_the_policy_names_only_real_addresses():
    csp = WS.page_policy(("https://decomp.me/api", "https://decomp.me", "javascript:alert(1)", "", "http://my-dme.local:8000/x"))
    assert "connect-src 'self' http://my-dme.local:8000 https://decomp.me;" in csp
    assert "javascript" not in csp
    assert "'unsafe-eval'" not in csp


def test_what_contributors_install_is_pinned_and_wheels_only():
    """START_PORTAL.bat and start_portal.sh install portal/requirements.txt on contributors' computers: exact
    versions only (a new or hijacked release can't arrive by itself), as ready-made wheels (no setup code runs)."""
    root = conftest.PORTAL.parent
    lines = [l.split("#", 1)[0].strip() for l in (conftest.PORTAL / "requirements.txt").read_text(encoding="utf-8").splitlines()]
    reqs = [l for l in lines if l]
    assert reqs and all("==" in r.split(";")[0] and not any(c in r.split(";")[0] for c in "<>~*") for r in reqs), reqs
    for launcher in ("START_PORTAL.bat", "start_portal.sh"):
        text = (root / launcher).read_text(encoding="utf-8")
        install = [l for l in text.splitlines() if "pip install" in l and not l.lstrip().startswith(("rem", "#"))]
        assert install and all("--only-binary :all:" in l for l in install), (launcher, install)
