#!/usr/bin/env python3
"""
The game's movies as videos a browser plays, for the portal's Game files view: Bink (.bik, the PC, Xbox and
prototype) and the PS2's RadMovie (.rmv, split by rmv.py into its IPU picture and its sound). Browsers play
neither, so each movie is turned into an MP4 (H.264 and AAC) once, with the person's own FFmpeg, and kept in
binaries/previews/movies/ for next time.

FFmpeg is free (ffmpeg.org; on Windows: winget install Gyan.FFmpeg). It is looked for where the person told
the portal it is (binaries/previews/ffmpeg_path.txt), on the PATH, and where winget, Chocolatey and Scoop put
it.

    find_ffmpeg(bin_dir) / remember_ffmpeg(bin_dir, path)
    MovieJob(bin_dir).start(path) / .status(path) / .ready(path) -> the MP4, once made

Your own copies, on your own computer; standard library only.
"""

from __future__ import annotations

import hashlib
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import threading
from pathlib import Path
from typing import Dict, List, Optional

sys.path.insert(0, str(Path(__file__).resolve().parent))
import rmv as RMV  # noqa: E402

PREVIEWS = "previews"
FFMPEG_PATH_FILE = "ffmpeg_path.txt"
MOVIE_EXTS = (".bik", ".rmv")
NEED_FFMPEG = ("Movies need FFmpeg, a free video tool: in PowerShell run  winget install Gyan.FFmpeg  then try "
               "again (no restart needed), or tell the portal where ffmpeg.exe is.")


class MovieError(ValueError):
    pass


def _exe(name: str) -> str:
    return name + ".exe" if os.name == "nt" else name


def find_ffmpeg(bin_dir: Path) -> Optional[Path]:
    """The person's FFmpeg: the one they told the portal about, on the PATH, or where installers put it."""
    tries: List[Path] = []
    try:
        told = (bin_dir / PREVIEWS / FFMPEG_PATH_FILE).read_text(encoding="utf-8").strip().strip('"')
        if told:
            tries.append(Path(told))
    except OSError:
        pass
    which = shutil.which("ffmpeg")
    if which:
        tries.append(Path(which))
    if os.name == "nt":
        local = Path(os.environ.get("LOCALAPPDATA", ""))
        if str(local):
            tries.append(local / "Microsoft" / "WinGet" / "Links" / "ffmpeg.exe")
            tries += sorted((local / "Microsoft" / "WinGet" / "Packages").glob("*FFmpeg*/*/bin/ffmpeg.exe"), reverse=True)
        tries += [Path(os.environ.get("ProgramData", r"C:\ProgramData"), "chocolatey", "bin", "ffmpeg.exe"),
                  Path(os.environ.get("USERPROFILE", ""), "scoop", "shims", "ffmpeg.exe"),
                  Path(r"C:\ffmpeg\bin\ffmpeg.exe"), Path(os.environ.get("ProgramFiles", r"C:\Program Files"), "ffmpeg", "bin", "ffmpeg.exe")]
    else:
        tries += [Path("/usr/bin/ffmpeg"), Path("/usr/local/bin/ffmpeg"), Path("/opt/homebrew/bin/ffmpeg")]
    for t in tries:
        try:
            if t.is_file():
                return t
        except OSError:
            continue
    return None


def remember_ffmpeg(bin_dir: Path, path: str) -> Optional[str]:
    """Keep where the person's FFmpeg is. None when kept, or why not."""
    p = Path(path.strip().strip('"'))
    if p.is_dir():
        p = p / _exe("ffmpeg") if (p / _exe("ffmpeg")).is_file() else p / "bin" / _exe("ffmpeg")
    if not p.is_file() or "ffmpeg" not in p.name.lower():
        return "That isn't FFmpeg: pick ffmpeg.exe (in the bin folder of FFmpeg)."
    (bin_dir / PREVIEWS).mkdir(parents=True, exist_ok=True)
    (bin_dir / PREVIEWS / FFMPEG_PATH_FILE).write_text(str(p), encoding="utf-8")
    return None


def bink_frames(head: bytes) -> int:
    """How many pictures a Bink movie has (its header: "BIK" or "KB2", a version letter, the size, then the
    frame count)."""
    if len(head) >= 12 and head[:3] in (b"BIK", b"KB2"):
        return struct.unpack_from("<I", head, 8)[0]
    return 0


_ENCODERS: Dict[str, set] = {}


def encoders(ffmpeg: Path) -> set:
    key = str(ffmpeg)
    if key not in _ENCODERS:
        try:
            out = subprocess.run([str(ffmpeg), "-hide_banner", "-encoders"], capture_output=True, text=True,
                                 timeout=30, creationflags=_NO_WINDOW).stdout
        except (OSError, subprocess.SubprocessError):
            out = ""
        _ENCODERS[key] = {m.group(1) for m in re.finditer(r"^\s*[VAS][.A-Z]{5}\s+(\S+)", out, re.M)}
    return _ENCODERS[key]


_NO_WINDOW = getattr(subprocess, "CREATE_NO_WINDOW", 0) if os.name == "nt" else 0


def video_args(have: set) -> List[str]:
    """H.264 (what every browser plays) with the first encoder this FFmpeg has: x264 at a quick setting,
    Windows' own (Media Foundation), or OpenH264."""
    if "libx264" in have or not have:
        return ["-c:v", "libx264", "-preset", "veryfast", "-crf", "20", "-pix_fmt", "yuv420p"]
    if "h264_mf" in have:
        return ["-c:v", "h264_mf", "-b:v", "6M", "-pix_fmt", "nv12"]
    if "libopenh264" in have:
        return ["-c:v", "libopenh264", "-b:v", "6M", "-pix_fmt", "yuv420p"]
    raise MovieError("this FFmpeg has no H.264 encoder; get the full build (winget install Gyan.FFmpeg)")


class MovieJob:
    """Makes the MP4s, one at a time, in the background; each is made once and kept."""

    def __init__(self, bin_dir: Path):
        self.bin_dir = bin_dir
        self._lock = threading.Lock()
        self._turn = threading.Lock()                     # one FFmpeg at a time
        self._state: Dict[str, dict] = {}

    def target(self, src: Path) -> Path:
        st = src.stat()
        tag = hashlib.sha1(f"{src.resolve()}|{st.st_size}|{st.st_mtime_ns}".encode()).hexdigest()[:10]
        stem = re.sub(r"[^A-Za-z0-9._-]", "_", src.stem)
        return self.bin_dir / PREVIEWS / "movies" / f"{stem}-{tag}.mp4"

    def ready(self, src: Path) -> Optional[Path]:
        t = self.target(src)
        return t if t.is_file() and t.stat().st_size > 0 else None

    def status(self, src: Path) -> dict:
        if self.ready(src) is not None:
            return {"state": "done", "progress": 1.0}
        with self._lock:
            st = self._state.get(str(self.target(src)))
            return dict(st) if st else {"state": "none", "progress": 0.0}

    def start(self, src: Path) -> dict:
        """Start making the MP4 (if it isn't made or being made). The status, or why not."""
        if self.ready(src) is not None:
            return {"state": "done", "progress": 1.0}
        ffmpeg = find_ffmpeg(self.bin_dir)
        if ffmpeg is None:
            return {"state": "error", "need_ffmpeg": True, "error": NEED_FFMPEG}
        key = str(self.target(src))
        with self._lock:
            if self._state.get(key, {}).get("state") in ("waiting", "converting"):
                return dict(self._state[key])
            self._state[key] = {"state": "waiting", "progress": 0.0}
        threading.Thread(target=self._make, args=(ffmpeg, src, Path(key)), daemon=True, name="movie").start()
        return {"state": "waiting", "progress": 0.0}

    def _set(self, key: Path, **kw) -> None:
        with self._lock:
            self._state.setdefault(str(key), {}).update(kw)

    def _make(self, ffmpeg: Path, src: Path, out: Path) -> None:
        with self._turn:
            tmp_dir = Path(tempfile.mkdtemp(prefix="movie-", dir=str(self._tmp_root())))
            try:
                self._set(out, state="converting", progress=0.0)
                inputs, sound, frames, shape = self._inputs(src, tmp_dir)
                args = video_args(encoders(ffmpeg)) + shape
                part = tmp_dir / "out.mp4"
                cmd = [str(ffmpeg), "-hide_banner", "-nostdin", "-y", *inputs, "-map", "0:v:0", "-map", sound,
                       *args, "-c:a", "aac", "-b:a", "160k", "-ac", "2", "-movflags", "+faststart",
                       "-progress", "pipe:1", "-nostats", str(part)]
                proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True,
                                        creationflags=_NO_WINDOW)
                err: List[str] = []
                drain = threading.Thread(target=lambda: err.extend(proc.stderr.readlines()), daemon=True)
                drain.start()
                for line in proc.stdout:
                    if line.startswith("frame=") and frames:
                        try:
                            self._set(out, progress=min(0.99, int(line[6:].strip() or 0) / frames))
                        except ValueError:
                            pass
                code = proc.wait()
                drain.join(5)
                if code != 0 or not part.is_file():
                    tail = " ".join(x.strip() for x in err[-3:]) or f"FFmpeg stopped ({code})"
                    raise MovieError(tail[-300:])
                out.parent.mkdir(parents=True, exist_ok=True)
                os.replace(part, out)
                self._set(out, state="done", progress=1.0)
            except (MovieError, RMV.RmvError, OSError) as e:
                self._set(out, state="error", error=f"Couldn't make the video: {e}")
            finally:
                shutil.rmtree(tmp_dir, ignore_errors=True)

    def _tmp_root(self) -> Path:
        root = self.bin_dir / PREVIEWS / "tmp"
        root.mkdir(parents=True, exist_ok=True)
        return root

    def _inputs(self, src: Path, tmp_dir: Path):
        """FFmpeg's inputs for a movie, and how many pictures it has (for the progress)."""
        with open(src, "rb") as f:
            head = f.read(2048)
        if head[:8] == RMV.MAGIC:
            info = RMV.read_header(head)
            parts = RMV.split(src, tmp_dir)
            ipu = next(p for p in parts if p.suffix == ".ipu")
            wav = next((p for p in parts if p.suffix == ".wav"), None)
            inputs = ["-r", f"{info.fps:.3f}" if info.fps else "29.97", "-f", "ipu", "-i", str(ipu)]
            # the PS2 shows a movie the whole width of a 4:3 picture 448 lines high: 640 x 336 is 16:9
            shape = ["-aspect", f"{4 / 3 * 448 / max(1, info.height):.4f}"]
            if wav is None:
                return inputs, "0:a:0?", info.frames, shape
            return inputs + ["-i", str(wav)], "1:a:0", info.frames, shape
        if head[:3] in (b"BIK", b"KB2"):
            return ["-i", str(src)], "0:a:0?", bink_frames(head), []
        raise MovieError("not a movie the portal knows (Bink .bik or the PS2's .rmv)")
