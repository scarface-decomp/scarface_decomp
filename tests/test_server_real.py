"""
The real portal server (decomp_portal_server.py) with the real compiler, on a throwaway copy of the
repository, so nothing in the working tree is touched. Skipped without cl.exe or default.xbe.

One Xbox function (sub_001CDC80, 6 bytes) is put at the front of the copy's queue (and taken out of its
registry, if it is there); the tests then claim it and verify it through the HTTP API and in a browser.
"""
import json
import os
import shutil
import socket
import subprocess
import sys
import time
import urllib.error
import urllib.request

import pytest

from conftest import ROOT, needs_compiler, needs_xbox

pytestmark = [needs_compiler, needs_xbox]

KEY, TID, VA = "xb:0x001CDC80", "xb_001CDC80", 0x001CDC80
GOOD = 'extern "C" char DAT_00439DA4; void* __cdecl sub_001CDC80(void) { return &DAT_00439DA4; }'
HARDCODED = "void* __cdecl sub_001CDC80(void) { return (void*)0x00439DA4; }"


def _free_port():
    with socket.socket() as s:
        s.bind(("127.0.0.1", 0))
        return s.getsockname()[1]


@pytest.fixture(scope="module")
def portal(tmp_path_factory):
    work = tmp_path_factory.mktemp("portal") / "repo"
    work.mkdir()
    # Only what the portal needs: never the game archives, ISOs or other large local folders.
    skip = shutil.ignore_patterns("msvc71", "__pycache__", "*.tmp")
    for name in ("decomp_portal_server.py", "verify.py", "SCARFACE_DECOMP_AI_HANDOFF.md", "tools", "scripts",
                 "reconstructed_src", "include", "reports", "website_kit"):
        src = ROOT / name
        if src.is_dir():
            shutil.copytree(src, work / name, ignore=skip)
        elif src.exists():
            shutil.copy2(src, work / name)
    try:                                   # Windows needs Developer Mode or admin rights for symlinks
        (work / "binaries").symlink_to(ROOT / "binaries", target_is_directory=True)
    except OSError:
        (work / "binaries").mkdir()
        for name in ("Scarface.exe", "default.xbe", "game.xbe"):
            if (ROOT / "binaries" / name).exists():
                shutil.copy2(ROOT / "binaries" / name, work / "binaries" / name)
    for f in ("private/contributor_tokens.json", "reports/contributor_tokens.json", "reports/task_progress_state.json"):
        (work / f).unlink(missing_ok=True)

    reg_p = work / "reports" / "verified_registry.json"
    reg = json.loads(reg_p.read_text(encoding="utf-8"))
    reg["entries"].pop(KEY, None)
    reg_p.write_text(json.dumps(reg), encoding="utf-8")
    q_p = work / "reports" / "full_remaining_queue.json"
    queue = json.loads(q_p.read_text(encoding="utf-8")) if q_p.exists() else []
    queue = [t for t in queue if t.get("id") != TID]
    queue.insert(0, {"id": TID, "bin": "xb", "lane": "Shared Engine & Gameplay", "symbol": "PauseMenuPageStats::vfunc_00",
                     "match_substr": "sub_001CDC80", "va": "0x001CDC80", "fva_int": VA, "size": 6,
                     "flags": "/O2 /Ot /Oy /G6 /Gd /GR /EHsc /Zp4", "status": "UNCLAIMED", "claimed_by": "",
                     "tier": "TIER_1_QUICK", "tier_label": "Tier 1: Quick (<20 B)", "est_label": "~5 mins",
                     "lease_minutes": 15, "hint": "test"})
    q_p.write_text(json.dumps(queue), encoding="utf-8")

    port = _free_port()
    import msvc_verify as MV
    env = dict(os.environ, SCARFACE_PORT=str(port), SCARFACE_NO_BROWSER="1", SCARFACE_MAINTAINERS="Maint",
               SCARFACE_MSVC_BIN=str(MV.find_msvc71_bin()))
    log = open(work / "server.log", "wb")
    proc = subprocess.Popen([sys.executable, "decomp_portal_server.py"], cwd=work, env=env, stdout=log,
                            stderr=subprocess.STDOUT)
    base = f"http://127.0.0.1:{port}"
    for _ in range(600):
        try:
            urllib.request.urlopen(base + "/api/health", timeout=1).read()
            break
        except Exception:
            if proc.poll() is not None:
                raise RuntimeError((work / "server.log").read_text(errors="replace"))
            time.sleep(0.25)
    else:
        proc.kill()
        raise RuntimeError("portal did not start:\n" + (work / "server.log").read_text(errors="replace"))
    yield {"base": base, "work": work, "env": env}
    proc.terminate()
    try:
        proc.wait(timeout=10)
    except subprocess.TimeoutExpired:
        proc.kill()


def get(p, path):
    return json.loads(urllib.request.urlopen(p["base"] + path, timeout=60).read())


def post(p, path, body):
    req = urllib.request.Request(p["base"] + path, data=json.dumps(body).encode(),
                                 headers={"Content-Type": "application/json"}, method="POST")
    try:
        with urllib.request.urlopen(req, timeout=300) as r:
            return r.status, json.loads(r.read())
    except urllib.error.HTTPError as e:
        return e.code, json.loads(e.read())


ALICE = {"user": "Alice", "pin": "alice-pin-1"}
BOB = {"user": "Bob", "pin": "bob-pin-123"}


def test_health_and_progress_come_from_the_registry(portal):
    st = get(portal, "/api/state")
    prog = st["progress"]
    reg = json.loads((portal["work"] / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    assert prog["matched_functions"] == len(reg["entries"])
    assert prog["by_binary"]["xbox"] == sum(1 for e in reg["entries"].values() if e["bin"] == "xb")
    assert "13.10.3052" in prog["compiler"]


def test_login_rules(portal):
    assert post(portal, "/api/login", {"user": "Shorty", "pin": "1234"})[0] == 403       # new handles need 8+
    assert post(portal, "/api/login", ALICE) == (200, {"ok": True, "message": "Registered"})
    assert post(portal, "/api/login", ALICE)[1]["ok"]
    assert post(portal, "/api/login", {"user": "Alice", "pin": "wrong-pin-x"})[0] == 403
    code, res = post(portal, "/api/login", {"user": "alice", "pin": "alice-pin-1"})
    assert code == 403 and "not case-sensitive" in res["error"]
    assert post(portal, "/api/login", BOB)[1]["ok"]


def test_failed_logins_are_throttled(portal):
    m = {"user": "Mallory", "pin": "mallory-pin"}
    assert post(portal, "/api/login", m)[1]["ok"]
    for _ in range(8):
        post(portal, "/api/login", {"user": "Mallory", "pin": "guess-guess"})
    code, res = post(portal, "/api/login", m)
    assert code == 403 and "Too many" in res["error"]


def test_task_has_the_real_target_bytes(portal):
    q = get(portal, "/api/queue?q=001cdc80")
    assert any(i["id"] == TID for i in q["items"])
    t = get(portal, f"/api/task?id={TID}")["task"]
    assert t["target_hex"] == "B8 A4 9D 43 00 C3"


def test_decompme_target_and_remembered_scratch(portal):
    import base64
    import msvc_verify as MV
    prep = get(portal, f"/api/decompme?id={TID}")
    assert prep["ok"] and prep["api"] == "https://decomp.me" and prep["existing_url"] == ""
    assert prep["fields"]["compiler"] == "msvc7.1" and prep["fields"]["compiler_flags"].startswith("/TP ")
    coff = MV.CoffObject(base64.b64decode(prep["obj_b64"]))
    (fn,) = coff.functions()
    assert fn.code == bytes.fromhex("B8 00 00 00 00 C3")             # the address became a relocation
    assert [coff.symbols[si].name for _o, si, _t in fn.relocs] == ["_DAT_00439DA4"]
    assert post(portal, "/api/decompme", {"id": TID, "slug": "../evil"})[0] == 400
    assert post(portal, "/api/decompme", {"id": TID, "slug": "AbC12"}) == (200, {"ok": True})
    assert get(portal, f"/api/decompme?id={TID}")["existing_url"] == "https://decomp.me/scratch/AbC12"
    assert get(portal, f"/api/task?id={TID}")["task"]["decompme_slug"] == "AbC12"
    assert get(portal, f"/api/decompme?id={TID}&fresh=1")["existing_url"] == ""


def test_claims(portal):
    assert post(portal, "/api/verify", {**ALICE, "id": TID, "cpp_code": GOOD})[0] == 403   # claim first
    assert post(portal, "/api/claim", {**ALICE, "id": TID})[1]["ok"]
    code, res = post(portal, "/api/claim", {**BOB, "id": TID})
    assert not res["ok"] and "Alice" in res["error"]
    assert post(portal, "/api/cancel", {**BOB, "id": TID})[0] == 403
    assert post(portal, "/api/verify", {**BOB, "id": TID, "cpp_code": GOOD})[0] == 403


def test_hardcoded_address_matches_bytes_but_does_not_count(portal):
    _, res = post(portal, "/api/verify", {**ALICE, "id": TID, "cpp_code": HARDCODED})
    assert res["ok"] and res["bytes_exact"] and not res["verified"] and not res["is_exact"]
    assert res["hardcoded_addresses"] and not res["newly_promoted"]


def test_compile_error_and_policy(portal):
    _, res = post(portal, "/api/verify", {**ALICE, "id": TID, "cpp_code": "void f() { int x = ; }"})
    assert not res["ok"] and "C2059" in res["compiler_error"]
    _, res = post(portal, "/api/verify", {**ALICE, "id": TID, "cpp_code": "void* sub_001CDC80() { __asm { nop } return 0; }"})
    assert not res["ok"] and res.get("policy_violation")


def test_exact_match_is_recorded(portal):
    _, res = post(portal, "/api/verify", {**ALICE, "id": TID, "cpp_code": GOOD, "tool_used": "pytest"})
    assert res["ok"] and res["verified"] and res["newly_promoted"], res
    assert res["reloc_checked"] == 1 and not res["reloc_mismatch"]
    work = portal["work"]
    reg = json.loads((work / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    e = reg["entries"][KEY]
    assert e["verified_by"] == "Alice" and e["source"] == "portal" and e["code"] == GOOD and e["match"] == "sub_001CDC80"
    out = (work / "reconstructed_src" / "Original_Binary_Order_Xbox.cpp").read_text(encoding="utf-8")
    assert "By: Alice" in out
    assert get(portal, "/api/state")["leaderboard"].get("Alice") == 1
    _, again = post(portal, "/api/claim", {**BOB, "id": TID})
    assert not again["ok"] and "Already verified" in again["error"]


def test_only_maintainers_can_push(portal):
    code, res = post(portal, "/api/git-sync", ALICE)
    assert code == 403 and "maintainers" in res["error"]


def test_reverify_keeps_portal_entries(portal):
    """scripts/reverify_all.py must re-check portal-verified functions, not drop them."""
    work = portal["work"]
    r = subprocess.run([sys.executable, "scripts/reverify_all.py", "--jobs", "4"], cwd=work, capture_output=True,
                       text=True, timeout=1800, env=portal["env"])
    assert r.returncode == 0, r.stdout[-2000:] + r.stderr[-2000:]
    reg = json.loads((work / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    assert reg["entries"][KEY]["verified_by"] == "Alice"


def test_page_against_real_server(portal):
    sync_api = pytest.importorskip("playwright.sync_api")
    from conftest import launch_chromium
    with sync_api.sync_playwright() as p:
        b = launch_chromium(p)
        ctx = b.new_context(viewport={"width": 1440, "height": 1000})
        ctx.route("https://fonts.googleapis.com/**", lambda r: r.abort())
        ctx.route("https://fonts.gstatic.com/**", lambda r: r.abort())
        pg = ctx.new_page()
        errors = []
        pg.on("pageerror", lambda e: errors.append(str(e)))
        pg.goto(portal["base"] + "/#workbench")
        reg = json.loads((portal["work"] / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
        n = f"{len(reg['entries']):,}"
        pg.wait_for_function(f"document.getElementById('top-verified-value').textContent.startsWith('{n} /')")
        pg.wait_for_function("document.getElementById('live-by-binary').textContent.includes('Xbox')")
        pg.fill("#contrib-name", ALICE["user"])
        pg.fill("#contrib-pin", ALICE["pin"])
        pg.click("#auth-form-row button[type=submit]")
        pg.wait_for_selector("#auth-signed-in-row", state="visible")
        pg.wait_for_selector(".queue-item")
        assert not errors, errors
        b.close()
