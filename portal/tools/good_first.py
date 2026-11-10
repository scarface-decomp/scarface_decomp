#!/usr/bin/env python3
"""
Good first functions: small functions on the main versions (Xbox, PC) with a head start, for someone's first
match. Used by the portal's "Good first functions" list, the website (reports/progress.json) and the
Discord announcements.

A head start, best first:
  1. one of its look-alikes is already matched (the same code at another address: its C++ is a template);
  2. it was matched before the 2026-11-08 reset (so it is known to be doable);
  3. it stands for a group of look-alikes (matching it matches the others too);
  4. it has a name from the game's class information (a hint at what it does).
Then smaller first. Only one function per look-alike group.
"""

from __future__ import annotations

from typing import Dict, Iterable, List, Optional

MAIN_BINS = ("xb", "pc")
MAX_SIZE = 32                         # bytes: the quick and small tiers, about
KINDS = ("lookalike_matched", "matched_before", "group", "named")
PER_KIND = 3                          # on the website: a few of each kind, for variety


def _named(symbol: str) -> bool:
    return not symbol.startswith(("sub_", "func_", "FUN_"))


def rank(tasks: Iterable[dict], limit: Optional[int] = None) -> List[dict]:
    """The good first functions among tasks (the portal's queue), best first, each with a 'why'."""
    tasks = list(tasks)
    groups_done = {t.get("lookalike_group") for t in tasks if t.get("status") == "VERIFIED" and t.get("lookalike_group")}
    scored = []
    for t in tasks:
        if t.get("bin") not in MAIN_BINS or t.get("status") not in ("UNCLAIMED", "PARTIAL") or t.get("claimed_by"):
            continue
        size = int(t.get("size") or 0)
        if not 0 < size <= MAX_SIZE:
            continue
        group, others = t.get("lookalike_group"), int(t.get("lookalikes") or 0)
        if group and group in groups_done:
            score, why = 0, "a look-alike is already matched: its C++ is a good start"
        elif str(t.get("hint", "")).startswith("Matched before"):
            score, why = 1, "it was matched before the reset, so it can be done"
        elif t.get("lookalike_rep") and others >= 2:
            score, why = 2, f"matching it also matches its {others:,} look-alikes"
        elif _named(t.get("symbol", "")):
            score, why = 3, "the game's class information names it"
        else:
            continue
        scored.append((score, size, -others, t.get("fva_int", 0), t, why))
    scored.sort(key=lambda s: s[:4])
    out, seen_groups = [], set()
    for score, size, _o, _va, t, why in scored:
        group = t.get("lookalike_group")
        if group and group in seen_groups:
            continue
        if group:
            seen_groups.add(group)
        out.append({"id": t.get("id", ""), "bin": t["bin"], "va": t.get("va", ""), "symbol": t.get("symbol", ""),
                    "size": size, "why": why, "kind": KINDS[score]})
        if limit and len(out) >= limit:
            break
    return out


def for_site(queue: Optional[list], registry: dict, previous: Optional[List[Dict]], n: int = 10) -> List[Dict]:
    """The list for reports/progress.json: from the queue when there is one, else the last list without the
    functions matched since."""
    done = {k.lower() for k in registry.get("entries", {})}
    if queue is not None:
        ranked = [p for p in rank(queue) if _key(p) not in done]
        picks = []
        for kind in KINDS:
            picks += [p for p in ranked if p["kind"] == kind][:PER_KIND]
        picks += [p for p in ranked if p not in picks]
    else:
        picks = [p for p in previous or [] if _key(p) not in done]
    return picks[:n]


def _key(p: dict) -> str:
    return f"{p['bin']}:{p['va'].split()[-1]}".lower()
