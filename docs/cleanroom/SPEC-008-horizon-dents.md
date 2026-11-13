# Clean-room spec 008: the horizon's colour by the hour, and the cars' dents

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)). The examiner has read published
  notes by a third party whose research was done next to leaked source code. Those notes pointed at two
  chunks that the repository had wrong. Everything below was then read again, in the examiner's own words,
  from the US PC files and the user's own Xbox `default.xbe`. The implementer must not open the notes.
* **What this is:**
  1. the horizon's colour through the day, which the repository says doesn't change;
  2. the vehicles' "two extra vectors per vertex", which `FORMATS.md` guesses are tangents. They are
     **dents**;
  3. two small chunks: a cut-scene package's file entry and the exporter's notes.

  No code, and no function names: the implementer chooses names.
* **How sure:** **[checked]** was read from the US PC files (1.00.2) with the repository's chunk reader and
  texture decoder. **[checked on the Xbox]** was read from `default.xbe` with a disassembler. *(check)*
  marks what is still a reading. If the files or the programs disagree with this spec, they win: fix the
  spec in the same pull request.

---

## 1. The horizon's colour by the hour **[checked]**

### 1.1 What the repository has wrong

SPEC-001 §3.4 and `FORMATS.md` say the two horizon meshes' colour sets are all zero, so "the horizon keeps
its own colours all day". The colour sets are zero, but each set also carries **texture offsets**, and those
move. Over the day they slide the horizon's texture coordinates across a strip of colours, one colour per
hour.

### 1.2 The chunk: `0x00010F01` texture offsets **[checked] [checked on the Xbox]**

It sits next to a colour list (`0x00010F02`, `CLR0`) inside a vertex set (`0x00121306`, under a mesh's
`0x00121305`):

```
u32     version (0)
u32     which    a four-character code: UV0, UV1 or UV2 (the texture-coordinate set it moves)
u32     count
count × { u32 vertex; f32 u offset; f32 v offset }
```

`UV0` is the only code in the US files. The Xbox's vertex-set reader takes `0x00010F00` plus a small
number. It accepts colour lists (`CLR0`, `CLR1`) and texture offsets (`UV0`, `UV1`, `UV2`).

The game adds a set's offsets to the listed vertices' texture coordinates, and it blends between sets as
the mesh's `VRTX` animation moves from one to the next. That is the same way it blends the colour sets
(SPEC-001 §3.4) *(check on the Xbox: the blend itself)*.

### 1.3 Where it's used **[checked]**

107 in the PC files, also in some cut-scene, level and package files not looked at here. The ones looked at:

| Mesh (file) | Sets | Offsets |
| :--- | :--- | :--- |
| `skybox2Shape`, `skybox_horizonShape` (`Common.p3d`) | 2 | set 0: u 0 on every vertex; set 1: u 1.0 |
| `skybox17Shape`, `skybox18Shape` (`Common.p3d`, the cloud layers) | 5, 4 | all 0 |
| `tm_office_tvs7Shape` to `tm_office_tvs12Shape` (`tonyOffice_01_shell.p3d`) | 4 | u 0, 0.67, 0.67, 0.33 |

**The horizon:** both meshes use the `HorizonGradient` shaders and the texture `skyBoxGradHorizon_XB.tga`
(128 × 128). Every vertex sits at u ≈ 0 (−0.004), with v running from the top of the texture to the bottom.
The texture is a strip of colours from left to right, and its alpha rises from 0 at the top to 178 at the
bottom. Sampled across the bottom row:

| u (column / 128) | Colour (R, G, B) |
| :--- | :--- |
| 0 to 0.12 | (39, 51, 71), dark blue |
| 0.12 to 0.25 | (49, 63, 87), blue |
| 0.25, 0.44 to 0.56 | (231, 235, 171), pale cream |
| 0.31 to 0.38, 0.62 | (255, 247, 149), yellow-cream |
| 0.69 to 0.75 | (255, 234, 79), yellow |
| 0.81 to 0.88 | (171, 93, 67), red-brown |
| 0.94 | (74, 44, 34), dark brown |

`VRTX_skybox2Shape` and `VRTX_skybox_horizonShape` are 241 frames at 30 a second, cyclic: the whole day,
driven by the clock (SPEC-001 §1.4). Their channel is an integer channel with keys at frame 0 (set 0) and
frame 240 (set 1), interpolated. So at hour *h* the u offset is about *h* / 24, and the horizon band takes
the colour of the column at *h* / 24: dark blue at night, cream through the morning, yellow in the late
afternoon, red-brown in the evening. The texture coordinates wrap at midnight.

**Tony's office monitors:** `tmTv.bmp` holds pictures side by side; the four sets show one third or another
of it. The animation is 16 frames, not cyclic, with keys at frames 1 to 4 choosing sets 0 to 3, so the
screens change picture.

---

## 2. The cars' dents **[checked] [checked on the Xbox]**

### 2.1 What the repository has wrong

`FORMATS.md` (*Not yet described*) lists "the vehicles' two extra vectors per vertex (tangents, most
likely)". They are a **dent per vertex**: how far each vertex moves, and how its normal turns, when that part
of the car is damaged.

### 2.2 The chunks

Both sit in a mesh piece (`0x00010020`) after its normals, with the same layout as the position list
(`0x00010005`): u32 count, then count × three f32. The count is the piece's vertex count.

| Chunk | What |
| :--- | :--- |
| `0x00010022` | per vertex, how far it moves when dented (an offset from its position, in the mesh's units) |
| `0x00010023` | per vertex, the change to its normal when dented |

A piece that has them carries bit **`0x100000`** in its vertex type: `sedan.p3d`'s pieces are `0x102012`
(position, normal, two texture sets, dents). `p3d.py`'s vertex-type names don't know that bit yet. The Xbox's
mesh-piece reader reads both lists only when the bit is set. It then writes the vectors into the vertex
buffer next to the others, so the dent is applied on the graphics chip *(check: how much of the dent
is used, and where that amount comes from; the vehicle's damage per part is the likely source)*.

### 2.3 What they hold **[checked]**

About 3,950 of each in the PC files, in the vehicles. In `sedan.p3d`, 34 pieces carry them (3,452 vertices):

* **Which parts:** doors, bumpers, hood, trunk and side panels, and a little of the roof and wheels. The
  windows, windscreens, the main body shell and the low-detail mesh have all zeros.
* **How big:** 666 vertices move. The median is 4 cm and the largest 18 cm, against parts about 1 to 2 m
  across.
* **Which way:** 434 of the 666 point against the vertex's normal (inwards), 79 outwards and 153 sideways.
  These are dents pushed into the panel.
* **Normals:** the normal changes are zero where the vertex doesn't move (1,917 of 3,452 are zero), and up
  to 1.0 long where it does.

A remaster can show damage by moving each vertex by *amount* × its offset and turning its normal by
*amount* × its change, with *amount* from 0 (new) to 1 (fully dented).

---

## 3. Two small chunks **[checked]**

* **`0x08800103`, a cut-scene package's file (206 in the files):** a sub-chunk of the cut-scene package
  `0x08800102`. Its layout is text (the file, such as `MNIS_AMB_Ogrady_Owned/static.p3d`), u32 1, then the
  same text again.
* **`0x00007030`, `0x00007031`, `0x00007032`, the exporter's notes:** `0x00007030` holds the text
  `Exported From Maya`. Each `0x00007031` under it is two texts, a name and a value: `ExporterVersion`
  `3.24.11`, `Exported By`, `Exported At` (a date in May 2006), `Maya Version` `4.0.2`, `Maya Scene`. They
  have nothing for the game; tools can show or skip them.

---

## 4. What to build

For the implementer. Choose your own names; keep each step small.

1. **`p3d.py`:** read `0x00010F01` (§1.2), `0x00010022` and `0x00010023` (§2.2), `0x08800103` and
   `0x00007030` to `0x00007032` (§3). Name the vertex-type bit `0x100000`, and give the chunks descriptive
   names in `NAMES`.
2. **FORMATS.md:** replace "the horizon keeps its own colours all day" with §1, and "tangents, most likely"
   with §2. Take both off the *Not yet described* list.
3. **The sky in the exports and the viewer:** slide the horizon meshes' texture coordinates by the hour as
   §1.3, so the horizon band at dusk is red-brown and not the morning's colour.
4. **Cars:** export each vehicle piece's dent as a glTF morph target (positions and normals), named so
   Blender shows it as a shape key, with weight 0. The viewer can then show a damaged car.
5. **Decomp:** the Xbox mesh-piece reader is `sub_00294310` (2,676 bytes) and the vertex-set reader
   `sub_002A88F0`. Their guide entries describe them.

### Questions from the implementer, and answers

*(none yet)*
