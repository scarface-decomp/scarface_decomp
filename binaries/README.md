# Your game files go here

Put your game files here, or the downloads they came in. When the portal starts it takes out what it
needs by itself: nothing has to be installed or unpacked first. Everything stays on your computer:
this folder is never uploaded, and Git ignores everything in it except this note.

| Version | Put in any of these | Needed for |
| :--- | :--- | :--- |
| Xbox, US disc | `default.xbe`, or the disc image (`.iso`), or the `.7z` / `.zip` it came in | **the main one**: almost all of the work |
| PC, US 1.00.2 | `Scarface.exe` 1.00.2, or the official 1.00.2 patch (`scarface_update_en_1001_1002.exe`), which has the whole file inside | optional: the PC-only functions |
| Xbox prototype, April 20, 2006 | `game.xbe`, or the `.zip` of its folder | optional: unreleased code (its own lane) |

The portal also copies the game's scripts out of these into `scripts_and_data/<version>/` for its
Game Scripts tab. The first start takes a few minutes while it reads the downloads and lists every
function; after that it starts quickly.

Only these exact versions are accepted: other regions, the unpatched PC 1.00 and edited files are
refused, because their code is at different addresses. The accepted files and their SHA-256 are in
[`docs/GAME_VERSIONS.md`](../docs/GAME_VERSIONS.md); `python portal/tools/game_files.py` checks yours.
