"""SPEC-011 section 3.1: every frame controller in the shipped files is ANIM, 0 cycles, for ever. Runs on
your own copy of the game (extracted/game_files/PC) when SCARFACE_SLOW=1; it reads every file."""
import os
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "portal" / "scripts"))
FILES = ROOT / "extracted" / "game_files" / "PC"


@pytest.mark.skipif(not FILES.is_dir() or os.environ.get("SCARFACE_SLOW") != "1",
                    reason="needs the game's PC files and SCARFACE_SLOW=1 (reads every file)")
def test_every_shipped_frame_controller_plays_as_its_animation_says():
    import check_frame_controllers as C
    modes, _types, odd = C.controllers(FILES)
    assert sum(modes.values()) > 0
    assert odd == []                                         # on the PC files, 19 November 2026: 588, none odd
