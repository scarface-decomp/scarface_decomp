# Scarface's file formats

What is known about the files *Scarface: The World Is Yours* ships with, on every version: how they are
laid out, which version uses what, and which tool in this repository reads them. Everything here was
worked out from the game files and checked by the portal's own readers, which take every file off the
Xbox, PS2, PC and April 2006 prototype releases ([README](../README.md#game-files-for-your-own-use)).

All numbers are little-endian unless a section says otherwise. Offsets are in hexadecimal.

| Format | Files | Versions | Read by |
| :--- | :--- | :--- | :--- |
| [Disc images](#disc-images-and-installers) | `.iso`, `.xiso` | all | `portal/tools/game_assets.py`, `game_files.py` |
| [PC installer](#disc-images-and-installers) | `SCARFACE.MSI`, `Data1.cab` | PC | `msi_reader.py`, `ms_cab.py` |
| [Cement archives](#cement-archives-rcf) | `.rcf` | all | `rcf.py`, `game_assets.py` |
| [Pure3D](#pure3d-p3d) | `.p3d` | all | `game_assets.py` (contents), `media.py` (pictures) |
| [Pictures in Pure3D](#pictures) | PNG, DDS, P3DI | PC, Xbox, PS2 | `media.py` |
| [Sounds](#sounds-rsd) | `.rsd` | all | `game_assets.py` (facts), `media.py` (playing) |
| [Videos](#videos-bik) | `.bik`, `.rmv` | Xbox and PC (Bink), PS2 (`.rmv`) | `game_assets.py` (Bink picture size) |
| [Compiled scripts](#scripts-cso-dso-dtr) | `.cso`, `.dso` | all | `torque_dso.py` and friends ([SCRIPTS.md](SCRIPTS.md)) |
| [AI decision trees](#scripts-cso-dso-dtr) | `.dtr` | all | `dtr_format.py` |
| [Programs](#programs) | `default.xbe`, `Scarface.exe`, `SLUS_211.11` | all | `sf_binaries.py`, `ps2_binary.py` |

Something missing or wrong? Open an issue or a pull request. A format counts as described here once a
tool in `portal/tools/` reads it and the tests check it on made-up files.

## Disc images and installers

**Xbox (XDVDFS).** The Xbox disc's own file system. Its volume descriptor is at sector `0x20` (2,048-byte
sectors) from where the file system starts: `MICROSOFT*XBOX*MEDIA`, u32 sector and u32 size of the root
directory, and the same 20 bytes again at `0x7EC`. The file system starts at 0 in a trimmed image and at
`0x18300000`, `0x0FD90000` or `0x02080000` in a full one. A directory is a binary tree of entries: u16 left
and u16 right (offsets in 4-byte units, `0xFFFF 0xFFFF` for an empty slot), u32 sector, u32 size, u8
attributes (`0x10`: a directory), u8 name length, the name.

**PS2 and PC (ISO 9660).** Standard CD/DVD file system: the primary volume descriptor at sector 16
(`CD001`), the root directory record at byte 156 of it. Names end in `;1`.

**PC installer.** The PC disc has the game in cabinets (`Data1.cab` and more, a spanning set, MSZIP
compressed) and its installer database `SCARFACE.MSI` (an OLE compound file). The database's File,
Component and Directory tables give each cabinet file its real name and folder, so the portal can lay the
game out exactly as installing would, without installing. The 1.00.2 patch (`...Patch-v1002.exe`) carries
`patch01.rcf`, which a patched install has beside the others.

**Prototype.** The April 2006 Xbox build comes as a `.zip` of loose files: its archives are already
unpacked, so `art/x.p3d` there is `cement.rcf/art/x.p3d` on the retail Xbox disc.

## Cement archives (`.rcf`)

Radical's "Radcore Cement Library". Almost everything the game loads is in one of these, `cement.rcf`
(scripts, models, textures) among them. Some archives hold other archives; that is where the dialogue
is.

```
0x00  "ATG CORE CEMENT LIBRARY", NUL padded to 32 bytes
0x20  u32 ?, u32 directory offset, u32 directory size, u32 names offset, u32 names size, u32 ?, u32 file count
directory   file count x (u32 name hash, u32 offset, u32 size), sorted by hash
names       at names offset + 8: file count x (u32 date, u32, u32, u32 length, name[length - 1], 4 bytes)
```

The names come in the order the files are stored, so the i-th name belongs to the directory entry with
the i-th lowest offset (an empty file comes before a file that starts where it does). Paths use `\`.
Layout first published by the [STWIY ToolKit](https://github.com/STWIY/ToolKit).

## Pure3D (`.p3d`)

Radical's Pure3D engine format, used for models, textures, animations, fonts and some text. A file is a
tree of chunks:

```
file    "P3D" 0xFF, u32 header size (12), u32 file size, then chunks
chunk   u32 id, u32 size of the chunk's own data (with these 12 bytes), u32 size with its sub-chunks,
        the data, then the sub-chunks
```

A reader can skip any chunk it doesn't know by its third size. Ids the portal uses:

| Id | Chunk | Holds |
| :--- | :--- | :--- |
| `0x00010000` | Mesh | a model's geometry (the portal files the `.p3d` under Models) |
| `0x00010001` | Skin | a skinned (animated) model |
| `0x00019000` | Texture | name (u8 length, then the text with its NUL), u32 version, u32 width, u32 height, u32 bits per pixel; an Image inside |
| `0x00019001` | Image | name, u32 version (14000), width, height, bits per pixel, palettized, has alpha, format; an Image Data inside |
| `0x00019002` | Image Data | u32 size, then the picture in the format below |
| `0x00121000` | Animation | animation data (the file is filed under Animations when it has no mesh) |

### Pictures

The Image chunk's *format* says how its Image Data is stored, and it differs per version:

| Format | Version | Stored as |
| :--- | :--- | :--- |
| 1 | PC | a PNG file, top row first |
| 6, 8, 10 | Xbox | a DDS file with DXT1, DXT3 or DXT5 blocks, **bottom row first** |
| 11, 12 | PS2 | a P3DI picture, 4 or 8 bits per pixel with a palette, **bottom row first** |

**P3DI (PS2).** A 28-byte header, the palette, then the pixels:

```
0x00  "P3DI"
0x04  u32  13 for 4-bit pictures, 14 for 8-bit ones (in every file seen)
0x08  u32  width, u32 height, u32 bits per pixel, u32 palette bytes, u32 pixel bytes
0x1C  palette: RGBA, 4 bytes per colour; alpha runs 0 to 0x80 (0x80 is opaque)
      pixels: one byte each (8-bit) or two to a byte, low nibble first (4-bit)
```

A 256-colour palette is in the PS2 graphics chip's CSM1 order: in each run of 32 colours, colours 8-15
and 16-23 swap places.

**Square** PS2 pictures are also stored in the graphics chip's own block order, ready to be sent to it as
32-bit data (PSMCT32) and read back as 8-bit (PSMT8) or 4-bit (PSMT4) pixels. To show one, work out where
the chip would read each pixel: send the data as a PSMCT32 picture of width/2 x height/2 (8-bit) or
width/2 x height/4 (4-bit), then read pixel (x, y) at its PSMT8 or PSMT4 address. The page, block and
column tables are the ones in Sony's GS manual (and in emulators such as PCSX2); `media.py` has them
written out. Pictures that aren't square are stored row by row. All 66 PS2 pictures in the samples
checked follow these rules and match the PC versions of the same textures.

## Sounds (`.rsd`)

Radical sound files. Most sit at `art/sound/rsd/<x>/<16 hex digits>.rsd`, named by a hash, but each one
keeps the path it had on the developers' machines, which is how the portal gives sounds their names
back.

```
0x00  "RSD" + a version digit ("RSD6")
0x04  codec, 4 characters
0x08  u32 channels, u32 bits per sample, u32 sample rate
0x14  "****" then the original file name, NUL-terminated (when present)
0x800 the sound data
```

| Codec | Version | Data at `0x800` |
| :--- | :--- | :--- |
| `OOGV` | PC | an Ogg Vorbis stream (44.1 to 48 kHz) |
| `XADP` | Xbox | Xbox IMA ADPCM: per channel, 36-byte blocks (s16 first sample, u8 step index, u8 0, then 32 bytes = 64 samples, low nibble first). With two channels both 4-byte headers come first, then 4-byte runs of each channel in turn |
| `WMA ` | Xbox | 8 bytes, then a Windows Media Audio (ASF) file; its own header has the real sample rate (the RSD field doesn't) |
| `VAG ` | PS2 | Sony ADPCM: 16-byte frames (shift and filter, flags, 14 bytes = 28 samples); flag 7 ends the sound. Two-channel sounds are read as 0x800-byte blocks of each channel in turn (not yet checked against a stereo sample) |
| `PCM ` | | plain 16-bit samples |
| `RADP` | Xbox prototype | Radical's own ADPCM, at 24,000 Hz in the prototype's speech: not described yet |

## Videos (`.bik`)

Bink videos (RAD Game Tools): `BIK` + a version letter, u32 file size - 8, u32 frame count, u32 largest
frame size, u32 frame count again, then u32 width and u32 height at `0x14` and `0x18`. The PC's are
1280x720, and the Xbox program carries RAD's Bink library (its `BINK*` sections). Play them with RAD
Video Tools or a player that supports Bink (ffmpeg reads Bink 1).

The PS2 has no Bink videos: its movies are `.rmv` files in `MOVIES.RCF` (`prologue.rmv`, `radical.rmv`,
...), a format not described yet.

## Scripts (`.cso`, `.dso`, `.dtr`)

Compiled TorqueScript and AI decision trees, all inside `scriptc\` in `cement.rcf`. Their layouts are in
[SCRIPTS.md](SCRIPTS.md) and at the top of `portal/tools/torque_dso.py` and `dtr_format.py`; every
script file the game ships round-trips byte for byte through those readers.

Names in the engine are often stored as a key instead of text: start with 0, then for each byte (upper
case turned to lower case) multiply by `0x1003F` (keeping 31 bits) and xor in the byte; set the top bit
at the end. `torque_names.name_key` has it, and the `.dtr` files use it for the tree's name and every
task's class.

## Programs

| File | Version | Format |
| :--- | :--- | :--- |
| `default.xbe` | Xbox | Xbox executable (XBE, starts with `XBEH`): a header with the section table, then the sections; x86 code built with MSVC 7.1 |
| `game.xbe` | April 2006 prototype | the same, from an earlier build |
| `Scarface.exe` | PC 1.00.2 | Windows PE, x86, MSVC 7.1 |
| `SLUS_211.11` | PS2 | ELF for the Emotion Engine (MIPS R5900), CodeWarrior; see [PS2.md](PS2.md) |

[GAME_VERSIONS.md](GAME_VERSIONS.md) lists the exact copies (with their SHA-256) the project works from.

## Not yet described

Anything the portal's Game files list puts under *Other* is a format nobody has written up here yet:
open one in a hex editor, compare the versions (the [version differences](VERSIONS.md) help), and add
what you find. Known gaps:

* the PS2's `.rmv` movies and its front-end overlays (`CEMENT.RCF/Overlays/FrontEnd/*.bin`, an `f`, `r` and `t` file for
  each);
* the prototype's `RADP` sounds;
* the Pure3D chunks for meshes, skins and animations (only their ids are used so far).
