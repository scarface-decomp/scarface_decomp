"""Sync to GitHub: clear answers when the folder isn't a git clone or GitHub has moved on."""
import shutil
import subprocess

import pytest

import conftest  # noqa: F401  (puts tools/ on the path)

pytestmark = pytest.mark.skipif(shutil.which("git") is None, reason="git is not installed")


@pytest.fixture()
def S():
    import importlib, sys
    sys.path.insert(0, str(conftest.PORTAL))
    return importlib.import_module("decomp_portal_server")


def git(cwd, *args):
    return subprocess.run(["git", *args], cwd=cwd, capture_output=True, text=True, check=True).stdout


def make_clone(tmp_path):
    hub = tmp_path / "hub.git"
    git(tmp_path, "init", "-q", "--bare", "-b", "main", str(hub))
    work = tmp_path / "work"
    git(tmp_path, "clone", "-q", str(hub), str(work))
    git(work, "config", "user.email", "t@example.invalid")
    git(work, "config", "user.name", "t")
    (work / "reports").mkdir()
    (work / "reports" / "verified_registry.json").write_text("{}\n")
    git(work, "add", "-A")
    git(work, "commit", "-q", "-m", "start")
    git(work, "push", "-q", "-u", "origin", "main")
    return hub, work


def test_a_zip_download_gets_told_how_to_connect(S, tmp_path):
    folder = tmp_path / "scarface_decomp-main"
    (folder / "reports").mkdir(parents=True)
    (folder / "reports" / "verified_registry.json").write_text("{}\n")
    res = S.git_sync("someone", folder)
    assert not res["ok"] and "downloaded as a ZIP" in res["error"] and "CONTRIBUTING" in res["error"]


def test_a_folder_inside_another_repo_is_not_used(S, tmp_path):
    hub, work = make_clone(tmp_path)
    inner = work / "copy"
    inner.mkdir()
    res = S.git_sync("someone", inner)
    assert not res["ok"] and "downloaded as a ZIP" in res["error"]
    assert git(work, "rev-list", "--count", "HEAD").strip() == "1"     # nothing was committed to the outer repo


def test_pushes_new_verified_work(S, tmp_path):
    hub, work = make_clone(tmp_path)
    (work / "reports" / "verified_registry.json").write_text('{"entries": {}}\n')
    res = S.git_sync("someone", work)
    assert res["ok"], res
    assert "synced from portal by someone" in git(hub, "log", "-1", "--format=%s")
    assert S.git_sync("someone", work)["message"].startswith("Nothing new")


def test_github_ahead_says_pull_first(S, tmp_path):
    hub, work = make_clone(tmp_path)
    other = tmp_path / "other"
    git(tmp_path, "clone", "-q", str(hub), str(other))
    git(other, "config", "user.email", "o@example.invalid")
    git(other, "config", "user.name", "o")
    (other / "README.md").write_text("someone else's change\n")
    git(other, "add", "-A")
    git(other, "commit", "-q", "-m", "other")
    git(other, "push", "-q")
    (work / "reports" / "verified_registry.json").write_text('{"entries": {"x": 1}}\n')
    res = S.git_sync("someone", work)
    assert not res["ok"] and "git pull" in res["error"]
