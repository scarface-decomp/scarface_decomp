# The PS2 and Wii versions

**The PS2 version is in the portal now**, as its own lane: its compiler was identified (CodeWarrior for PS2
3.0.1, which decomp.me runs), its functions are listed, and they are checked against your own copy. See
[PS2.md](PS2.md) for how. This page keeps the background.

The **Wii** version was built for another processor (PowerPC) with another compiler, so its C++ needs its
own setup. Nobody has started it yet. If you want to, you're welcome: open an issue on GitHub so others can
join in.

The PS2's **scripts** are already covered: they are the same files as the Xbox's, and all of them
decompile to TorqueScript that compiles back byte for byte.

## Why the PS2 version is worth it

It has things the PC version doesn't. According to PCGamingWiki and the PC restoration mods, the PC port
is missing the PS2's blood effects on clothing and skin, and the PS2 has explosion sounds of its own. The
console versions also show cracked windshields where the PC only has intact or smashed ones. Some of this
is code, some of it is data (sounds and effects) on the disc.

## What we already know about the PS2 program

Checked on 2026-11-08 from the NTSC-U disc (SLUS-21111):

| | |
| :--- | :--- |
| Program | `SLUS_211.11` on the disc (the disc's `SYSTEM.CNF` boots `cdrom0:\SLUS_211.11`) |
| Format | 32-bit ELF, MIPS (the PS2's Emotion Engine), entry point `0x001A0008`, about 6.9 MB |
| Compiler | Metrowerks CodeWarrior for PlayStation 2, 3.0.1 build 87-103 (the `.comment` text, `MW MIPS C Compiler (2.4.1.01)`, is shared by several builds; [PS2.md](PS2.md) says how it was narrowed down) |
| Names | The symbol table is stripped. C++ class names are stored as plain text, which helps with naming. |
| Scripts | **Done.** `CEMENT.RCF` holds the compiled scripts, byte-identical to the Xbox disc's. The portal copies them out of your PS2 `.iso` (or `python portal/scripts/extract_scripts.py <PS2 .iso>`), and all 635 decompile to readable TorqueScript that compiles back byte for byte (`docs/SCRIPTS.md`). |

The portal takes the program out of your own disc image by itself (put the `.iso`, or the `.7z`/`.zip`
it came in, in `binaries/`). It stays out of the repository: Git ignores everything in `binaries/`.

Most of the game's C++ is the same source on every version, so C++ written for the Xbox build is a good
starting point for the PS2 one, and the portal offers it where it can pair the two. It still has to match
the PS2 compiler's output on its own.

## The Wii version

The Wii port (2007) mostly changed the controls (Wii Remote aiming, motion-controlled chainsaw), and some
tuning: it is uncut and its economy was rebalanced. So there is less in it that the other versions don't
have than on the PS2, but it's open too. Its program hasn't been examined yet. The Wii uses a PowerPC
processor, so it needs its own compiler and tools as well.

## Sources

* [PCGamingWiki: Scarface: The World Is Yours](https://www.pcgamingwiki.com/wiki/Scarface:_The_World_Is_Yours)
  (PC versus console differences)
* [Wikipedia: Scarface: The World Is Yours](https://en.wikipedia.org/wiki/Scarface_videogame) (Wii version)
* [ScarfaceEX](https://www.moddb.com/mods/scarfaceex) (PS2-exclusive explosion sounds restored on PC)
