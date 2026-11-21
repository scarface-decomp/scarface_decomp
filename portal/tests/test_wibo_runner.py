"""How msvc_verify chooses what runs cl.exe off Windows: wibo first, Wine as the fallback."""

import os
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "tools"))
sys.path.insert(0, str(ROOT / "portal" / "scripts"))

import msvc_verify as MV  # noqa: E402

pytestmark = pytest.mark.skipif(os.name == "nt", reason="Windows runs cl.exe natively")


@pytest.fixture
def fake_wibo(tmp_path):
    p = tmp_path / "wibo"
    p.write_bytes(b"#!/bin/sh\n")
    p.chmod(0o755)
    return p


def test_named_wibo_is_used(monkeypatch, fake_wibo, tmp_path):
    monkeypatch.delenv("SCARFACE_USE_WINE", raising=False)
    monkeypatch.setenv("SCARFACE_WIBO", str(fake_wibo))
    assert MV.runner_name() == "wibo"
    assert MV._runner(tmp_path) == [str(fake_wibo), str(tmp_path / "cl.exe")]


def test_wibo_keeps_host_paths(monkeypatch, fake_wibo):
    monkeypatch.delenv("SCARFACE_USE_WINE", raising=False)
    monkeypatch.setenv("SCARFACE_WIBO", str(fake_wibo))
    assert MV._compiler_path(Path("/tmp/sfv_x")) == "/tmp/sfv_x"


def test_missing_named_wibo_is_not_used(monkeypatch, tmp_path):
    monkeypatch.delenv("SCARFACE_USE_WINE", raising=False)
    monkeypatch.setenv("SCARFACE_WIBO", str(tmp_path / "nope"))
    assert MV._wibo() is None


def test_use_wine_forces_wine(monkeypatch, fake_wibo, tmp_path):
    monkeypatch.setenv("SCARFACE_WIBO", str(fake_wibo))
    monkeypatch.setenv("SCARFACE_USE_WINE", "1")
    monkeypatch.setattr(MV.shutil, "which", lambda name: "/usr/bin/wine" if name == "wine" else None)
    assert MV._wibo() is None
    assert MV.runner_name() == "wine"
    assert MV._runner(tmp_path) == ["/usr/bin/wine", str(tmp_path / "cl.exe")]
    assert MV._compiler_path(Path("/tmp/a")) == "Z:\\tmp\\a"


def test_nothing_to_run_it(monkeypatch, tmp_path):
    monkeypatch.setenv("SCARFACE_USE_WINE", "1")
    monkeypatch.setattr(MV.shutil, "which", lambda name: None)
    assert MV.runner_name() == ""
    with pytest.raises(RuntimeError, match="wibo or Wine"):
        MV._runner(tmp_path)


def test_setup_wibo_is_pinned():
    import setup_wibo
    assert setup_wibo.VERSION in setup_wibo.URL
    assert len(setup_wibo.SHA256) == 64 and int(setup_wibo.SHA256, 16) >= 0
    assert setup_wibo.DEST == ROOT / "portal" / "tools" / "wibo" / "wibo"
