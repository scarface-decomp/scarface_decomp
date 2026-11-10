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
| [Pure3D](#pure3d-p3d) | `.p3d` | all | `p3d.py` (chunks, models to .obj), `p3d_gltf.py` (models, animations and maps to glTF for Blender), `game_assets.py` (contents), `media.py` (pictures) |
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
read, and `--obj OUT.obj` writes its meshes and skins as plain geometry. `portal/tools/p3d_gltf.py` writes
whole scenes as glTF (`.glb`), which Blender opens with File > Import > glTF 2.0: textured models,
characters with their skeletons, skin weights and animations, guns and cars with their moving parts, and
map areas with everything placed on them ([Exporting to Blender](#exporting-to-blender)).

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
| `0x00121201` | Frame Controller | u32 version, name, 4 characters type (`CAM`, `PTRN` ...), `ANIM`, two u32, then the name of what it drives (a camera) and the animation it plays |
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

### Exporting to Blender

```
python portal/tools/p3d_gltf.py tony.glb  packages/characters/pc/MCP_BlackSuitTony.p3d --anim art/animations/GEN_Conv_Motion_Toward.p3d
python portal/tools/p3d_gltf.py car.glb   art/vehicles/cabriolet.p3d
python portal/tools/p3d_gltf.py guns.glb  art/stateprops/weapons_test/guns.p3d
python portal/tools/p3d_gltf.py area.glb  "packages/z04/stripmall_01_*.p3d" --map
python portal/tools/p3d_gltf.py miami/    packages/z04 --map --split
```

The portal does the same from the game files you copied (its Game files tab; **Copy everything, PC first**
copies them the way these exports like best): **Open** next to any `.p3d` file says what it holds and
offers what fits it (a character with the game's animations from `art/animations`, a file of animations
shown on Tony, a camera with its move, a map file with what its region places on it), and the **In
Blender** box gives a whole map area in one scene, or the whole city, one file per area, in
`binaries/blender/`. **Open in Blender** starts your own Blender with the scene imported and saves it as a
`.blend` beside it; the whole city opens as one scene, every area at its place. A `.glb` you download goes
in with File > Import > glTF 2.0: double-clicked, Blender tries to open it as a `.blend` and says it isn't
a valid Blender file. Characters come with their skeleton as an armature, their skin
weights and each animation (from `--anim` files or the file itself) as an action. Several models in one
file (the 28 guns of `guns.p3d`) are set out side by side. With `--map` each area comes in at its place
in the city, with its placed objects; the shared files the areas need (regions, `miami_lod`, `Common`) are
read from the same folder unless `--library` says where. `--split` writes one `.glb` per area, which line
up when imported together; the low-detail city in `miami_lod.p3d` is left out next to real areas unless
`--lod` is given. PC, Xbox and PS2 files all work; textures are decoded on your computer.

Left out for now: lights, particles and light flares, shadow volumes, collision shapes and state-prop
animations' callbacks.

### Ids seen but not worked out

`0x00010021` (u32 0, then seven u32: 32 on the PC and Xbox, 8 or 16 on the PS2, perhaps the bits each
kind of vertex data is stored in), `0x0001001D` (u32 1, 3, 1, 0 in every mesh), `0x00122000` (u32 0 and a
float, 0.5 or 0), `0x00121008` (u32 2), `0x00121402` (u32 0, 0), `0x01000001`, the fields of the loaders'
chunks not written up above.

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
  per vertex are (tangents, most likely);
* lights (`0x00013000` and its sub-chunks), so map exports can carry them.

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
  `p3d_gltf.py` writes.

The rest was worked out from the game files and checked against the other versions of the same files: the
`RADP` speech against the PC's Ogg Vorbis copies, the PS2's stereo music and movie sound against the PC's,
the movies' pictures by decoding them, the PS2 rotations against the PC's, the Xbox and PS2 vertex data
against the PC's lists, and the chunk names and the placement records against the Xbox program's own
loaders.
