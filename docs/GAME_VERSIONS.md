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
| `SLUS_211.11` | **PS2, US disc (SLUS-21111)** (optional). Its own compiler and its own row ([PS2.md](PS2.md)). The portal reads it out of the disc image. | 7,073,896 bytes | `42404f03867f507b9c86d77b179b0b354d7c775cb955648b7e0b9a91ac3d5781` |
| `PauseMenuOverlayf.bin` | PS2 code overlay: the pause menu (optional; copied out of the PS2 disc's `CEMENT.RCF` with the scripts). | 35,328 bytes | `6b14237b541bf2733949ea87b37340f84deee9694c5ed355d667c28283690618` |
| `ExoticsOverlayf.bin` | PS2 code overlay: the exotics shop (optional; copied out of the PS2 disc's `CEMENT.RCF` with the scripts). | 30,976 bytes | `d310690986a4a5f6395580764917a08b2fdc2da689d91609b70bae72ef753614` |
| `ModalsOverlayf.bin` | PS2 code overlay: the business screens (optional; copied out of the PS2 disc's `CEMENT.RCF` with the scripts). | 38,400 bytes | `327e0f391e61c728eed2f09da6880c2378f368f56791bc10a2b67af5049295f2` |
| `ModalsOverlay1f.bin` | PS2 code overlay: the empire and mansion screens (optional; copied out of the PS2 disc's `CEMENT.RCF` with the scripts). | 26,880 bytes | `d4ea255589d9678b44d64d0d88473d8dbe2469e40b262b353bf836409e2db1f6` |
| `ModalsOverlay2f.bin` | PS2 code overlay: the weapon screens (optional; copied out of the PS2 disc's `CEMENT.RCF` with the scripts). | 29,440 bytes | `dbfdc8947d1e9eef58e56524cf0375dd91ab8db0d7482e20089768ba97f825a9` |
| `MiniGamesOverlayf.bin` | PS2 code overlay: the gambling mini-games (optional; copied out of the PS2 disc's `CEMENT.RCF` with the scripts). | 34,816 bytes | `e5a7f8856c285a459fb8b94a35fda8a9c26e0be1b5900b2c7dcc1538962afefc` |

Start with `default.xbe`: the whole Xbox game can be read, so almost all of the work is there.
`Scarface.exe` is an optional extra for the PC-only functions (most of the PC file is encrypted, so
only about 1,500 of its functions can be worked on), and `game.xbe` adds the prototype's. The portal
also runs with only `Scarface.exe`, but then there is much less to do.

**The copy protection's jumps in `Scarface.exe`.** Even in the readable part, the accepted file is not
always the game's code. In 94 places the protection overwrote the game's instructions with a jump of its
own: 63 jump through a pointer inside the protection's own sections, and 31 jump into the encrypted part.
84 functions hold one of them, 17 right at their start. Those 17 had been recorded as matched: what
matched was the protection's five or six bytes, so they were withdrawn on 25 November 2026
(`reports/reopened_matches.json`, with who had recorded each and when). The other 67 were open tasks that
could never have been matched honestly. All 84 are out of the work queue:

* a jump through a pointer in the protection's sections is recognised by the portal from the accepted
  file alone;
* a jump into the encrypted part looks like any other jump there, so those 27 functions are listed in
  `reports/queue_exclusions.json`. They were told apart by comparing with a copy of the same build that
  has the protection removed (same link time; not in the repository, and not a file a match is checked
  against). In that copy the other 763 matched PC functions have the same bytes, apart from the
  addresses of imported Windows functions, which its rebuilt import table moves.

You don't need the files on their own: the portal also takes them out of the downloads they came in,
including `Scarface.exe` 1.00.2 from the official 1.00.2 patch, which carries the whole file (see
[binaries/README.md](../binaries/README.md)). To check yours, start the portal, or run
`python portal/tools/game_files.py`, or in PowerShell: `Get-FileHash binaries\default.xbe`.

## Not accepted

| What | Why |
| :--- | :--- |
| **PC 1.00 without the patch**, or any other patch level | The patch replaced `Scarface.exe` with a newer build (linked November 16, 2006), so functions sit at different addresses and some changed. Supporting both would mean every PC function twice. If your copy is 1.00, install the official 1.00.2 patch and use that `Scarface.exe`. Having the patch file in `binaries/` next to the game isn't enough: a patch file changes nothing until you run it on your installed game. The portal tells you this if it sees the patch there. |
| **Any other Xbox disc or build** (other regions or languages, reprints with different files) | Only the US disc's `default.xbe` above. If you have a different disc, its file won't match the hashes and the portal won't use it. |
| **Edited executables, as the file a match is checked against**: fan patches, remaster or "fixed" versions, widescreen or frame-rate fixes, trainers, repacks | A match means "this C++ compiles to the original game's exact bytes", so the file it is checked against has to be the original. Edited copies are welcome as something to study: see below. |
| **Other PS2 discs** (other regions, the Greatest Hits reprint if its program differs) | Only the US disc's `SLUS_211.11` above. |
| **The Wii version** | A different program for a different processor and compiler, so it can't be matched here yet. It is welcome as a separate effort: see [OTHER_VERSIONS.md](OTHER_VERSIONS.md). |
| **Other prototypes or betas** | Only the April 20, 2006 build for now. If you have another one, open an issue to discuss it. Don't upload it. |

The game's **scripts** (`.cso`/`.dso`) are the same files on the US Xbox and PS2 discs (checked file by
file, see [SCRIPTS.md](SCRIPTS.md)), so either disc can be used to copy them out. The PS2 program itself
is matched in its own lane, with its own compiler: see [PS2.md](PS2.md).

## Edited copies, mods and other versions: fine to study

The list above is only about which file a match is checked against. It doesn't limit what you may look
at. Fan patches, widescreen and frame-rate fixes, trainers, mods, other regions' discs, other patch
levels and other prototypes are all fair material to learn from, like any published tool or research
([PROVENANCE.md](PROVENANCE.md)):

* What a patch changes, and where, often shows what a function or a value is for.
* A fact or a name learned that way counts once the original game's code agrees with it, and the patch
  or mod is credited in [CREDITS.md](CREDITS.md).
* Copy code from a mod only where its licence allows.
* The edited files themselves stay off the project, like every other game file.

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
