"""The names behind the game's hashed keys (stx + 8 letters in the compiled scripts).

A key can't be reversed, but a candidate text can be hashed and compared. This gathers candidates from the
user's own game files and from what the project has already worked out, hashes each one both ways the game
does (NameKey 0x00243FA0, which folds letter case, and NameKeyCaseSensitive 0x00243FF0, which doesn't), and
keeps the ones that land on a key the scripts use:

    {"0x8F3A...": {"stx": "stx...", "names": [{"text", "fold", "source", "certain"}], "ambiguous": bool}}

A name is "certain" when its text is in the game's own data: a string in an executable (the PS2 one too) or
a script, a name in a fight script or AI tree (.fsc, .dtr), a class name from the run-time type information,
a script command or class field the program registers. A word of three letters or fewer found only in an
executable is too likely a chance hit and counts as "dictionary". Names from
the project's own files (reports/names.json) and names made by joining two known words are "dictionary":
probably right, but a wrong text matches some key by chance now and then (the report says how often to
expect that). A key two different texts hash to is "ambiguous".

    python portal/tools/hash_names.py binaries/            -> reports/hash_names.json

torque_script.py uses the certain names when it decompiles (and the dictionary ones with --dictionary).
"""
from __future__ import annotations

import json
import random
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path
from typing import Dict, Iterable, List, Optional, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
import torque_dso as TD  # noqa: E402
from torque_names import RUN, WORD, casing_score, is_hashed, name_key, stx  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
EXECUTABLES = ("default.xbe", "game.xbe", "Scarface.exe", "SLUS_211.11")
DATA_TEXT = (".fsc", ".dtr", ".txt")          # other game files that hold names as text (fight scripts, AI trees)
SHORT = 3                                   # an executable-only word this short is too likely a chance hit
PREFIXES = ("", "$", "%")
# The script compiler keys every name with NameKey (folded). A case-sensitive key landing on a script's key
# is a coincidence of the folding ("Ei" kept as is is "%i" folded), so scripts are matched folded only;
# key(text, fold=False) is there for the program's own case-sensitive lookups.
FOLDS = (True,)
RTTI = re.compile(rb"\.\?A[VU]([A-Za-z0-9_@?$]+?)@@")


def key(text: str, fold: bool = True, start: int = 0) -> int:
    """NameKey (fold) or NameKeyCaseSensitive (not) of text."""
    return _finish(_step(start & 0x7FFFFFFF, text.encode("latin-1", "replace"), fold)) if text else start


def _step(h: int, data: bytes, fold: bool = True) -> int:
    for c in data:
        h = (h * 65599) & 0x7FFFFFFF
        if c >= 0x80:
            c -= 0x100
        if fold and c < 0x61:
            c += 0x20
        h = (h ^ c) & 0xFFFFFFFF
    return h


def _finish(h: int) -> int:
    return (h | 0x80000000) & 0xFFFFFFFF


# ---------------------------------------------------------------------------- what the scripts use

def script_keys(files: Iterable[Path], data_texts: Optional[List[str]] = None) -> Tuple[set, List[str]]:
    """The hashed keys the scripts use, and the plain texts they hold (strings, .cs files). The text of the
    other game files that hold names (DATA_TEXT) is added to data_texts when one is given."""
    wanted, texts = set(), []
    for p in files:
        suf = p.suffix.lower()
        if suf in DATA_TEXT:
            if data_texts is not None:
                data_texts.append(p.read_bytes().decode("latin-1"))
            continue
        if suf == ".cs":
            texts.append(p.read_bytes().decode("latin-1"))
            continue
        if suf not in (".cso", ".dso"):
            continue
        try:
            s = TD.parse(p.read_bytes())
        except TD.DsoError:
            continue
        for table in (s.global_strings, s.function_strings):
            for v in s.strings(table).values():
                if is_hashed(v):
                    wanted.add(name_key(v))
                else:
                    texts.append(v)
    return wanted, texts


# ---------------------------------------------------------------------------- candidates

def demangle(body: str) -> List[str]:
    """`Foo@bar` (from .?AVFoo@bar@@) -> ["Foo", "bar::Foo"]; template arguments are dropped."""
    if body.startswith("?$"):
        name = body[2:].split("@")[0]
        return [name] if re.fullmatch(r"[A-Za-z_]\w*", name) else []
    parts = [p for p in body.split("@") if p and not p.startswith(("?", "$"))]
    if not parts or not re.fullmatch(r"[A-Za-z_]\w*", parts[0]):
        return []
    out = [parts[0]]
    if len(parts) > 1 and all(re.fullmatch(r"[A-Za-z_]\w*", p) for p in parts):
        out.append("::".join(reversed(parts)))
    return out


def certain_candidates(bins: Iterable[bytes], texts: Iterable[str], data_texts: Iterable[str] = ()) -> Dict[str, str]:
    """{text: source} for texts in the game's own data."""
    c: Dict[str, str] = {}
    for label, group in (("script", texts), ("game data file", data_texts)):
        for s in group:
            for run in RUN.findall(s.encode("latin-1", "replace")):
                for t in WORD.findall(run):
                    if len(t) <= 64:
                        c.setdefault(t.decode(), label)
    for name, data in bins:
        for m in RTTI.finditer(data):
            for t in demangle(m.group(1).decode("latin-1")):
                c.setdefault(t, "rtti")
        for run in RUN.findall(data):
            for t in WORD.findall(run):
                if len(t) <= 64:
                    c.setdefault(t.decode(), name)
    for t in _report_names("script_bindings.json", lambda d: [b["name"] for v in d["versions"].values() for b in v]):
        c.setdefault(t, "script commands (reports/script_bindings.json)")
    for t in _report_names("fields.json", lambda d: [f["name"] for k in d.get("classes", {}).values()
                                                     for f in k.get("fields", [])]
                           + [f["name"] for f in d.get("unowned", [])] + list(d.get("classes", {}))):
        c.setdefault(t, "class fields (reports/fields.json)")
    return c


def project_candidates() -> Dict[str, str]:
    """{text: source} for the names the project worked out (reports/names.json): functions, their last
    part, and members (with and without m_)."""
    out: Dict[str, str] = {}
    def grab(d):
        names = []
        for v in d.get("names", {}).values():
            n = v["name"]
            names += [n, n.split("::")[-1]]
        for cls, mem in d.get("members", {}).items():
            names.append(cls.split(":", 1)[1])
            for v in mem.values():
                names += [v["name"], v["name"][2:] if v["name"].startswith("m_") else v["name"]]
        return names
    for t in _report_names("names.json", grab):
        if re.fullmatch(r"[A-Za-z_][\w:]*", t):
            out.setdefault(t, "names.json")
    return out


def _report_names(fn: str, get) -> List[str]:
    try:
        return [t for t in get(json.loads((ROOT / "reports" / fn).read_text())) if t]
    except (OSError, ValueError, KeyError):
        return []


PIECE = re.compile(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+")


def vocabulary(names: Iterable[str], least: int = 2, most: int = 4000) -> List[str]:
    """The word pieces the scripters use, from names already recovered: camel case and _ split, lower case."""
    c = Counter()
    for n in names:
        for part in re.split(r"[_:$%]+", n):
            for p in PIECE.findall(part):
                if len(p) >= 2 or p.isdigit():
                    c[p.lower()] += 1
    return [w for w, k in c.most_common(most) if k >= least]


def camel(pre: str, a: str, b: str) -> str:
    """How to write two joined pieces (any letter case has the same folded key): %musicFilter, forceSpawn."""
    return pre + a + b[:1].upper() + b[1:]


def compounds(words: List[str], wanted: set) -> Dict[int, List[str]]:
    """Two pieces joined (folded keys, so letter case doesn't matter), with each variable prefix."""
    hits: Dict[int, List[str]] = defaultdict(list)
    enc = [(w, w.encode()) for w in words]
    for pre in PREFIXES:
        base = _step(0, pre.encode())
        for a, ab in enc:
            ha = _step(base, ab)
            for b, bb in enc:
                k = _finish(_step(ha, bb))
                if k in wanted:
                    hits[k].append(camel(pre, a, b))
    return hits


def expected_chance(words: List[str], n_wanted: int) -> float:
    """How many of the compound hits to expect by chance: every try is a 1 in 2^31 shot at each key."""
    return len(words) ** 2 * len(PREFIXES) * n_wanted / 2 ** 31


# ---------------------------------------------------------------------------- the table

def build(bin_dir: Path, script_files: Iterable[Path], compound: bool = True) -> dict:
    data_texts: List[str] = []
    wanted, texts = script_keys(script_files, data_texts)
    bins = [(e, (bin_dir / e).read_bytes()) for e in EXECUTABLES if (bin_dir / e).is_file()]
    found: Dict[int, Dict[str, dict]] = defaultdict(dict)

    def offer(text: str, source: str, certain: bool):
        for pre in PREFIXES:
            if pre and text[:1] in "$%":
                continue
            t = pre + text
            for fold in FOLDS:
                k = key(t, fold)
                if k in wanted:
                    have = found[k].get(t.lower() if fold else t)
                    if have is None or (certain and not have["certain"]):
                        found[k][t.lower() if fold else t] = {"text": t, "fold": fold, "source": source,
                                                              "certain": certain}

    for t, src in certain_candidates(bins, texts, data_texts).items():
        # a short word found only in an executable is as likely chance as a name: probable, not certain
        offer(t, src, not (src in EXECUTABLES and len(t.lstrip("$%")) <= SHORT))
    for t, src in project_candidates().items():
        offer(t, src, False)
    chance = 0.0
    if compound:
        words = vocabulary(n["text"] for v in found.values() for n in v.values())
        left = wanted - set(found)
        for k, ts in compounds(words, left).items():
            for t in ts:
                found[k].setdefault(t.lower(), {"text": t, "fold": True, "source": "two known words joined",
                                                "certain": False})
        chance = expected_chance(words, len(left))
    table = {}
    for k in sorted(found):
        names = sorted(found[k].values(), key=lambda n: (not n["certain"], -casing_score(n["text"]), n["text"]))
        # a folded key matches every spelling; keep the best-looking one per distinct text
        table[f"0x{k:08X}"] = {"stx": stx(k), "names": names,
                               "ambiguous": len({n["text"].lower() for n in names}) > 1}
    certain = sum(1 for v in table.values() if v["names"][0]["certain"])
    return {"what": "Names for the hashed keys the game's scripts use (portal/tools/hash_names.py). certain: the "
                    "text is in the game's own data; dictionary: from the project's names or two known words "
                    "joined, so check it; ambiguous: more than one text hashes to the key.",
            "keys_in_scripts": len(wanted), "named": len(table), "certain": certain,
            "dictionary": len(table) - certain,
            "ambiguous": sum(1 for v in table.values() if v["ambiguous"]),
            "compound_chance_hits": round(chance, 1),
            "engine_callbacks": engine_callbacks(bin_dir),
            "keys": table}


def engine_callbacks(bin_dir: Path) -> List[dict]:
    """The script function names the engine itself looks for (Initialize, OnKilled ...), in the order of its
    table: bit i of a namespace's callback mask says a script defines the i-th. Read from the Xbox game's
    InitNamespaces (its address from reports/names.json), which stores the 36 name pointers one after another."""
    import struct
    try:
        names = json.loads((ROOT / "reports" / "names.json").read_text())["names"]
        va = next(int(k.split(":")[1], 16) for k, v in names.items() if k.startswith("xb:") and v["name"] == "InitNamespaces")
        from sf_binaries import BinaryImage
        img = BinaryImage(bin_dir / "default.xbe")
    except (OSError, ValueError, KeyError, StopIteration):
        return []
    body = img.read(va, 0x140) or b""
    found = []
    for m in re.finditer(rb"\xC7(?:\x44\x24(.)|\x84\x24(.{4}))(.{4})", body, re.S):      # mov [esp+N], imm32
        slot = m.group(1)[0] if m.group(1) else struct.unpack("<I", m.group(2))[0]
        off = img.va_to_off(struct.unpack("<I", m.group(3))[0])
        if off is None:
            continue
        end = img.data.find(b"\0", off, off + 64)
        text = img.data[off:end].decode("latin-1") if end > off else ""
        if re.fullmatch(r"[A-Za-z_]\w*", text):
            found.append((slot, text))
    return [{"bit": i, "name": t, "key": f"0x{key(t):08X}"} for i, (_slot, t) in enumerate(sorted(found))]


def best(table: dict, dictionary: bool = False) -> Dict[int, str]:
    """{key: name} to show in decompiled scripts: the first certain name, or with dictionary any first name;
    ambiguous keys only when the first name is certain and no other certain text shares the key."""
    out = {}
    for k, v in table.get("keys", {}).items():
        names = v["names"] if dictionary else [n for n in v["names"] if n["certain"]]
        if not names:
            continue
        if len({n["text"].lower() for n in names if n["certain"] == names[0]["certain"]}) > 1:
            continue
        out[int(k, 16)] = names[0]["text"]
    return out


def write(t: dict, path: Path) -> None:
    """One key per line, so a change shows as a few lines in a diff."""
    head = {k: v for k, v in t.items() if k not in ("keys", "engine_callbacks")}
    head["engine_callbacks"] = "see below"
    lines = [f" {json.dumps(k)}: {json.dumps(v, ensure_ascii=False)}" for k, v in t["keys"].items()]
    text = json.dumps(head, indent=1, ensure_ascii=False)[:-2].replace(
        '"engine_callbacks": "see below"', '"engine_callbacks": [\n  ' + ",\n  ".join(
            json.dumps(c) for c in t.get("engine_callbacks", [])) + "\n ]")
    text += ',\n "keys": {\n' + ",\n".join(lines) + "\n }\n}\n"
    path.write_text(text, newline="\n")


def load(path: Optional[Path] = None) -> dict:
    try:
        return json.loads((path or ROOT / "reports" / "hash_names.json").read_text())
    except (OSError, ValueError):
        return {}


def main(argv=None) -> int:
    import argparse
    ap = argparse.ArgumentParser(description="Work out the names behind the scripts' hashed keys.")
    ap.add_argument("folder", type=Path, nargs="?", default=ROOT / "binaries",
                    help="folder with the game's executables and its scripts (default: binaries/)")
    ap.add_argument("--scripts", type=Path, nargs="*", help="script folders (default: everything under folder)")
    ap.add_argument("--out", type=Path, default=ROOT / "reports" / "hash_names.json")
    ap.add_argument("--no-compounds", action="store_true", help="skip joining two known words")
    a = ap.parse_args(argv)
    files = [p for d in (a.scripts or [a.folder]) for p in sorted(d.rglob("*"))
             if p.suffix.lower() in (".cso", ".dso", ".cs") + DATA_TEXT]
    t = build(a.folder, files, compound=not a.no_compounds)
    write(t, a.out)
    print(f"{t['named']} of {t['keys_in_scripts']} keys named: {t['certain']} certain, {t['dictionary']} "
          f"dictionary ({t['compound_chance_hits']} of the joined-word ones expected by chance), "
          f"{t['ambiguous']} ambiguous -> {a.out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
