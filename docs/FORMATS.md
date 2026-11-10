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
| [Pure3D](#pure3d-p3d) | `.p3d` | all | `p3d.py` (chunks, models to .obj), `game_assets.py` (contents), `media.py` (pictures) |
| [Pictures in Pure3D](#pictures) | PNG, DDS, P3DI | PC, Xbox, PS2 | `media.py` |
| [Sounds](#sounds-rsd) | `.rsd` | all | `game_assets.py` (facts), `media.py` (playing) |
| [Videos](#videos-bik) | `.bik` | Xbox and PC (Bink) | `game_assets.py` (Bink picture size) |
| [PS2 movies](#ps2-movies-rmv) | `.rmv` | PS2 | `rmv.py` (to an `.ipu` picture and a `.wav`) |
| [Compiled scripts](#scripts-cso-dso-dtr) | `.cso`, `.dso` | all | `torque_dso.py` and friends ([SCRIPTS.md](SCRIPTS.md)) |
| [AI decision trees](#scripts-cso-dso-dtr) | `.dtr` | all | `dtr_format.py` |
| [Programs](#programs) | `default.xbe`, `Scarface.exe`, `SLUS_211.11` | all | `sf_binaries.py`, `ps2_binary.py` |
| [PS2 code overlays](#ps2-code-overlays) | `Overlays/FrontEnd/*.bin` | PS2 | `ps2_overlay.py` |

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

`portal/tools/p3d.py FILE.p3d` prints any file's chunk tree with every chunk below named and its fields
read, and `--obj OUT.obj` writes its meshes and skins for Blender and other 3D programs.

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

### Models: meshes and skins

Most chunks keep the layouts Radical used in *The Simpsons: Hit & Run* (see the Donut Team's notes in the
credits below), with a newer primitive group and skeleton. Text is a u8 length, padded so the next field
stays 4-byte aligned, then the characters with NULs after them.

| Id | Chunk | Data, then sub-chunks |
| :--- | :--- | :--- |
| `0x00010000` | Mesh | name, u32 version, u32 number of primitive groups |
| `0x00010001` | Skin | name, u32 version (3), skeleton name, u32 number of primitive groups |
| `0x00010020` | Primitive Group | u32 version, shader name, u32 primitive type, u32 vertex type, u32 vertices, u32 indices, u32 matrices, u32 *memory image* (1 when the vertices are in a ready-made buffer, below), u32 1, u32 0, u32 0 |
| `0x00010005` | Position List | u32 count, count x 3 floats |
| `0x00010006` | Normal List | u32 count, count x 3 floats |
| `0x00010010` | Packed Normal List | u32 count, one byte per vertex, probably an index into a fixed table of 256 directions: vertices with the same byte have float normals within about 12 degrees of each other |
| `0x00010007` | UV List | u32 count, u32 channel, count x 2 floats |
| `0x00010008` | Colour List | u32 count, a u32 colour per vertex |
| `0x0001000A` | Index List | u32 count, u32 indices |
| `0x0001000B` | Matrix List | u32 count, four one-byte matrix palette indices per vertex, **last byte first**: byte 3 goes with the first weight, byte 2 with the second, and so on |
| `0x0001000C` | Weight List | u32 count, 3 floats per vertex (the fourth weight is 1 minus the others) |
| `0x0001000D` | Matrix Palette | u32 count, u32 skeleton joint numbers: the matrix list's indices point into this |
| `0x00010011` | Vertex Shader | a name (empty in every file seen) |
| `0x00010012` | Memory Image Vertex List | u32, u32, u32 size, then a vertex buffer as the console uses it (below) |
| `0x00010013` | Memory Image Index List | u32, u32, u32 size, then u16 indices (Xbox) |
| `0x00010014` | Memory Image Vertex Description | seven u32 (PS2 skins) |
| `0x00010003` | Bounding Box | 3 floats minimum, 3 floats maximum |
| `0x00010004` | Bounding Sphere | 3 floats centre, float radius |
| `0x00010017` | Render Status | u32 (1 in every file seen) |
| `0x00010019` | Shadow Skin | probably a low-detail copy of the skin for shadows: position, matrix and weight lists and a `0x0001001B` chunk |

*Primitive type*: 0 triangle list, 1 triangle strip (one strip, joined by repeated indices), 2 line list,
3 line strip, 4 points. *Vertex type* is a set of bits: `0x2000` position, `0x0010` normal, `0x0020`
colour, `0x0080` matrix indices, `0x0100` weights, and the low four bits the number of UV sets (`0x2011`:
positions, normals and one UV set; `0x2191`: a skin's). The Donut Team's list has no names for
`0x00010012` to `0x00010014`, `0x00010019`, `0x00010020`, `0x00023000` or `0x00023001`; the names here are
descriptive ones of ours.

The same model is stored three ways:

* **PC**: plain lists (positions, normals, packed normals, UVs, indices, and for skins the matrix list,
  weight list and palette).
* **Xbox**: a memory image for meshes. `0x00010012` holds the vertices as the Xbox's graphics chip reads
  them, each starting with its position as 3 floats (24 bytes a vertex for `0x2011`: position, a packed
  normal, UV), and `0x00010013` holds u16 indices. Skins keep the PC's plain lists.
* **PS2**: only a memory image: `0x00010012` is a ready-made VIF packet for the vector unit's
  microprogram. The vertices come in batches of up to 54. Each batch starts with a 4-quadword header (its
  first word is the vertex count; the third quadword holds the scale of the positions and of the normals,
  1/127; the fourth is a GIF tag), then each vertex takes five quadwords, one per attribute: UVs as 2
  floats, the normal as 3 signed bytes, the position as 3 signed 16-bit numbers (times the scale), and for
  skins four matrix offsets (palette index x 4) and four 16-bit weights (4096 = 1). The index count is 0:
  each batch is drawn as it comes.

### Skeletons

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x00023000` | Skeleton | name, u32 version, u32 number of joints, u32 0, u32 0; the joints follow as sub-chunks |
| `0x00023001` | Skeleton Joint | name, u32 parent (its own number for the first), then a 4x4 float matrix: the rest pose relative to the parent, rows, translation in the last row |

A joint's place in the world is its matrix times its parent's (row vectors). *The Simpsons: Hit & Run*
used `0x4500` and `0x4501` for these.

### Animations

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x00121000` | Animation | u32 version, name, 4 characters type (`PTRN`: moves a skeleton), float frames, float frame rate (30), u32 cyclic |
| `0x00121006` | Animation Header | u32 version, u32 number of groups; holds Channel Counts |
| `0x00121007` | Animation Channel Count | u32 version, u32 the id of a channel type, u32 how many channels of it, then u16 key counts, one per channel |
| `0x00121002` | Animation Group List | u32 version, u32 number of groups |
| `0x00121001` | Animation Group | u32 version, name (a joint's name), u32 group id (the joint's number), u32 number of channels |
| `0x00121104` | Vector3DOF Channel | u32 version, 4 characters parameter (`TRAN`), u32 keys, u16 frame numbers, 3 floats per key |
| `0x00121102`, `0x00121103` | Vector1DOF, Vector2DOF Channel | u32 version, parameter, u16 mapping (which components move), 3 floats constants (the rest), u32 keys, u16 frames, 1 or 2 floats per key |
| `0x00121105` | Quaternion Channel | u32 version (1), parameter (`ROT`), u32 keys, u16 frames, 4 floats per key: x, y, z, w |
| `0x00121112` | Compressed Quaternion Channel2 | the same header, then x, y, z as signed 16-bit numbers over 32,767 (Xbox and PS2) |
| `0x00121114` | no name known (`p3d.py` says Byte Quaternion Channel) | the same header, then x, y, z as signed bytes over 127 (Xbox and PS2; about 1% precision) |
| `0x00121110` | Channel Interpolation Mode | u32 version, u32 interpolate (-1: yes) |

The PC keeps every rotation as four floats. The Xbox and the PS2 use the two compressed forms instead,
choosing per joint, and keep fewer keys: in `GEN_Conv_Motion_Toward.p3d` the PC has 509 keys, the Xbox
460 (all at frames the PC has keys too) and the PS2 fewer again (the pelvis: 23, 23 and 18). In the
compressed forms the rotation is turned so that w is not negative, and w is worked out as
`sqrt(1 - x² - y² - z²)`. Against the PC's rotations at the same frames, the 16-bit form is within 0.1
degree; the bytes are rounded towards zero (about one step low), a few degrees at worst.

### Ids seen but not worked out

`0x00010021` (u32 0, then seven u32: 32 on the PC and Xbox, 8 or 16 on the PS2, perhaps the bits each
kind of vertex data is stored in), `0x0001001D` (u32 1, 3, 1, 0 in every mesh), `0x00122000` (u32 0 and a
float, 0.5 or 0), `0x00121008` (u32 2), `0x00121402` (u32 0, 0), `0x00123000` with `0x00123001`,
`0x08020002` to `0x0802000E` (state props in *Hit & Run*), `0x088xxxxx`, `0x099001xx`, `0x01000001`,
`0x0100500A`.

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
| `VAG ` | PS2 | Sony ADPCM: 16-byte frames (shift and filter, flags, 14 bytes = 28 samples); flag 7 ends the sound. With two channels the frames take turns: one of the left, one of the right (checked against the PC's music and movies) |
| `PCM ` | | plain 16-bit samples |
| `RADP` | Xbox prototype | Radical's IMA ADPCM, every sound in the prototype (mostly 24,000 Hz): blocks of 20 bytes per channel. Each channel's s16 step index and s16 sample come first, then 16 rows of one byte per channel; a row gives every channel its low nibble, then every channel its high nibble (32 samples per channel per block). The usual IMA tables, with each step's change `((2 x (nibble & 7) + 1) x step) >> 3` |

## Videos (`.bik`)

Bink videos (RAD Game Tools): `BIK` + a version letter, u32 file size - 8, u32 frame count, u32 largest
frame size, u32 frame count again, then u32 width and u32 height at `0x14` and `0x18`. The PC's are
1280x720, and the Xbox program carries RAD's Bink library (its `BINK*` sections). Play them with RAD
Video Tools or a player that supports Bink (ffmpeg reads Bink 1).

The PS2 has no Bink videos: its movies are `.rmv` files (below).

## PS2 movies (`.rmv`)

Radical's "RadMovie" files in `MOVIES.RCF` (`prologue.rmv`, `radical.rmv`, `sierra.rmv`, ...): a 2 KB
header, the picture as a raw PS2 IPU stream, then the sound as an ordinary `.rsd` file.

```
0x00  "rmvps212"
0x08  u16 width, u16 height, u32 frames, u32 file size
0x14  u32 where the picture starts (0x800)
0x18  u32 number of sound tracks (1 in every movie on the disc)
0x1C  16 x u32  where each sound track starts (the picture ends at the first)
0x5C  16 x u32  each sound track's size
0x9C  u32 frames per second x 100 (2997)
      0xAD bytes to 0x800, and after the picture to the next 2 KB
```

The pictures are 640x336, or 640x240 for `prologue.rmv`, at 29.97 frames a second, and the sound is a
stereo `VAG` `.rsd` at 48,000 Hz. The IPU stream is what the PS2's IPU (its MPEG-2 decoding chip) reads:
the same as Sony's `.ipu` files without their 16-byte header (`ipum`, u32 size, u16 width, u16 height,
u32 frames), which FFmpeg reads. `portal/tools/rmv.py` writes the `.ipu` file (with that header) and the
sound as `.rsd` and `.wav`, and prints the FFmpeg command that turns them into an `.mp4`.

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

### PS2 code overlays

`CEMENT.RCF/Overlays/FrontEnd/*.bin` are more program code: the front end's pause menu, exotics shop,
pop-ups and mini-game screens, which `SLUS_211.11` loads when it needs them. They are CodeWarrior overlay
files, copied whole (header included) to their load address:

```
0x00  "MWo3"
0x04  u32 overlay number (6 to 11)
0x08  u32 load address of byte 0 of the file
0x0C  u32 code size, u32 data size, u32 bss size: the code starts at 0x40 (with 0x40 zero bytes first),
      the data follows it, and header + code + data is the whole file
0x18  u32 start and end address of the list of static constructors to call after loading
0x20  the overlay's name, NUL-terminated (32 bytes)
```

Each comes in three builds, `<name>f.bin`, `r.bin` and `t.bin`. Only the **f** ones fit the retail
program: all of their 3,097 calls into it land on the start of one of its functions (the r and t builds
hit almost none and load at other addresses), and `SLUS_211.11` itself has one empty segment for each at
`0x845480`, exactly the size of the f file. The r and t builds were made for other builds of the program,
probably Radical's "release" and "tune" configurations. The program was linked together with its
overlays: their virtual tables are in its data, and it calls into them directly.

The six f overlays hold 730 functions that are not in `SLUS_211.11`; the portal copies them out of the
PS2 disc and puts those functions in the work queue ([PS2.md](PS2.md#the-overlays)).
`portal/tools/ps2_overlay.py` shows the headers, counts the calls that land on functions
(`--check binaries/SLUS_211.11`) and writes each overlay as an ELF file Ghidra, IDA or objdump open at the
right address (`--elf FOLDER`).

[GAME_VERSIONS.md](GAME_VERSIONS.md) lists the exact copies (with their SHA-256) the project works from.

## Not yet described

Anything the portal's Game files list puts under *Other* is a format nobody has written up here yet:
open one in a hex editor, compare the versions (the [version differences](VERSIONS.md) help), and add
what you find. Known gaps:

* the Pure3D ids under [Ids seen but not worked out](#ids-seen-but-not-worked-out);
* the PS2's vector-unit packets in full (which attributes plain meshes carry, how a batch's strip is
  started), so that `p3d.py --obj` can draw PS2 models too;
* the seven u32 of `0x00010014` and the two u32 before each memory image's size.

## Credits and sources

* [FFmpeg](https://ffmpeg.org/): James Almer's `adpcm_ima_rad` decoder and `rsd` demuxer (2013), which
  play `RADP` sounds; `media.py`'s decoder gives the same samples on the prototype's files. Paul B Mahol's
  IPU decoder and demuxer (2020) play the movies' pictures once `rmv.py` has written them out.
* The [Donut Team](https://docs.donutteam.com/docs/Pure3DFiles/ChunkTypes/AllChunkTypes)'s Pure3D chunk
  list, and the *Hit & Run* chunk work behind Proddy's (Hampo's)
  [NetP3DLib](https://github.com/Hampo/NetP3DLib) and [LuaP3DLib](https://github.com/Hampo/LuaP3DLib)
  (with chunk structures by Lucas Cardellini): the names of most chunks, and the older layouts these
  build on.
* The PS2's VIF command set, as documented for emulators such as PCSX2, to read the vector-unit packets.

The rest was worked out from the game files and checked against the other versions of the same files: the
`RADP` speech against the PC's Ogg Vorbis copies, the PS2's stereo music and movie sound against the PC's,
the movies' pictures by decoding them, and the PS2 rotations against the PC's.
