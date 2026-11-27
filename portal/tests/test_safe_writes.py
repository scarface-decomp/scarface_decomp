"""Writing the registry and the generated files while another program reads or writes them."""
import os
import sys
from pathlib import Path

import pytest

PORTAL = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PORTAL / "tools"))

import registry_outputs as RO  # noqa: E402


def test_the_temporary_file_is_this_programs_own(tmp_path):
    """The portal and a registry_outputs.py run beside it write the same files: with one shared temporary
    name, one could move the other's half-written file into place."""
    path = tmp_path / "Original_Binary_Order_Xbox.cpp"
    tmp = RO.temporary_for(path)
    assert tmp.parent == path.parent and tmp.name.endswith(".tmp") and str(os.getpid()) in tmp.name
    RO._write(path, "one\n")
    RO._write(path, "two\n")
    assert path.read_text() == "two\n" and [p.name for p in tmp_path.iterdir()] == [path.name]


def test_a_file_someone_has_open_is_tried_again(tmp_path, monkeypatch):
    """On Windows a file cannot be replaced while git or a scanner has it open; a moment later it can."""
    path, tmp = tmp_path / "progress.json", tmp_path / "progress.json.1.tmp"
    path.write_text("old")
    tmp.write_text("new")
    real, refused = os.replace, []

    def busy(a, b):
        if len(refused) < 3:
            refused.append(b)
            raise PermissionError(5, "Access is denied")
        real(a, b)

    monkeypatch.setattr(RO.os, "replace", busy)
    RO.replace_file(tmp, path, wait=0)
    assert len(refused) == 3 and path.read_text() == "new" and not tmp.exists()
    tmp.write_text("newer")
    refused.clear()
    monkeypatch.setattr(RO.os, "replace", lambda a, b: (_ for _ in ()).throw(PermissionError(5, "Access is denied")))
    with pytest.raises(PermissionError):                 # still open after every try: say so, don't hide it
        RO.replace_file(tmp, path, tries=4, wait=0)
    assert path.read_text() == "new"
