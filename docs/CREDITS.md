# Credits

## Project

* **RRutherrfordd (Founder) / RogiPogee**: project lead, original analysis and the portal.

## Contributors

Everyone who verifies a function through the portal is recorded by handle in
`reports/verified_registry.json` (`verified_by`) and shown on the portal's leaderboard. Pull request
authors are credited in the commit history. Thank you.

## Tools and references

* [Capstone](https://www.capstone-engine.org/) disassembler, used for function sizing and checks.
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
* For compiling TorqueScript the way the game does: the code generator of
  [Torque2D](https://github.com/TorqueGameEngines/Torque2D) (`astNodes.cc`, `compiler.cc`, MIT
  licence), the open-source descendant of the engine Scarface's script compiler came from. It was read
  to get the order of the string, number and name tables right; the Python compiler here is new code.
* The fonts of the website and the portal: [Anton](https://github.com/googlefonts/AntonFont) (The Anton
  Project Authors), [Josefin Sans](https://github.com/ThomasJockin/JosefinSansFont-master) (The Josefin
  Sans Project Authors) and Marcellus (Brian J. Bonislawsky, Astigmatic), each under the SIL Open Font
  License 1.1, in the files packaged by [Fontsource](https://fontsource.org). They are in `docs/fonts/`
  with their licences, so no page loads anything from a font site.
