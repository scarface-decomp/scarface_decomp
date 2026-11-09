# Which copies of the game are accepted

Every function in this project is matched against the exact bytes of one copy of the game. Another
version, even one that looks the same, has different code at different addresses, so a match made
against it doesn't count here. Everyone works on these files, and only these.

## Accepted

| File in `binaries/` | Version | Size | SHA-256 |
| :--- | :--- | ---: | :--- |
| `default.xbe` | **Xbox, US retail disc.** Built 2006-08-04, title ID `5655003F`. Disc-preservation databases list it as "USA, Europe" because the same disc was sold in both. | 4,718,592 bytes | `dbcf8a3df01f94b879a4a3e642a9f6c3ab5027cc31bdb0229f10e0c6d140b0d6` |
| | The same file as some tools copy it: padded to the size in its header with bytes from the next file on the disc. The code is identical, so it is accepted too. | 5,060,096 bytes | `b15dd7cb1cda9cd2ada8d13709c6409e8ff8a824de1e449a12257c69cc1954a0` |
| `Scarface.exe` | **PC, US, version 1.00.2**: the US game with the official 1.00.2 patch installed. Its file version reads `1.0.0.2`. | 8,462,848 bytes | `1c1dd03ff81592acfa43c45f461fbdc4818503c739cd2f127e0a61fe6a6969c6` |
| `game.xbe` | **Xbox prototype, April 20, 2006** (optional). Unreleased code, counted on its own row. | 4,854,976 bytes | `ecd980d0f25c444d263c968b8e4032e1707e0e684a422483890257ee12ec0384` |

Start with `default.xbe`: the whole Xbox game can be read, so almost all of the work is there.
`Scarface.exe` is an optional extra for the PC-only functions (most of the PC file is encrypted, so
only about 1,500 of its functions can be worked on), and `game.xbe` adds the prototype's. The portal
also runs with only `Scarface.exe`, but then there is much less to do.

You don't need the files on their own: the portal also takes them out of the downloads they came in,
including `Scarface.exe` 1.00.2 from the official 1.00.2 patch, which carries the whole file (see
[binaries/README.md](../binaries/README.md)). To check yours, start the portal, or run
`python portal/tools/game_files.py`, or in PowerShell: `Get-FileHash binaries\default.xbe`.

## Not accepted

| What | Why |
| :--- | :--- |
| **PC 1.00 without the patch**, or any other patch level | The patch replaced `Scarface.exe` with a newer build (linked November 16, 2006), so functions sit at different addresses and some changed. Supporting both would mean every PC function twice. If your copy is 1.00, install the official 1.00.2 patch and use that `Scarface.exe`. Having the patch file in `binaries/` next to the game isn't enough: a patch file changes nothing until you run it on your installed game. The portal tells you this if it sees the patch there. |
| **Any other Xbox disc or build** (other regions or languages, reprints with different files) | Only the US disc's `default.xbe` above. If you have a different disc, its file won't match the hashes and the portal won't use it. |
| **Edited executables of any kind**: fan patches, remaster or "fixed" versions, widescreen or frame-rate fixes, trainers, repacks | They are no longer the game's original code. |
| **PS2 and Wii versions** | They are different programs for different processors and compilers, so they can't be matched here. They are welcome as separate efforts: see [OTHER_VERSIONS.md](OTHER_VERSIONS.md). |
| **Other prototypes or betas** | Only the April 20, 2006 build for now. If you have another one, open an issue to discuss it. Don't upload it. |

The game's **scripts** (`.cso`/`.dso`) are the same files on the US Xbox and PS2 discs (checked file by
file, see [SCRIPTS.md](SCRIPTS.md)), so either disc can be used to copy them out. The PS2 disc is used
only for that; none of its code is decompiled here.

## What you may and may not share

**Allowed**

* Your own copies of the accepted files, in `binaries/` on your own computer.
* Scripts copied out of your own copy, kept in `binaries/scripts_and_data/` on your computer.
* C++ you wrote, names you worked out, notes, and links to decomp.me scratches.
* AI tools, decomp.me, Ghidra and similar, as long as you say what you used ([PROVENANCE.md](PROVENANCE.md)).

**Not allowed**, anywhere in the project (GitHub, issues, pull requests, chat):

* Game files: executables, disc images, archives, extracted scripts or assets, or links to download them.
* The Visual C++ Toolkit's files.
* Leaked or stolen source code, or names and structures taken from it ([PROVENANCE.md](PROVENANCE.md)).
* Matches made against any copy not listed above, or edits to `reports/verified_registry.json` by hand.

## How this is enforced

* The portal, `portal/verify.py`, the queue builder and `portal/scripts/reverify_all.py` check each game file's
  SHA-256 and refuse one that isn't listed above. The portal shows what the file is (its version, build
  date and regions) and why it isn't used.
* CI rejects a registry that was verified against any other game files, and any commit that contains
  game or compiler files.
* Maintainers re-verify every submission with `portal/scripts/reverify_all.py` on the accepted files before
  merging.
