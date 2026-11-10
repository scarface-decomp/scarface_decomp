"""What differs between the versions: listing each version's files without copying them
(game_assets.list_versions) and the public report made from the lists (version_report.py), on the tiny
made-up games of test_game_assets.py. The report must hold names and descriptions only."""
import json

import game_assets as GA
import version_report as VR
from test_game_assets import CAR, SOUND, make_binaries, small  # noqa: F401  (small: the fixture)


def test_listing_writes_nothing_but_the_lists(tmp_path):
    b = make_binaries(tmp_path)
    cats = GA.list_versions(list(GA.VERSIONS), b, log=lambda m: None)
    assert set(cats) == {"xbox", "pc", "ps2", "prototype"}
    out = b / "game_files"
    assert sorted(p.name for p in out.rglob("*") if p.is_file()) == sorted(f"catalog-{v}.json" for v in GA.VERSIONS)
    xb = {r[0]: r for r in cats["xbox"]}
    assert xb["cement.rcf/art/sound/hello.rsd"][1] == len(SOUND) and xb["cement.rcf/art/sound/hello.rsd"][3]["rate"] == 24000
    assert xb["media/copy.bik"][2] == xb["media/intro.bik"][2]            # the same data under two names
    # a second run reuses the lists
    seen = []
    GA.list_versions(["xbox"], b, log=seen.append)
    assert seen == ["[=] Xbox: already listed (%d files)" % len(cats["xbox"])]


def test_report_from_the_lists(tmp_path):
    b = make_binaries(tmp_path)
    GA.list_versions(list(GA.VERSIONS), b, log=lambda m: None)
    report = VR.build(VR.catalogs_from_disk(b), today="2026-11-10")
    vs = {v["id"]: v for v in report["versions"]}
    assert [v["id"] for v in report["versions"]] == ["xbox", "pc", "ps2", "prototype"]
    assert vs["prototype"]["kinds"]["models"]["changed"] >= 1 and vs["xbox"]["files"] == sum(vs["xbox"][s] for s in VR.STATUSES)
    only_proto = [f[0] for f in report["only"]["prototype"]]
    assert "art/cut/protoonly.p3d" in only_proto
    assert "Scarface.exe" in [f[0] for f in report["only"]["pc"]]
    sound = next(d for d in report["changed"] if d[0] == "art/sound/hello.rsd")
    assert sound[1] == "sounds" and [x[0] for x in sound[3]] == ["xbox", "ps2", "prototype"]
    assert any("Hz" in x[2] for x in sound[3])
    # names and descriptions only: no hashes, no contents
    text = json.dumps(report)
    for rows in GA.plan(VR.catalogs_from_disk(b), "unique")[0].values():
        for r in rows:
            assert r[2] not in text
    assert "retail car" not in text and CAR.hex()[:40] not in text


def test_markdown_and_files(tmp_path):
    b = make_binaries(tmp_path)
    GA.list_versions(list(GA.VERSIONS), b, log=lambda m: None)
    report = VR.build(VR.catalogs_from_disk(b), today="2026-11-10")
    docs = tmp_path / "docs"
    docs.mkdir()
    VR.write(report, docs)
    md = (docs / "VERSIONS.md").read_text(encoding="utf-8")
    assert md.startswith("# What differs between the versions") and "| Xbox 2006 prototype |" in md
    assert "## Only in the PS2 version" in md and "2026-11-10" in md
    small = json.loads((docs / "versions.json").read_text(encoding="utf-8"))
    assert small["schema"] == VR.SCHEMA and "changed" not in small and small["changed_file"] == "versions-changed.json"
    assert json.loads((docs / "versions-changed.json").read_text(encoding="utf-8"))["changed"] == report["changed"]


def test_report_from_an_earlier_copy(tmp_path):
    b = make_binaries(tmp_path)
    GA.run(["xbox", "prototype"], "unique", b, log=lambda m: None)
    cats = VR.catalogs_from_disk(b)
    assert set(cats) == {"xbox", "prototype"}
    assert VR.build(cats)["versions"][0]["files"] == len(cats["xbox"])
