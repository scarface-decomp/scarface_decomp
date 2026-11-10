"""
The security headers the local portal sends with every answer. decomp_portal_server.py and the mock
(mock_portal_api.py) both use them, so the browser tests run the page under the same rules as the real portal.

What they do:
  * No other site can show the portal inside a frame (clickjacking: a page that hides the portal's buttons under
    its own and gets you to click them).
  * The page may load scripts, styles, fonts, pictures and sounds only from the portal itself, and talk only to
    the portal and to decomp.me. Its own script is inline (with onclick= handlers), so scripts need
    'unsafe-inline'; the rest is what stops an injected script from sending anything elsewhere.
  * Anything that isn't the page (JSON, pictures, downloads) gets a policy that runs nothing at all, and other
    sites can't embed it (Cross-Origin-Resource-Policy), except the decomp.me bridge, which decomp.me reads.
"""
from typing import Iterable, List, Tuple
from urllib.parse import urlparse


def origin(url: str) -> str:
    """'https://decomp.me/api' -> 'https://decomp.me'; '' for anything that isn't an http(s) address."""
    u = urlparse(str(url or "").strip())
    if u.scheme not in ("http", "https") or not u.netloc:
        return ""
    return f"{u.scheme}://{u.netloc}".lower()


def page_policy(connect: Iterable[str] = ()) -> str:
    """The Content-Security-Policy for the portal's page. connect: the outside addresses the page calls itself
    (decomp.me, or the instance SCARFACE_DECOMPME_URL names)."""
    extra = sorted({o for o in map(origin, connect) if o})
    return "; ".join([
        "default-src 'self'",
        "script-src 'self' 'unsafe-inline'",
        "style-src 'self' 'unsafe-inline'",
        "img-src 'self' data: blob:",
        "media-src 'self' blob:",
        "font-src 'self'",
        "connect-src " + " ".join(["'self'"] + extra),
        "frame-src 'none'",
        "object-src 'none'",
        "base-uri 'none'",
        "form-action 'self'",
        "frame-ancestors 'none'",
    ])


# For everything that isn't the page: run nothing, so a file opened in a tab can't act as a page. Pictures,
# sounds and movies opened on their own still show.
OTHER_POLICY = "default-src 'none'; img-src 'self' data:; media-src 'self'; style-src 'unsafe-inline'; frame-ancestors 'none'"


def headers(content_type: str, page_csp: str, shared: bool = False) -> List[Tuple[str, str]]:
    """The headers for one answer. shared: other sites may read it (the decomp.me bridge)."""
    html = (content_type or "").lower().startswith("text/html")
    out = [("X-Frame-Options", "DENY"),
           ("X-Content-Type-Options", "nosniff"),
           ("Referrer-Policy", "no-referrer"),
           ("Content-Security-Policy", page_csp if html else OTHER_POLICY)]
    if not shared:
        out.append(("Cross-Origin-Resource-Policy", "same-origin"))
    return out


def refuse_cross_site_get(method: str, path: str, sec_fetch_site: str, sec_fetch_mode: str, bridge_ok: bool) -> bool:
    """True when a GET came from a page on another site (the browser says so in Sec-Fetch-Site) and isn't one
    of the two things another site may do: open the portal's page, or (decomp.me) use the bridge. GET answers
    change nothing, but previews and downloads take real work, and other sites have no business starting them."""
    if method != "GET" or (sec_fetch_site or "").strip().lower() != "cross-site":
        return False
    if path in ("/", "/index.html") and (sec_fetch_mode or "").strip().lower() == "navigate":
        return False
    return not bridge_ok
