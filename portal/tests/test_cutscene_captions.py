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
