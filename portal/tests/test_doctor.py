"""portal/doctor.py: the setup check. Made-up folders and stand-ins for git, the compiler and decomp.me;
nothing here needs the game, the compiler or the network."""
import importlib.util
import socket
import sys
import threading
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

import pytest

from conftest import PORTAL

spec = importlib.util.spec_from_file_location("doctor", PORTAL / "doctor.py")
doctor = importlib.util.module_from_spec(spec)
sys.modules["doctor"] = doctor                    # dataclasses look their module up there
spec.loader.exec_module(doctor)

import game_files as GF          # noqa: E402  (doctor puts tools/ on the path)
import msvc_verify as MV         # noqa: E402


def states(r):
    return [(c.state, c.title) for c in r.checks]


def test_python_version():
    r = doctor.Report()
    doctor.check_python(r, (3, 8, 10))
    doctor.check_python(r, (3, 12, 1))
    assert [c.state for c in r.checks] == ["fix", "ok"] and "too old" in r.checks[0].title


def test_git_states(tmp_path):
    def fake(answers):
        return lambda args, cwd: answers.get(args[0] if args[0] != "rev-list" else "rev-list")
    r = doctor.Report()
    doctor.check_git(r, tmp_path, fake({"rev-parse": None}))
    assert r.checks[-1].state == "note" and "ZIP" in r.checks[-1].title
    top = str(tmp_path)
    answers = {"rev-parse": top, "rev-list": "0\t3"}
    git = lambda args, cwd: "main" if args[:2] == ["rev-parse", "--abbrev-ref"] else answers.get(args[0])   # noqa: E731
    doctor.check_git(r, tmp_path, git)
    assert "3 update(s) on GitHub" in r.checks[-1].title and r.checks[-1].fix == ["Update with: git pull"]
    answers["rev-list"] = "2\t0"
    doctor.check_git(r, tmp_path, git)
    assert r.checks[-1].title == "Git clone, branch main, 2 commit(s) not pushed yet"


def test_game_files(tmp_path, monkeypatch):
    b = tmp_path / "binaries"
    b.mkdir()
    monkeypatch.setattr(GF, "_installed_pc_exe", lambda: None)
    r = doctor.Report()
    doctor.check_game_files(r, b)
    assert ("fix", "No Xbox game (default.xbe)") in states(r)
    assert all(s == "note" for s, t in states(r) if "optional" in t)
    # the right Xbox file, a wrong PC one, a PS2 download waiting to be unpacked
    data = b"XBEH" + bytes(400)
    (b / "default.xbe").write_bytes(data)
    (b / "Scarface.exe").write_bytes(b"MZ" + bytes(100))
    (b / "Scarface (ps2).7z").write_bytes(b"7z")
    monkeypatch.setitem(GF.EXPECTED, "default.xbe", ((GF.sha256_of(b / "default.xbe"),), "Xbox, US disc"))
    r = doctor.Report()
    doctor.check_game_files(r, b)
    got = dict((t, s) for s, t in states(r))
    assert got["default.xbe: Xbox, US disc (accepted)"] == "ok"
    assert got["Scarface.exe is not the accepted copy"] == "fix"
    assert got["SLUS_211.11: not taken out yet; the portal gets it from Scarface (ps2).7z when it starts"] == "ok"
    pc = next(c for c in r.checks if c.title.startswith("Scarface.exe"))
    assert "1.00.2" in pc.fix[0]


def test_compiler(monkeypatch):
    monkeypatch.setattr(MV, "find_msvc71_bin", lambda: None)
    r = doctor.Report()
    doctor.check_compiler(r)
    assert r.checks[-1].state == "fix" and "setup_msvc71.py" in r.checks[-1].fix[0]
    monkeypatch.setattr(MV, "find_msvc71_bin", lambda: PORTAL)
    monkeypatch.setattr(doctor.os, "name", "nt")
    monkeypatch.setattr(MV, "compiler_build", lambda b=None: "14.00.50727")
    monkeypatch.setattr(MV, "compiler_version", lambda b=None: "Version 14.00.50727.42")
    doctor.check_compiler(r)
    assert r.checks[-1].state == "fix" and "not 13.10.3052 or 13.10.3077" in r.checks[-1].title
    monkeypatch.setattr(MV, "compiler_build", lambda b=None: "13.10.3077")
    monkeypatch.setattr(MV, "compile_cpp", lambda code, flags: MV.CompileResult(ok=True, obj=b"obj"))
    doctor.check_compiler(r)
    assert states(r)[-1] == ("ok", "Compiler: cl.exe 13.10.3077, and a test compile works")
    monkeypatch.setattr(MV, "compile_cpp", lambda code, flags: MV.CompileResult(ok=False, error="cl : fatal error C1083\nmore"))
    doctor.check_compiler(r)
    assert r.checks[-1].state == "fix" and r.checks[-1].fix[0] == "cl : fatal error C1083"


def test_port_free_busy_and_portal():
    r = doctor.Report()
    with socket.socket() as s:
        s.bind(("127.0.0.1", 0))
        port = s.getsockname()[1]
    doctor.check_port(r, port)
    assert r.checks[-1].state == "ok"
    with socket.socket() as s:                              # something else holds it
        s.bind(("127.0.0.1", 0))
        s.listen()
        doctor.check_port(r, s.getsockname()[1])
        assert r.checks[-1].state == "fix" and "SCARFACE_PORT" in r.checks[-1].fix[0]

    class Portal(BaseHTTPRequestHandler):
        def log_message(self, *a):
            pass

        def do_GET(self):
            body = b'{"progress": {}}'
            self.send_response(200)
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)
    srv = ThreadingHTTPServer(("127.0.0.1", 0), Portal)
    threading.Thread(target=srv.serve_forever, daemon=True).start()
    try:
        doctor.check_port(r, srv.server_address[1])
        assert r.checks[-1].state == "note" and r.checks[-1].title.startswith("The portal is already running")
    finally:
        srv.shutdown()


@pytest.mark.parametrize("status,word", [(200, "answers this computer"), (403, "turns away programs")])
def test_decompme(status, word):
    r = doctor.Report()
    doctor.check_decompme(r, lambda: status)
    assert word in r.checks[-1].title


def test_decompme_unreachable():
    def boom():
        raise OSError("no route")
    r = doctor.Report()
    doctor.check_decompme(r, boom)
    assert r.checks[-1].state == "note"


def test_render_share_and_startup(monkeypatch):
    r = doctor.Report()
    r.add("ok", "Python 3.12.1")
    r.add("fix", f"Something in {doctor.ROOT / 'binaries'}", f"Look in {doctor.Path.home() / 'Downloads'}")
    r.add("note", "The portal is already running: open http://localhost:8085")
    r.add("note", "Optional thing")
    full = doctor.render(r)
    assert full.startswith("Scarface decomp: checking your setup") and full.endswith("1 thing to fix.")
    shared = doctor.render(r, share=True)
    assert str(doctor.ROOT) not in shared and "<project>" in shared and str(doctor.Path.home()) not in shared
    monkeypatch.setenv("USERNAME", "peyto")
    r.add("note", "C:\\Users\\peyto\\Desktop")
    assert "peyto" not in doctor.render(r, share=True)
    quick = doctor.render(r, only_problems=True)
    assert quick.splitlines()[0].startswith("Setup check: 1 thing to fix")
    assert "already running" in quick and "Optional thing" not in quick and "Python" not in quick
    assert doctor.render(doctor.Report(), only_problems=True) == ""


def test_main_exit_code(monkeypatch, capsys):
    monkeypatch.setattr(doctor, "run", lambda online=True: doctor.Report([doctor.Check("ok", "fine")]))
    assert doctor.main(["--offline"]) == 0
    monkeypatch.setattr(doctor, "run", lambda online=True: doctor.Report([doctor.Check("fix", "broken", ["do this"])]))
    assert doctor.main(["--startup"]) == 1
    assert "broken" in capsys.readouterr().out
