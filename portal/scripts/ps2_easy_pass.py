#!/usr/bin/env python3
"""
Run the PS2 easy pass: the portal tries its own starter code on the open PS2 functions and records every
exact match under your handle.

    python portal/scripts/ps2_easy_pass.py            (the portal must be running)

What it tries, smallest functions first:

* C++ written from a function's two or three instructions (an empty function, one that returns or stores a
  member, one that returns a constant or a global);
* the C++ of an already matched PS2 look-alike, with this function's addresses;
* the C++ of the matched Xbox function it is paired with, when that code names no address.

PS2 code is compiled on decomp.me, through your own decomp.me tab: open https://decomp.me, click the
"Scarface -> decomp.me" bookmark in that tab (docs/PS2.md has the three steps) and leave it open. The pass
is a light user of decomp.me on purpose: everything goes through one scratch, the same text is never
compiled twice, real compiles are two seconds apart, and a run stops after 400 of them. Run it again
later to go on from where it stopped.

It asks for your handle and PIN (the PIN isn't shown, stored or printed). Ctrl+C stops the pass.
When it is done, commit reports/ and reconstructed_src/ as the portal left them.
"""

from __future__ import annotations

import argparse
import getpass
import json
import sys
import time
import urllib.error
import urllib.request


def call(base: str, path: str, body: dict) -> dict:
    req = urllib.request.Request(base + path, data=json.dumps(body).encode(), headers={"Content-Type": "application/json"})
    try:
        with urllib.request.urlopen(req, timeout=120) as r:
            return json.loads(r.read().decode("utf-8", "replace"))
    except urllib.error.HTTPError as e:
        try:
            return json.loads(e.read().decode("utf-8", "replace"))
        except ValueError:
            return {"ok": False, "error": f"the portal answered {e.code}"}


def line(st: dict) -> str:
    return (f"tried {st.get('tried', 0):,} of {st.get('total', 0):,}   matched {st.get('matched', 0):,}   "
            f"compiles on decomp.me {st.get('compiles', 0):,}")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--portal", default="http://127.0.0.1:8085", help="where your portal is running")
    args = ap.parse_args()
    user = input("Your handle: ").strip()
    creds = {"user": user, "pin": getpass.getpass("Your PIN (not shown): ")}
    try:
        st = call(args.portal, "/api/ps2-easy-pass", creds)
    except OSError:
        print("The portal isn't answering at", args.portal, "- start it (START_PORTAL.bat) and try again.")
        return 1
    if not st.get("ok"):
        print(st.get("error") or "The portal would not start the pass.")
        return 1
    print("Started. Leave your decomp.me tab open.")
    last = ""
    try:
        while True:
            time.sleep(3)
            st = call(args.portal, "/api/ps2-easy-pass", dict(creds, status=True))
            now = line(st)
            if now != last:
                print("  " + now + (f"   last: {st['last']}" if st.get("last") and st.get("running") else ""))
                last = now
            if not st.get("running"):
                break
    except KeyboardInterrupt:
        call(args.portal, "/api/ps2-easy-pass", dict(creds, stop=True))
        print("\nStopping after the function it is on.")
        return 0
    except OSError:
        print("Lost the portal; whatever it matched so far is recorded.")
        return 1
    if st.get("last"):
        print(st["last"])
    print(f"Done: {st.get('matched', 0):,} PS2 function(s) recorded. Commit reports/ and reconstructed_src/ as the portal left them.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
