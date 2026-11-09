# Your game files go here

Copy these from your own copy of the game into this folder. They stay on your computer: this folder
is never uploaded, and Git ignores everything in it except this note.

| File | From | Needed for |
| :--- | :--- | :--- |
| `default.xbe` | the US Xbox disc | **the main file**: the Xbox functions, almost all of the work |
| `Scarface.exe` | the US PC game, version 1.00.2 (install the 1.00.2 patch first) | optional: the PC-only functions |
| `game.xbe` | the April 20, 2006 Xbox prototype | optional: unreleased code (its own lane) |

Only these exact versions are accepted: other regions, the unpatched PC 1.00 and edited files are
refused, because their code is at different addresses. The accepted files and their SHA-256 are in
[`docs/GAME_VERSIONS.md`](../docs/GAME_VERSIONS.md); `python portal/tools/game_files.py` checks yours.

Start with `default.xbe`; the other two are optional. Only have the Xbox disc image? Put the `.iso`,
or the `.zip` it came in, here instead: the portal copies `default.xbe` out the first time it starts
(unpack a `.7z` with 7-Zip first). Then start the portal: double-click `START_PORTAL.bat`
(Windows) or run `sh start_portal.sh` (macOS, Linux). The first start takes a few minutes while it
lists every function in your files.

The game's scripts (`.cso`/`.dso`) are copied into `scripts_and_data/<version>/` here by
`python portal/scripts/extract_scripts.py <your Xbox .7z, prototype .zip, PS2 .iso or cement.rcf>`; see
`docs/SCRIPTS.md`. Reading the Xbox `.7z` needs one extra package: `pip install py7zr`.
