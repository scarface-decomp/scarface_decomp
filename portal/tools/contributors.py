"""One name per person on the leaderboards.

A handle typed two ways (a typo in the portal's name box, a renamed account) would show one person twice on
the website and the portal. `reports/contributor_aliases.json` maps each other spelling to the name the person
uses; the counts add them up under that name. The registry itself keeps each match as it was recorded.
"""
from __future__ import annotations

import json
from collections import Counter
from pathlib import Path
from typing import Dict, Iterable, Optional

ALIASES_FILE = Path(__file__).resolve().parents[2] / "reports" / "contributor_aliases.json"


def aliases(path: Optional[Path] = None) -> Dict[str, str]:
    """{other spelling: the name to show}. An unreadable or missing file means no aliases."""
    try:
        data = json.loads(Path(path or ALIASES_FILE).read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return {}
    table = data.get("aliases", data) if isinstance(data, dict) else {}
    return {str(k): str(v) for k, v in table.items() if isinstance(v, str) and v and k != v}


def canonical(name: str, table: Optional[Dict[str, str]] = None) -> str:
    table = aliases() if table is None else table
    seen = set()
    while name in table and name not in seen:      # follow a chain, never loop
        seen.add(name)
        name = table[name]
    return name


def count(entries: Iterable[dict], table: Optional[Dict[str, str]] = None,
          unattributed: Optional[str] = None) -> Counter:
    """Matches per person. Entries with no `verified_by` are counted under `unattributed` when it is given,
    and left out otherwise."""
    table = aliases() if table is None else table
    c: Counter = Counter()
    for e in entries:
        who = e.get("verified_by")
        if who:
            c[canonical(who, table)] += 1
        elif unattributed:
            c[unattributed] += 1
    return c
