#!/usr/bin/env python3
"""
Generate the browsable source views from reports/verified_registry.json:

  reconstructed_src/Original_Binary_Order_PC_1002.cpp   every PC function, ascending address
  reconstructed_src/Original_Binary_Order_Xbox.cpp       every Xbox function, ascending address
  reconstructed_src/Original_Binary_Order_Proto.cpp      every function of the April 2006 prototype
  reconstructed_src/Original_Binary_Order_PS2.cpp        every function of the PS2 game (SLUS_211.11)
  reconstructed_src/pc/<subsystem>/<Class>.cpp           the matched code grouped by class
  reconstructed_src/xbox/<subsystem>/<Class>.cpp

With the function list (the portal's queue), the address-order files hold every function of the game file:
matched ones as their C++, the rest as one "// [TODO]" line each in their place, under a header that says
how complete the file is. Without it (no game files here), they hold the matched functions only.

These files are generated. Every block compiles on its own (that is how it was verified), so a
whole file is NOT one translation unit. Edit the registry (via the portal or
portal/scripts/reverify_all.py), not these files.
"""

from __future__ import annotations

import os
import re
import urllib.parse
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional

import ps2_overlay

BIN_INFO = {
    "pc": ("Original_Binary_Order_PC_1002.cpp", "pc", "Retail PC Scarface.exe v1.00.2"),
    "xb": ("Original_Binary_Order_Xbox.cpp", "xbox", "Retail Xbox default.xbe"),
    "proto": ("Original_Binary_Order_Proto.cpp", "proto", "April 2006 prototype game.xbe"),
    "ps2": ("Original_Binary_Order_PS2.cpp", "ps2", "Retail PS2 SLUS_211.11"),
}
# The PS2 program's code overlays: one file each, as they all load at the same addresses.
for _o in ps2_overlay.OVERLAYS:
    _stem = _o.file[:-len("f.bin")].replace("Overlay", "")          # ModalsOverlay1f.bin -> Modals1
    BIN_INFO[_o.bin] = (f"Original_Binary_Order_PS2_{_stem}.cpp", _o.bin.replace("ps2", "ps2_", 1),
                        f"Retail PS2 overlay {_o.file} ({_o.label}), loaded at 0x845480")
PS2_CODEWARRIOR = "Metrowerks CodeWarrior for PS2 3.0.1 (decomp.me: mwcps2-3.0.1b103-040528, -O3 -lang c++ -str readonly)"
# The PS2 game has its own compiler; everything else was built with Visual C++ 2003.
BIN_COMPILER = {b: PS2_CODEWARRIOR for b in ("ps2",) + ps2_overlay.BINS}


def classify_subsystem_and_class(sym: str):
    s_low = sym.lower()
    parts = [p for p in sym.split("::") if p]
    ns = parts[0].lower() if len(parts) >= 3 else ""
    cls_raw = parts[-2] if len(parts) >= 2 else "GlobalFunctions"
    cls_clean = re.sub(r"[^A-Za-z0-9_]", "_", cls_raw) or "EngineUnit"
    if ns in ("core", "radcore") or "drivethread" in s_low or "platform" in s_low or "controller" in s_low or "memory" in s_low:
        return "core", cls_clean
    if ns in ("audio", "radmusic", "radsound") or "sound" in s_low or "stream" in s_low:
        return "audio", cls_clean
    if ns in ("pure3d", "p3d", "content", "render") or "shader" in s_low or "pddi" in s_low:
        return "pure3d", cls_clean
    if ns in ("fe", "frontend", "gui", "hud") or "hud" in s_low or "menu" in s_low:
        return "fe", cls_clean
    if "aiaction" in s_low or ns == "ai" or "npc" in s_low:
        return "ai", cls_clean
    if ns in ("om", "objectmodel"):
        return "om", cls_clean
    if ns in ("world", "sim", "physics") or "collision" in s_low:
        return "world", cls_clean
    return "engine", cls_clean


def entry_path(e: dict) -> str:
    """Where write_outputs puts this entry, relative to the repository root."""
    info = BIN_INFO.get(e.get("bin", ""))
    if not info:
        return ""
    sub, cls = classify_subsystem_and_class(e.get("symbol", ""))
    return f"reconstructed_src/{info[1]}/{sub}/{cls}.cpp"


def _block(key: str, e: dict) -> str:
    by = e.get("verified_by") or "unattributed"
    if e.get("revised_by"):
        by += f" | Cleaned up by: {e['revised_by']}"
    note = f" | {e['note']}" if e.get("note") else ""
    if e.get("excerpt"):
        note += f" | excerpt from reconstructed_src/{e.get('source', '')}"
    what = " ".join(str(e.get("what") or "").split())
    return (
        "// ============================================================================\n"
        f"// [VERIFIED] {e['symbol']} ({e['va']}, {e['size']} B)\n"
        f"// By: {by} | Flags: {e.get('flags', '')}{note}\n"
        + (f"// What it does: {what}\n" if what else "") +
        "// ============================================================================\n"
        f"{(e.get('code') or '').strip()}\n\n"
    )


def _todo(va: int, t: dict) -> str:
    return f"// [TODO] 0x{va:08X} {t.get('symbol', '')} ({int(t.get('size', 0))} B)\n"


def _progress_lines(done: int, total: int, fname: str = "") -> str:
    pct = done / total * 100 if total else 0.0
    if total and done >= total:
        return f"// PROGRESS: COMPLETE. All {total:,} functions are matched.\n"
    where = f"in {fname}" if fname else "below"
    return (f"// PROGRESS: {done:,} of {total:,} functions matched ({pct:.2f}%). NOT COMPLETE YET.\n"
            f"// The {total - done:,} still to do are listed in their place {where} as \"// [TODO] address name (size)\"\n"
            "// lines, so you can see what is missing and where; matched ones are the C++ itself.\n")


def _header(title: str, compiler: str, progress: str = "") -> str:
    return (
        "// ============================================================================\n"
        f"// SCARFACE: THE WORLD IS YOURS — {title}\n"
        "// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.\n"
        f"{progress}"
        f"// Every [VERIFIED] block compiled byte-for-byte with {compiler}.\n"
        "// Blocks marked 'excerpt' are cut from the named source file and are built from that file;\n"
        "// every other block compiles on its own. The file as a whole is not one translation unit.\n"
        "// ============================================================================\n\n"
    )


def _write(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_suffix(path.suffix + ".tmp")
    tmp.write_text(text, encoding="utf-8", newline="\n")
    os.replace(tmp, path)


STATUS_START = "<!-- status:start (generated by portal/tools/registry_outputs.py from reports/verified_registry.json) -->"
STATUS_END = "<!-- status:end -->"


def status_block(registry: dict) -> str:
    entries = list(registry.get("entries", {}).values())
    by = defaultdict(int)
    for e in entries:
        by[e["bin"]] += 1
    ps2 = sum(n for b, n in by.items() if ps2_overlay.is_ps2(b))
    entries = [e for e in entries if not ps2_overlay.is_ps2(e["bin"])]        # the sizes below are x86 bytes
    small = sum(1 for e in entries if int(e.get("size", 0)) < 10)
    largest = max((int(e.get("size", 0)) for e in entries), default=0)
    lines = [
        STATUS_START,
        "| | Xbox `default.xbe` | PC `Scarface.exe` 1.00.2 | Total |",
        "| :--- | ---: | ---: | ---: |",
        f"| Verified functions | {by['xb']:,} | {by['pc']:,} | **{by['pc'] + by['xb']:,}** |",
        "",
    ] + ([f"Plus {by['proto']:,} in the April 2006 Xbox prototype (`game.xbe`), unreleased code, counted on its own.", ""]
         if by["proto"] else []) + ([f"Plus {ps2:,} in the PS2 game (`SLUS_211.11` and its overlays), built with its own "
                                     "compiler, counted on its own.", ""]
         if ps2 else []) + [
        (f"{small:,} of them are under 10 bytes and the largest is {largest:,} bytes, so the medium and large "
         "functions are where the work is." if entries else
         "Nothing is verified yet: the count was reset on 2026-11-08 so every function is rebuilt and checked "
         "again from scratch. Pick one in the portal and be the first."),
        STATUS_END,
    ]
    return "\n".join(lines)


def update_readme(readme: Path, registry: dict) -> bool:
    """Rewrite the status block in README.md. Returns True if the file changed."""
    if not readme.exists():
        return False
    text = readme.read_text(encoding="utf-8")
    i, j = text.find(STATUS_START), text.find(STATUS_END)
    if i == -1 or j == -1:
        return False
    new = text[:i] + status_block(registry) + text[j + len(STATUS_END):]
    if new != text:
        _write(readme, new)
        return True
    return False


SIZE_BUCKETS = [("1-9 B", 1, 10), ("10-19 B", 10, 20), ("20-39 B", 20, 40), ("40-79 B", 40, 80), ("80+ B", 80, 1 << 30)]


def progress_summary(registry: dict, queue: Optional[list], previous: Optional[dict]) -> dict:
    """Small summary for the website: verified counts from the registry, work-queue counts from the local
    queue file when there is one (otherwise the last known numbers are kept)."""
    entries = list(registry.get("entries", {}).values())
    by = defaultdict(int)
    for e in entries:
        by["ps2" if ps2_overlay.is_ps2(e["bin"]) else e["bin"]] += 1         # the PS2 overlays count as the PS2
    stamps = [e.get("verified_at") or e.get("reverified_at") or "" for e in entries]
    contributors = defaultdict(int)
    for e in entries:
        if e.get("verified_by"):
            contributors[e["verified_by"]] += 1
    out = {
        "schema": "scarface_progress_v1",
        "updated_at": max(stamps) if stamps else (registry.get("reset") or {}).get("at", ""),
        "compiler": registry.get("compiler", ""),
        # "total" and "bytes" are the released game on PC + Xbox (one compiler); the April 2006 prototype
        # (unreleased code) and the PS2 game (another compiler) are counted only under "proto" and "ps2".
        "verified": {"pc": by["pc"], "xb": by["xb"], "proto": by["proto"], "ps2": by["ps2"], "total": by["pc"] + by["xb"],
                     "bytes": sum(int(e.get("size", 0)) for e in entries if e["bin"] in ("pc", "xb")),
                     "ps2_bytes": sum(int(e.get("size", 0)) for e in entries if ps2_overlay.is_ps2(e["bin"]))},
        "size_buckets": {name: sum(1 for e in entries if e["bin"] in ("pc", "xb") and lo <= int(e.get("size", 0)) < hi)
                         for name, lo, hi in SIZE_BUCKETS},
        "contributors": dict(sorted(contributors.items(), key=lambda kv: (-kv[1], kv[0].lower()))),
        "unattributed": sum(1 for e in entries if not e.get("verified_by")),
        "queue": (previous or {}).get("queue"),
    }
    if queue is not None:
        open_tasks = [t for t in queue if t.get("status") != "VERIFIED"]
        q = defaultdict(int)
        tiers = defaultdict(int)
        for t in open_tasks:
            q["ps2" if ps2_overlay.is_ps2(t.get("bin")) else t.get("bin", "?")] += 1
            if t.get("bin") in ("pc", "xb"):
                tiers[t.get("tier", "?")] += 1
        out["queue"] = {"pc": q["pc"], "xb": q["xb"], "proto": q["proto"], "ps2": q["ps2"], "total": q["pc"] + q["xb"],
                        "tiers": dict(sorted(tiers.items()))}
    import good_first
    out["good_first"] = good_first.for_site(queue, registry, (previous or {}).get("good_first"))
    return out


SITE = "https://scarface-decomp.pages.dev/"
REPO = "https://github.com/scarface-decomp/scarface_decomp"
FEED_ENTRIES = 50
BIN_WORD = {"pc": "PC", "xb": "Xbox", "proto": "Xbox prototype", "ps2": "PS2",
            **{o.bin: f"PS2 {o.label} overlay" for o in ps2_overlay.OVERLAYS}}


def feed_xml(registry: dict) -> str:
    """An Atom feed of the newest matches (docs/feed.xml), for feed readers and Discord feed bots."""
    from xml.sax.saxutils import escape

    def stamp(e: dict) -> str:
        t = (e.get("verified_at") or e.get("reverified_at") or "").strip()
        return (t.replace(" ", "T") + "Z") if re.match(r"^\d{4}-\d\d-\d\d \d\d:\d\d:\d\d$", t) else "2026-11-08T00:00:00Z"
    entries = sorted(registry.get("entries", {}).items(), key=lambda kv: (stamp(kv[1]), kv[0]), reverse=True)[:FEED_ENTRIES]
    updated = stamp(entries[0][1]) if entries else "2026-11-08T00:00:00Z"
    out = ['<?xml version="1.0" encoding="utf-8"?>',
           '<feed xmlns="http://www.w3.org/2005/Atom">',
           "  <title>Scarface decomp: new matches</title>",
           "  <subtitle>Functions of Scarface: The World Is Yours rebuilt in C++ that compiles to the exact same bytes.</subtitle>",
           f'  <link href="{SITE}feed.xml" rel="self"/>',
           f'  <link href="{SITE}"/>',
           "  <id>tag:scarface-decomp.pages.dev,2026:matches</id>",
           f"  <updated>{updated}</updated>",
           "  <author><name>Scarface decomp contributors</name></author>"]
    for key, e in entries:
        who = e.get("verified_by") or "unattributed"
        where = BIN_WORD.get(e["bin"], e["bin"])
        size = int(e.get("size", 0))
        title = f"{e['symbol']} ({where}, {size} byte{'' if size == 1 else 's'}) by {who}"
        what = " ".join(str(e.get("what") or "").split())
        summary = (what + " " if what else "") + f"{e['va']} in the {where} version, matched byte for byte with its original."
        link = f"{SITE}function.html?f={urllib.parse.quote(key, safe='')}"
        out += ["  <entry>",
                f"    <title>{escape(title)}</title>",
                f'    <link href="{escape(link)}"/>',
                f"    <id>tag:scarface-decomp.pages.dev,2026:{escape(key)}</id>",
                f"    <updated>{stamp(e)}</updated>",
                f"    <summary>{escape(summary)}</summary>",
                "  </entry>"]
    out.append("</feed>")
    return "\n".join(out) + "\n"


def write_feed(registry: dict, docs_dir: Path) -> bool:
    path = docs_dir / "feed.xml"
    text = feed_xml(registry)
    if path.exists() and path.read_text(encoding="utf-8").replace("\r\n", "\n") == text:
        return False
    _write(path, text)
    return True


def write_progress(registry: dict, reports_dir: Path) -> bool:
    import json
    path = reports_dir / "progress.json"
    previous = None
    try:
        previous = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        pass
    queue = None
    qpath = reports_dir / "full_remaining_queue.json"
    if qpath.exists():
        try:
            queue = json.loads(qpath.read_text(encoding="utf-8"))
        except (OSError, ValueError):
            queue = None
    text = json.dumps(progress_summary(registry, queue, previous), indent=2) + "\n"
    if path.exists() and path.read_text(encoding="utf-8").replace("\r\n", "\n") == text:
        return False
    reports_dir.mkdir(parents=True, exist_ok=True)
    _write(path, text)
    return True


_TODO_RE = re.compile(r"^// \[TODO\] 0x([0-9A-Fa-f]{8}) (.*) \((\d+) B\)$")
_DONE_RE = re.compile(r"^// \[VERIFIED\] (.*) \((0x[0-9A-Fa-f]{8}), (\d+) B\)$")
FULL_LISTING = "every function in address order"


def known_from_files(recon_dir: Path) -> Dict[str, Dict[int, dict]]:
    """The function list as the address-order files already have it (their [TODO] and [VERIFIED] lines), for
    when the game files are not here: the regenerated files then keep every function in its place."""
    out: Dict[str, Dict[int, dict]] = defaultdict(dict)
    for b, (fname, _f, _l) in BIN_INFO.items():
        path = recon_dir / fname
        if not path.exists():
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        if FULL_LISTING not in text[:600]:
            continue
        for line in text.splitlines():
            m = _TODO_RE.match(line)
            if m:
                va, sym, size = int(m.group(1), 16), m.group(2), int(m.group(3))
            else:
                m = _DONE_RE.match(line)
                if not m:
                    continue
                sym, va, size = m.group(1), int(m.group(2), 16), int(m.group(3))
            out[b][va] = {"bin": b, "fva_int": va, "symbol": sym, "size": size}
    return out


def write_outputs(registry: dict, recon_dir: Path, queue: Optional[list] = None,
                  known_from: Optional[Path] = None) -> List[str]:
    """(Re)write all generated files. Returns the relative paths written. `queue`: every function of the game
    files (the portal's tasks, matched or not); with it the address-order files list all of them. Without it,
    the list is read from the address-order files in `known_from` (default: recon_dir)."""
    entries: Dict[str, dict] = registry.get("entries", {})
    compiler = registry.get("compiler", "MSVC 7.10")
    written: List[str] = []
    by_bin: Dict[str, List] = defaultdict(list)
    for k, e in entries.items():
        by_bin[e["bin"]].append((int(e["va"], 16), k, e))
    known: Dict[str, Dict[int, dict]] = defaultdict(dict)
    for t in queue or []:
        if t.get("bin") in BIN_INFO and "fva_int" in t:
            known[t["bin"]][int(t["fva_int"])] = t
    if any(b not in known for b in BIN_INFO):
        for b, fns in known_from_files(known_from or recon_dir).items():
            if b not in known:
                known[b] = fns
    class_total: Dict[tuple, int] = defaultdict(int)
    for b, fns in known.items():
        for t in fns.values():
            class_total[(b,) + classify_subsystem_and_class(t.get("symbol", ""))] += 1
    for b, (fname, folder, label) in BIN_INFO.items():
        items = sorted(by_bin.get(b, []))
        allfn = known.get(b)
        if not items and not allfn and not (recon_dir / fname).exists():
            continue
        comp = BIN_COMPILER.get(b, compiler)
        if allfn:
            done = {va for va, _, _ in items}
            total = len(set(allfn) | done)
            text = _header(f"{label}, {FULL_LISTING}", comp, _progress_lines(len(items), total))
            rows = sorted([(va, 0, k, e) for va, k, e in items] + [(va, 1, "", t) for va, t in allfn.items() if va not in done],
                          key=lambda r: (r[0], r[1]))
            text += "".join(_block(k, x) if kind == 0 else _todo(va, x) for va, kind, k, x in rows)
        else:
            text = _header(f"{label}, verified functions in address order ({len(items)})", comp)
            text += "".join(_block(k, e) for _, k, e in items)
        _write(recon_dir / fname, text)
        written.append(fname)
        groups: Dict[tuple, List] = defaultdict(list)
        for va, k, e in items:
            groups[classify_subsystem_and_class(e["symbol"])].append((va, k, e))
        gen_root = recon_dir / folder
        keep = set()
        for (sub, cls), lst in groups.items():
            rel = Path(folder) / sub / f"{cls}.cpp"
            of = class_total.get((b, sub, cls), 0)
            body = _header(f"{label}, {sub}/{cls}.cpp ({len(lst)} verified)", comp,
                           _progress_lines(len(lst), max(of, len(lst)), fname) if of else "")
            body += "".join(_block(k, e) for _, k, e in sorted(lst))
            _write(recon_dir / rel, body)
            keep.add((recon_dir / rel).resolve())
            written.append(str(rel).replace("\\", "/"))
        # blank out generated files that no longer have entries (we never delete files)
        if gen_root.exists():
            for p in gen_root.rglob("*.cpp"):
                if p.resolve() not in keep and p.read_text(encoding="utf-8", errors="ignore").find("GENERATED from reports/verified_registry.json") != -1:
                    _write(p, _header(f"{label}, {p.relative_to(recon_dir)} (0 verified)", comp))
    if update_readme(recon_dir.parent / "README.md", registry):
        written.append("../README.md")
    if write_progress(registry, recon_dir.parent / "reports"):
        written.append("../reports/progress.json")
    if write_feed(registry, recon_dir.parent / "docs"):
        written.append("../docs/feed.xml")
    return written


if __name__ == "__main__":
    import json
    root = Path(__file__).resolve().parents[2]           # the project folder
    reg = json.loads((root / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    qfile = root / "reports" / "full_remaining_queue.json"          # every function; built from your game files
    queue = json.loads(qfile.read_text(encoding="utf-8")) if qfile.exists() else None
    for p in write_outputs(reg, root / "reconstructed_src", queue=queue):
        print("wrote reconstructed_src/" + p)
