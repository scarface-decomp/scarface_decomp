"""
A cutscene's spoken lines as captions with times (clean-room spec SPEC-009 section 4): the script names
each line, the line's subtitle file holds its text, and the game cuts it into captions.
"""
import struct

import cutscene as CUT
import media

SCRIPT = r'''
NISSequenceCue { CameraAnimationName "cam"; };
NISScriptFunctionCallTrack
{
    FrameBegin 136;
    ScriptFunctionCall "SubtitleManager_LocalisedDialogueEvent( ^nis\\\\MNIS_A23_0_Intro_to_Tranq_02^, 0, 2600 );";
};
NISScriptFunctionCallTrack
{
    FrameBegin 30;
    ScriptFunctionCall "SubtitleManager_LocalisedDialogueEvent( ^nis\\\\MNIS_A23_0_Intro_to_Tranq_01^, 500, 4000, 3 );";
};
NISScriptFunctionCallTrack
{
    FrameBegin 400;
    ScriptFunctionCall "SubtitleManager_ClearDialogueEvents();";
};
'''


def subtitle_file(text, begin=-1, total=-1, short=False, language=b"English"):
    words = text.encode("utf-16-le")
    if short:                                                # the 16-bit layout: the name, its zero, no padding
        head = struct.pack("<H", len(language) + 1) + language + b"\0"
    else:
        name = language + b"\0"
        head = struct.pack("<I", len(language)) + name + b"\0" * (-len(name) % 4)
    body = head + struct.pack("<iiI", begin, total, len(text)) + words
    body += b"\0" * (-len(body) % 4)
    chunk = struct.pack("<3I", media.SUBTITLE, 12 + len(body), 12 + len(body)) + body
    return b"P3D\xff" + struct.pack("<2I", 12, 12 + len(chunk)) + chunk


def test_the_script_names_each_line_with_its_frame_and_times():
    lines = CUT.spoken_lines(SCRIPT)
    assert lines == [
        {"name": r"nis\MNIS_A23_0_Intro_to_Tranq_01", "frame": 30.0, "begin": 500, "total": 4000, "priority": 3},
        {"name": r"nis\MNIS_A23_0_Intro_to_Tranq_02", "frame": 136.0, "begin": 0, "total": 2600, "priority": 10}]
    assert CUT.line_path(lines[0]["name"]) == r"localised\english\nis\MNIS_A23_0_Intro_to_Tranq_01"
    # SPEC-009 section 4.2's own example: the path gives the file
    assert media.subtitle_file(CUT.line_path(lines[0]["name"])) == "art/subtitles/c/c8c7f4b0e0999977.p3d"
    assert CUT.spoken_lines("NISSequenceCue { CameraAnimationName \"cam\"; };") == []


def test_a_subtitle_file_gives_its_text_and_times_in_both_layouts():
    assert media.subtitle_entries(subtitle_file("Hello there.")) == [
        {"language": "English", "text": "Hello there.", "begin": None, "total": None}]
    assert media.subtitle_entries(subtitle_file("Hello?#Hey.", 2500, 61500)) == [
        {"language": "English", "text": "Hello?#Hey.", "begin": 2500, "total": 61500}]
    assert media.subtitle_entries(subtitle_file("Odd one.", short=True)) == [
        {"language": "English", "text": "Odd one.", "begin": None, "total": None}]
    assert media.subtitles(subtitle_file("Two  spaces.")) == [("English", "Two spaces.")]
    assert media.subtitle_entries(b"junk") == [] and media.subtitle_entries(subtitle_file("Cut")[:-6]) == []


def test_a_line_is_cut_into_captions_of_at_most_80_characters():
    assert CUT.split_line("Tony the Colombians have hit back hard.") == [(0, "Tony the Colombians have hit back hard.")]
    assert CUT.split_line("Hello? #Hey, Rico.@Come here.#Okay.") == [(0, "Hello?"), (1, "Hey, Rico."), (1, "Come here."), (2, "Okay.")]
    long = "This is the first sentence of a long line. And here is a second one that goes on, and on, past the eightieth"
    parts = CUT.split_line(long)
    assert parts[0] == (0, "This is the first sentence of a long line.")           # the last full stop within 80
    assert all(len(t) <= 80 for _s, t in parts) and " ".join(t for _s, t in parts) == long
    comma = "no stops here just a comma, " + "word " * 20
    assert CUT.split_line(comma)[0][1].endswith(",")                               # else the last comma
    assert len(CUT.split_line("x" * 200)) == 3 and CUT.split_line("  ") == []      # no place to cut: at 80


def test_captions_share_the_lines_time_by_their_length():
    files = {r"nis\MNIS_A23_0_Intro_to_Tranq_01": {"text": "Tony.#The Colombians hit back.", "begin": None, "total": None},
             r"nis\MNIS_A23_0_Intro_to_Tranq_02": {"text": "On the phone.", "begin": 1000, "total": 2000}}
    caps = CUT.captions(CUT.spoken_lines(SCRIPT), files.get)
    assert [(c["start"], c["end"], c["speaker"], c["text"]) for c in caps] == [
        (1.5, 2.19, 0, "Tony."),                                     # frame 30 = 1 s, + 0.5 s; 5 of 29 letters of 4 s
        (2.19, 5.5, 1, "The Colombians hit back."),
        (5.533, 7.533, 0, "On the phone.")]                         # the file's own times replace the script's
    assert CUT.captions(CUT.spoken_lines(SCRIPT), lambda name: None) == []          # no subtitle file: no caption
    text = CUT.srt(caps)
    assert text.startswith("1\n00:00:01,500 --> 00:00:02,190\nTony.\n\n2\n00:00:02,190 --> 00:00:05,500\n")
    assert text.count("-->") == 3 and CUT.srt([]) == ""


# --------------------------------------------------------------------------- the scene's sound

def test_a_cutscenes_sound_script_names_its_sound_track():
    script = (b"P3D\xff" + bytes(20) + b"MNIS_X\0" + b"SeqEventStream\0" + struct.pack("<I", 40)
              + b"localised\\english\\nis\\ps2_finals\\mnis_x_00\0\0" + bytes(12))
    assert media.stream_names(script) == ["localised\\english\\nis\\ps2_finals\\mnis_x_00"]
    assert media.stream_names(b"P3D\xff" + b"SeqEventStream\0") == []


def test_a_cutscenes_sound_comes_from_the_copied_files_and_lands_beside_the_scene(tmp_path):
    import sys
    import types
    import blender_export as BX
    name = "localised\\english\\nis\\ps2_finals\\mnis_x_00"
    ogg = b"OggS" + bytes(range(200))
    rsd = b"RSD6OOGV" + struct.pack("<3I", 2, 16, 48000) + b"****" + b"c:\\x.wav\0"
    rsd = rsd + bytes(0x800 - len(rsd)) + ogg
    files = {"sound.rcf/art/sound/scripts/localised/english/nis/MNIS_X.p3d": b"P3D\xff" + name.encode() + b"\0",
             "sound.rcf/" + media.sound_file(name): rsd}
    out = tmp_path / "game_files"
    rows = []
    for path, data in files.items():
        (out / "PC" / path).parent.mkdir(parents=True, exist_ok=True)
        (out / "PC" / path).write_bytes(data)
        rows.append([path, len(data), "s", "only", "PC/" + path, None, 1])
    # the Xbox's own copies weren't copied (the PC-first layout): the PC's sound is used
    index = {"versions": {"pc": {"files": rows}, "xbox": {"files": [[r[0], r[1] + 1, "x", "changed", r[4], None, 1] for r in rows]}}}
    for version in ("pc", "xbox"):
        sounds = BX.cutscene_sounds(out, index, version, "MNIS_X")
        assert [ext for _d, ext in sounds] == [".ogg"] and sounds[0][0].startswith(b"OggS")
    assert BX.cutscene_sounds(out, index, "pc", "MNIS_Y") == []
    glb = tmp_path / "Opened" / "MNIS_X.glb"
    glb.parent.mkdir()
    (glb.parent / "MNIS_X.sound3.wav").write_bytes(b"old")
    made = BX.write_sounds(glb, sounds + [(b"RIFF", ".wav")])
    assert [p.name for p in made] == ["MNIS_X.sound.ogg", "MNIS_X.sound2.wav"]
    assert sorted(p.name for p in glb.parent.iterdir()) == ["MNIS_X.sound.ogg", "MNIS_X.sound2.wav"]

    # in Blender: sound strips from frame 0, one after the other, and playback in step with the sound
    placed = []

    class Strips:
        def new_sound(self, label, path, channel, frame):
            placed.append((label, channel, frame))
            return types.SimpleNamespace(frame_final_end=frame + 300)
    scene = types.SimpleNamespace(frame_end=120, sync_mode="NONE",
                                  sequence_editor_create=lambda: types.SimpleNamespace(sequences=Strips()))
    old = sys.modules.get("bpy")
    sys.modules["bpy"] = types.SimpleNamespace(app=types.SimpleNamespace(
        background=False, timers=types.SimpleNamespace(register=lambda *a, **k: None)))
    try:
        ns: dict = {}
        exec(compile(BX.OPEN_SCRIPT % {"files": [str(glb)], "save": None, "fps": 30}, "open_in_blender.py", "exec"), ns)
        assert ns["add_sounds"](scene) == 2
    finally:
        if old is None:
            del sys.modules["bpy"]
        else:
            sys.modules["bpy"] = old
    assert placed == [("MNIS_X.sound.ogg", 1, 0), ("MNIS_X.sound2.wav", 2, 300)]
    assert scene.frame_end == 600 and scene.sync_mode == "AUDIO_SYNC"


def test_joined_cutscenes_get_each_parts_sound_and_camera_at_its_start(tmp_path):
    import json
    import sys
    import types
    import blender_export as BX
    glb = tmp_path / "MNIS_One.glb"
    parts = [{"name": "MNIS_One", "start": 0.0, "end": 10.0, "camera": "CAM_One"},
             {"name": "MNIS_Two", "start": 10.0, "end": 14.0, "camera": "CAM_Two"},
             {"name": "MNIS_Three", "start": 14.0, "end": 20.0, "camera": "CAM_Three"}]
    js = json.dumps({"scene": 0, "scenes": [{"nodes": [], "extras": {"parts": parts}}]}).encode()
    js += b" " * (-len(js) % 4)
    glb.write_bytes(b"glTF" + struct.pack("<II", 2, 20 + len(js)) + struct.pack("<I", len(js)) + b"JSON" + js)
    # the second part has no sound: the third's still starts with the third
    made = BX.write_sounds(glb, [(b"OggS", ".ogg"), None, (b"OggS", ".ogg")])
    assert [p.name for p in made] == ["MNIS_One.sound.ogg", "MNIS_One.sound3.ogg"]
    placed, markers = [], []

    class Strips:
        def new_sound(self, label, path, channel, frame):
            placed.append((label, frame))
            return types.SimpleNamespace(frame_final_end=frame + 100)

    class Markers:
        def new(self, name, frame=0):
            markers.append(types.SimpleNamespace(name=name, frame=frame, camera=None))
            return markers[-1]
    cams = {n: types.SimpleNamespace(type="CAMERA", name=n) for n in ("CAM_One", "CAM_Two")}     # the third's is missing
    scene = types.SimpleNamespace(frame_end=10, sync_mode="NONE", timeline_markers=Markers(),
                                  sequence_editor_create=lambda: types.SimpleNamespace(strips=Strips()))
    old = sys.modules.get("bpy")
    sys.modules["bpy"] = types.SimpleNamespace(
        app=types.SimpleNamespace(background=False, timers=types.SimpleNamespace(register=lambda *a, **k: None)),
        data=types.SimpleNamespace(objects=cams))
    try:
        ns: dict = {}
        exec(compile(BX.OPEN_SCRIPT % {"files": [str(glb)], "save": None, "fps": 60}, "open_in_blender.py", "exec"), ns)
        assert ns["add_sounds"](scene) == 2 and ns["part_cameras"](scene) == 2
    finally:
        if old is None:
            del sys.modules["bpy"]
        else:
            sys.modules["bpy"] = old
    assert placed == [("MNIS_One.sound.ogg", 0), ("MNIS_One.sound3.ogg", 840)]           # 14 seconds at 60 a second
    assert [(m.name, m.frame, m.camera.name) for m in markers] == [("MNIS_One", 0, "CAM_One"), ("MNIS_Two", 600, "CAM_Two")]


def test_the_80_are_counted_over_the_stored_text_marks_and_all():
    """SPEC-009 section 4.4 (the examiner's answer): the count runs over the text as stored."""
    spans = CUT.caption_spans("a" * 70 + ". " + "b" * 20)
    assert [(s, len(t), n) for s, t, n in spans] == [(0, 71, 71), (0, 20, 21)]   # the space goes with the second
    assert CUT.caption_spans("x" * 79) == [(0, "x" * 79, 79)]                     # 79 + 1 is 80: kept whole
    assert len(CUT.caption_spans("Hi.#" + "y" * 90)) == 3                          # the mark ends the first
    assert CUT.caption_spans("Done." + "z" * 76 + "#Next.")[0] == (0, "Done.", 5)
