"""
The real portal server (portal/decomp_portal_server.py) with the real compiler, on a throwaway copy of the
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

from conftest import PORTAL, ROOT, needs_compiler, needs_xbox

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
    (work / "portal").mkdir()
    (work / "docs").mkdir()
    for src, dst in [(PORTAL / n, work / "portal" / n) for n in ("decomp_portal_server.py", "verify.py", "tools", "scripts", "website_kit")] + \
                    [(ROOT / n, work / n) for n in ("reconstructed_src", "reports")] + \
                    [(ROOT / "docs" / n, work / "docs" / n) for n in ("SCARFACE_DECOMP_AI_HANDOFF.md", "favicon.svg")]:
        if src.is_dir():
            shutil.copytree(src, dst, ignore=skip)
        elif src.exists():
            shutil.copy2(src, dst)
    try:                                   # Windows needs Developer Mode or admin rights for symlinks
        (work / "binaries").symlink_to(ROOT / "binaries", target_is_directory=True)
    except OSError:
        (work / "binaries").mkdir()
        for name in ("Scarface.exe", "default.xbe", "game.xbe"):
            if (ROOT / "binaries" / name).exists():
                shutil.copy2(ROOT / "binaries" / name, work / "binaries" / name)
    for f in ("portal/private/contributor_tokens.json", "reports/contributor_tokens.json", "reports/task_progress_state.json"):
        (work / f).unlink(missing_ok=True)

    reg_p = work / "reports" / "verified_registry.json"
    reg = json.loads(reg_p.read_text(encoding="utf-8"))
    # The test function and everything matched from the same code go back to "open", as they were when
    # nobody had matched them: its look-alikes are what the carry-over tests carry the match to.
    first = (reg["entries"].get(KEY) or {}).get("ported_from") or TID
    for k in [k for k, e in reg["entries"].items()
              if k == KEY or e.get("ported_from") in (first, TID) or f"{e['bin']}_{int(str(e['va']), 16):08X}" == first]:
        reg["entries"].pop(k)
    reg_p.write_text(json.dumps(reg), encoding="utf-8")
    q_p = work / "reports" / "full_remaining_queue.json"
    queue = json.loads(q_p.read_text(encoding="utf-8")) if q_p.exists() else []
    # The test matches the function under a plain name, and a match is only carried to look-alikes named the
    # same way: give a few of its look-alikes plain names too (and regroup), so there is somewhere to carry it.
    group = next((t.get("lookalike_group") for t in queue if t.get("id") == TID), "")
    mates = [t for t in queue if group and t.get("lookalike_group") == group and t.get("bin") == "xb" and t.get("id") != TID][:5]
    for t in mates:
        t.update(symbol=f"sub_{t['fva_int']:08X}", match_substr=f"sub_{t['fva_int']:08X}")
        reg["entries"].pop(f"xb:0x{t['fva_int']:08X}", None)
    for t in queue if mates else []:
        for k in ("lookalike_group", "lookalikes", "lookalike_rep"):
            t.pop(k, None)
    reg_p.write_text(json.dumps(reg), encoding="utf-8")
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
               SCARFACE_MSVC_BIN=str(MV.find_msvc71_bin()), SCARFACE_LOOKALIKE_MAX="3", SCARFACE_EASY_MAX="12", SCARFACE_NO_CATCHUP="1")
    log = open(work / "server.log", "wb")
    proc = subprocess.Popen([sys.executable, "portal/decomp_portal_server.py"], cwd=work, env=env, stdout=log,
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
    assert prog["matched_functions"] == sum(1 for e in reg["entries"].values() if e["bin"] in ("xb", "pc"))
    assert prog["by_binary"]["xbox"] == sum(1 for e in reg["entries"].values() if e["bin"] == "xb")
    assert "13.10.3052" in prog["compiler"]


def test_accepted_game_files_and_no_stray_404s(portal):
    assert get(portal, "/api/state")["binary_problems"] == {}       # the US files are accepted
    with urllib.request.urlopen(portal["base"] + "/favicon.ico", timeout=30) as r:
        assert r.status in (200, 204)                                # browsers ask for it on their own


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
    # The checked address shows as matched bytes (green), with the value the linker writes.
    linked = [d for d in res["diff_details"] if d["status"] == "linked"]
    assert len(linked) == 4 and all(d["symbol"] == "DAT_00439DA4" and d["address"] == "0x00439DA4" for d in linked)
    assert "".join(d["target"] for d in linked) == "A49D4300"
    assert res["saved_to"].startswith("reconstructed_src/xbox/") and res["saved_to"].endswith(".cpp")
    work = portal["work"]
    reg = json.loads((work / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    e = reg["entries"][KEY]
    assert e["verified_by"] == "Alice" and e["source"] == "portal" and e["code"] == GOOD and e["match"] == "sub_001CDC80"
    assert e["compiler"] in ("13.10.3052", "13.10.3077")      # which Toolkit release made the match
    out = (work / "reconstructed_src" / "Original_Binary_Order_Xbox.cpp").read_text(encoding="utf-8")
    assert "By: Alice" in out
    _, again = post(portal, "/api/claim", {**BOB, "id": TID})
    assert not again["ok"] and "Already verified" in again["error"]

    # sub_001CDC80 is `mov eax, offset DAT; ret`: hundreds of functions have the same code with their own
    # address. The server tries Alice's code on (here, at most 3 of) them and records the ones that match.
    assert res["lookalikes_queued"] == 3
    for _ in range(240):
        st = get(portal, f"/api/lookalikes?id={TID}")
        if not st["running"]:
            break
        time.sleep(0.5)
    assert st["ok"] and not st["running"] and st["tried"] == 3 and st["matched"] == 3, st
    reg = json.loads((work / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    for mid in st["matched_ids"]:
        task = get(portal, f"/api/task?id={mid}")["task"]
        e = reg["entries"][f"{task['bin']}:0x{task['fva_int']:08X}"]
        assert e["verified_by"] == "Alice" and e["ported_from"] == TID and task["status"] == "VERIFIED"
        assert e["code"].startswith("// Same machine code as") and f"sub_{task['fva_int']:08X}" in e["code"]
        assert "DAT_00439DA4" not in e["code"]           # each one points at its own global
    assert get(portal, "/api/state")["leaderboard"].get("Alice") == 4
    assert get(portal, "/api/state")["lookalikes"]["groups"] > 100


def test_cleaned_up_version_replaces_the_saved_one(portal):
    """After the match, a tidier version that still matches exactly is kept; credit stays with Alice."""
    nicer = ('// Returns the stats page object.\nextern "C" char DAT_00439DA4;\n\n'
             'void* __cdecl sub_001CDC80(void)\n{\n    return &DAT_00439DA4;\n}')
    _, res = post(portal, "/api/verify", {**BOB, "id": TID, "cpp_code": nicer})          # AI loop: never kept
    assert res["is_exact"] and not res["revised"]
    _, res = post(portal, "/api/verify", {**BOB, "id": TID, "cpp_code": HARDCODED, "keep_revision": True})
    assert not res["is_exact"] and not res["revised"]                                      # must still verify
    _, res = post(portal, "/api/verify", {**BOB, "id": TID, "cpp_code": nicer, "keep_revision": True})
    assert res["is_exact"] and res["revised"], res
    work = portal["work"]
    e = json.loads((work / "reports" / "verified_registry.json").read_text(encoding="utf-8"))["entries"][KEY]
    assert e["code"] == nicer and e["verified_by"] == "Alice" and e["revised_by"] == "Bob"
    out = (work / res["saved_to"]).read_text(encoding="utf-8")
    assert "Cleaned up by: Bob" in out and "Returns the stats page object." in out
    assert get(portal, "/api/state")["leaderboard"].get("Bob", 0) == 0


def test_same_method_in_another_build_starts_from_the_match(portal):
    """PauseMenuPageStats::vfunc_00 is in the prototype too. Once the retail one is matched, the prototype's
    copy opens with that code (and says where it came from)."""
    code, res = None, None
    try:
        res = get(portal, "/api/task?id=proto_00196800")
    except urllib.error.HTTPError as e:
        code = e.code
    if code == 404:
        pytest.skip("the prototype (binaries/game.xbe) is not in this queue")
    t = res["task"]
    assert any(c["id"] == TID and c["status"] == "VERIFIED" for c in t["counterparts"])
    if t["status"] != "VERIFIED":
        assert t["starter_from"] == TID and t["starter_kind"] == "counterpart"
        assert "DAT_00439DA4" in t["starter_cpp"] and "already matched in the retail Xbox game" in t["starter_cpp"]


def test_queue_shows_lookalike_groups_first(portal):
    q = get(portal, "/api/queue?limit=20")
    sizes = [i["lookalikes"] for i in q["items"]]
    assert sizes[0] > 50 and sizes == sorted(sizes, reverse=True)


def test_other_websites_and_hosts_are_refused(portal):
    """A page on another site can make the visitor's browser POST to localhost; the portal refuses it.
    So does a request whose Host header names another site (DNS rebinding)."""
    code, res = post(portal, "/api/login", ALICE)
    assert code == 200
    req = urllib.request.Request(portal["base"] + "/api/login", data=json.dumps(ALICE).encode(), method="POST",
                                 headers={"Content-Type": "text/plain", "Origin": "https://evil.example"})
    try:
        urllib.request.urlopen(req, timeout=30)
        raise AssertionError("cross-site POST was accepted")
    except urllib.error.HTTPError as e:
        assert e.code == 403 and "other websites" in json.loads(e.read())["error"]
    req = urllib.request.Request(portal["base"] + "/api/state", headers={"Host": "evil.example"})
    try:
        urllib.request.urlopen(req, timeout=30)
        raise AssertionError("foreign Host header was accepted")
    except urllib.error.HTTPError as e:
        assert e.code == 403


def test_new_handles_are_plain_names(portal):
    code, res = post(portal, "/api/login", {"user": "<b>x</b>", "pin": "long-enough-pin"})
    assert code == 403 and "Handles use" in res["error"]
    code, res = post(portal, "/api/login", {"user": "Tony M. (Founder)", "pin": "long-enough-pin"})
    assert code == 200 and res["ok"]


def test_only_maintainers_can_push(portal):
    code, res = post(portal, "/api/git-sync", ALICE)
    assert code == 403 and "maintainers" in res["error"]


def test_reverify_keeps_portal_entries(portal):
    """portal/scripts/reverify_all.py must re-check portal-verified functions, not drop them."""
    work = portal["work"]
    r = subprocess.run([sys.executable, "portal/scripts/reverify_all.py", "--jobs", "4"], cwd=work, capture_output=True,
                       text=True, timeout=1800, env=portal["env"])
    assert r.returncode == 0, r.stdout[-2000:] + r.stderr[-2000:]
    reg = json.loads((work / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    assert reg["entries"][KEY]["verified_by"] == "Alice" and reg["entries"][KEY]["revised_by"] == "Bob"
    assert reg["entries"][KEY]["compiler"] in ("13.10.3052", "13.10.3077")


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
        n = f"{get(portal, '/api/state')['progress']['matched_functions']:,}"
        # (the real server's content policy forbids evaluating strings, so wait on the elements themselves)
        sync_api.expect(pg.locator("#top-verified-value")).to_contain_text(f"{n} /", timeout=30000)
        sync_api.expect(pg.locator("#live-by-binary")).to_contain_text("Xbox")
        pg.fill("#contrib-name", ALICE["user"])
        pg.fill("#contrib-pin", ALICE["pin"])
        with pg.expect_response("**/api/login", timeout=60000) as info:
            pg.click("#auth-form-row button[type=submit]")
        assert info.value.ok
        pg.wait_for_selector("#auth-signed-in-row", state="visible")
        pg.wait_for_selector(".queue-item")
        assert not errors, errors
        b.close()


def test_a_names_pass_is_kept_only_when_it_names_something(portal):
    """only_if_clearer: an exact revision replaces the saved text only if it leaves fewer stand-in names."""
    work = portal["work"]
    stored = json.loads((work / "reports" / "verified_registry.json").read_text(encoding="utf-8"))["entries"][KEY]["code"]
    task = get(portal, f"/api/task?id={TID}")["task"]
    assert task["starter_cpp"] == stored and task["can_rename"] and task["readable"]["left"] >= 1
    same = stored + "\n// a comment names nothing\n"
    _, res = post(portal, "/api/verify", {**BOB, "id": TID, "cpp_code": same, "keep_revision": True, "only_if_clearer": True})
    assert res["is_exact"] and not res["revised"] and "to name" in res["not_kept"], res
    worse = same.replace("DAT_00439DA4", "g_statsPage")          # a made-up name: its address can't be checked
    _, res = post(portal, "/api/verify", {**BOB, "id": TID, "cpp_code": worse, "keep_revision": True, "only_if_clearer": True})
    assert not res["revised"] and "reports/names.json" in res["not_kept"], res
    after = json.loads((work / "reports" / "verified_registry.json").read_text(encoding="utf-8"))["entries"][KEY]["code"]
    assert after == stored


def test_easy_pass_matches_what_the_starter_code_already_gets(portal):
    """The portal's own starter code, compiled for every open function: exact, fully checked ones are recorded."""
    status, res = post(portal, "/api/easy-pass", {"user": "Nobody", "pin": "0000"})
    assert status == 403
    before = get(portal, "/api/state")["progress"]["matched_functions"]
    _, res = post(portal, "/api/easy-pass", BOB)
    assert res["ok"] and res["running"], res
    for _ in range(600):
        st = get(portal, "/api/easy-pass")
        if not st["running"]:
            break
        time.sleep(0.5)
    assert not st["running"] and st["tried"] == st["total"] > 0 and st["matched"] > 0 and st["by"] == "Bob", st
    assert st["progress"]["matched_functions"] + st["progress"]["prototype"]["matched"] >= before + st["matched"]
    reg = json.loads((portal["work"] / "reports" / "verified_registry.json").read_text(encoding="utf-8"))
    mine = [e for e in reg["entries"].values() if e.get("tool_used") == "the portal's starter code (no AI)"]
    assert len(mine) == st["matched"] and all(e["verified_by"] == "Bob" for e in mine)
    assert all("unchecked" not in (e.get("note") or "") for e in mine)
    assert st["total"] == 12
    tried = json.loads((portal["work"] / "portal" / "private" / "easy_pass.json").read_text(encoding="utf-8"))
    assert len(tried) == st["tried"] - st["matched"]                    # the ones that didn't match aren't tried twice
    _, again = post(portal, "/api/easy-pass", BOB)                       # the next twelve
    _, stop = post(portal, "/api/easy-pass", {**BOB, "stop": True})
    assert again["ok"] and stop["ok"]
    for _ in range(600):
        if not get(portal, "/api/easy-pass")["running"]:
            break
        time.sleep(0.5)
    assert not get(portal, "/api/easy-pass")["running"]
