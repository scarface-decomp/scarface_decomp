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

On GitHub, .github/workflows/discord.yml does the same for every push to main, whoever pushed and however
(git push, the portal, a merged pull request): it compares the registry and the names before and after the
push and posts what is new, matches, descriptions and names, to the webhook kept in the repository's secret
DISCORD_WEBHOOK (Settings > Secrets and variables > Actions). Use one or the other, not both, or each
match is posted twice.

    python portal/tools/discord_feed.py --old-registry OLD.json [--old-names OLD_NAMES.json] [--dry-run]
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


def push_message(old: dict, new: dict, old_names: dict, new_names: dict, progress: dict) -> Optional[str]:
    """What a push brought, as one Discord message, or None when it brought nothing to say: new matches (as
    message() writes them), then how many functions got a description or a name."""
    before, after = old.get("entries", {}), new.get("entries", {})
    matched = [e for k, e in after.items() if k not in before]
    described = [k for k, e in after.items() if (e.get("what") or "").strip()
                 and (e.get("what") or "").strip() != ((before.get(k) or {}).get("what") or "").strip()]
    named = [k for k in new_names.get("names", {}) if k not in old_names.get("names", {})]
    if not (matched or described or named):
        return None
    v, q = progress.get("verified") or {}, progress.get("queue") or {}
    done = int(v.get("total", 0))
    total = done + int(q.get("total", 0)) if q else 0
    lines = []
    if matched:
        lines.append(message(matched, done, total, list(progress.get("good_first") or [])))
    extra = []
    if described:
        how = progress.get("described") or {}
        extra.append(f"**{len(described):,}** function{'' if len(described) == 1 else 's'} got a one-line description"
                     + (f" ({how.get('total', 0):,} of the released game's rebuilt functions have one now)" if how else ""))
    if named:
        extra.append(f"**{len(named):,}** got a real name in reports/names.json")
    if extra:
        lines.append(("Also: " if matched else "") + "; ".join(extra) + "." + ("" if matched else f"\n<{SITE}>"))
    return "\n".join(lines)[:LIMIT]


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


def main(argv=None) -> int:
    import argparse
    import sys
    ap = argparse.ArgumentParser(description="Post what a push to main brought to the Discord webhook.")
    ap.add_argument("--old-registry", required=True, help="reports/verified_registry.json as it was before the push")
    ap.add_argument("--old-names", default="", help="reports/names.json as it was before the push")
    ap.add_argument("--dry-run", action="store_true", help="print the message instead of posting it")
    args = ap.parse_args(argv)
    base = Path(__file__).resolve().parents[2]

    def load(path) -> dict:
        try:
            return json.loads(Path(path).read_text(encoding="utf-8"))
        except (OSError, ValueError):
            return {}
    text = push_message(load(args.old_registry), load(base / "reports" / "verified_registry.json"),
                        load(args.old_names) if args.old_names else load(base / "reports" / "names.json"),
                        load(base / "reports" / "names.json"), load(base / "reports" / "progress.json"))
    if not text:
        print("Nothing new to post.")
        return 0
    if args.dry_run:
        print(text)
        return 0
    url = webhook_url(base)
    if not url:
        print("No Discord webhook set up (SCARFACE_DISCORD_WEBHOOK): not posted.")
        return 0
    ok, err = post(url, text)
    print("Posted to Discord." if ok else f"Not posted: {err}")
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
