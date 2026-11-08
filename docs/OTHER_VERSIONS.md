# The PS2 and Wii versions: open for anyone who wants to start

This project matches the **Xbox** and **PC** builds (and the April 2006 Xbox prototype), because they
were all built with the same Microsoft compiler that the portal runs. The **PlayStation 2** and **Wii**
versions were built for other processors with other compilers, so they need their own setup. Nobody
has started one yet. If you want to, you're welcome: open an issue on GitHub so others can join in.

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
| Compiler | Metrowerks CodeWarrior for PlayStation 2: the `.comment` section says `MW MIPS C Compiler (2.4.1.01)` |
| Names | The symbol table is stripped. C++ class names are stored as plain text, which helps with naming. |
| Scripts | `CEMENT.RCF` holds the compiled scripts. `python portal/scripts/extract_scripts.py <PS2 .iso>` already extracts them, and the script tools here read them. They are byte-identical to the Xbox disc's scripts. |

To get the program out of your own disc image, open the `.iso` with 7-Zip (or any ISO tool) and
copy `SLUS_211.11`. Keep it out of the repository: put it in `binaries/ps2/`, which Git ignores.

## What a PS2 lane would need

The same rules as the rest of the project, with PS2 tools:

1. **The exact compiler.** CodeWarrior for PS2, version 2.4.1, and the flags the game used. Without that
   version, nothing can be matched byte for byte.
2. **A function list.** Split the ELF into functions, as `portal/tools/queue_builder.py` does for the x86 files.
3. **A byte-exact check.** Compile the C++, compare length and bytes, check relocations, and allow no
   inline assembly. That is what `portal/tools/msvc_verify.py` does for x86.

Most of the game's C++ is the same source on every version, so C++ written for the Xbox build is a good
starting point for the PS2 one. It still has to match the PS2 compiler's output on its own.

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
