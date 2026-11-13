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
| [Pure3D](#pure3d-p3d) | `.p3d` | all | `p3d.py` (chunks, models to .obj), `p3d_gltf.py` (models, animations and maps to glTF for Blender), `stream_graph.py` ([what is loaded where](#the-stream-graph)), `game_assets.py` (contents), `media.py` (pictures) |
| [Pictures in Pure3D](#pictures) | PNG, DDS, P3DI | PC, Xbox, PS2 | `media.py` |
| [Sounds](#sounds-rsd) | `.rsd` | all | `game_assets.py` (facts), `media.py` (playing) |
| [Videos](#videos-bik) | `.bik` | Xbox and PC (Bink) | `game_assets.py` (Bink picture size) |
| [PS2 movies](#ps2-movies-rmv) | `.rmv` | PS2 | `rmv.py` (to an `.ipu` picture and a `.wav`) |
| [Compiled scripts](#scripts-cso-dso-dtr) | `.cso`, `.dso` | all | `torque_dso.py` and friends ([SCRIPTS.md](SCRIPTS.md)), `fog.py` ([the fog](#fog-by-time-of-day)) |
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
read, and `--obj OUT.obj` writes its meshes and skins as plain geometry. `portal/tools/p3d_gltf.py` writes
whole scenes as glTF (`.glb`), which Blender opens with File > Import > glTF 2.0: textured models,
characters with their skeletons, skin weights and animations, guns and cars with their moving parts, and
map areas with everything placed on them and their lights ([Exporting to Blender](#exporting-to-blender)).

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

**Square** PS2 pictures, and 8-bit ones of at least 128 x 64 (one GS page), are also stored in the graphics chip's own block order, ready to be sent to it as
32-bit data (PSMCT32) and read back as 8-bit (PSMT8) or 4-bit (PSMT4) pixels. To show one, work out where
the chip would read each pixel: send the data as a PSMCT32 picture of width/2 x height/2 (8-bit) or
width/2 x height/4 (4-bit), then read pixel (x, y) at its PSMT8 or PSMT4 address. The page, block and
column tables are the ones in Sony's GS manual (and in emulators such as PCSX2); `media.py` has them
written out. The rest (4-bit pictures that aren't square, and small 8-bit ones such as a 64 x 32 mipmap
level) are stored row by row. All 65 PS2 pictures in the samples that have a PC twin follow these rules:
decoded this way each matches the PC picture of the same name, and decoded the other way it doesn't.

Across the versions, by name (3,568 different texture names on the PC, 3,243 in the 2006 prototype): the
Xbox's textures are the same size as the PC's (smaller in 7 files), the PS2's the same or smaller, and the
prototype has 2,866 the same size, 92 smaller, 48 bigger and 237 the PC doesn't have. Of the 48 bigger,
the world textures (`garbageBagA.bmp`, `r_ind_stone_1.tga`, `l_pedro_books_vhs.tga` ...) are the same
picture at twice the resolution: shrunk to the PC's size they match it (`media.likeness()` 0.99 and up),
the PC's being a halved copy. The menu icons (`MIcon01.png`, `ammo_pistol.tga` ...) and
`lbank_carpet002.bmp` are different pictures under the same name (0.2 and below). Per file, the
prototype's maps often hold more textures than the PC's: the final game keeps them in shared region files
instead. `portal/tools/textures.py` writes every texture out on these terms.

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
  them and `0x00010013` holds u16 indices (both after three u32: `0x20001`, 0, the size in bytes). A
  vertex is the position (3 floats), then the normal if the vertex type has one (a packed u32, Direct3D's
  NORMPACKED3: x and y in 11 signed bits, z in 10), the colour if it has one (u32, ARGB), one more u32
  colour for each of the bits `0x4000` and `0x10000` (the PC keeps these in `0x0001001C` lists: u32 count,
  u32 channel, a u32 per vertex), each UV set (2 floats), and on vehicles (vertex type bit `0x100000`) two
  more vectors (6 floats). Skins keep the PC's plain lists.
* **PS2**: only a memory image: `0x00010012` (after three u32: `0x100008`, the number of quadwords, the
  size) is a ready-made VIF packet for the vector unit's microprogram. See
  [PS2 vertex packets](#ps2-vertex-packets).

#### PS2 vertex packets

The vertices come in batches of up to 72 (54 for skins), each its own triangle strip. A batch is a run of
VIF codes: an UNPACK of four quadwords (V4-32) to address 0, the header, then a STCYCL whose CL is the
number of quadwords per vertex, then one UNPACK per attribute, starting at address 4 (STMASK, STCOL,
STMOD and STROW fill the parts the data doesn't).

```
header   u32 vertex count, u32 flags, two VU addresses
         4 floats: the batch's bounding sphere (centre and radius)
         4 floats: the scales: positions, normals (1/127), then UVs (see below)
         the GIF tag
```

The attributes, in this order, one quadword each:

| Attribute | Stored as | Value |
| :--- | :--- | :--- |
| each UV set | V2-32 floats, or V2-16 | 16-bit numbers times a scale: the header's fourth for the first UV set and its third for the second; on vehicles the second for the first set and the fourth for the second |
| colour | V4-8 (128 is full), or V4-5 (5-5-5-1 bits) | |
| normal | V3-8 over 127, or V3-32 floats | on vehicles two more vectors come before it |
| position | V3-32 floats, or V3-16 or V3-8 | 8- and 16-bit numbers times the header's first scale |
| matrices (skins) | V4-8 unsigned | palette index x 4 |
| weights (skins) | V4-16 | the first weight over 4096; each next one over 4096 times the weight before it (0.6, 0.2, 0.2 is stored as 2458, 1365, 4096) |

The lowest bit of a vertex's U (the float's bits, or the 16-bit number) is set when the triangle that
ends at that vertex is not drawn: the strip starts again there, as the PC's strips do with repeated
indices. Triangles alternate in direction along the strip, counting from the batch's first vertex; the
even ones turn the same way as the PC's. Decoded this way, the PS2's character, car and map samples match
the PC's positions, UVs, colours, joints and weights.

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
| `0x00121102`, `0x00121103` | Vector1DOF, Vector2DOF Channel | u32 version, parameter, u16 mapping, 3 floats constants, u32 keys, u16 frames, 1 or 2 floats per key. For one moving component the mapping says which (0 x, 1 y, 2 z); for two it says which one stays at its constant |
| `0x00121105` | Quaternion Channel | u32 version (1), parameter (`ROT`), u32 keys, u16 frames, 4 floats per key: x, y, z, w |
| `0x00121112` | Compressed Quaternion Channel2 | the same header, then x, y, z as signed 16-bit numbers over 32,767 (Xbox and PS2) |
| `0x00121114` | no name known (`p3d.py` says Byte Quaternion Channel) | the same header, then x, y, z as signed bytes over 127 (Xbox and PS2; about 1% precision) |
| `0x00121110` | Channel Interpolation Mode | u32 version, u32 interpolate (-1: yes) |
| `0x00121100` | Float1 Channel | u32 version, parameter, u32 keys, u16 frames, 1 float per key |
| `0x00121109` | Colour Channel | u32 version, parameter (`CLR`), u32 keys, u16 frames, then a u32 colour (`0xAARRGGBB`) per key: two arrays, not interleaved |
| `0x0012110E` | Integer Channel | u32 version, parameter (`VRTX`), u32 keys, u16 frames, then a u32 per key, with no padding between the two arrays |
| `0x00121201` | Frame Controller | u32 version, name, 4 characters type (`CAM`, `PTRN`, `LITE` ...), `ANIM`, two u32, then the name of what it drives (a camera, a light) and the animation it plays |
| `0x00002200` | Camera | name, u32 version (2), float field of view (radians, across the picture), float aspect, float near and far clip, then position, look direction and up (3 floats each) |

Every person in the game has the same 27-joint skeleton (`character_root`, `pelvis`, `hip_l` ...), so
the animations in `art/animations` fit any of them; the portal shows them on Tony.

A camera's move (`frontend/prebuilt/*.p3d`, the cutscenes) is an animation of type `CAM` played on the
camera by a frame controller. Its groups have Vector channels `TRAN` (position), `LOOK` (the direction it
looks, a unit vector) and `UP`, and Float1 channels `FOV`, `NCLP` and `FCLP` (near and far clip), `DFFD`
and `DFFS` (depth of field). Exported, the camera looks the way glTF wants (down its -Z, Y up), turned
from `LOOK` and `UP` at each of their keys.

The PC keeps every rotation as four floats. The Xbox and the PS2 use the two compressed forms instead,
choosing per joint, and keep fewer keys: in `GEN_Conv_Motion_Toward.p3d` the PC has 509 keys, the Xbox
460 (all at frames the PC has keys too) and the PS2 fewer again (the pelvis: 23, 23 and 18). In the
compressed forms the rotation is turned so that w is not negative, and w is worked out as
`sqrt(1 - x² - y² - z²)`. Against the PC's rotations at the same frames, the 16-bit form is within 0.1
degree; the bytes are rounded towards zero (about one step low), a few degrees at worst.

### Which way round

Pure3D is left-handed with Y up (like Direct3D): a character faces -Z with its left side at +X, and
text on signs reads correctly only when that is kept. glTF and Blender are right-handed, so `p3d_gltf.py`
mirrors Z (a position's z, a rotation's x and y) and turns every triangle round to keep it facing out.
UVs have V running up from the bottom of the picture, so V is flipped too.

### Composite drawables

Most things the game draws are composite drawables: a skeleton and the meshes (or skins) hung on its
joints. A gun, a car, a placed tree and each part of a map are one.

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x00123000` | Composite Drawable | u32 version (0), name, skeleton name, u32 number of parts; the parts follow |
| `0x00123001` | Composite Drawable Part | u32 0, u32 0, the drawable's name, u32 kind (1 a model; `0x20` a shadow mesh, `0x40` a shadow skin), u32 the joint it hangs on |
| `0x08800005` | State Prop | name, the composite drawable's name |
| `0x0802000D` | State Prop Data | u32 version (4), name, drawable name, u32 1, u32 number of states; holds `0x08020008` (name and value properties: `name`, `visibility`) and one `0x0802000E` per state |
| `0x0802000E` | Prop State | the state's name (`idle`, `final`, `damage1`, `shake`, `open` ...), then 36 bytes not worked out; holds one `0x08020002` per part |
| `0x08020002` | Part Visibility | the part's name (a composite drawable part), u32 shown (1) or hidden (0) in this state |

A part's mesh is in its joint's space: the joint's world matrix times the vertex.

### Shaders

A primitive group names its shader, and the shader says how the surface is drawn. This section,
[The sea](#the-sea) and [Shadows](#shadows) come from the clean-room spec
[SPEC-002](cleanroom/SPEC-002-materials-ocean-shadows.md) ([how that works](CLEAN_ROOM.md)). Its examiner read
the shaders' settings, the textures, the scripts and the shadow records back from the PC files. What the PC
program does with them is marked *(reported)*: it comes from the research behind the spec and can't be checked
from the files alone.

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x00011000` | Shader | name, u32 version, the kind (text), u32 translucent, u32 vertex needs, u32 vertex mask, u32 number of settings; the settings follow |
| `0x00011002` | Shader Texture Parameter | 4 characters (`TEX`), the texture's name |
| `0x00011003` | Shader Integer Parameter | 4 characters (`BLMD` ...), u32 |
| `0x00011004` | Shader Float Parameter | 4 characters (`ACTH` ...), f32 |
| `0x00011005` | Shader Colour Parameter | 4 characters, u32 colour (`0xAARRGGBB`) |

The kinds, over the 5,393 shaders in `packages/z04/*.p3d` and `art/ecoprops/*.p3d`:

| Kind | Shaders | What uses it |
| :--- | ---: | :--- |
| `simple` | 4,278 | most of the world, props, the sky, the sun's flares, the sea (`ocean_text`, `ocean_foam`) |
| `cbvlit` | 654 | world surfaces lit by their vertex colours |
| `decal` | 235 | grime, cracks, arrows, signs, light glows laid over other surfaces |
| `layered` | 111 | two textures blended (`TBLM`, `CLYR` settings) |
| `nightlight` | 53 | lit windows and signs (`..._win_Add_...`, `l_sign.bmp`) |
| `shadowdecal` | 24 | shadows painted on the ground ([Shadows](#shadows)) |
| `foam` | 14 | shore and wake foam (`ShoreGradient.tga`, `Boat_wakeFoam`) |
| `specular` | 13 | roads and pavements with a shine texture |
| `environment` | 6 | reflections laid over glass (`g_reflection.tga`, `r_lt_reflection.bmp`) |
| `vertexfade` | 4 | the low-detail hull of the city and the islands (below) |
| `untextured` | 1 | |

The settings that matter here:

| Setting | Seen | What it does |
| :--- | :--- | :--- |
| `BLMD` | 0 or none (solid), 1 (1,456 shaders), 2 (325), 3 (18) | how the surface goes over what is behind it (below) |
| `ATST` | 1 in 555 shaders, never 0 | a cut-out: a pixel whose alpha fails the test isn't drawn and leaves no depth *(reported)* |
| `ACMP` | 4 in all 555 | the test: 4 is "greater than" (Direct3D's `D3DCMP_GREATER`); without `ACMP` it would be "greater or equal" *(reported)* |
| `ACTH` (float) | in 55 of them: 0.01, 0.054, 0.07, 0.2, 0.3, 0.6, 0.65, 0.7, 0.8 | the alpha the test compares with; 0.5 without it *(reported)* |
| `2SID` | 1 in 900, 0 in 4,328 | drawn from both sides |
| `UVMD` | 0 in all 5,318 that have it | textures repeat |
| `LIT` | 1 in 2,084, none elsewhere | lit by the scene's lights; without it, not lit. In `packages/z04` every shader whose name says `lit0` has no `LIT` and every one that says `lit1` has `LIT` 1 (2,802 and 2,043; SPEC-002's answers) |
| `ZWRT`, `ZTST` | 0 in 54 shaders, all in `art/ecoprops` | ignored by the PC game *(reported)*, and by the exports |

The shader names spell most of these out ([Maps](#maps)); the settings chunks are what the game reads.

**The blend modes.**

| `BLMD` | What the game does | Used by |
| :--- | :--- | :--- |
| 1 | ordinary see-through: the texture's alpha mixes it with what is behind *(reported)* | 1,456 shaders, among them the props' leaves, the shadow decals and the low-detail hull (below) |
| 2 | adds light. The textures are opaque (alpha 255 everywhere) and mostly black, 40 to 87 % of their pixels, with the light in colour on top: the black adds nothing. Drawn with ordinary blending they come out as black squares | the sun's flares and lens rings (`Flare_Star_xb.bmp`, `LENS03.bmp` ...), light glows (`lightGlowWhite.bmp`), boat lights, the `nightlight` windows, one tunnel lighting texture |
| 3 | darkens; exactly how isn't known. Multiplying what is behind by the texture fits all of them | skid marks (`SkidMark_Asphalt.bmp`, opaque and dark, 3 to 19 out of 255 on average), grime (`grime.tga`: grey 125, alpha 175), `r_tonymsn_shadow_circle.bmp` |

**What hides what** *(reported)*. Ordinary see-through world surfaces (`BLMD` 1) are drawn after the solid
ones, sorted from far to near, and still write depth. The `decal`, `nightlight` and `shadowdecal` kinds, the
light-adding surfaces (`BLMD` 2) and the sky are drawn without writing depth: they never hide anything drawn
after them. A `decal` with `BLMD` 1 also drops pixels whose alpha is exactly 0, and decals are drawn without fog.

**Leaves** *(reported)*. The trees and bushes the city places as props use unlit see-through shaders (`BLMD` 1,
no `LIT`, no `ATST`). The game draws them twice: once for their colour, blended, without writing depth; then once
more writing depth only, where the alpha is at least 228 out of 255 (0.894). So the solid core of each leaf
hides what is behind it, and the soft edges never cut holes into the leaves behind. Lit ones are drawn once.

**The low-detail hull.** `miami_lod.p3d` and `islands_LOD.p3d` hold a coarse copy of the whole city and the
islands, drawn with the `vertexfade` kind: `pure3dVertexFadeShader1` in `miami_lod.p3d`; `RockShader`,
`islands_LOD_pure3dVertexFadeShader1` and `pure3dVertexFadeShader3` in `islands_LOD.p3d`; all `BLMD` 1 and
`LIT` 1. The game fades it out towards the camera *(reported)*: fully see-through nearer than about 200 m, whole
beyond about 250 m, and every pixel with an alpha below 20 out of 255 cut out. Close up it is invisible, and far
away it stands in for the detailed areas. Shown whole next to them, it is a shell that covers them.

`p3d_gltf.shader_info` reads a shader and its settings (the kind is its `pddi`). A shader known only by name, from
a file not given, is read from its name, kind included (`shader_from_name`).

### The game's loaders

The game reads each kind of chunk with a loader object, and the Xbox program still has their class names
(run-time type information). Each loader's constructor stores the chunk id it handles
(`mov dword ptr [reg+8], id`), so the program names the chunks itself:

| Id | Loader | Id | Loader |
| :--- | :--- | :--- | :--- |
| `0x08800000` | `renderer::CharacterLoader` | `0x08800100` | `StreamPackage` |
| `0x08800001` | `VehicleLoader` | `0x08800101` | `StreamTrigger` |
| `0x08800002` | `SkyLoader` | `0x08800102` | `NISPackage` |
| `0x08800003` | `WorldGeoLoader` | `0x08800104` | `ScriptFileChunk` |
| `0x08800004` | `ZonePkgLoader` | `0x08800105` | `LoadPackageChunk` |
| `0x08800005` | `SFStatePropLoader` | `0x08800108` | `Cement` |
| `0x08800007` | `SFLightGroupLoader` | `0x08800112` | `LoadPackageIdentifier` |
| `0x08800008` | `ShadowLoader` | `0x08800113`, `0x08800114` | `NISStreamData`, `NISStreamPartitionInfo` |
| `0x0880000A` | `occlude::OccluderLoader` | `0x08800150` | `CVLoadObject` |
| `0x08800160`, `0x08800161` | `TrafficConfig`, `SubzoneTrafficTrigger` | `0x08800180`, `0x08800181` | `ScriptObject`, `GameGroup` |
| `0x09900190`, `0x09900191` | `ScriptObjectData`, `GameGroupData` | `0x08800201` to `0x08800203` | `WaterData` (dock, obstacle, shallow area) |
| `0x08011000`, `0x08011005` | `NavMesh`, `RoadGraph` | `0x07010000`, `0x07011000`, `0x07010025` | `ravenphysics` collision object, rigid body, world collision object |
| `0x0802000D` | `prop::StatePropData` | `0x00123000` | `CompositeDrawable` |
| `0x0001001A`, `0x00010019` | `ShadowMesh`, `ShadowSkin` | `0x0001580C`, `0x00017006` | `ParticleSystem`, `Billboard` |
| `0x00002200`, `0x00013000`, `0x00002380`, `0x00014000` | camera, light, light group, locator | `0x00021000` to `0x00021002` | expression loaders |
| `0x00022000`, `0x00022002` | texture font, image font | `0x00121201`, `0x00121202` | frame controller, multi controller |
| `0x00018000`, `0x0001800D`, `0x00019005` | frontend project, text bible, sprite | `0x01005002` to `0x0100500B` | sound entities |

`p3d.py` names every chunk in this list.

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x08800000` | Character | name, the skin's name, then nine u32 (3 in every file seen) |
| `0x08800001` | Vehicle | name, its composite drawable, its low-detail composite drawable, the paint shaders' names, then three u32 |

### Maps

The city is cut into areas (`packages/z04/<area>_shell.p3d`, `_detail.p3d`, `_detailB.p3d`...), which
the game streams in and out, plus files shared by many areas: a region's shaders and textures
(`<region>_region.p3d`) and the models its areas place (`<region>_region_D.p3d`), the shaders and models
used everywhere (`miami_lod.p3d`, `miami_lod_D.p3d`), and `Common.p3d`. Each area's shaders are named
after what they do, for example `GlobalShader_g_hedge.tga_simple_blmd1_mcbv0_lit1_alpha1_atst1_alum1_2sid0`
(the texture, the shader kind, then blend mode, colour-by-vertex, lit, alpha, alpha test, luminance and
two-sided flags); the `RegionShader_` ones live in the area's region file.

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x08800003` | World Geometry | name, the composite drawable's name, u32 flags (5 for every underwater part seen, 3 for the low-detail city, else 0). The composite's joints sit at world positions and each mesh (`collapsedMesh_...`) hangs on one |
| `0x08800004` | Zone Package | the area's name, u32 count, that many World Geometry names |
| `0x08800112` | Load Package Name | the file's own package name |
| `0x09900191` | Game Group Data | the script file (`objects.ds`), the group's name, its class (`gamegroup`), u32 1; its objects follow |
| `0x09900190` | Script Object Data | the script file, the object's name, its class (`instanceobject`, `missiontriggerobject`, `shadowobject`, ...); its properties follow |
| `0x09900192` | Script Object Property | name, u32 type: 0 for text (then the text, for example `position` = `-1928.0890 5.5734810 -943.42900`), 2 for binary (then u32 3 and a `0x09900194` sub-chunk) |

**Placed objects.** Trees, lamps, benches, signs and the like are *instance objects*: a Script Object
of class `instanceobject` whose `modelname` names the model (a composite drawable or state prop, found by
name with letter case ignored, in the area itself, its region's `_D` file or `miami_lod_D.p3d`) and whose
`instanceposition` properties each place one copy. Each is a binary value (`0x09900194`) of twelve
32-bit numbers:

```
0x00  float x, float y (in centimetres), float z
0x0C  u32 x angle, u32 y angle, u32 z angle (degrees)
0x18  u32 a, u32 b, u32 c (6 bits each), u32 same (1: one scale for all three axes)
0x28  u32 d (4 bits: 0 is 1.0, else d/15, passed on with the model), u32 e (4 bits, 0 in every file seen)
```

The game packs this into bit fields as it loads it (`default.xbe` `0x677B0`), so it keeps the height as
a 16-bit number of centimetres and the X and Z angles in steps of 2 degrees (the Y angle, the heading, in
whole degrees). The scale is `(a + b*64 + c*4096) / 1000` on all axes when *same* is set, else
`a/20, b/20, c/20` per axis. The text form of the same property (`x y z ax ay az scale...`, read at
`0x1D0820`) ends up in the same fields. To draw a copy the game (`0x8C540`, `0x53E50`) builds, for row
vectors, *scale x rotation*, then puts the position in the last row; the rotation is the one Pure3D
builds from three angles (`0x243020`: about X first, then Y, then Z) given minus the X angle, minus the Y
angle and the Z angle. Placed this way the samples' street lamps, bus stops, parking meters and trees
line up with the roads and pavements in the areas' own geometry.

A placed prop's composite drawable holds every look it can have. Most have a full-detail part
(`garbageCanBInstanceShape`) and a low-detail one for far away (`...LODShape`), both shown in its first
state: the game picks between them by distance. Props that can break have a damaged part too
(`garbageCanBDamageShape`, `garagePostIBShape`), hidden in the first state (`idle`) and shown in a later
one (`final`) while the whole one is hidden. The exports show each prop as its first state has it, at full
detail; a prop's file opened on its own also gets each later state's look beside it, named after the state.

Traffic, pedestrians and mission cars aren't models placed in the files: the game spawns them while it runs,
at spawn objects the areas do place (`worldambiencespawnobject`, `enemycharactergeneratorspawnobject`, ...).

### Lights

This section, the next three and the Colour and Integer Channels above come from the clean-room spec
[SPEC-001](cleanroom/SPEC-001-lights-sky-streaming.md) ([how that works](CLEAN_ROOM.md)), whose examiner
checked them on the PC files; `p3d.py` and `fog.py` read them, and the tests check that on made-up files.

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x00013000` | Light | name, u32 version (`0x101`), u32 type (0 ambient, 1 point, 2 directional, 3 spot), u32 colour (`0xAARRGGBB`), 3 floats attenuation (constant, linear, quadratic: 1, 0, 0 in every Miami file), u32 enabled (1 or 0); the sub-chunks below |
| `0x00013001` | Light Direction | 3 floats: a unit vector, the way the light shines |
| `0x00013002` | Light Position | 3 floats, in the same space as the map's geometry |
| `0x00013003` | Light Spot Cone | 4 floats: two angles, a falloff and a range. Which angle is the inner one, and whether they are in degrees or radians, isn't known yet |
| `0x00013004` | Light Casts Shadows | u32 |
| `0x00013006` | Light Decay Range | u32 shape (0 none, 1 sphere, 2 box, 3 ellipsoid), 3 floats inner size, 3 floats outer size; may hold a `0x00013007` |
| `0x00013007` | Light Decay Range Rotation | a float: a turn about the vertical axis, in radians |
| `0x00013008` | Light Illumination Kind | u32: 0 adds light, 1 none, 2 takes light away |
| `0x00002380` | Light Group | name, u32 count, then that many light names. The lights are `0x00013000` chunks in the same file |
| `0x08800007` | Light Group (game) | name, the light group's name, u32 kind, u32 count, then that many frame controller names |

The names of the sub-chunks are descriptive ones of ours. In the city's files (`packages/z04`) there are
1,830 lights: 1,105 point, 593 directional, 132 ambient and no spot lights. Every one has a position and a
shadow flag and belongs to a light group.

**The decay range.** A light is at full strength inside the inner size, fades smoothly to nothing at the
outer size, and does nothing beyond. A sphere uses only the first of the three sizes (its radius); a box is
turned by the `0x00013007` angle first; the game handles an ellipsoid as a box. The game counts a light
with a decay range as a local light, and only when the decay where you are is above zero and the light is
within about 50 m. Only the city-wide lights in `miami_lod.p3d` and `islands_LOD.p3d` have none. Every lamp
and every interior light has one, many directional lights among them: those light only their range, not
the whole city.

The record's kind says what a light group is for:

| Kind | Where | What |
| :--- | :--- | :--- |
| 0 | `miami_lod.p3d`, `islands_LOD.p3d` | the daylight (`zone_lights`): ambient, sun, fill, building ambient |
| 1 | the same two | the same four lights for rain (`zone_rainlights`) |
| 2 | mostly `*_detail.p3d` and `*_detailB.p3d`, a few `*_shell.p3d` | outdoor night lights (signs, a petrol station, a theatre front) |
| 3 | `*_shell.p3d` | one group per interior |
| 4 | `Common.p3d` | templates: `lamp_talllight`, `lamp_shortlight`, `vehicle_headlight` |

The building ambient light (`MiamiBuildingAmbientShape`) isn't part of the light the world is lit with: it
belongs to the lit windows at night.

**The daylight changes with the hour.** The kind 0 and kind 1 records each name a frame controller per
light (`LITE_<light name>`, type `LITE`), which plays an animation of type `LITE` on it: 241 frames, one
day, frame 0 midnight, frame 120 noon, a frame every six minutes. Its `CLR` channel (a Colour Channel)
gives the colour and its `DIR` channel (a Vector3DOF Channel) the direction; either may hold a Channel
Interpolation Mode. These tags are padded with a NUL, not a space. The values stored in the lights are
midnight's: `miami_lod.p3d`'s sun stores 31, 45, 48 and (0, -0.788, -0.616), and at noon is 99, 97, 72 and
(-0.473, -0.743, 0.473).

**One weather at a time.** `miami_lod.p3d` and `islands_LOD.p3d` each hold the daylight twice: kind 0
(`zone_lights`) for clear weather and kind 1 (`zone_rainlights`) for rain, four lights each, sun included.
They are alternatives, not layers: the game is in one weather at a time, and it starts in clear weather
(`enableraining` 0 in the `tod` object, see [Fog by time of day](#fog-by-time-of-day)). Rain fades in and out
over 50 frames (`rainstarttransitframes`, `rainendtransitframes`). A scene should be lit by one of the two
groups, with the fog and the sky of the same weather.

### The draw-order key and the sky

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x00122000` | Draw Order | u32 version (0), a float: the draw-order key of the mesh (`0x00010000`) it sits directly under. Billboard groups carry one too |
| `0x08800002` | Sky | name, the composite drawable's name |

The game clamps the key to 0..1, and a mesh without one counts as 0.5. It matters for the sky, which is
drawn first, with no depth test, no depth writes and no fog, from the highest key to the lowest: a lower
key ends up on top. Without it the dome can cover the clouds and the horizon, and the sky becomes one flat
colour. The game doesn't sort the billboard groups by it.

| Mesh | Key | What it is |
| :--- | ---: | :--- |
| `skyboxShape` | 1.0 | the dome, drawn first |
| `skybox16Shape` | 0.9 | untextured |
| `skybox17Shape`, `skybox18Shape` | 0.3, 0.2 | two cloud layers (`Cloud_variant_001.tga`) |
| `skybox2Shape`, `skybox_horizonShape` | 0.0 | the horizon gradient, drawn last, on top |
| `rainy_skyShape`, `rainy_sky2Shape` | 0.5 | the rain sky |
| `rainy_sky3Shape`, `rainy_sky4Shape` | 0.6 | the rain sky |

`Common.p3d` has two Sky chunks: `sky` (its composite has 6 meshes and 6 billboard groups) and
`rainy_skybox` (6 meshes). A name starting `rainy_` is the rain sky: the game starts it faded out and
cross-fades between the two with the weather.

**How the game draws it.** The whole sky is drawn at twice its size. The sky's meshes move with the camera
across, not up: they take the camera's x and z, and their height stays 0, so the sky turns with the camera
but doesn't rise with it. The billboard groups (the sun, its two flare stars, two lens flares and the moon;
there are no stars) take the camera's whole position: they sit at infinity, and are drawn near the end of
the frame. The sky is never culled by distance.

**Where the sun is.** The `sky` composite's skeleton (`0x00023000`) has 14 joints: `sky` (the root),
`skybox`, `sun_grp`, the six billboard joints hanging from `sun_grp` (`sun`, `fxSys_SunFlare`,
`p3dBillboardQuadGroup1`, `p3dBillboardQuadGroup2`, `fxSys_SunFlare1`, `p3dBillboardQuadGroup3`; which one
is the moon isn't known), then `skybox16`, `skybox2`, `skybox17`, `skybox18` and `skybox_horizon` under the
root. The animation `PTRN_sky` (type `PTRN`, 241 frames at 30 a second: one day, frame = hour x 10, like the
daylight's) turns `sun_grp`: a Quaternion Channel `ROT` with 21 keys. Its other group, `sun`, is a
Vector3DOF Channel `TRAN` with two equal keys, (832.597, -0.755, -1.531): the sun's offset from `sun_grp`,
which is also its rest offset. The skeleton's rest pose puts the sun about 755 m below the ground, at
(8.0, -755.2, 350.5), so a viewer that doesn't play `PTRN_sky` draws it underground. Between the keys at
frames 153 and 154 the quaternion changes sign (it is the same rotation): taken along the shorter arc the
sun moves on; taken the long way, it jumps across the sky around 15:20. Played at frame = hour x 10, the sun
is this high above the horizon (degrees):

| Hour | 0 | 2.2 | 4.4 | 6.6 | 8.9 | 10.6 | 12.0 | 13.1 | 13.9 | 14.9 | 16.9 | 18.0 | 19.9 | 21.7 | 23.5 |
| :--- | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: | --: |
| Height | -65.1 | -60.4 | -38.3 | -12.8 | 13.2 | 34.7 | 50.5 | 65.1 | 72.0 | 66.1 | 32.1 | 12.0 | -19.9 | -48.1 | -65.5 |

Sunrise is at about 7.7 h, sunset at about 18.7 h.

**The sky's colours.** Five of the clear sky's six meshes change colour through the day. Their primitive
groups are triangle strips with no index list.

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x00121305` | Vertex Colour Sets | right under the mesh: u32 version, u32 count n, n u32 (0, 1, 2 ... in every sky mesh), n u32 (meaning not known); then n Vertex Colour Sets |
| `0x00121306` | Vertex Colour Set | u32 version, u32 frame, u32 (meaning not known); holds a `0x00010F02` |
| `0x00010F02` | Vertex Colour Amounts | u32 version, `CLR0`, u32 count (every vertex of the mesh), then per vertex u32 vertex number, u16 red, u16 green, u16 blue, u16 0 |

The chunk names are descriptive ones of ours. A set holds **amounts added to the mesh's own vertex
colours**, not new colours. The mesh's own colours are the night sky (the dome is `0x0a0d14`, dark blue), and
the first set is all zeros. Each set gives every vertex the same amount, so the dome really is one flat
colour; the look of the sky comes from the other meshes. The animation `VRTX_<mesh name>` (type `VRTX`, 241
frames at 30 a second) picks the set: its Integer Channel gives the set's number at each key, and before the
first key the first value holds. It isn't linear in the time of day:

| Animation | Key frames: set |
| :--- | :--- |
| `VRTX_skyboxShape` | 40, 90, 120, 180, 210, 240: 0, 1, 2, 3, 4, 5 |
| `VRTX_skybox17Shape` | 40, 41, 90, 210, 240: 0, 1, 2, 3, 4 |
| `VRTX_skybox18Shape` | 40, 90, 210, 240: 0, 1, 2, 3 |
| `VRTX_skybox2Shape`, `VRTX_skybox_horizonShape` | 0, 240: 0, 1 |

Keeping the fraction of the number between keys and blending the two sets either side of it makes the sky
cross-fade instead of jump. At noon the dome is on set 2. The dome's six sets are (0, 0, 0), (104, 201, 209),
(132, 149, 204), (104, 177, 112), (4, 3, 11) and (0, 0, 0); the second, added to (10, 13, 20), is the familiar
Miami sky blue. The cloud layers: `skybox17Shape` (0, 0, 0), (2, 2, 1), (122, 127, 85), (122, 127, 85),
(0, 0, 0); `skybox18Shape` (0, 0, 0), (104, 109, 70), (104, 109, 70), (0, 0, 0). The two horizon meshes' sets
are all zero: the horizon keeps its own colours all day.

### The stream graph

`art/levels/z04/streamgraph.p3d` says which packages the game keeps loaded at each place in the city: 216
Stream Packages and 297 Stream Triggers.

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x08800100` | Stream Package | the package's name (lower case, no `.p3d`), u32 (5 to 65535, one per package; meaning not known) |
| `0x08800101` | Stream Trigger | name (`loadTrigger`, `loadTrigger_100` ...), the subzone it belongs to (`bsand_02_shell`), float height (13 for the street-level ones), u32 count and that many points (3 floats: x, y, z), u32 count and that many package names, u32 count (the same) and the slot each package goes in, two region names (`fountainrock_region`, `lobst_region`; meaning not known), u32 (0 in all but one; meaning not known) |

A trigger's points are a closed outline on the ground; y is its base. Its packages are what must be loaded
while you are inside it, each in a slot:

| Slot | Holds |
| :--- | :--- |
| `Global_S`, `Global_D` | the city-wide backdrop and the models it places (`miami_lod`, `miami_lod_d`, or the islands' `islands_lod`, `islands_lod_d`) |
| `Region_S`, `Region_D` | a region's shaders and textures, and its models |
| `Shell` | an area's streets and large buildings |
| `Detail` | the small things on top of a shell; a shell can have several (`_detail`, `_detailB` ...) |
| `ZoneAnimation` | `packages/ZoneAnimations/<name>_anim` |

What is loaded at a place is every package of every trigger whose outline holds it. Triggers overlap:
usually three to six shells and three to eight details are loaded at once, the area you stand in and its
neighbours. Outside every trigger, the nearest one stands in. The coordinates are the map's own, before the
exports mirror Z ([Which way round](#which-way-round)).

```
python portal/tools/stream_graph.py streamgraph.p3d               every trigger
python portal/tools/stream_graph.py streamgraph.p3d --at X Z      what is loaded at x, z
```

The stream graph doesn't cover `packages/azones/*_pocket.p3d` (32), which the mission script
`scriptc/missions/z04/azone_triggers.dso` loads as the player crosses its outlines (some are outdoor ground,
so a city built from the stream graph alone has holes there; the map exports include them), nor
`packages/dzones/*_dzone.p3d` (135: the furniture and props of interiors, from `dzone_triggers.dso`), nor
the areas the game picks one of (`tonymansion_01_shell_TS0` to `TS3`, `cargoShip_01_shell_CS0` and `CS1`).

### Fog by time of day

The fog isn't in any `.p3d`. It is in `EnvironmentObject`s that the compiled script `scriptc/graphanims.cso`
creates (for the islands, `scriptc/island_envobjects.cso`, whose objects are named
`island_environment_...`): `environment_clear_<hour>` and `environment_rainy_<hour>` for the hours 4, 9, 12,
18, 21 and 24. The repository's script decompiler shows them as
`new EnvironmentObject("environment_clear_12") { FogStart = 25; FogEnd = 900; ... };`. Their fog properties:

| Property | What |
| :--- | :--- |
| `FogEnabled` | 1: fog on (in all 24 objects) |
| `FogStart`, `FogEnd` | the distances the fog runs from and to, in metres from the camera |
| `FogColor_Red`, `FogColor_Green`, `FogColor_Blue` | the fog's colour, each over 255 |
| `FogColor_Alpha` | meaning not known (95 to 150) |
| `FogClamp` | meaning not known; the `*_xbox.cso` copies of the scripts differ only in it |

The same objects set about fifty more looks (`Bloom_*`, `ColourFX_*`, `DOF*`, `PrelitLuminance_*`,
`Window*`, `WindStrength` ...), not described here.

| Object | Miami: start to end, colour | Islands: start to end, colour |
| :--- | :--- | :--- |
| `..._clear_4` | 20 to 800, (23, 28, 40) | 20 to 700, (25, 30, 40) |
| `..._clear_9` | 25 to 800, (245, 240, 160) | 20 to 800, (205, 200, 132) |
| `..._clear_12` | 25 to 900, (200, 200, 150) | 20 to 800, (190, 190, 145) |
| `..._clear_18` | 25 to 800, (227, 223, 105) | 20 to 800, (217, 213, 100) |
| `..._clear_21` | 20 to 800, (50, 35, 33) | 20 to 800, (65, 45, 43) |
| `..._clear_24` | 20 to 800, (20, 25, 32) | 20 to 600, (20, 25, 32) |
| `..._rainy_4` | 10 to 525, (16, 16, 17) | 2 to 550, (16, 18, 21) |
| `..._rainy_9` | 20 to 700, (35, 35, 23) | 2 to 500, (36, 40, 35) |
| `..._rainy_12` | 20 to 700, (35, 35, 28) | 2 to 550, (35, 35, 33) |
| `..._rainy_18` | 20 to 600, (35, 35, 21) | 2 to 500, (44, 43, 35) |
| `..._rainy_21` | 20 to 700, (26, 21, 21) | 2 to 500, (28, 21, 21) |
| `..._rainy_24` | 10 to 500, (14, 14, 16) | 2 to 550, (14, 16, 18) |

**The key hours.** The script object `tod` (class `todobject`) in `packages/z04/miami_lod.p3d` (a Script
Object Data chunk with its properties, see [Maps](#maps)) has six keys, N = 0 to 5:

| Property | What |
| :--- | :--- |
| `prelitluminancetime_N` | the key's hour: 4, 9, 12.0, 18.0, 21.0, 24.0 |
| `attachedclearenvparamname_N`, `attachedrainyenvparamname_N` | the names of that hour's two `EnvironmentObject`s, for example `environment_clear_4` and `environment_rainy_4` |
| `timetohold_N`, `timetotransit_N` | 0, 20, 0, 40, 120, 40 and 200, 360, 700, 340, 260, 200; how they turn into time isn't known |

The same object sets the starting time (`settimeofdayhour` 18, `settimeofdayminute` 00), the clock's speed
(`timeofdayspeed` 2000), `pausetimeofday` 0, and the weather: `enableraining` 0, `rainpercentage` 1,
`rainstarttransitframes` 50, `rainendtransitframes` 50.

The game draws plain linear fog by distance from the camera along the view direction (depth), from the start
to the end distance, in the fog colour. The sky, the night lights and decals are drawn without fog.

`portal/tools/fog.py` gives the fog for an hour and a weather: it decompiles the script with the
repository's own decompiler (or reads a decompiled `.cs`), takes the `EnvironmentObject`s' fog properties,
and blends in a straight line by the clock between the two key hours around the hour (the plain reading of
the keys, since hold and transit aren't understood). The hours go round: 24 is also 0, so 2 a.m. lies between
the 24 and the 4 key. The compiled scripts store names hashed ([Scripts](#scripts-cso-dso-dtr)), so `fog.py`
matches the properties and objects by their hash and needs no name recovery. For the islands (`--islands`,
with `island_envobjects.cso`) it looks for each linked name with `island_` in front too.

```
python portal/tools/fog.py packages/z04/miami_lod.p3d scriptc/graphanims.cso --hour 15
python portal/tools/fog.py packages/z04/miami_lod.p3d scriptc/graphanims.cso --hour 2 --weather rain
```

It prints the fog as JSON: `enabled`, `start`, `end`, `color` (red, green and blue, each over 255), `alpha`
and `clamp` (as the objects have them), the two objects blended (`keys`) and how far from the first to the
second (`blend`). Clear weather in Miami, as a check: noon is 25 to 900 m in (200, 200, 150), 4 a.m. 20 to
800 m in (23, 28, 40), 9 a.m. 25 to 800 m in (245, 240, 160); rain at noon is 20 to 700 m in (35, 35, 28).

### The sea

From [SPEC-002](cleanroom/SPEC-002-materials-ocean-shadows.md), like [Shaders](#shaders). No `.p3d` holds the
sea's shape: the program makes it. Its settings are in two compiled scripts:

| Script | Creates |
| :--- | :--- |
| `scriptc/templates/ocean.cso` | three `oceanTemplate`s (`OceanTemplateDefault`, `OceanTemplateNightDefault`, `OceanTemplateRiver`), fifteen `OceanTuningTemplate`s (`OceanTuningTemplateDefault`, `...Wave45`, `...Light`, `...Calm`, `...Ripples` ...) and a `waketemplate` |
| `scriptc/missions/z04/objects_static.dso` | the one sea: `OceanObject("Ocean")` with `position = "0 0 0"`, `oceanTemplate = "OceanTemplateDefault"`, `tuningTemplate = "OceanTuningTemplateDefault"` and `RoomIndex = 1` |

| Property | The object | The templates |
| :--- | :--- | :--- |
| `DetailTextureName` | | `water_01.BMP` (`OceanTemplateNightDefault`: `water_night_01.BMP`) |
| `FoamTextureName` | | `Water_Ocean_Foam.tga` |
| `ReflectionTextureName` | | `skyTexture`: not a texture in the files, the program draws the reflection into it |
| `OceanModelName` | | `OceanModel` (`ModelInventory = "Common"`; there is no such model in `Common.p3d`) |
| `DetailOpacity` | 0.225 | 0.225 |
| `DetailTextureScale` | 0.075 | 0.2 |
| `ReflectionRedScale`, `...GreenScale`, `...BlueScale` | 0.50 each | 0.25, 0.23, 0.25 |
| `ReflectionAlphaScale` | 1.0 | 0.98 |
| `FoamMinHeight`, `FoamMaxHeight`, `FoamMaxOpacity` | 0.15, 1.0, 1.0 | |
| `MinWaveLength`, `MaxWaveLength` | | 0.1, 12.0 |
| `AmplitudeRatio` | | 0.0130 |
| `WindDirectionMean`, `WindDirectionVariance` | | 90.0, 30.0 |
| `speedScaleFactor` | | 1.2 |

The template values are `OceanTemplateDefault`'s and `OceanTuningTemplateDefault`'s. `Common.p3d` holds the sea's
two shaders and their textures: `ocean_text` (`simple`, `water_01.bmp`) and `ocean_foam` (`simple`, `LIT` 1,
`Water_Ocean_Foam.tga`).

What the game does with them *(reported)*:

* The sea is a flat plane at height 0. There is no sea-level setting anywhere.
* At start the tuning template's look replaces the object's: the reflection tint (0.25, 0.23, 0.25), alpha 0.98,
  detail opacity 0.225 and detail scale 0.2, not the object's 0.5 and 0.075. The foam values are the object's.
* It is drawn see-through (alpha 0.98: 2 % of the sea bed shows), writing depth, and fogged like the world, so at
  the horizon it takes the fog's colour. It is never culled, and the PC draws it in one pass.
* It shows the sky reflected in it, tinted by the reflection scales; `water_01.bmp` laid over at `DetailOpacity`,
  repeating about every 5 m (scale 0.2); an animated ripple pattern; foam on the higher waves.
* The waves are tiny: sixteen wave trains, each with a wavelength between `MinWaveLength` and `MaxWaveLength` (the
  shorter ones far more common), an amplitude of the wavelength times `AmplitudeRatio` (at most about 16 cm),
  heading `WindDirectionMean` give or take `WindDirectionVariance` degrees, moving at deep-water speed times
  `speedScaleFactor`. Only four of them move the surface on the PC. For a still picture, the sea is flat.
* Trigger volumes in z04 switch the tuning to `OceanTuningTemplateLight` or `...Calm` in some places; the other
  templates aren't used by the shipped data.

The exports don't read these scripts yet: `p3d_gltf.py` keeps the PC values above (`OCEAN`) and makes the sea
from them ([Exporting to Blender](#exporting-to-blender)).

### Shadows

From [SPEC-002](cleanroom/SPEC-002-materials-ocean-shadows.md), like [Shaders](#shaders).

| Id | Chunk | Data |
| :--- | :--- | :--- |
| `0x08800008` | Shadow (`ShadowLoader`) | name, the composite drawable's name, u32 building shadow (1 or 0), u32 (0 in every one), f32 (0.0 in every one), f32 (200.0 for buildings, 15.0 for `NPC_shadow`). What the last three mean isn't known |

There are 44 in the city, all read to the last byte with these fields: 43 building shadows
(`DevilsCay_02_shadow` ...) and `NPC_shadow`. The building shadows' composites are made of Shadow Mesh
(`0x0001001A`) parts: closed shells the program stretches away from the sun to darken what lies behind them
*(reported)*. They are never drawn as surfaces, and the exports leave them out. `p3d.py` reads the record.

**Shadow decals.** 410 meshes have a primitive group whose shader is of the `shadowdecal` kind: 408
`collapsedMesh_..._details_...` meshes of the city's detail world geometry, in 47 of the 220 `packages/z04`
files, and `vehicleShadowDecalShape` and `characterShadowDecalShape` in `Common.p3d` (the blob shadows under cars
and people).

* Their shaders are all `BLMD` 1, unlit, with no alpha test, one-sided, and their textures repeat
  (`LocalShader_shadowdecal.TGA_shadowdecal_blmd1_mcbv0_lit0_alpha1_atst0_alum0_2sid0`, `vehicleShadowDecal_SG`,
  `characterShadowDecal_SG`).
* Their textures are pure black, with the shadow's coverage in the alpha: `r_tree_shadow.tga` (128 x 128, in the
  region files), `shadowdecal.TGA` (256 x 256), `lmp_table_001.tga`, `Shadow_vehicle.tga`, `Shadow_character.tga`
  (64 x 64).
* **The PC game shows none of them** *(reported)*. The pass that should put them on screen draws into a scratch
  picture that never reaches the frame. Whether the Xbox shows them isn't known.
* They were meant to darken what is under them by their coverage, two overlapping decals not darkening twice: the
  decals are gathered into one coverage mask, then the frame is darkened by the mask once *(reported)*. Drawn
  simply as black see-through surfaces, one decal looks right and two overlapping ones come out too dark.
* They are drawn only near the camera, like the rest of the detail geometry.

### Exporting to Blender

```
python portal/tools/p3d_gltf.py tony.glb  packages/characters/pc/MCP_BlackSuitTony.p3d --anim art/animations/GEN_Conv_Motion_Toward.p3d
python portal/tools/p3d_gltf.py car.glb   art/vehicles/cabriolet.p3d
python portal/tools/p3d_gltf.py guns.glb  art/stateprops/weapons_test/guns.p3d
python portal/tools/p3d_gltf.py area.glb  "packages/z04/stripmall_01_*.p3d" --map
python portal/tools/p3d_gltf.py miami/    packages/z04 --map --split
python portal/tools/p3d_gltf.py city.glb  packages/z04/miami_lod.p3d --map --hour 12
```

The portal does the same from the game files you copied (its Game files tab; **Copy everything, PC first**
copies them the way these exports like best): **Open** next to any `.p3d` file says what it holds and
offers what fits it (a character with the game's animations from `art/animations`, a file of animations
shown on Tony, a camera with its move, a map file with what its region places on it), and the **In
Blender** box gives a whole map area in one scene, or the whole city, one file per area, in
`extracted/blender/`. **Open in Blender** starts your own Blender with the scene imported and saves it as a
`.blend` beside it; the whole city opens as one scene, every area at its place. A `.glb` you download goes
in with File > Import > glTF 2.0: double-clicked, Blender tries to open it as a `.blend` and says it isn't
a valid Blender file. Characters come with their skeleton as an armature, their skin
weights and each animation (from `--anim` files or the file itself) as an action. Several models in one
file (the 28 guns of `guns.p3d`) are set out side by side. With `--map` each area comes in at its place
in the city, with its placed objects; the shared files the areas need (regions, `miami_lod`, `Common`) are
read from the same folder unless `--library` says where. `--split` writes one `.glb` per area, which line
up when imported together; the low-detail city in `miami_lod.p3d` is left out next to real areas unless
`--lod` is given (then its hull is marked hidden: *The low-detail hull* below). PC, Xbox and PS2 files all
work; textures are decoded on your computer.

**Lights.** With `--map` each area's [lights](#lights) come in too, in a node `<file> lights`, with a node per
light group inside it (its extras give the record's kind). Point and spot lights, and directional lights
without a decay range (the city-wide ones), are glTF lights (`KHR_lights_punctual`) at their place,
directional and spot lights turned the way they shine; a point or spot light's range is its decay range's
outer size (a sphere's radius, a box's or an ellipsoid's largest size). Ambient lights, directional lights
with a decay range (glTF's directional lights have no range, so they would light the whole scene), and lights
that are off or don't add light come in as empty nodes. Every light's node has the game's settings in its
extras: the type, the colour, whether it is on and casts shadows, the decay range, the illumination kind, the
spot cone, the light group's kind and, with `--hour`, the hour. Colours are the game's, each channel over 255.
The game's brightness scale isn't known, so every light gets the same intensity: 2,000 lux for a directional
light and 50,000 candela for a point or spot light, which lights a surface 5 m away as strongly. Change them
in Blender to taste. A spot light keeps glTF's own cone, since which of the game's two angles is which isn't
known. `--hour H` (0 to 24) lights the daylight for that hour from its `LITE` animations; without it the
lights are as the files store them, at midnight. The daylight is in `miami_lod.p3d` and `islands_LOD.p3d`, so
it comes in when those are exported (alone, or with `--lod`).

**The weather.** The clear weather's daylight and the rain's are [alternatives](#lights), so an export is lit
by one of them: clear, as the game starts, unless `--weather rain` says otherwise. The other group's lights
still come in, as empty nodes with their settings in extras and `"dataOnly": true`; the node of each daylight
group says its `weather` in its extras, and the export's report says which group was kept as data only. The
weather also picks the sky and the fog below.

```
python portal/tools/p3d_gltf.py city.glb  packages/z04/miami_lod.p3d --map --hour 18 --weather rain --scripts scriptc
python portal/tools/p3d_gltf.py sky.glb   Common.p3d --hour 7.5 --library packages/z04/miami_lod.p3d
```

**The sky through the day.** Exported as a model, `Common.p3d` gives both skies side by side, or with
`--weather` only that weather's. `--hour` works on it without `--map`. With an hour, the
[sky](#the-draw-order-key-and-the-sky)'s skeleton takes the pose `PTRN_sky` has at frame hour x 10, each
rotation taken along the shorter arc between its keys, so the sun and its billboard joints are where the game
puts them (the billboards themselves are left out, like the light flares). `PTRN_sky` isn't added as an
animation then, so the pose holds. Each sky mesh's vertex colours are its own plus the set its `VRTX_`
animation picks for that hour, blended between the two sets either side of the number, each channel kept to
255; the mesh's extras give the `hour` and the set's number (`colourSet`, with its fraction). Without an hour
the sky is as the file stores it (the sun under the ground, the night colours), with `PTRN_sky` as an
animation that plays the day.

**The fog.** With `--hour` the scene's extras say the hour and the weather and hold the
[fog](#fog-by-time-of-day) of that hour as `fog.py` gives it, when the game's scripts and the `tod` object are
found: the scripts from `--scripts` (the `.cso` files, a folder holding them or a folder with a `scriptc`
folder), or else from the files' own folder or one up to three folders above it, or a `scriptc` folder in
one of those; the `tod` object from `miami_lod.p3d` among the files or the library. Without them the fog is left out and the export says why.
The fog is Miami's, or the islands' when the export's own files are `islands_LOD.p3d` (and not
`miami_lod.p3d`). An export with `--weather` and no hour says the weather in the scene's extras.

**See-through surfaces.** From [SPEC-002](cleanroom/SPEC-002-materials-ocean-shadows.md) ([Shaders](#shaders)).
Every material whose shader blends says how, in its extras: `{"blend": "alpha"}` for `BLMD` 1, `"add"` for 2,
`"darken"` for 3. glTF has only ordinary blending, so the light-adding and darkening surfaces get their picture
made ready for it:

| `BLMD` | In the glTF | In Blender (**Open in Blender**) |
| :--- | :--- | :--- |
| 1 | `BLEND`, or `MASK` with a cut-out | as Blender's importer makes it |
| 2, adds light | `BLEND`. Each pixel's alpha is its brightness (the largest of its red, green and blue) and its colour is divided by that. Blended as usual, black lets what is behind through and the light lies on top of it; where the light is bright, what is behind is dimmed (times 1 minus the brightness) instead of added to | an Emission shader (the picture's colour times its alpha) added to a Transparent BSDF: real additive light |
| 3, darkens | `BLEND`. The picture is black, with an alpha of 1 minus its brightness (luminance): what is behind ends up multiplied by that brightness, the same for red, green and blue | a Transparent BSDF in the colour of that brightness, which multiplies what is behind by it |

The picture's own alpha is used only for a cut-out. A light-adding or darkening material whose picture isn't in
the files is fully see-through, not a dark square.

**Lit or not.** A shader without `LIT` 1 isn't lit by the scene's lights, so its material is unlit
(`KHR_materials_unlit`): one read from the files without `LIT`, and one known only by a name that says `lit0`
(SPEC-002's answers). A shader the files don't have and whose name says nothing is left lit. Blender's importer
makes the unlit ones shadeless, and the portal's 3D view doesn't shade them. The portal's own 3D view (**View here**) draws the
light-adding ones adding.

**Cut-outs.** A shader with `ATST` is glTF's `MASK` at its `ACTH`, or 0.5 when it has none. glTF keeps a pixel
whose alpha is exactly the cut-off; the game (`ACMP` 4) doesn't. A light-adding or darkening cut-out has the
cut-out in its made picture, done as the game does it, and stays `BLEND`.

**Depth.** `"depthWrite": false` marks the materials the game draws without writing depth: the `decal`,
`nightlight` and `shadowdecal` kinds, the light-adding ones and the sky's. **Open in Blender** draws the
see-through ones among them blended in Eevee (blended surfaces don't write depth), every layer shown, and casting
no shadow (in Cycles too, through a Light Path node's *Is Shadow Ray*). The light-adding and darkening ones are
blended too. The other see-through materials stay as the importer makes them. The portal's 3D view draws the
see-through surfaces after the solid ones, far to near by the middle of each part, writing depth unless the
material says not to.

**Leaves.** On the props a map places, an unlit see-through shader without a cut-out comes in twice, on the same
vertices: see-through and marked `"depthWrite": false` (`"leaves": "colour"`, material `<shader> (leaves)`), and
as a cut-out at 228/255 (`"leaves": "depth"`, `<shader> (leaves, solid core)`). That is an approximation of the
game's two passes: the cut-out draws its colour as well as its depth. Where it does, the leaf is nearly opaque,
so it looks the same. The same shader anywhere else (the area's own geometry, a model by itself) comes in once.

**The low-detail hull.** Next to detailed areas (`--lod`), the hull's world geometry is marked
`{"lowDetailHull": true, "hidden": true}`; with `--split`, the hull's own file is marked so too when areas come
beside it. By itself it is `{"lowDetailHull": true}` and shown: then it is the city. Its materials carry
`{"lowDetailHull": true, "fade": [200, 250], "fadeCutoff": 0.0784}`, the game's fade, which the exports don't draw.
Its file's lights are never hidden: the daylight still lights the scene. **Open in Blender** puts the hull in a
collection of its own, *Low-detail hull*, switched off when it is hidden (its tick box in the Outliner brings it
back), and the portal's 3D view leaves hidden nodes out.

**The sea.** A map export (`--map`, a map area or a map file in the portal, not a cutscene) has a node `Ocean`: a
flat surface at height 0, reaching at least 1,000 m past the map on every side, farther than the fog ends (900 m
at the most). It is made of 1 km squares on a grid from 0, 0, so that the seas of different exports line up. Its
material, `ocean_text` (unlit, `BLEND`), is `water_01.bmp` repeating every 5 m (1 over `DetailTextureScale`), laid
at `DetailOpacity` (0.225) over the sea's colour, with an alpha of 0.98. The sea's colour is the reflection's tint
(0.25, 0.23, 0.25) times the sky's colour: the average vertex colour of the weather's sky mesh drawn first (the
highest [draw-order key](#the-draw-order-key-and-the-sky): the clear sky's dome), at the hour with `--hour`, else
as stored (the night). Without `Common.p3d` among the files the sea is the tint itself (times white), without the
picture. The node's extras hold the [settings](#the-sea) (named as in the scripts), `seaColour`, `skyColour`,
`picture`, the weather and the hour. `--no-ocean` leaves it out; with `--split` the areas go without, and one
`ocean.glb` beside them holds the sea for all of them. **Open in Blender** puts it in a collection *Sea*. Not
drawn: the reflection, the ripples, the waves and the foam.

```
python portal/tools/p3d_gltf.py area.glb  "packages/z04/stripmall_01_*.p3d" --map --no-ocean
```

**Shadow decals.** Each primitive group with a `shadowdecal` shader comes in a glTF mesh of its own, in a node
`<mesh> shadow decal` under its mesh's node, or as the mesh's node itself when the mesh is nothing else (the
blobs in `Common.p3d`). The node and the mesh have `{"shadowDecal": true}` in their extras, and so does the
material. They are shown: as black see-through surfaces, each looks right where it doesn't overlap another, and
two overlapping ones come out too dark. The PC game never shows them ([Shadows](#shadows)). **Open in Blender**
puts them in a collection *Shadow decals*, whose tick box hides them all.

**The whole city in Blender.** The portal's city export (the **In Blender** box) also writes `sky.glb` beside
the areas when `Common.p3d` is among the copied files: the weather's sky, centred on the city (the middle of
what the areas fill, at height 0) and made big enough to reach a tenth past the city's farthest corner, and
never smaller than the game's twice. The game doesn't do that: it moves the sky with the camera, so the sky
is always round the viewer, and a scene has no camera to follow. The sky's top node says so in its extras
(`"followsCamera": true`). Beside **Export the city** the page asks for two things, kept for next time with
its other settings:

* **Time of day**: **As stored** (no hour, as before) or a whole hour from midnight to midnight (0 to 24),
  sent to the portal as `hour`. Without an hour the sky is as stored, with `PTRN_sky` to play the day. With an
  hour, the sky is posed and coloured for it, and every file of the city carries that hour's fog, from the
  copied `miami_lod.p3d` and `scriptc/graphanims.cso` (or the scripts copied out into
  `binaries/scripts_and_data/`).
* **Weather**: **Clear** (as the game starts) or **Rain**, sent as `weather`: the rain sky and, with an hour,
  the rain's fog.

The export's status says the time of day and the weather, and when there is no sky or no fog, and why. Every
export makes all the areas and the sky again, and a finished one keeps the hour and weather it was made at
in `made_with.json` beside them (an export stopped part-way leaves a mix, so none). When the city in the
folder is at another time or weather than the one picked, the page says that **Open the whole city in
Blender** opens it that way until it is exported again. A `.blend` saved earlier is opened only when it is
newer than every `.glb`, so after an export the city is brought in afresh. **Open in Blender** reads the
first fog among the files it imports and shows it as the world's mist: from the fog's start, over the
distance to its end, fading in a straight line, with the Mist pass on; the world's colour is the fog colour,
turned from the game's screen colours into Blender's linear ones.

The city export also writes `ocean.glb` beside the areas, which go without a sea each: one sea (**The sea** above)
round the box the areas fill, at the hour and in the weather picked, with `ocean_text`'s picture and the sky's
colour from the copied `Common.p3d` (without it, a plain sea in the tint). Every export makes it again. The page
has no switch for it yet: to go without, delete `ocean.glb` or untick the *Sea* collection in Blender. The export
itself leaves it out when it is asked with `"ocean": false` (and `CityJob.start(..., ocean=False)`). **Open in
Blender** treats the city's files as it does a single export's: the see-through surfaces as the game blends them,
and the shadow decals, the low-detail hull and the sea each in a collection of its own.

A mesh with a [draw-order key](#the-draw-order-key-and-the-sky) carries it in its extras
(`{"drawOrder": 0.3}`), clamped to 0..1 as the game does.

Left out for now: particles and light flares, shadow volumes, collision shapes and state-prop
animations' callbacks; the sea's reflection, ripples, waves and foam, and the low-detail hull's fade.

### Ids seen but not worked out

`0x00010021` (u32 0, then seven u32: 32 on the PC and Xbox, 8 or 16 on the PS2, perhaps the bits each
kind of vertex data is stored in), `0x0001001D` (u32 1, 3, 1, 0 in every mesh), `0x00121008` (u32 2),
`0x00121402` (u32 0, 0), `0x01000001`, the fields of the loaders' chunks not written up above.

## Cutscenes (`art/nis/`)

A cutscene is three things, found by its name (`MNIS_A56_2_Tony_Delivers_the_Goods`):

| Where | What |
| :--- | :--- |
| `art/nis/fsc/<name>.fsc` | Its script, as plain text: nested `{ }` blocks of `key value;` lines. |
| `art/nis/<name>/stream<n>.p3d` | Its animations (`0x121000`), cut into pieces: `<animation>0` in `stream0`, `<animation>1` in `stream1`, and so on. The pieces follow one another. |
| `art/nis/<name>.p3d`, `static.p3d` | Small files for the game's loader. |

The script's blocks that say who is in the scene:

| Block | Says |
| :--- | :--- |
| `NISResourceLoader` | `Name` (what the scene calls someone) and `TemplateName`. A person's model is `art/characters/npc/<TemplateName>.p3d`. |
| `NISCharacterPosition`, `NISObjectPosition` | Where someone stands (`Position`: x, y, z) and the way they face (`Facing`, degrees about the upright axis). |
| `NISCharacterAnimation`, `NISVehicleAnimation` | Which animation they play. `MainCharacter` is Tony. |
| `NISSwapModel` | The suit Tony wears: `tonynisHawaiianDrawable` is `art/nis/characters/tonynisHawaiian.p3d`. |
| `NISSequenceCue` | The camera's animation (`CameraAnimationName`). |
| `NISWeaponAttach` | A weapon put in someone's hand: `WeaponTemplateMetalPipe` is the model `metal_pipe` in `art/stateprops/weapons_test/guns.p3d`, hung on the joint `right_hand_attach`. |

A person's animation moves them from where the script stands them. A vehicle's animation moves one joint,
named after the vehicle's file (`sportfishing_boat` is `art/vehicles/sportfishing_boat.p3d`), in the
city's own coordinates; so does the camera's (its place, the way it looks, which way is up).


Someone the script moves but never loads was already in the game: their template is `CharTemp_<name>`.
A cutscene whose people all stand at 0, 0, 0 has no place of its own (it plays wherever Tony is); the
others happen where the script first stands someone, and the map there is what the
[stream graph](#the-stream-graph) keeps loaded at that spot (its `Shell` and `Detail` packages).

`cutscene.py` reads all of this and makes one scene with everybody in it, on the street or in the room
where it happens; opening any of a cutscene's files in the portal gives the whole cutscene. Not read yet:
props (`NISStatePropSpawn`), effects and sound; faces of people other than Tony whose model the script swaps in (`NISSwapModel`); a weapon hangs on the hand joint as it is, without the
small shift the game gives each weapon.

### Faces: shapes and sliders

Worked out from the PC files (`art/nis/characters/tonynisHawaiian.p3d` and the cutscenes' stream files)
by reading the chunks; `p3d_gltf.py` and `cutscene.py` read them, and the tests check that on made-up files.

A head that can change expression is a skin (`0x10001`) with a set list (`0x121305`, the same container
the map's colour sets use). Each set (`0x121306`: u32 0, a shape's number, a primitive group's number)
holds position offsets (`0x10F00`: u32 0, the four bytes `POS\0`, a count, then per entry a vertex number
and three floats: how far that vertex moves, in the mesh's own space). Tony's cutscene head has 18 shapes.

An expression group (`0x21001`: u32 0, its name, the mesh's name, a count) holds the sliders that work
the shapes. Each expression (`0x21000`) is u32 0, a name (`A___Top_Lip_Up_Down`, `H___Eye_Blink_Left`),
a count, that many slider values and that many shape numbers: the shape that is fully on when the slider
is at that value. A lip slider has a shape at -1 and another at 1; a blink has one, at 1.

A cutscene's script plays a face with `NISExpAnimation` (`CharacterName`, `AnimationName`,
`MixerModelName`: the expression group). The animation (type `EXP`) is in the stream files, cut into
pieces like the others; it has one group per slider, named after it, each with a Float1 channel
(`0x121100`): the slider's value over time. In a glTF export the shapes are morph targets named after
their sliders (Blender: shape keys), and a cutscene's face animation is their weights.

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
| `XADP` | Xbox | Xbox IMA ADPCM: per channel, 36-byte blocks (s16 first sample, u8 step index, u8 0, then 32 bytes = 64 samples, low nibble first). With more channels every 4-byte header comes first, then 4-byte runs of each channel in turn. The cutscenes' sound has six channels: 5.1 (front left and right, centre, low frequency, back left and right) |
| `WMA ` | Xbox | 8 bytes, then a Windows Media Audio (ASF) file; its own header has the real sample rate (the RSD field doesn't) |
| `VAG ` | PS2 | Sony ADPCM: 16-byte frames (shift and filter, flags, 14 bytes = 28 samples); flag 7 ends the sound. With two channels the frames take turns: one of the left, one of the right (checked against the PC's music and movies) |
| `PCM ` | | plain 16-bit samples |
| `RADP` | Xbox prototype | Radical's IMA ADPCM, every sound in the prototype (mostly 24,000 Hz): blocks of 20 bytes per channel. Each channel's s16 step index and s16 sample come first, then 16 rows of one byte per channel; a row gives every channel its low nibble, then every channel its high nibble (32 samples per channel per block). The usual IMA tables, with each step's change `((2 x (nibble & 7) + 1) x step) >> 3` |

## Subtitles (`art/subtitles/<x>/<name>.p3d`)

What each line of speech says, in a Pure3D file named like its sound (`art/sound/rsd/<x>/<name>.rsd`).
One `0x0100500A` chunk per language: u32 length and the language's name (`English`), ended and padded
to 4 bytes, two s32 (-1), u32 the length of the text in UTF-16 units, then the text (UTF-16). The portal
shows them under the sound they go with.

## Videos (`.bik`)

Bink videos (RAD Game Tools): `BIK` + a version letter, u32 file size - 8, u32 frame count, u32 largest
frame size, u32 frame count again, then u32 width and u32 height at `0x14` and `0x18`. The PC's are
1280x720, and the Xbox program carries RAD's Bink library (its `BINK*` sections). Play them with RAD
Video Tools or a player that supports Bink (ffmpeg reads Bink 1). The portal's **Watch** makes each movie
(and the PS2's `.rmv`) into an MP4 once, with your own FFmpeg, and plays it in the page.

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
* the seven u32 of `0x00010014`, and what the PS2 header's flags word and the vehicles' two extra vectors
  per vertex are (tangents, most likely).

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
* The [glTF 2.0 specification](https://registry.khronos.org/glTF/specs/2.0/glTF-2.0.html) (Khronos), which
  `p3d_gltf.py` writes, and its
  [KHR_lights_punctual](https://github.com/KhronosGroup/glTF/blob/main/extensions/2.0/Khronos/KHR_lights_punctual/README.md)
  extension, which the map exports' lights follow, and
  [KHR_materials_unlit](https://github.com/KhronosGroup/glTF/blob/main/extensions/2.0/Khronos/KHR_materials_unlit/README.md),
  which the sea's material uses.
* The clean-room spec [SPEC-001](cleanroom/SPEC-001-lights-sky-streaming.md): the lights, the daylight's
  animations, the draw-order key, the sky and the stream graph; and in its second part one weather at a time,
  the sky through the day (the sun's joint and the sky's colour sets) and the fog by time of day.
* The clean-room spec [SPEC-002](cleanroom/SPEC-002-materials-ocean-shadows.md): the shaders' kinds and
  settings, the blend modes, cut-outs and depth, the props' leaves, the low-detail hull, the sea's scripts, the
  shadow records and the shadow decals; and, in its answers to the implementer's questions, that a shader
  without `LIT` is unlit.
* The [Blender Python API](https://docs.blender.org/api/current/) documentation, for the world's mist that
  shows the fog in Blender, and the shaders, blend modes and collections that show the game's see-through
  surfaces and its groups.

The rest was worked out from the game files and checked against the other versions of the same files: the
`RADP` speech against the PC's Ogg Vorbis copies, the PS2's stereo music and movie sound against the PC's,
the movies' pictures by decoding them, the PS2 rotations against the PC's, the Xbox and PS2 vertex data
against the PC's lists, and the chunk names and the placement records against the Xbox program's own
loaders.
