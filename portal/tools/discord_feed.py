#!/usr/bin/env python3
"""
Tell the Discord about new matches: when a maintainer's portal pushes to GitHub ("Sync to GitHub" or "Submit
your work"), it posts the functions matched since the last post, the progress, and a few good first
functions, to a Discord webhook.

Nothing is posted unless a maintainer sets a webhook up on their own computer, in one of two ways (the URL is
a secret: it never goes in the repository):

    the environment variable SCARFACE_DISCORD_WEBHOOK, or
    portal/private/discord_webhook.txt (portal/private/ is never committed)

In Discord: Server Settings > Integrations > Webhooks > New Webhook, pick the channel, Copy Webhook URL.
The first push after setting it up only notes what is already matched; posts start with the next new
match. Anyone else can follow docs/feed.xml (an Atom feed of new matches) with a feed bot instead.
"""

from __future__ import annotations

import json
import os
import re
import urllib.error
import urllib.request
from pathlib import Path
from typing import Callable, Dict, List, Optional, Tuple

import ps2_overlay

ENV = "SCARFACE_DISCORD_WEBHOOK"
URL_FILE = Path("portal") / "private" / "discord_webhook.txt"
STATE_FILE = Path("portal") / "private" / "discord_announced.json"
WEBHOOK_RE = re.compile(r"^https://(?:(?:ptb|canary)\.)?discord(?:app)?\.com/api/webhooks/\d+/[A-Za-z0-9_-]+$")
SITE = "https://scarface-decomp.pages.dev/"
BIN_WORD = {"pc": "PC", "xb": "Xbox", "proto": "Xbox prototype", "ps2": "PS2",
            **{o.bin: f"PS2 {o.label} overlay" for o in ps2_overlay.OVERLAYS}}
MAX_LINES = 15
LIMIT = 1900                                  # Discord allows 2,000 characters a message


def webhook_url(base: Path) -> Optional[str]:
    """The webhook set up on this computer, if it is one (only Discord webhook addresses are used)."""
    url = os.environ.get(ENV, "").strip()
    if not url:
        try:
            url = (base / URL_FILE).read_text(encoding="utf-8").strip()
        except OSError:
            return None
    return url if WEBHOOK_RE.match(url) else None


def _plain(text: str, limit: int = 60) -> str:
    """Text as plain text in Discord: no formatting, no mentions."""
    text = " ".join(str(text).split())[:limit]
    text = re.sub(r"([\\*_~`|>#\[\]()])", r"\\\1", text)
    return text.replace("@", "@\u200b")


def message(new: List[dict], done: int, total: int, good: List[dict]) -> str:
    n = len(new)
    pct = done / total * 100 if total else 0.0
    lines = [f"**{n} new match{'' if n == 1 else 'es'}** on GitHub. The released game is now "
             f"{done:,} of {total:,} functions ({pct:.2f}%)."]
    for e in sorted(new, key=lambda e: (e.get("verified_at") or "", e.get("va", "")))[:MAX_LINES]:
        size = int(e.get("size", 0))
        who = _plain(e.get("verified_by") or "unattributed")
        sym = str(e.get("symbol", "")).replace("`", "'")
        what = f": {_plain(e['what'], 90)}" if e.get("what") else ""
        lines.append(f"• `{sym}` ({BIN_WORD.get(e.get('bin'), e.get('bin'))} {e.get('va', '')}, "
                     f"{size} byte{'' if size == 1 else 's'}) by {who}{what}")
    if n > MAX_LINES:
        lines.append(f"…and {n - MAX_LINES:,} more.")
    if good:
        picks = ", ".join(f"`{str(p['symbol']).replace('`', chr(39))}` ({BIN_WORD.get(p['bin'], p['bin'])}, {p['size']} B)"
                          for p in good[:3])
        lines.append(f"Want one? Good first functions: {picks}. In the portal: *Good first functions*.")
    lines.append(f"<{SITE}>")
    text = "\n".join(lines)
    while len(text) > LIMIT and len(lines) > 3:
        lines.pop(-3)                       # drop match lines from the end until it fits
        text = "\n".join(lines)
    return text[:LIMIT]


def post(url: str, content: str, timeout: float = 15) -> Tuple[bool, str]:
    body = json.dumps({"content": content, "username": "Scarface decomp",
                       "allowed_mentions": {"parse": []}}).encode("utf-8")
    req = urllib.request.Request(url, data=body, method="POST",
                                 headers={"Content-Type": "application/json", "User-Agent": "scarface-decomp-portal"})
    try:
        with urllib.request.urlopen(req, timeout=timeout) as r:
            return 200 <= r.status < 300, ""
    except urllib.error.HTTPError as e:
        return False, f"Discord answered HTTP {e.code}"
    except (urllib.error.URLError, OSError) as e:
        return False, f"couldn't reach Discord: {e}"


def announce_new(base: Path, registry: dict, done: int, total: int, good: List[dict],
                 send: Callable[[str, str], Tuple[bool, str]] = post) -> Dict[str, object]:
    """Post the matches not announced yet. Returns {"posted": n} or {"skipped": why}."""
    url = webhook_url(base)
    if not url:
        return {"skipped": "no webhook set up"}
    entries = registry.get("entries", {})
    state_path = base / STATE_FILE
    try:
        seen = set(json.loads(state_path.read_text(encoding="utf-8")).get("announced", []))
        first = False
    except (OSError, ValueError):
        seen, first = set(), True
    new = [] if first else [e for k, e in entries.items() if k not in seen]
    if new:
        ok, err = send(url, message(new, done, total, good))
        if not ok:
            return {"skipped": err}
    state_path.parent.mkdir(parents=True, exist_ok=True)
    state_path.write_text(json.dumps({"announced": sorted(entries)}, indent=1) + "\n", encoding="utf-8")
    return {"posted": len(new)} if new else {"skipped": "nothing new" if not first else "first run: noted what is matched"}
