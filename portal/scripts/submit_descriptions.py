#!/usr/bin/env python3
"""Send prepared one-line descriptions ("what it does") of rebuilt functions to your local portal.

Each file is reports/to_submit/descriptions_*.json:

    {"schema": "scarface_descriptions_v1", "by": "who wrote them",
     "descriptions": {"xb:0x00329310": {"what": "One plain sentence, at most 160 characters.",
                                        "how": "read"}, ...}}

"how" says where the sentence came from: "read" (someone read the function and what it calls), "shape" (a
rule on the shape of the code alone: destructors, class records), "twin" (copied from the same bytes in
another version) or "human" (the default). The website counts them apart.

With the portal running (START_PORTAL.bat) and you signed in as a maintainer:

    python portal/scripts/submit_descriptions.py

The portal records each description on the function (credited to the file's "by"), skips functions that
aren't rebuilt yet or already say the same, turns down (with the reason) a sentence that is longer than 160
characters or only restates the code, and the file is deleted once it's taken. Nothing is compiled:
descriptions are text only. Standard library only.
"""

from __future__ import annotations

import argparse
import getpass
import json
import sys
import time
import urllib.error
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
FOLDER = ROOT / "reports" / "to_submit"


def call(base, path, body=None):
    req = urllib.request.Request(base + path, data=json.dumps(body).encode() if body is not None else None,
                                 headers={"Content-Type": "application/json"} if body is not None else {})
    try:
        with urllib.request.urlopen(req, timeout=300) as r:
            return json.loads(r.read().decode("utf-8", "replace"))
    except urllib.error.HTTPError as e:
        try:
            return json.loads(e.read().decode("utf-8", "replace"))
        except ValueError:
            return {"ok": False, "error": f"the portal answered {e.code}"}


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--portal", default="http://127.0.0.1:8085")
    ap.add_argument("--folder", default=str(FOLDER))
    args = ap.parse_args()
    files = sorted(Path(args.folder).glob("descriptions_*.json"))
    if not files:
        print("Nothing to send: no descriptions_*.json in", args.folder)
        return 0
    try:
        call(args.portal, "/api/queue?limit=1")
    except OSError:
        print("The portal isn't answering at", args.portal, "- start it (START_PORTAL.bat) and try again.")
        return 1
    user = input("Your handle: ").strip()
    pin = getpass.getpass("Your PIN (not shown): ")
    bad = 0
    for path in files:
        data = json.loads(path.read_text(encoding="utf-8"))
        by = str(data.get("by") or user)[:64]
        notes = {k: {"what": v.get("what", ""), "what_by": str(v.get("by") or by)[:64], "how": v.get("how", "")}
                 for k, v in (data.get("descriptions") or {}).items() if isinstance(v, dict)}
        bundle = {"format": "scarface-decomp-submission", "submitted_by": by, "entries": {}, "descriptions": notes}
        res = call(args.portal, "/api/import-submission", {"user": user, "pin": pin, "bundle": bundle})
        if not res.get("ok"):
            print(f"  NO   {path.name}: {res.get('error')}")
            bad += 1
            continue
        while True:
            time.sleep(1)
            st = call(args.portal, "/api/import-status")
            if not st.get("running"):
                break
        if st.get("error"):
            print(f"  NO   {path.name}: {st['error']}")
            bad += 1
            continue
        refused = st.get("refused") or []
        for r in refused[:20]:
            print(f"  no   {r.get('key')}: {r.get('reason')}")
        if len(refused) > 20:
            print(f"  ... and {len(refused) - 20} more turned down")
        print(f"  ok   {path.name}: {st.get('described', 0)} of {len(notes)} described "
              "(the rest weren't rebuilt here yet, already said the same, or were turned down above)")
        if refused:
            keep = {r.get("key") for r in refused}
            data["descriptions"] = {k: v for k, v in (data.get("descriptions") or {}).items() if k in keep}
            path.write_text(json.dumps(data, indent=1, ensure_ascii=False) + "\n", encoding="utf-8")
            print(f"       {path.name} now holds only the {len(refused)} turned down: fix them and send it again.")
            bad += 1
            continue
        path.unlink()
    print("Done. Commit reports/ and reconstructed_src/ as the portal left them.")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
