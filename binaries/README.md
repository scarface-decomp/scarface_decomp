# Your game files go here

Copy these from your own copy of the game into this folder. They stay on your computer: this folder
is never uploaded, and Git ignores everything in it except this note.

| File | From | Needed for |
| :--- | :--- | :--- |
| `default.xbe` | the retail Xbox disc | the Xbox functions (most of the work) |
| `Scarface.exe` | PC version 1.00.2 (install the 1.00.2 patch first) | the PC functions |
| `game.xbe` | the April 20, 2006 Xbox prototype | optional bonus functions |

You need at least one of the first two. Then start the portal: double-click `START_PORTAL.bat`
(Windows) or run `sh start_portal.sh` (macOS, Linux). The first start takes a few minutes while it
lists every function in your files.

The game's scripts (`.cso`/`.dso`) are copied into `scripts_and_data/` here by
`python scripts/extract_scripts.py`; see `docs/SCRIPTS.md`.
