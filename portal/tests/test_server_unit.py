"""Small parts of portal/decomp_portal_server.py that need no compiler or game files."""
import importlib
import io
import sys

import pytest

import conftest


@pytest.fixture(scope="module")
def S():
    sys.path.insert(0, str(conftest.PORTAL))
    return importlib.import_module("decomp_portal_server")


class _GoneWriter(io.RawIOBase):
    def write(self, b):
        raise ConnectionAbortedError(10053, "An established connection was aborted")


def test_a_page_that_stopped_waiting_is_not_an_error(S, capsys):
    """Stop & Save (or a closed tab) drops the connection before the AI answer arrives. Writing the
    reply then fails; that must not print tracebacks or try to send a second, 500 reply."""
    h = S.Handler.__new__(S.Handler)
    h.wfile = _GoneWriter()
    h.request_version = "HTTP/1.1"
    h.requestline = "POST /api/ai HTTP/1.1"
    h.command = "POST"
    h.client_address = ("127.0.0.1", 1)
    h.close_connection = False
    h.log_request = lambda *a, **k: None
    h._json({"ok": True})
    assert h.close_connection is True
    out = capsys.readouterr()
    assert "Traceback" not in out.out + out.err


def test_saved_file_for_an_entry(S):
    import registry_outputs as RO
    assert RO.entry_path({"bin": "pc", "symbol": "CollisionBehaviourTypeGroup::vfunc_00"}).startswith("reconstructed_src/pc/")
    assert RO.entry_path({"bin": "xb", "symbol": "sub_001CDC80"}).startswith("reconstructed_src/xbox/")
    assert RO.entry_path({"bin": "nope", "symbol": "x"}) == ""


class _Img:
    """Just enough of BinaryImage: bytes at addresses."""
    def __init__(self, blobs):
        self.blobs = blobs

    def read(self, va, n):
        for base, data in self.blobs.items():
            if base <= va and va + n <= base + len(data):
                return data[va - base:va - base + n]
        return None


@pytest.mark.parametrize("code, ok", [
    (b"\xC3", True),                                    # void f() {}
    (b"\x56\x8B\xF1\x5E\xC3", True),                    # push esi; mov esi, ecx; pop esi; ret
    (b"\xE8\x00\x00\x00\x00\xCC", True),                # call to a function that does not return
    (b"\xFF\x24\x85\x00\x10\x00\x00\xCB\xCF", True),     # jmp [table]: the data after it is never run
    (b"\xCB", False),                                   # retf: never made from C++
    (b"\x3C\x8B", False),                               # cmp al, 8Bh and then nothing
    (b"\x05\x05\x02\x05\x05\xCC", False),               # a table of small numbers, then padding
    (b"\xC5\x10\x8B\x4D\x00\xC3", False),               # lds: the middle of another instruction
])
def test_data_is_not_queued_as_a_function(code, ok):
    from sf_binaries import not_compiled_reason
    reason = not_compiled_reason(_Img({0x1000: code}), 0x1000, len(code))
    assert (reason == "") is ok, reason


def test_old_queues_lose_their_non_functions_once(S, tmp_path, monkeypatch):
    img = _Img({0x1000: b"\xC3", 0x2000: b"\xCB", 0x3000: b"\xCB"})
    monkeypatch.setattr(S, "image_for", lambda b: img)
    monkeypatch.setattr(S, "QUEUE_JSON", tmp_path / "q.json")
    monkeypatch.setattr(S, "REPORTS_DIR", tmp_path)
    tasks = [{"bin": "xb", "fva_int": 0x1000, "size": 1}, {"bin": "xb", "fva_int": 0x2000, "size": 1},
             {"bin": "xb", "fva_int": 0x3000, "size": 1}]
    kept = S.drop_non_code(tasks, verified={"xb:0x00003000"})    # verified ones always stay
    assert [t["fva_int"] for t in kept] == [0x1000, 0x3000]
    assert all(t["code_check"] for t in kept)
    assert S.read_json(tmp_path / "q.json", None) == kept
    (tmp_path / "q.json").unlink()
    assert S.drop_non_code(kept, verified=set()) is kept and not (tmp_path / "q.json").exists()  # checked once


def test_prototype_functions_also_in_retail_are_left_out_of_the_queue(S, monkeypatch):
    """The queue lists the released game plus the prototype's own code. A prototype function with the
    same code as a retail one is matched along with it, and one with the same class method is an older
    version of it; both only show up in their own lane, when searched for, or once verified."""
    def task(i, b, symbol, group=""):
        return {"id": f"{b}{i}", "bin": b, "symbol": symbol, "lookalike_group": group, "status": "UNCLAIMED"}
    xb_same = task(1, "xb", "sub_00011000", "g1")
    proto_same = task(2, "proto", "sub_00022000", "g1")
    xb_method = task(3, "xb", "Car::Drive")
    proto_method = task(4, "proto", "Car::Drive")
    proto_own = task(5, "proto", "EditorTool::Draw")
    proto_pair = [task(6, "proto", "sub_00033000", "g2"), task(7, "proto", "sub_00034000", "g2")]
    tasks = [xb_same, proto_same, xb_method, proto_method, proto_own] + proto_pair
    monkeypatch.setattr(S, "GROUPS", {"g1": [xb_same, proto_same], "g2": proto_pair})
    monkeypatch.setattr(S, "BY_SYMBOL", {"Car::Drive": [xb_method, proto_method], "EditorTool::Draw": [proto_own]})
    assert [S.in_retail(t) for t in tasks] == ["", "code", "", "method", "", "", ""]
    for t in tasks:
        t["in_retail"] = S.in_retail(t)
    assert [t["id"] for t in tasks if S.in_default_queue(t)] == ["xb1", "xb3", "proto5", "proto6", "proto7"]


def test_progress_without_the_game_isnt_100_percent(S, monkeypatch):
    """A fresh clone with no game in binaries/ has no work queue. The matched functions are then not "all
    there are": the totals come from the project's own lists, and the portal says the game is missing."""
    monkeypatch.setattr(S, "REGISTRY", {"entries": {
        "xb:0x00011000": {"bin": "xb", "size": 10}, "xb:0x00011010": {"bin": "xb", "size": 6},
        "pc:0x00700000": {"bin": "pc", "size": 4}, "proto:0x00012000": {"bin": "proto", "size": 2}}})
    monkeypatch.setattr(S, "ALL_TASKS", [])
    monkeypatch.setattr(S, "accepted_binaries", lambda: {})
    monkeypatch.setattr(S, "_LISTED", {"xb": 100, "pc": 20, "proto": 50, "": 0})
    p = S.progress()
    assert (p["matched_functions"], p["total_functions"], p["matched_percent"]) == (3, 120, 2.5)
    assert p["no_game"] is True and p["prototype"] == {"matched": 1, "total": 50}
    # with the Xbox game here, its own queue counts; the PC's still comes from the lists
    monkeypatch.setattr(S, "accepted_binaries", lambda: {"xb": "default.xbe"})
    monkeypatch.setattr(S, "ALL_TASKS", [{"bin": "xb", "status": "UNCLAIMED"}] * 7 + [{"bin": "xb", "status": "VERIFIED"}] * 2)
    p = S.progress()
    assert p["no_game"] is False and p["total_functions"] == 2 + 7 + 20


def test_how_many_look_alikes_are_still_to_try(S, monkeypatch):
    """What the page shows beside the count of new matches, which keeps rising while this is above zero."""
    monkeypatch.setattr(S, "PORT_STATUS", {"a": {"running": True, "total": 67, "tried": 60},
                                           "b": {"running": False, "total": 9, "tried": 2},     # finished or failed
                                           "c": {"running": True, "total": 5, "tried": 5}})
    assert S.porting_left() == 7
    monkeypatch.setattr(S, "PORT_STATUS", {})
    assert S.porting_left() == 0


def test_earlier_matches_catch_up_on_their_look_alikes(S, monkeypatch, tmp_path):
    """A retail match made before the prototype was added is tried on the prototype's identical copy at
    startup, credited to whoever matched it. A failed try is not repeated at every start, unless the
    match's code changes."""
    def task(i, b, va):
        return {"id": f"{b}_{va:08X}", "bin": b, "fva_int": va, "va": f"0x{va:08X}", "symbol": f"sub_{va:08X}",
                "status": "UNCLAIMED", "lookalike_group": "g", "size": 8, "flags": "/O2"}
    src, twin, other = task(1, "xb", 0x11000), task(2, "proto", 0x22000), task(3, "proto", 0x33000)
    src["status"] = "VERIFIED"
    reg = {"entries": {S.task_key(src): {"code": "int f() { return 1; }", "verified_by": "Ana", "tool_used": "by hand"}}}
    monkeypatch.setattr(S, "REGISTRY", reg)
    monkeypatch.setattr(S, "GROUPS", {"g": [src, twin, other]})
    monkeypatch.setattr(S, "CATCHUP_JSON", tmp_path / "catchup.json")
    monkeypatch.setattr(S.MV, "find_msvc71_bin", lambda: "cl")
    monkeypatch.setattr(S, "relocs_for", lambda t: [])
    monkeypatch.setattr(S.LA, "port_code", lambda code, *a: code)
    monkeypatch.setattr(S, "save_overlay", lambda t: None)
    monkeypatch.setattr(S, "save_registry", lambda: None)
    monkeypatch.setattr(S, "append_audit", lambda e: None)
    tries = []

    def verify(m, code):
        tries.append(m["id"])
        return {"ok": True, "verified": m is twin, "matched_bytes": 8, "total_bytes": 8}
    monkeypatch.setattr(S, "run_verify", verify)
    jobs = []
    monkeypatch.setattr(S, "queue_port", lambda t, code, user, tool, catchup=False, tried=None:
                        jobs.append((t, code, user, tool, catchup)) or len(S.catchup_targets(t, code, user, tried or {})))

    assert S.catch_up_lookalikes() == 2
    S.port_lookalikes(*jobs[0])
    assert sorted(tries) == sorted([twin["id"], other["id"]])
    assert twin["status"] == "VERIFIED" and reg["entries"][S.task_key(twin)]["verified_by"] == "Ana"
    assert reg["entries"][S.task_key(twin)]["ported_from"] == src["id"]

    jobs.clear(); tries.clear()
    assert S.catch_up_lookalikes() == 0                      # the failed try is remembered, not repeated
    reg["entries"][S.task_key(src)]["code"] = "int f() { return 1; } // tidied"
    jobs.clear()
    assert S.catch_up_lookalikes() == 1                      # new code: worth another try
    assert [m["id"] for m in S.catchup_targets(src, jobs[0][1], "Ana", S.read_json(S.CATCHUP_JSON, {}))] == [other["id"]]

    monkeypatch.setattr(S.MV, "find_msvc71_bin", lambda: None)
    assert S.catch_up_lookalikes() == 0          # nothing to compile with: nothing is tried or remembered


def test_submissions_carry_only_new_matches_and_imports_check_each_one(S, monkeypatch, tmp_path):
    """A contributor's file holds the matches that are not on GitHub yet; importing it compiles each one
    again and adds only exact matches, credited to whoever made them."""
    def task(va, status="UNCLAIMED"):
        return {"id": f"xb_{va:08X}", "bin": "xb", "fva_int": va, "va": f"0x{va:08X}", "symbol": f"sub_{va:08X}",
                "status": status, "size": 4, "flags": "/O2", "lookalike_group": ""}
    a, b, c = task(0x1000, "VERIFIED"), task(0x2000, "VERIFIED"), task(0x3000)
    reg = {"entries": {S.task_key(a): {"bin": "xb", "va": a["va"], "size": 4, "symbol": a["symbol"], "code": "int a();", "verified_by": "Bo"},
                       S.task_key(b): {"bin": "xb", "va": b["va"], "size": 4, "symbol": b["symbol"], "code": "int b();", "verified_by": "Bo",
                                       "tool_used": "by hand"}}}
    monkeypatch.setattr(S, "REGISTRY", reg)
    monkeypatch.setattr(S, "published_keys", lambda base=None: frozenset({S.task_key(a)}))
    sub = S.make_submission("Bo")
    assert sub["format"] == S.SUBMISSION_FORMAT and list(sub["entries"]) == [S.task_key(b)]
    assert sub["entries"][S.task_key(b)]["code"] == "int b();" and "imported_by" not in sub["entries"][S.task_key(b)]
    assert S.submission_filename("Bo the Great!").startswith("scarface-submission-Bo-the-Great-")

    # import on a maintainer's portal: c is new and matches, a is already there, an unknown key and a miss fail
    reg2 = {"entries": {S.task_key(a): reg["entries"][S.task_key(a)]}}
    a2, c2, d2 = dict(a), dict(c), task(0x4000)
    monkeypatch.setattr(S, "REGISTRY", reg2)
    monkeypatch.setattr(S, "ALL_TASKS", [a2, c2, d2])
    monkeypatch.setattr(S, "save_overlay", lambda t: None)
    monkeypatch.setattr(S, "save_registry", lambda: None)
    monkeypatch.setattr(S, "append_audit", lambda e: None)
    monkeypatch.setattr(S, "queue_port", lambda *a, **k: 0)
    monkeypatch.setattr(S, "run_verify", lambda t, code: {"ok": True, "verified": "good" in code, "matched_bytes": 4 if "good" in code else 2,
                                                          "total_bytes": 4, "flags": "/O2"})
    bundle = {"format": S.SUBMISSION_FORMAT, "submitted_by": "Cy", "entries": {
        S.task_key(a): {"code": "good a"}, S.task_key(c2): {"code": "good c", "verified_by": "Cy", "tool_used": "AI"},
        S.task_key(d2): {"code": "bad d"}, "xb:0x09999999": {"code": "good ?"}}}
    st = S.import_submission(bundle, "Founder")
    assert (st["added"], st["already"], len(st["failed"]), st["running"], st["error"]) == (1, 1, 2, False, "")
    e = reg2["entries"][S.task_key(c2)]
    assert e["verified_by"] == "Cy" and e["tool_used"] == "AI" and e["imported_by"] == "Founder" and c2["status"] == "VERIFIED"
    assert d2["status"] == "UNCLAIMED"
    assert S.import_submission({"entries": {}}, "Founder")["error"]          # not a submission file


# --------------------------------------------------------------------------- "what it does"

@pytest.fixture
def described(S, monkeypatch):
    """A registry with one rebuilt function and the task list around it; nothing is written to disk."""
    reg = {"entries": {"xb:0x00011000": {"bin": "xb", "va": "0x00011000", "size": 6, "symbol": "Car::Lights",
                                         "flags": "/O2", "verified_by": "Alice", "code": "void f() {}"}}}
    tasks = [{"id": "xb_00011000", "bin": "xb", "fva_int": 0x11000, "va": "0x00011000", "size": 6, "symbol": "Car::Lights",
              "status": "VERIFIED", "flags": "/O2"},
             {"id": "xb_00011010", "bin": "xb", "fva_int": 0x11010, "va": "0x00011010", "size": 8, "symbol": "sub_00011010",
              "status": "UNCLAIMED", "flags": "/O2"}]
    monkeypatch.setattr(S, "REGISTRY", reg)
    monkeypatch.setattr(S, "ALL_TASKS", tasks)
    monkeypatch.setattr(S, "TASK_BY_ID", {t["id"]: t for t in tasks})
    monkeypatch.setattr(S, "save_registry", lambda: None)
    return reg, tasks


def test_what_is_one_short_line(S):
    assert S.clean_what("  Turns the\n headlights\x00 on  ") == "Turns the headlights on"
    assert len(S.clean_what("x" * 500)) == S.WHAT_MAX
    assert S.clean_what(None) == "" and S.clean_what(42) == ""


def test_describing_a_rebuilt_function(S, described):
    reg, tasks = described
    assert "Only rebuilt functions" in S.describe_verified(tasks[1], "Something", "Bob")
    assert S.describe_verified(tasks[0], "Turns the car's lights on", "Bob") is None
    e = reg["entries"]["xb:0x00011000"]
    assert e["what"] == "Turns the car's lights on" and e["what_by"] == "Bob"
    assert S.live_task(tasks[0])["what"] == "Turns the car's lights on"
    assert S.describe_verified(tasks[0], "  ", "Bob") is None and "what" not in e         # cleared


def test_descriptions_travel_in_submissions(S, described, monkeypatch):
    reg, tasks = described
    monkeypatch.setattr(S, "published_keys", lambda base=None: frozenset(reg["entries"]))
    monkeypatch.setitem(S._PUBLISHED, "what", {"xb:0x00011000": ""})
    S.describe_verified(tasks[0], "Turns the car's lights on", "Bob")
    bundle = S.make_submission("Bob")
    assert bundle["count"] == 1 and bundle["entries"] == {}
    assert bundle["descriptions"] == {"xb:0x00011000": {"what": "Turns the car's lights on", "what_by": "Bob"}}
    # a maintainer imports it elsewhere: the text only, nothing to compile
    reg["entries"]["xb:0x00011000"].pop("what")
    monkeypatch.setattr(S, "append_audit", lambda *a: None)
    st = S.import_submission(dict(bundle, descriptions={"xb:0x00011000": {"what": "Turns the car's lights on\n", "what_by": "Bob"},
                                                        "xb:0x0FFFFFFF": {"what": "nobody", "what_by": "Eve"}}), "Maint")
    assert st["described"] == 1 and not st["error"]
    assert reg["entries"]["xb:0x00011000"]["what"] == "Turns the car's lights on"
    assert reg["entries"]["xb:0x00011000"]["what_by"] == "Bob"


def test_what_reaches_the_generated_files_and_the_feed(S):
    import registry_outputs as RO
    e = {"bin": "xb", "va": "0x00011000", "size": 6, "symbol": "Car::Lights", "flags": "/O2", "verified_by": "Alice",
         "code": "void f() {}", "what": "Turns the car's lights on", "verified_at": "2026-11-10 10:00:00"}
    assert "// What it does: Turns the car's lights on\n" in RO._block("xb:0x00011000", e)
    assert "What it does" not in RO._block("xb:0x00011000", dict(e, what=""))
    assert "<summary>Turns the car&apos;s lights on 0x00011000" in RO.feed_xml({"entries": {"xb:0x00011000": e}}) or \
        "<summary>Turns the car's lights on 0x00011000" in RO.feed_xml({"entries": {"xb:0x00011000": e}})


# --------------------------------------------------------------------------- the city for Blender

class _Replies:
    """Just enough of a request handler for the post_* methods: what they answer."""
    def __init__(self):
        self.sent = []

    def _json(self, obj, code=200):
        self.sent.append((code, obj))


def test_the_city_export_gets_the_time_of_day_and_weather_the_page_picked(S, monkeypatch):
    """The page always sends the weather, and an hour only when one is picked: none is the sky as stored,
    and midnight (0) is an hour like the others."""
    asked = []
    monkeypatch.setattr(S.BLENDER, "start", lambda version, index, hour=None, weather="clear":
                        asked.append((version, hour, weather)) or None)
    monkeypatch.setattr(S.GAME_FILES, "index", lambda: {})
    h = _Replies()
    for body in ({"version": "pc", "weather": "clear"}, {"version": "pc", "hour": 18, "weather": "rain"},
                 {"version": "pc", "hour": 0, "weather": "clear"}, {"version": "pc", "hour": 24, "weather": "rain"}):
        S.Handler.post_game_files_blender(h, body)
        assert h.sent[-1][0] == 200 and h.sent[-1][1]["ok"] is True
    assert asked == [("pc", None, "clear"), ("pc", 18.0, "rain"), ("pc", 0.0, "clear"), ("pc", 24.0, "rain")]
    S.Handler.post_game_files_blender(h, {"version": "pc", "hour": "six", "weather": "rain"})
    assert h.sent[-1] == (400, {"ok": False, "error": "The hour is from 0 to 24."}) and len(asked) == 4


def test_the_city_export_says_when_the_hour_or_weather_cant_be(S, monkeypatch):
    """The real job's answers reach the page as errors, and nothing starts."""
    monkeypatch.setattr(S.BLENDER, "busy", lambda: "")
    monkeypatch.setattr(S.GAME_FILES, "index", lambda: {})
    h = _Replies()
    S.Handler.post_game_files_blender(h, {"version": "pc", "hour": 25})
    assert h.sent[-1] == (400, {"ok": False, "error": "The hour is from 0 to 24."})
    S.Handler.post_game_files_blender(h, {"version": "pc", "weather": "snow"})
    assert h.sent[-1] == (400, {"ok": False, "error": "The weather is clear or rain."})
    assert not S.BLENDER.running


def test_the_city_time_of_day_and_weather_are_kept_with_the_other_settings(S, monkeypatch, tmp_path):
    """Like the frames a second and the Xbox tones beside them, the city's time of day and weather are kept
    for next time; a save of the other switches leaves them, and what isn't a time or a weather is ignored."""
    monkeypatch.setattr(S, "SPEED_FILE", tmp_path / "portal_speed.json")
    monkeypatch.setattr(S, "apply_texture_look", lambda on: None)

    def kept():
        st = S.speed_settings()
        return st["city_hour"], st["city_weather"]
    assert kept() == (None, "clear")                                       # nothing kept yet: as stored, clear
    h = _Replies()
    S.Handler.post_game_files_speed(h, {"use_cores": True, "use_gpu": True, "xbox_look": False, "fps": 60,
                                        "city_hour": 18, "city_weather": "rain"})
    assert h.sent[-1][0] == 200 and (h.sent[-1][1]["city_hour"], h.sent[-1][1]["city_weather"]) == (18, "rain")
    assert kept() == (18, "rain") and S.speed_settings()["fps"] == 60
    S.Handler.post_game_files_speed(h, {"use_cores": False})
    assert kept() == (18, "rain") and S.speed_settings()["cores"] is False
    S.Handler.post_game_files_speed(h, {"city_hour": 30, "city_weather": "snow"})
    S.Handler.post_game_files_speed(h, {"city_hour": "dusk", "city_weather": None})
    S.Handler.post_game_files_speed(h, {"city_hour": True})
    assert kept() == (18, "rain")
    S.Handler.post_game_files_speed(h, {"city_hour": 0})
    assert kept() == (0, "rain")
    S.Handler.post_game_files_speed(h, {"city_hour": None, "city_weather": "clear"})     # As stored
    assert kept() == (None, "clear")
    (tmp_path / "portal_speed.json").write_text('{"city_hour": 99, "city_weather": "fog"}', encoding="utf-8")
    assert kept() == (None, "clear")


def test_the_setup_checklist_says_what_is_missing_and_how_to_fix_it(S, monkeypatch):
    monkeypatch.setattr(S, "image_for", lambda b: b"x" if b == "xb" else None)
    monkeypatch.setattr(S, "compiler_build", lambda: "")
    monkeypatch.setattr(S.GAME_FILES, "index", lambda: None)
    monkeypatch.setattr(S.MOVIES, "find_ffmpeg", lambda d: None)
    monkeypatch.setattr(S.BX, "find_blender", lambda d: None)
    rows = {r["key"]: r for r in S.setup_checklist()}
    assert list(rows) == ["game", "compiler", "copied", "ffmpeg", "blender"]
    assert rows["game"]["ok"] and rows["game"]["note"] == "Xbox default.xbe" and not rows["game"]["fix"]
    for key, word in (("compiler", "setup_msvc71.py"), ("copied", "Copy everything"), ("ffmpeg", "Install FFmpeg"),
                      ("blender", "blender.org")):
        assert not rows[key]["ok"] and word in rows[key]["fix"] and not rows[key]["note"], key
    monkeypatch.setattr(S, "compiler_build", lambda: "13.10.3052")
    monkeypatch.setattr(S.BX, "find_blender", lambda d: S.Path("C:/Blender/blender.exe"))
    rows = {r["key"]: r for r in S.setup_checklist()}
    assert rows["compiler"]["ok"] and "13.10.3052" in rows["compiler"]["note"]
    assert rows["blender"]["ok"] and "blender.exe" in rows["blender"]["note"]


def test_a_wrong_pin_says_where_pins_are_kept_and_how_to_start_over(S, monkeypatch, tmp_path):
    monkeypatch.setattr(S, "AUTH_JSON", tmp_path / "contributor_tokens.json")
    monkeypatch.setattr(S, "LEGACY_AUTH_JSON", tmp_path / "none.json")
    monkeypatch.setattr(S, "_FAILS", {})
    assert S.authenticate("Somebody", "first-pin-1234")[0]
    ok, why = S.authenticate("Somebody", "another-pin-99")
    assert not ok and "different PIN" in why and "only on this computer" in why and "rename that file" in why
    assert "first-pin" not in why and "another-pin" not in why


def test_the_ai_is_shown_matched_functions_of_the_same_class(S, monkeypatch):
    reg = {"entries": {
        "xb:0x00000010": {"bin": "xb", "va": "0x00000010", "size": 40, "symbol": "core::Timer::vfunc_02", "code": "class Timer { int m_ticks; };"},
        "xb:0x00000020": {"bin": "xb", "va": "0x00000020", "size": 12, "symbol": "core::Timer::vfunc_03", "code": "// short"},
        "pc:0x00000030": {"bin": "pc", "va": "0x00000030", "size": 99, "symbol": "core::Timer::vfunc_02", "code": "// the PC's"},
        "xb:0x00000040": {"bin": "xb", "va": "0x00000040", "size": 50, "symbol": "core::Clock::vfunc_01", "code": "// another class"},
        "xb:0x00000050": {"bin": "xb", "va": "0x00000050", "size": 70, "symbol": "core::Timer::vfunc_09", "code": "x" * 9000}}}
    monkeypatch.setattr(S, "REGISTRY", reg)
    monkeypatch.setattr(S, "_CLASSMATES", (-1, {}))
    t = {"bin": "xb", "fva_int": 0x20, "symbol": "core::Timer::vfunc_03"}
    near = S.neighbours(t)
    assert [n["symbol"] + "@" + n["va"] for n in near] == ["core::Timer::vfunc_02@0x00000010", "core::Timer::vfunc_02@0x00000030"]
    assert near[0]["code"].startswith("class Timer") and "Xbox" in near[0]["build"] and "PC" in near[1]["build"]
    assert S.neighbours({"bin": "xb", "fva_int": 0x99, "symbol": "sub_00000099"}) == []      # not in a class
    assert S.class_of("pure3d::Shader::vfunc_04") == "pure3d::Shader" and S.class_of("sub_1") == ""
