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
