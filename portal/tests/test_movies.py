"""The game's movies as videos for the browser (portal/tools/movies.py): finding FFmpeg, choosing an H.264
encoder, and one whole conversion with FFmpeg's own test picture (skipped where FFmpeg isn't installed).
Nothing here comes from the game."""
import shutil
import struct
import time
from pathlib import Path

import pytest

import movies as M


def test_ffmpeg_is_found_where_you_say_it_is(tmp_path, monkeypatch):
    monkeypatch.setattr(M.shutil, "which", lambda name: None)
    monkeypatch.setattr(M.os, "name", "posix")
    exe = tmp_path / "tools" / "bin" / "ffmpeg"
    exe.parent.mkdir(parents=True)
    exe.write_bytes(b"x")
    assert M.remember_ffmpeg(tmp_path, str(tmp_path / "notepad.exe"))
    assert M.remember_ffmpeg(tmp_path, str(tmp_path / "tools")) is None              # its folder will do
    assert M.find_ffmpeg(tmp_path) == exe


def test_without_ffmpeg_it_says_how_to_get_it(tmp_path, monkeypatch):
    monkeypatch.setattr(M, "find_ffmpeg", lambda bin_dir: None)
    movie = tmp_path / "sierra.bik"
    movie.write_bytes(b"BIKi" + struct.pack("<II", 100, 121) + bytes(40))
    st = M.MovieJob(tmp_path).start(movie)
    assert st["state"] == "error" and st["need_ffmpeg"] and "winget install Gyan.FFmpeg" in st["error"]


def test_bink_frames_and_the_h264_encoders():
    assert M.bink_frames(b"BIKi" + struct.pack("<II", 1000, 121)) == 121
    assert M.bink_frames(b"RIFF" + bytes(12)) == 0
    assert M.video_args({"libx264", "aac"})[:2] == ["-c:v", "libx264"]
    assert "veryfast" in M.video_args({"libx264"})
    assert M.video_args({"h264_mf"})[:2] == ["-c:v", "h264_mf"]                   # Windows' own
    with pytest.raises(M.MovieError):
        M.video_args({"mpeg4", "aac"})


@pytest.mark.skipif(not shutil.which("ffmpeg"), reason="FFmpeg isn't installed here")
def test_a_whole_conversion(tmp_path, monkeypatch):
    movie = tmp_path / "radical.bik"
    movie.write_bytes(b"BIKi" + struct.pack("<II", 100, 10) + bytes(40))
    # FFmpeg's own test picture and tone stand in for a Bink movie
    monkeypatch.setattr(M.MovieJob, "_inputs", lambda self, src, tmp: (
        ["-f", "lavfi", "-i", "testsrc=duration=1:size=64x48:rate=10", "-f", "lavfi", "-i",
         "sine=duration=1"], "1:a:0", 10, []))
    job = M.MovieJob(tmp_path)
    assert job.start(movie)["state"] in ("waiting", "converting", "done")
    for _ in range(300):
        if job.status(movie)["state"] in ("done", "error"):
            break
        time.sleep(0.1)
    made = job.ready(movie)
    assert job.status(movie) == {"state": "done", "progress": 1.0} and made is not None
    head = made.read_bytes()[:12]
    assert head[4:8] == b"ftyp"                                                       # an MP4
    assert made.parent == tmp_path / "previews" / "movies"
    assert job.start(movie)["state"] == "done"                                        # kept: not made twice
    assert not list((tmp_path / "previews" / "tmp").iterdir())                       # nothing left behind


@pytest.mark.skipif(not shutil.which("ffmpeg"), reason="FFmpeg isn't installed here")
def test_a_graphics_card_that_fails_falls_back_to_the_processor(tmp_path, monkeypatch):
    movie = tmp_path / "radical.bik"
    movie.write_bytes(b"BIKi" + struct.pack("<II", 100, 10) + bytes(40))
    monkeypatch.setattr(M.MovieJob, "_inputs", lambda self, src, tmp: (
        ["-f", "lavfi", "-i", "testsrc=duration=1:size=64x48:rate=10"], "0:a:0?", 10, []))
    monkeypatch.setattr(M, "graphics_card", lambda ffmpeg: ("h264_no_such_card", "Made-up", []))
    job = M.MovieJob(tmp_path)
    job.start(movie)
    for _ in range(300):
        if job.status(movie)["state"] in ("done", "error"):
            break
        time.sleep(0.1)
    assert job.status(movie)["state"] == "done" and job.ready(movie) is not None
    assert job._state[str(job.target(movie))]["encoder"] == "processor"


def test_no_graphics_card_check_without_ffmpeg():
    assert M.graphics_card(None) is None


def test_the_speed_switches_are_kept(tmp_path, monkeypatch):
    import importlib
    import sys
    from conftest import PORTAL
    sys.path.insert(0, str(PORTAL))
    server = importlib.import_module("decomp_portal_server")
    monkeypatch.setattr(server, "SPEED_FILE", tmp_path / "portal_speed.json")
    sent = []

    class Fake:
        def _json(self, obj, code=200):
            sent.append((code, obj))
    assert server.speed_settings() == {"cores": True, "gpu": True}               # both on to start with
    server.Handler.post_game_files_speed(Fake(), {"use_cores": False})
    assert sent[-1][1]["use_cores"] is False and server.speed_settings() == {"cores": False, "gpu": True}
    assert server.GAME_FILES.use_cores() is False and server.BLENDER.use_cores() is False
    server.Handler.post_game_files_speed(Fake(), {"use_gpu": False, "use_cores": "yes"})   # not a yes/no: kept
    assert server.speed_settings() == {"cores": False, "gpu": False} and server.MOVIES_JOB.use_gpu() is False
