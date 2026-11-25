# Credits

## Project

* **RRutherrfordd (Founder) / RogiPogee**: project lead, original analysis and the portal.

## Contributors

Everyone who verifies a function through the portal is recorded by handle in
`reports/verified_registry.json` (`verified_by`) and shown on the portal's leaderboard. Pull request
authors are credited in the commit history. Thank you.

* **lemiur**: 73 Xbox matches (46 game functions and 27 library ones, among them the `<algorithm>`
  instantiations and zlib's `adler32`), the symcov import (564 library names, 556 missing function
  starts, 164 functions moved to the library list), the Hit & Run linker-map bridge
  (`tools/shar_bridge.c`) and a list of gaps in the project's own checking tools
  (`reports/campaign_status.md`).

## Tools and references

* [Capstone](https://www.capstone-engine.org/) disassembler, used for function sizing and checks.
* [zlib](https://zlib.net/) 1.2.1 by Jean-loup Gailly and Mark Adler, under the zlib licence: the game links
  its decompression side. The published source files are in `reconstructed_src/include/zlib-1.2.1/`,
  unchanged, with the library's README and licence text; the game's zlib functions are matched by
  compiling them as C (SPEC-014 §5.3).
* The Microsoft Visual C++ Toolkit 2003 (cl.exe 13.10.3052 or 13.10.3077), which each contributor supplies.
* Prior matching-decompilation projects whose methods informed this one, among them
  [fnv_decomp](https://github.com/momusdigital/fnv_decomp) (Fallout: New Vegas, MSVC),
  the [Halo 2 decompilation](https://github.com/kirklandsig/halo2-decompiled) (Xbox, MSVC 7.1) and
  [LEGO Island](https://github.com/isledecomp/isle) with its [reccmp](https://github.com/isledecomp/reccmp)
  tools (MSVC 4.2). No code was taken from them.
* [decomp.me](https://decomp.me), which hosts the same compiler (`msvc7.1`) for working on functions in
  the browser.
* For the script and archive formats: the [STWIY ToolKit](https://github.com/STWIY/ToolKit) (layout of
  `.rcf` archives), [Broken Face](https://github.com/sulzbals/BrokenFace) by sulzbals and Meth0d's
  write-up on Scarface's compiled TorqueScript (layout of `.cso` / `.dso`). Their documentation was
  read; no code was copied.
* The [Scarface Remastered Project](https://www.nexusmods.com/scarfacetheworldisyours/mods/6) by Neoxaero,
  with sulzbals, Talon and DomenicoPe: the mod that keeps the PC game playable and looking its best, and the
  community this project grew beside. None of it is part of this project or shipped with it, at its
  author's wish: the portal can read a copy you downloaded yourself, on your own computer, and nothing from
  it goes into the repository or onto the site.
* For how the PC game works inside: [SilentPatch for Scarface](https://github.com/CookiePLMonster/SilentPatchScarface)
  by Silent (CookiePLMonster) and his [write-up](https://silentsblog.com/2020/03/29/silentpatch-scarface/)
  (how the renderer keeps its vertex and index buffers), [RCFRedirect](https://github.com/GangstaTeam/RCFRedirect)
  by GangstaTeam (where the game opens files from its `.rcf` archives) and
  [ScarfaceHook](https://github.com/ermaccer/scarfacehook) by ermaccer (which functions move the camera,
  create cars and people, set the time of day). They were read as references for what functions do and
  what they are called; no code was copied. Names that come from them say so in `reports/names.json`:
  `core::CementLibrary::OpenFileByHash` and the file-name hash it works with are RCFRedirect's. The
  game's script commands (`DBChangeDirtyCash`, `CVM_SetMainCharacterPackage` and some 800 more) are
  named in the game's own program, but it was ScarfaceHook and
  [ScarfaceEX](https://www.moddb.com/mods/scarfaceex), which call them, that showed they were there to
  be read ([NAMES.md](NAMES.md)).
* For a second opinion on the scripts' names: Gangsta Team's
  [natives list](https://gangsta-team.github.io/website/#/documentation/game/natives) (public domain)
  and the word list of their [RCF explorer](https://gangsta-team.github.io/web-rcf-explorer/). The
  natives list confirmed all 820 script commands read from the Xbox program and showed the 34 only the
  PC game has; the word list agreed with every hashed name both sides have. No name was taken from the
  word list ([SCRIPTS.md](SCRIPTS.md#names)).
* For compiling TorqueScript the way the game does: the code generator of
  [Torque2D](https://github.com/TorqueGameEngines/Torque2D) (`astNodes.cc`, `compiler.cc`, MIT
  licence), the open-source descendant of the engine Scarface's script compiler came from. It was read
  to get the order of the string, number and name tables right; the Python compiler here is new code.
* For the names of a few script-system functions: the published Torque engine (the
  [Torque Game Engine](https://github.com/TorqueGameEngines/Torque3D) family, MIT licence, GarageGames),
  whose console system the game's own descends from. What each function does was read from the game's
  machine code; where the game's function is recognisably Torque's, it carries Torque's name
  (`dAtob`, `dSprintf`, `Namespace::createLocalEntry`, `Namespace::Entry::execute`, `Namespace::lookup`,
  `Namespace::classLinkTo`, `Con::getReturnBuffer`), and its entry in `reports/names.json` says so.
  `classLinkNamespaces` is in the game's own error text.
* [scarface-p3d](https://github.com/aap/scarface-p3d) by aap (MIT licence) and the research notes kept
  with an extended copy of it. Its author worked with leaked source open, so none of its code or names is
  used: it is read only by clean-room examiners, and what it showed about the game's files and behaviour
  reached the project as the specs in `docs/cleanroom/`, each checked on the game's own files
  ([CLEAN_ROOM.md](CLEAN_ROOM.md)).
* The fonts of the website and the portal: [Anton](https://github.com/googlefonts/AntonFont) (The Anton
  Project Authors), [Josefin Sans](https://github.com/ThomasJockin/JosefinSansFont-master) (The Josefin
  Sans Project Authors) and Marcellus (Brian J. Bonislawsky, Astigmatic), each under the SIL Open Font
  License 1.1, in the files packaged by [Fontsource](https://fontsource.org). They are in `docs/fonts/`
  with their licences, so no page loads anything from a font site.
