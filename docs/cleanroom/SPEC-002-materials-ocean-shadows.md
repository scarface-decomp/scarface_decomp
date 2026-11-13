# Clean-room spec 002: see-through surfaces, the ocean, shadows

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)), from published notes by a
  third party whose research was done next to leaked source code. The examiner read those notes; the
  implementer must not.
* **What this is:** a description of the game's *files* and of what the game *does* with them, in the
  examiner's own words. No code, and no names except ones this repository already has or text stored in
  the game's files (shader kinds, shader settings, script objects and their properties, file names).
* **How sure:** **[checked]** statements were read back from the PC game files on 2026-11-12, with this
  repository's own tools (`p3d.py`, `p3d_gltf.shader_info`, `media.py`, `torque_script.py decompile`) and
  small scripts that only count and average. **[reported]** statements describe what the PC program does;
  they come from the research and can't be checked from the files alone. *(check)* marks what is still
  open. If the files disagree with this spec, the files win: fix the spec in the same pull request.

Numbers like "of 5,393" are over every shader in `packages/z04/*.p3d` and `art/ecoprops/*.p3d`.

---

## 1. Shader settings and how see-through surfaces are drawn

### 1.1 What the shaders carry **[checked]**

A shader (`0x00011000`) names a **kind** (the "pddi shader" `p3d_gltf.shader_info` returns as `pddi`) and
carries integer settings (`0x00011003`), float settings and textures. The kinds in the city's files:

| Kind | How many | What uses it |
| :--- | ---: | :--- |
| `simple` | 4,278 | most of the world, props, the sky, the sun's flares, the ocean (`ocean_text`, `ocean_foam`) |
| `cbvlit` | 654 | world surfaces lit by their vertex colours |
| `decal` | 235 | grime, cracks, arrows, signs, light glows laid over other surfaces |
| `layered` | 111 | two textures blended (`TBLM`, `CLYR` settings) |
| `nightlight` | 53 | lit windows and signs (textures named `..._win_Add_...`, `l_sign.bmp`) |
| `shadowdecal` | 24 | shadows painted on the ground (§3) |
| `foam` | 14 | shore and wake foam (`ShoreGradient.tga`, `Boat_wakeFoam`) |
| `specular` | 13 | roads and pavements with a shine texture |
| `environment` | 6 | reflections laid over glass (`g_reflection.tga`, `r_lt_reflection.bmp`) |
| `vertexfade` | 4 | the low-detail hull of the city and the islands (§1.6) |
| `untextured` | 1 | |

The settings that matter here (their four-letter names are in the files):

| Setting | Seen | Meaning |
| :--- | :--- | :--- |
| `BLMD` | 0 or absent (opaque), 1 (1,456), 2 (325), 3 (18) | how the surface is combined with what is behind it, §1.2 |
| `ATST` | 1 in 555 shaders, never 0 | cut out the pixels whose alpha fails a test, §1.3 |
| `ACMP` | 4 in all 555 with `ATST` | the comparison for that test, §1.3 |
| `ACTH` (float) | in 55 of them: 0.01, 0.054, 0.07, 0.2, 0.3, 0.6, 0.65, 0.7, 0.8 | the alpha the test compares against, §1.3 |
| `2SID` | 1 in 900, 0 in 4,328 | drawn from both sides |
| `UVMD` | 0 in all 5,318 that have it | textures repeat (wrap) |
| `LIT` | 1 in 2,084 (absent elsewhere) | lit by the scene's lights |
| `ZWRT`, `ZTST` | 0 in 54 shaders, all in `art/ecoprops` | **ignored by the PC game [reported]**: an export should ignore them too |

The shader names spell most of these out (`..._decal_blmd2_mcbv0_lit0_alpha1_atst0_alum0_2sid0`), as
FORMATS.md says; the settings chunks are what the game reads.

### 1.2 The blend modes

* **`BLMD` 1: ordinary see-through.** The texture's alpha mixes it with what is behind (the usual "source
  alpha, one minus source alpha") **[reported]**.
* **`BLMD` 2: adds light [checked from the textures].** Used by the sun's flares and lens rings
  (`Flare_Star_xb.bmp`, `Ring_B_128_xb.tga`, `LENS03.bmp`, `sun_02.bmp`), light glows
  (`lightGlowWhite.bmp`, `Glow_A_16x.bmp`), boat lights, the `nightlight` windows (`r_lh_win_Add_06.tga`,
  `r_dt_win_Add_02.tga`) and one tunnel lighting texture. Their textures are **fully opaque (alpha 255
  everywhere) and mostly pure black** (40 to 87 % of their pixels are black), with the light drawn in
  colour on top: the black adds nothing, the light adds itself to what is behind. Drawn with ordinary
  alpha blending, they come out as black squares.
* **`BLMD` 3: darkens [checked from the textures], exactly how is not known *(check)*.** Used by the
  skid marks (`SkidMark_Asphalt.bmp`, `_Dirt`, `_Grass`, `_Sand_ver2`), grime (`grime.tga`,
  `r_lc_grime1.bmp`) and `r_tonymsn_shadow_circle.bmp`. The skid textures are opaque and dark (average
  3 to 19 out of 255); `grime.tga` is mid grey (125) with alpha 175. Multiplying what is behind by the
  texture is the reading that fits all of them.

### 1.3 Cut-outs (the alpha test)

* With `ATST` 1 a pixel is drawn only if its alpha passes the test; pixels that fail are not drawn at
  all and leave no depth **[reported]**.
* `ACMP` 4 is "greater than" (the PC program turns it into Direct3D's `D3DCMP_GREATER`). Without `ACMP`
  the test would be "greater or equal" **[reported]**.
* The value compared against is **`ACTH` when the shader has it, otherwise 0.5** **[reported]**. The
  repository's exporter uses 0.5 for every shader today; 55 shaders want another value (§1.1), from 0.01
  (keep almost everything) to 0.8.

### 1.4 Depth: what hides what **[reported]**

* Ordinary see-through world surfaces (`BLMD` 1 on the `simple`, `cbvlit` and similar kinds) are drawn
  after the solid ones, **sorted from far to near, and still write depth**.
* These are drawn **without writing depth**, so they never hide anything drawn after them: the `decal`
  kind, the light-adding surfaces (`BLMD` 2), the `nightlight` windows, the sky, and the shadow decals
  (the `shadowdecal` kind turns depth writing off itself).
* A `decal` with `BLMD` 1 also drops pixels whose alpha is exactly 0, and decals are drawn **without
  fog**.

### 1.5 Leaves on the props **[reported]**

The trees and bushes the city places as props (`art/ecoprops`, drawn many times over) use unlit
see-through shaders (`BLMD` 1, no `LIT`, no `ATST`; typically `..._simple_blmd1_..._alpha1_atst0_alum1_2sid1`).
The game draws them **twice**: once for colour, blended, **without writing depth**; and once more writing
**depth only, and only where the alpha is at least 228 out of 255** (0.894). So the solid core of each
leaf hides what is behind it, while the soft, see-through edges never cut holes into the leaves behind
them. The same applies only to unlit `BLMD` 1 shaders on such props; lit ones are drawn once.

### 1.6 The low-detail hull **[checked: the shaders] [reported: the fade]**

`miami_lod.p3d` and `islands_LOD.p3d` hold a coarse copy of the whole city and the islands, drawn with
the `vertexfade` kind (4 shaders: `pure3dVertexFadeShader1` in `miami_lod.p3d`; `RockShader`,
`islands_LOD_pure3dVertexFadeShader1`, `pure3dVertexFadeShader3` in `islands_LOD.p3d`; all `BLMD` 1,
`LIT` 1). The game **fades it out towards the camera: fully see-through nearer than about 200 m, fully
there beyond about 250 m**, and it cuts out every pixel whose alpha is below 20 out of 255. So close up
it is invisible, and it only stands in for the detailed areas far away. Shown solid next to the detailed
areas, it is a shell that covers them (trees, hedges and the boathouse at Tony's island disappear
inside it).

---

## 2. The ocean

### 2.1 Where it comes from **[checked]**

No `.p3d` holds the sea's shape: it is made by the program. Its settings are compiled scripts:

* `scriptc/templates/ocean.cso` creates the templates: three `oceanTemplate`s
  (`OceanTemplateDefault`, `OceanTemplateNightDefault`, `OceanTemplateRiver`) and fifteen
  `OceanTuningTemplate`s (`OceanTuningTemplateDefault`, `...Wave45`, `...Wave145`, `...Wave180`,
  `...WaveNeg45`, `...Light`, `...River`, `...RiverR`, `...RiverD`, `...RiverV`, `...RiverDU`, `...Calm`,
  `...Churn`, `...Boundary`, `...Ripples`), plus a `waketemplate`.
* `scriptc/missions/z04/objects_static.dso` creates the one sea: `OceanObject("Ocean")` with
  `position = "0 0 0"`, `oceanTemplate = "OceanTemplateDefault"`,
  `tuningTemplate = "OceanTuningTemplateDefault"`, `DetailTextureScale = "0.075"`, `DetailOpacity =
  "0.225"`, `ReflectionRed/Green/BlueScale = "0.50"`, `ReflectionAlphaScale = "1.0"`, `FoamMinHeight =
  "0.15"`, `FoamMaxHeight = "1.0"`, `FoamMaxOpacity = "1.0"`, `RoomIndex = 1`.
* `OceanTemplateDefault`: `ModelInventory = "Common"`, `OceanModelName = "OceanModel"` (no such model
  exists in `Common.p3d`), `ReflectionTextureName = "skyTexture"` (not a texture in the files: the
  program draws the reflection into it), `DetailTextureName = "water_01.BMP"`, `FoamTextureName =
  "Water_Ocean_Foam.tga"`. The night template differs in `water_night_01.BMP`.
* `OceanTuningTemplateDefault`: `MinWaveLength = ".1"`, `MaxWaveLength = "12.0"`, `AmplitudeRatio =
  "0.0130"`, `WindDirectionMean = "90.0"`, `WindDirectionVariance = "30.0"`, `speedScaleFactor = "1.2"`,
  `ReflectionRedScale = "0.25"`, `ReflectionGreenScale = "0.23"`, `ReflectionBlueScale = "0.25"`,
  `ReflectionAlphaScale = ".98"`, `DetailOpacity = "0.225"`, `DetailTextureScale = "0.2"`.
* `Common.p3d` holds the sea's two shaders: `ocean_text` (`simple`, texture `water_01.bmp`) and
  `ocean_foam` (`simple`, `LIT` 1, texture `Water_Ocean_Foam.tga`), and both textures.

### 2.2 What the game does with them **[reported]**

* **The sea is a flat plane at height 0** (y = 0 in the game's coordinates). There is no sea-level
  setting anywhere; the object's position is 0 0 0.
* At startup the tuning template's look **replaces** the object's: the sea uses the template's
  reflection tint (0.25, 0.23, 0.25) and alpha 0.98, detail opacity 0.225 and detail scale 0.2, not the
  object's 0.5 and 0.075. The foam values are the object's.
* It is drawn **see-through (alpha 0.98, so 2 % of the sea bed shows), writing depth, and fogged like
  the world**, so at the horizon it takes the fog's colour. It is never culled.
* What it looks like: the sky reflected in it, tinted by the reflection scales; the detail texture
  `water_01.bmp` laid over at `DetailOpacity`, repeating about every 5 m (scale 0.2); an animated ripple
  pattern; foam on the higher waves. The PC game draws it in a single pass.
* **The waves are tiny.** Sixteen wave trains, each with a wavelength between `MinWaveLength` and
  `MaxWaveLength` (0.1 to 12 m; the shorter ones far more common), an amplitude of wavelength ×
  `AmplitudeRatio` (at most about 16 cm), heading `WindDirectionMean` ± `WindDirectionVariance` degrees,
  moving at deep-water speed × `speedScaleFactor`. Only four of them move the surface on the PC. For a
  still picture, the sea is flat.
* Trigger volumes in z04 switch the tuning to `OceanTuningTemplateLight` or `...Calm` in some places;
  the rest of the templates are not used by the shipped data.

---

## 3. Shadows

### 3.1 Shadow decals **[checked: the data] [reported: what the PC shows]**

* **Where:** 410 meshes have a primitive group (`0x00010020`) whose shader is of the `shadowdecal` kind:
  408 `collapsedMesh_..._details_...` meshes of the city's detail world geometry, in 47 of the 220
  `packages/z04` files, plus `vehicleShadowDecalShape` and `characterShadowDecalShape` in `Common.p3d`
  (the blob shadows under cars and people).
* **Their shaders:** all `BLMD` 1, unlit, no alpha test, one-sided, `UVMD` 0 (the shadow textures
  repeat), e.g. `LocalShader_shadowdecal.TGA_shadowdecal_blmd1_mcbv0_lit0_alpha1_atst0_alum0_2sid0`,
  `vehicleShadowDecal_SG`, `characterShadowDecal_SG`.
* **Their textures are pure black with the shadow's coverage in the alpha**: `r_tree_shadow.tga`
  (128 × 128, in the region files, e.g. `bridge_01_detail.p3d`), `shadowdecal.TGA` (256 × 256),
  `lmp_table_001.tga`, `Shadow_vehicle.tga`, `Shadow_character.tga` (64 × 64): every pixel has red, green
  and blue 0.
* **What the PC game shows: none of them [reported].** The pass that should put them on screen draws
  into a scratch picture that never reaches the frame, on the PC build. Whether the Xbox build shows them
  is not known *(check)*.
* **What they were meant to do [reported]:** darken what is under them by their coverage, with
  overlapping decals not darkening twice (the decals are first gathered into one coverage mask, then the
  frame is darkened by the mask once). Drawn simply as black see-through surfaces, one decal looks
  right, and two overlapping ones come out too dark.
* They are drawn only near the camera, like the rest of the detail geometry.

### 3.2 Shadow records and shadow volumes **[checked]**

* `0x08800008` (`ShadowLoader`): name (text), composite drawable name (text), u32 building shadow (1 or
  0), u32 (0 in every one), f32 (0.0 in every one), f32 (200.0 for buildings, 15.0 for `NPC_shadow`).
  There are 44 in the city: 43 building shadows (`DevilsCay_02_shadow` ...) and `NPC_shadow`. All read to
  the last byte with these fields.
* The building shadows' composites are made of Shadow Mesh (`0x0001001A`) parts: closed shells the
  program stretches away from the sun to darken what lies behind them **[reported]**. They are never
  drawn as surfaces. The repository's exporter already leaves them out; keep it that way.

---

## Suggested work for the implementer

In priority order; tests on made-up files, as for SPEC-001.

1. **Blend modes in the exports (§1.2):** `BLMD` 2 surfaces must not come out as black squares. glTF
   has no "add" mode, so pick a faithful stand-in and say which in FORMATS.md: for example see-through
   with the texture's brightness as its alpha, or an emissive texture; record the game's mode in the
   material's `extras` (e.g. `{"blend": "add"}`), and have the Blender scene the repository builds use a
   real additive shader for them. `BLMD` 3 the same way, as darkening (`{"blend": "darken"}`), with a
   multiply in Blender.
2. **Cut-outs (§1.3):** the alpha cutoff is `ACTH` when the shader has it, else 0.5.
3. **Depth (§1.4, §1.5):** record in `extras` which materials the game draws without writing depth
   (`decal`, `nightlight`, `shadowdecal`, `BLMD` 2), and use it where the repository controls drawing
   (the Blender scene's material settings, the portal's in-page viewer if it is simple to do). For the
   props' leaves (§1.5), an approximation is fine; say what it is.
4. **The low-detail hull (§1.6):** when an export puts the low-detail files next to detailed areas
   (`--lod`, the whole city), keep the hull from covering them: for example leave it out where detailed
   areas are present, or give it its own group that the Blender scene hides; mark its materials in
   `extras`.
5. **The ocean (§2):** map and city exports get the sea: a large flat surface at height 0 reaching past
   the city on every side, with a material made from `ocean_text` / `water_01.bmp` repeating about every
   5 m at the template's detail opacity over a sea colour (the reflection tint times a sky colour; with an
   hour, the sky colour of that hour from SPEC-001 is a good choice), alpha 0.98, its settings in
   `extras`. A way to leave it out.
6. **Shadow decals (§3.1):** mark them (`extras`, e.g. `{"shadowDecal": true}`) and put them in their own
   group, so the Blender scene can show or hide them; say in FORMATS.md that the PC game never shows them.
   Keep them on by default unless that turns out to look wrong.
7. `docs/FORMATS.md`: the shader kinds and settings, the blend modes, the ocean's scripts, the shadow
   records (`0x08800008` fields) and decals, in the house style; credit this spec.

---

## Questions from the implementer, and answers

Asked on 2026-11-12; answered by the examiner from the PC files where they could be.

| Question | Answer |
| :--- | :--- |
| `BLMD` 3: does the picture's alpha take part, and is the darkening per colour channel? | Not known *(check)*. Darkening by brightness, with the alpha only for a cut-out, is a fair reading. |
| `BLMD` 2: does the picture's alpha matter; are lit ones lit before they are added? | Every light-adding picture checked is fully opaque (alpha 255 everywhere), so for them it makes no difference. Only one light-adding shader is lit (`r_tunnel-lighting.tga`, `cbvlit`); how the game lights it is not known. |
| Is a shader without `LIT` unlit? | **Yes [checked].** In `packages/z04`, every shader whose name says `lit0` has no `LIT` setting (2,802 of them) and every one whose name says `lit1` has `LIT` 1 (2,043); none says `lit1` without it. So a shader read from the files without `LIT` is not lit by the scene's lights, and should export as unlit, like a name that says `lit0`. |
| The sea's colour with no hour, and in rain? | Not in the files. The sky as stored (its night colours) with no hour, and the rain sky in rain, are fair readings. |
| When is `OceanTemplateNightDefault` used? | `objects_static.dso` names only `OceanTemplateDefault`; when, if ever, the game switches is not known. |
| The hull's fade: along the view or by distance, and is the 20/255 cut after the fade? | Not known *(check)*. |
| Which props get the leaves' two passes? | The ones the city places (instance objects); that is the same set as the `art/ecoprops` models. |
| Is the sky's dome drawn without writing depth too? | Yes: the whole sky is drawn with depth testing and writing off (SPEC-001 §3.2). |
