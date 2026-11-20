# Clean-room spec 010: cutscene effects, particle systems, gun fire, fades and grips

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)), on 19 November 2026, answering the
  implementer's seven questions. The outside research has next to nothing on particles or cutscene effects,
  so everything below was read from the user's US PC files and the user's own Xbox `default.xbe`, in the
  examiner's own words. The implementer must not open the research.
* **What this is:**
  1. where effects are defined, and the particle system chunk `0x1580C` and everything under it;
  2. what the cutscene's `NISCharacterEffect` does, and how long its effects last;
  3. gun fire in cutscenes (`NISWeaponFire`): muzzle flash, casings, tracers, `IsSecondaryWeapon`;
  4. blood and bullet marks left behind;
  5. `NISFade`;
  6. a scene prop before its animation's first key (the closet doors);
  7. two-handed grips;
  8. the disco ball (SPEC-009 §1.5);
  9. the Xbox functions read.

  No code, and no names from the research. Class names are the game's own, from the Xbox program's run-time
  type information; function names are the work queue's; field names are the game's own script text.
* **How sure:** **[checked]** read from the PC files; **[checked on the Xbox]** read from `default.xbe` with a
  disassembler; *(check)* not yet confirmed. If the files or the program disagree, they win: fix the spec in
  the same pull request.

The game's compiled scripts can be read with the repository's own decompiler
(`portal/tools/cso_dso_dtr_decompiler.py`, names from `torque_script.names_for`). Several answers below come
from `scriptc/effects.cso`, `scriptc/templates/effects.cso` and `scriptc/templates/weapons.cso`; the
template scripts are also carried inside `packages/InGameLoadTemplates.p3d` (chunk `0x8800104`, one per script).

---

## 1. Effects and particle systems

### 1.1 Where effects live [checked]

All the game's particle effects are in **`packages/z04/Common.p3d`**: 123 particle systems (`0x1580C`) and
the composite drawables (`0x123000`) that wrap them. Two names are in use for the same effect:

| Name form | What it is | Example | Who uses it |
|---|---|---|---|
| `<x>Shape` | the particle system chunk itself | `fxSys_Blood_HeadshotShape` | the effects template (§2), the weapon decal templates |
| `<x>` (no `Shape`) | a composite drawable whose part (kind 4) is that system, or several parts | `epDebris_Wood` → part `fxSys_Debris_WoodShape` | prop state effects (`0x0802000B`), weapon prop states (§3) |

A composite can hold more than one part. `fxSys_Rifle_MuzzleFlash` has the particle system plus two billboard
groups (`fx_MuzCentreFlashShape`, `fx_XflashShape`, kind 8) and a frame controller; `fx_tracer` is two
meshes. The composite's skeleton places each part (SPEC-005).

The effect names that prop states use, and their systems [checked]:

| Prop effect | Particle system |
|---|---|
| `epDebris_Wood` | `fxSys_Debris_WoodShape` |
| `fxSys_Grenade_Wood` | `fxSys_Grenade_WoodShape` |
| `epExplosion_Smoke` | `Explosion_SmokeShape` |
| `epExplosion_Generic` | `Explosion_GenericShape` |
| `epSmoke_Lingering` | `fxSys_SmokeLingerShape` |
| `epFire_Burning` | `fxSys_BurningFireShape` |
| `epFire_BurningStop` | `fxSys_BurningStopShape` |
| `epDebris_Dust` | `fxSys_Generic_Dust_PuffShape` |
| `epDebris_Metal` | `fxSys_Debris_MetalShape` |
| `epDebris_Sparks` | `fxSys_Debris_SparksShape` |

How a cutscene `EffectType` reaches its system is in §2.1.

### 1.2 The tree under a particle system

```
0x1580C  particle system
  0x15900  emitter            (one or more)
    0x121000  animation "SPAR"   per-particle curves over a particle's life
    0x121000  animation "SPEM"   the emitter's settings over the effect's time
    0x15B00 / 0x15B01 / 0x15B02  generator: point / plane / sphere
      0x121000  animation "PPTG" (point) or the plane's / sphere's own   the generator's settings over time
    0x10003, 0x10004          bounding box and sphere (always zero in Common.p3d)
  0x122000  sort value
  0x121201  frame controller, type "PSYS", naming the system
  0x10003, 0x10004            bounding box and sphere
```

The animations are ordinary animations (SPEC-005 layout); their channels are listed in §1.4 to §1.6.

### 1.3 The particle system chunk `0x1580C` [checked; reader checked on the Xbox]

| Field | Type | Meaning |
|---|---|---|
| version | u32 | 0 |
| name | text | e.g. `fxSys_PistolUzi_MuzzleFlashShape` |
| frame rate | f32 | 30 in every system |
| length | u32 | the effect's length in its frames (5 for a muzzle flash, 60 for `fxSys_Grenade_PersonShape`) |
| loops | u32 | 1 or 0 (below) |
| sphere | 4 × f32 | centre and radius; always (0, 0, 0, −1) |
| offset | 3 × f32 | always 0 |
| emitter count | u32 | number of `0x15900` children |

**Loops:** 54 systems have 1 and 69 have 0. The 1s are the effects that go on (burning fire, lingering
smoke, water streams, exhausts, rain, boat wakes, muzzle flashes, casings); the 0s are one-shots (impacts,
explosions, debris, blood, `epFire_BurningStop`). Read as "the effect's time wraps at its length" *(check: the
pattern is clear in the data; the code only stores it as a flag on the system)*.

Children: `0x122000` is a u32 (0) and an f32 kept between 0 and 1 (0.5 in the muzzle flash): a sort value
*(check what it sorts)*. `0x121201` is the system's frame controller; its frames drive everything below.

### 1.4 The emitter chunk `0x15900` [checked; reader checked on the Xbox]

| # | Field | Type | Meaning |
|---|---|---|---|
| 1 | version | u32 | 0 |
| 2 | name | text | e.g. `fx_FlareShape` |
| 3 | shader | text | a shader (`0x11000`) in the same file, e.g. `PistolUziMuzz_Flare` |
| 4 | mode word | u32 | how particles turn, change texture, change colour and move (below) |
| 5 | — | u32 | always 1 (meaning not found) |
| 6 | — | u32 | always 0 (meaning not found) |
| 7 | most particles | u32 | how many can be alive at once (3 to 100) |
| 8 | — | u32 | always 0 (meaning not found) |
| 9 | texture frames | u32 | how many pictures side by side in the texture (1, 2 or 4) |
| 10 | texture frame time | u32 | frames each picture lasts, for the cycling modes (1, 50 or 100) |
| 11 | start angle | f32 | each particle's starting turn, in radians |
| 12 | start angle spread | f32 | ± random added to it (π in most emitters) |
| 13 | follow movement | f32 | 0 to 1: how much of the emitter's movement live particles share (1 for muzzle flashes) |
| 14 | follow turning | f32 | 0 to 1: the same for the emitter's turning |

**The mode word** is one number made of four parts. Let *a* = word mod 3, and *w* = word ÷ 3 (whole number).
Then *b* = *w* mod 4, *c* = (*w* ÷ 4) mod 4, *d* = (*w* ÷ 16) mod 4. [checked on the Xbox]

| Part | Value | What it does |
|---|---|---|
| *a*: turning | 0 | the angle grows by the particle's spin each step |
| | 1 | the same, times the spin-over-life curve (`SNOL`) |
| | 2 | the sprite is turned to point along its movement on screen (sparks, streaks) |
| *b*: texture picture | 0 | a random picture at birth, kept |
| | 1 | cycles: picture = (age ÷ texture frame time), wrapped at the picture count |
| | 2 | picture from the texture-over-life curve (`TEOL`) |
| | 3 | a new random picture every texture frame time |
| *c*: colour | 0 | the birth colour and alpha are kept |
| | 1 | colour from the colour-over-life curve (`COOL`) |
| | 2 | alpha from the alpha-over-life curve (`ALOL`) |
| | 3 | both |
| *d*: space | 0 | particles stay where they were born |
| | 1 | particles are carried when the emitter moves (by field 13) |
| | 2 | particles are turned about the emitter when it turns (by field 14) |
| | 3 | both *(check: 3 read as 1 and 2 together)* |

Examples: the pistol muzzle flare is 60 (*a* 0, *b* 0, *c* 1, *d* 1: coloured over life, carried with the gun);
its smoke is 24 (*c* 2: fades by alpha, stays in the world). Common values: 33 (debris), 24 (smoke), 26, 69.

The colour/alpha step uses the curve's value for the current twentieth of life (no blend between twentieths)
and then adds the particle's own random colour offset, kept between 0 and 255. [checked on the Xbox]

### 1.5 The emitter's `SPEM` animation: settings over the effect's time [checked; binding checked on the Xbox]

Each channel is evaluated at the system's current frame. "V" channels are spreads: a new particle takes the
base plus the spread times a random number between −1 and +1.

| Channel | Type | Meaning |
|---|---|---|
| `RAT` | float | particles per frame (§1.7) |
| `LIF`, `LIFV` | float | life, in frames, and its spread |
| `SPD`, `SPDV` | float | start speed and spread |
| `SIZ`, `SIZV` | float | size and spread |
| `SPI`, `SPIV` | float | spin and spread |
| `WGT`, `WGTV` | float | weight (how strongly `GRA` acts on this particle) and spread |
| `GRA` | float | gravity: added to the particle's upward speed each step, times weight; negative pulls down |
| `DRA` | float | a factor on all movement each step (the name suggests drag; in the code it multiplies the whole step) |
| `CLR`, `CLRV` | colour | birth colour and a per-channel random range |
| `ALP`, `ALPV` | integer | birth alpha (0–255) and its random range |
| `TRA` | vector | the emitter's position over time (from the first group) |
| `ROT` | quaternion | the emitter's turn over time (from the first group) |

A `SPEM` animation can have several groups; the emitter blends between them *(check how)*. In Common.p3d
each has one.

### 1.6 The emitter's `SPAR` animation: curves over a particle's life [checked; checked on the Xbox]

`SPAR` animations are 100 frames long: frame = percent of life. When the effect loads, each curve is
sampled at 20 evenly spaced points (0, 5, … 95 percent) into a table; during life the step uses the
twentieth the particle is in, blended with the next for the float curves.

| Channel | Type | Meaning |
|---|---|---|
| `SPOL` | float | speed over life (multiplies the start speed) |
| `SZOL` | float | size over life (multiplies the birth size) |
| `SNOL` | float | spin over life (mode *a* = 1) |
| `WEOL` | float | weight over life (multiplies the weight's gravity) |
| `COOL` | colour | colour over life (mode *c*) |
| `ALOL` | integer | alpha over life (mode *c*) |
| `TEOL` | integer | texture picture over life (mode *b* = 2) |

### 1.7 Making particles [checked on the Xbox]

* **How many.** Each step the emitter adds the area under `RAT` between the previous frame and this one
  (straight lines between keys; a stepped channel gives rectangles) to a running count, times the effect's
  rate multiplier (§1.9), and makes that many whole particles, never more than its most-particles limit; the
  fraction left over carries to the next step.
* **Before the first key, and after the last** [checked on the Xbox]: if a step *starts* before the first
  key, the whole step counts at the first key's value, even the part of it after that key. If it starts at
  or after the last key, the whole step counts at the last key's value. So `RAT` is held flat outside its
  keys. In Common.p3d `RAT` is nearly always a pair like `fxSys_Debris_WoodShape`'s: 50 at frame 4, 0 at
  frame 5. Held at 50 from frame 0, the first step already gives 50, the emitter's limit: the burst comes at
  the start of the effect, not at frame 4, and the later frames add nothing while the 50 live. The pair's 0
  then holds after frame 5, so nothing more is made.
* **Where and which way.** The generator gives each new particle its position and direction:

| Chunk | Generator | Floats in the chunk, in order | Channels |
|---|---|---|---|
| `0x15B00` | point | horizontal spread, vertical spread, `RDVA` | `HOSP`, `VESP`, `RDVA` |
| `0x15B01` | plane | width, height, horizontal spread, vertical spread, `RDVA` | `WDT`, `HGT`, `HOSP`, `VESP`, `RDVA` |
| `0x15B02` | sphere | radius, `RDVA` | `RAD`, `RDVA` |

  The chunk starts with a u32 (0). **Which way and how wide** [checked on the Xbox, point generator]:
  * **Forward is the emitter's own +Y axis** (its "up"), turned by the emitter's matrix. With no spread every
    particle leaves along +Y.
  * **Each spread is a half-angle, in radians:** a particle's horizontal angle is forward ± a random fraction
    of the horizontal spread, and its vertical angle likewise, each with its own random number between −1 and
    +1. So 0.1745 (10°) gives directions up to 10° either side, 20° across. The two are independent, so the
    shape is a square in angle, not a round cone. In numbers, with *h* = π/2 + *r*1 × horizontal spread and
    *v* = π/2 + *r*2 × vertical spread, the direction is (sin *v* cos *h*, sin *v* sin *h*, cos *v*) in the
    emitter's frame: the horizontal spread swings it in the X–Y plane, the vertical toward Z.
  * **`RDVA`:** each particle starts a random ± `RDVA` along its own direction from the point.
  * Particles made in one step are spread evenly along the emitter's path between its last place and this one.
  * The plane and sphere generators were not read beyond their fields *(check: they are read as the same
    spreads around the same axis, from a rectangle of width × height, or a ball of the radius)*.
  * Where an effect points comes from the matrix it is played at: for a cutscene blood effect, the shot
    direction (§2.2); for a prop effect, the joint and the effect's angles. The M16's muzzle flash sits at
    (0, 0, 0.45) with angles 0, so its spray goes along the gun's +Y unless the effect's own skeleton turns it
    *(check on the gun: the `.50` cal's offsets run along −Z)*.
* **At birth:** speed `SPD`±`SPDV`, along the generator's direction; weight `WGT`±`WGTV`; size `SIZ`±`SIZV`;
  spin `SPI`±`SPIV`; angle (field 11)±(field 12); life `LIF`±`LIFV`; colour `CLR` with a random offset in
  `CLRV`, alpha `ALP` with one in `ALPV`; a random texture picture. Each of speed, size, spin, weight,
  gravity and movement factor has its own multiplier from the game (§1.9).

### 1.8 Moving particles [checked on the Xbox]

Each step, with *t* the step's length in the effect's frames:

1. age += *t*; a particle whose age reaches its life is removed;
2. upward speed += `WEOL`(life) × weight × `GRA` × *t*;
3. position += (start velocity × `SPOL`(life) + (0, upward speed, 0)) × `DRA` × *t*;
4. size = birth size × `SZOL`(life);
5. turning, texture picture and colour by the mode word (§1.4);
6. if the emitter moved or turned since the last step, live particles follow by fields 13 and 14 and mode *d*.

Time is counted in the effect's frames (30 a second): lives are 2 to 40 in Common.p3d, so 0.07 to 1.3 seconds.
*(check: the step's unit comes through the system's frame controller.)*

### 1.9 Drawing [checked]

Every emitter's shader in Common.p3d is a `simple` shader with a texture and `BLMD` 1 (alpha blend, 214
emitters) or 2 (add, 90 emitters: flares, sparks, fire); see FORMATS.md for `BLMD`. Particles are
squares of their size, facing the camera and turned by their angle *(check: camera-facing is from the
turning code, which measures on screen; the drawing code was not read)*. With several texture pictures the
texture is cut into that many equal strips across.

**Playing again** [checked on the Xbox]: when the game plays an effect through a renderable (the cutscene
blood) while the last one is still alive, it only moves it; a new one starts only when the old one has
ended. Props work differently (§1.10).

The game can change an effect while it plays with four multipliers [checked on the Xbox]:

| Multiplier | Acts on |
|---|---|
| size | every emitter's `SIZ` (and the object's own scale) |
| rate | every emitter's `RAT`; 0 stops making particles, more than 0 starts again |
| speed | every emitter's `SPD` |
| follow | fields 13 and 14 |

Fire props use the rate multiplier to stop and start burning.

### 1.10 A prop state effect's own fields (`0x0802000B`)

SPEC-009 §2.5 covers them. Adding to it: the effect name is a composite in Common.p3d (§1.1); the start time
(the last float) is on the state's clock. The size field multiplies the particles' size *(check: the prop's
call that sets it was not traced; read as the size multiplier of §1.9)*. Offset and angles place the effect
relative to its joint. The "number" and "joint 2" fields were not settled here.

**Starting and ending** [checked on the Xbox]:

* Each time the state's clock passes an effect's start time, a **new** copy of the effect starts. The
  effect's start-kind word decides how it is held: 0 on its joint (follows the joint), 1 on the prop, 2 left
  in the world where it started.
* The prop keeps a short list of the copies it started and drops each one that has ended.
* **On entering any state**, before the new state's effects start, every copy on that list is told to wind
  down (it stops making particles; a time limit of 10000 is also set on it) and the list is emptied. Its
  live particles finish their lives.

So a looping effect on a prop runs until the prop changes state. **A gun's muzzle flash** (`fire1`) is
started anew by each shot, and the shot before it is wound down, as long as each shot enters `fire1` again
*(check: that the weapon re-enters `fire1` for every shot, and not only when it starts firing; the weapon's
own fire code was not read)*. The flash's "loops" flag only matters if no shot follows.

---

## 2. `NISCharacterEffect`

### 2.1 From `EffectType` to particles [checked; checked on the Xbox]

The type name is looked up in a list of six: `Headshot` 0, `GoreBloodExplosion` 1, `GrenadeExplosion` 2,
`ShotEffectLight` 3, `ShotEffectHeavy` 4, `BloodPool` 5. Each calls the game's `EffectsObject` (the world
object of that name), whose settings come from `EffectsTemplate` in `scriptc/templates/effects.cso` and from
`scriptc/effects.cso`:

| Type | Particle system (template field) | Size given to it | Where |
|---|---|---|---|
| `Headshot` | `fxSys_Blood_HeadshotShape` | 2.0 | the target's `Head` joint, whatever `JointName` says |
| `GoreBloodExplosion` | `fxSys_Blood_HeadExplodeShape` | *(check: from another field of the object)* | the `JointName` joint |
| `GrenadeExplosion` | `fxSys_Grenade_PersonShape` | *(check: as above)* | the `JointName` joint |
| `ShotEffectLight` | `fxSys_Small_ImpactBloodShape` | 1.0 | the `JointName` joint |
| `ShotEffectHeavy` | `fxSys_Large_ImpactBloodShape` | 2.0 | the `JointName` joint |
| `BloodPool` | a growing decal, shader `blood_puddle` (§4.2) | — | under the character |

`JointName` is matched against the game's 42 body joint names (`Motion_Root`, `Balance_Root`,
`Character_Root`, `Pelvis`, … `Head` 13, … `Eye_R` 41). Names in the scripts are written with different
capitals (`head`, `spine_2`); the match is on the game's name key *(check: case)*. An empty name finds none.

### 2.2 `SourceCharacterName` [checked on the Xbox]

Yes: it gives the direction. The direction is from the source's `Neck` joint to the target's joint,
made one long. The effect is turned to face along it, so blood sprays away from the shooter. For types 0 to
4 it also:

* marks the target's own model at that joint *(check: what the mark looks like)*;
* if there is a source, sends a ray 15 units on from the joint along the same direction; where it hits the
  world, it puts the shooter's weapon's blood decal (§4.1) there: the splash on the wall behind the victim.

`BloodPool` ignores the source.

### 2.3 How long each lasts if nothing stops it [checked]

None loops (§1.3). Each makes its particles in a burst at its start (§1.7: `RAT` is held at its first key's
value before that key), and the effect is over when the last particle dies. At 30 frames a second:

| Type | System length | Longest life | Gone after about |
|---|---|---|---|
| `Headshot` | 18 frames | 15 | 18 frames (0.6 s) |
| `GoreBloodExplosion` | 29 | 21 | 29 frames (1.0 s) |
| `GrenadeExplosion` | 60 | 60 (smoke) | 60 frames (2 s) |
| `ShotEffectLight` | 22 | 30 (mist) | 30 frames (1 s) |
| `ShotEffectHeavy` | 30 | 30 (mist) | 30 frames (1 s) |
| `BloodPool` | — | — | stays; grows to full size (§4.2) |

---|---|---|---|---|
| `Headshot` | 18 frames | 3 to 5 | 15 | 20 frames (0.7 s) |
| `GoreBloodExplosion` | 29 | 2 to 4 | 21 | 25 frames (0.8 s) |
| `GrenadeExplosion` | 60 | 2 to 10 | 60 (smoke) | 70 frames (2.3 s) |
| `ShotEffectLight` | 22 | 3 to 5 | 30 (mist) | 35 frames (1.2 s) |
| `ShotEffectHeavy` | 30 | 3 to 5 | 30 (mist) | 35 frames (1.2 s) |
| `BloodPool` | — | — | — | stays; grows to full size (§4.2) |

---

## 3. Gun fire in cutscenes (`NISWeaponFire`) [checked on the Xbox]

### 3.1 What the action does

From `FrameBegin` to `FrameEnd` (frames × 1/30 s) it holds down one of the named character's controls,
exactly as a player's pad would, and lets go after `FrameEnd`. `IsSecondaryWeapon` 0 holds control 11 (fire),
1 holds control 12 (the alternate fire). Everything else is the weapon's normal firing, so the cutscene gets
what gameplay gets.

### 3.2 What normal firing makes [checked]

The weapons are props in `art/stateprops/weapons_test/guns.p3d`. A gun's skeleton has its root,
`muzzle_position` and (for Tony's) `tonyRightArmRage`. Each shot sets the gun prop's state `fire1`
(alternate fire: `fire2`), whose effects play:

| Gun | `fire1` effects | `fire2` effects |
|---|---|---|
| `M16` | `fxSys_Rifle_MuzzleFlash` at offset (0, 0, 0.45), `fxSys_Rifle_BulletCasing` at (0, 0.05, 0.25) | — |
| `M16_upgrade2` (the grenade-launcher M16) | the same | `fxSys_M16mortar_MuzzleFlash`, a dust puff |
| `uzi` | `fxSys_PistolUzi_MuzzleFlash`, `fxSys_PistolUzi_BulletCasing` | none |

How often: the weapon template's `FiringRate` (`scriptc/templates/weapons.cso`): 75 for the M16 and 105 for the
Uzi, read as milliseconds between shots *(check the unit)*. Tracers: every `TracerFrequency`-th bullet
(2 for both) draws `fx_tracer`, at most `MaxNumTracers` (40) at once. Bullet holes: each weapon has a
`WeaponDecalTemplate` (`DEC_M16`, `DEC_UZI`, …) with a shader, size and impact particle effect per surface
(dirt, concrete, wood, metal, blood, furniture, glass). *(check: that a cutscene's bullets reach the walls;
the firing path is the gameplay one.)*

### 3.3 `IsSecondaryWeapon` [checked]

All 11 uses are in `NIS_100_office_politics`. Tony there holds `WeaponTemplateM16Mortar`, whose alternate fire
is the grenade launcher (`AmmoType_Secondary` `GRENADE_AMMO`): that is the "little friend" shot. The others
hold Uzis (and one an AK-47 and a Colt). The Uzi template has `AmmoType_Secondary` "none" and its prop has no
`fire2`, so for them alternate fire should do nothing visible *(check in the game: they are seen firing for
100-frame stretches, so something may show)*. What a control does is decided by the fight tree's button
conditions (`ButtonEventCondition`), not by the cutscene.

---

## 4. Marks left behind

### 4.1 Blood on walls [checked on the Xbox]

Made only by `NISCharacterEffect` types 0 to 4 with a source (§2.2): one decal, from the shooter's weapon's
`WeaponDecalTemplate` blood entry (e.g. `Decal_Blood_SplatB`, size 1.5 for the M16), where the ray hits.

### 4.2 Blood pools [checked]

`BloodPool` starts a decal under the character with the shader named in `EffectsTemplate`
(`blood_puddle`). From `scriptc/effects.cso`: it grows by 0.005 every 2 frames up to a radius of 1.9, so
about 25 seconds to full size, and stays. *(check: that it is removed when the scene ends.)*

### 4.3 Bullet holes

From the weapon's normal firing (§3.2), not from cutscene data.

---

## 5. `NISFade` [checked on the Xbox; script fields checked]

Times are frames × 1/30 s. 380 fades in the PC scripts; 372 are black.

* **The common black case, `DurationFrames` 0 or less:**
  * if `FadeInFrames` > `FadeOutFrames`: the screen fades to black over `FadeInFrames` and stays black (the
    scene's end; the game fades back itself);
  * otherwise: the screen starts black and clears over `FadeOutFrames` (the scene's start: `FadeInFrames` 0,
    `FadeOutFrames` 15 at frame 0).
* **Any other fade** (a colour, or `DurationFrames` above 0): the overlay goes from clear to the colour over
  `FadeInFrames`, holds for `DurationFrames`, then back to clear over `FadeOutFrames`. A negative
  `DurationFrames` holds for ever (`NIS_124_frontal_assualt` has −1). Alpha changes in straight lines:
  elapsed ÷ fade-in, then 1 − elapsed ÷ fade-out.

The 8 white fades (255, 255, 255) are flashes.

---

## 6. Scene props before the first key [checked]

In `NIS_100_office_politics` the closet doors' animation (`NIS_100_office_politics_doors`, cut into pieces; the
first, `…_doors0`, in `stream0.p3d`) has keys at frame 0, so the question does not arise there. And the
skeleton's rest pose in `static.p3d` (`closet_doors`) is the same as the frame-0 key for both doors
(the joint matrix and the quaternion differ only by the usual sign of the turn). The doors:

| Joint | Turn about up, frame 0 (and rest) | From frame 79 | At 87 and after |
|---|---|---|---|
| `L_door_anim` | 129.2° | swings | 109.8° |
| `R_door_anim` | 11.7° | swings | 105.8° |

So the left door is about 19° from where it ends at frame 0, and the right about 94°. That is in the files:
the game shows the same. *(The general rule, before a channel's first key the first key's value is used, is
SPEC-005's.)*

---

## 7. Two-handed grips [checked; checked on the Xbox]

Nothing moves the off hand. The Xbox program's class list has no inverse-kinematics or hand-reach class;
the gun props have no grip or foregrip joint (root, `muzzle_position`, and for Tony's `tonyRightArmRage`
only); the cutscene has no field for it. The left hand's place is all in the cutscene animation. Characters
have `right_hand_attach` (under `Wrist_R`) and `left_hand_attach` (under `Wrist_L`) joints, about 0.1 units
past the wrists, and the gun goes on `right_hand_attach` with its root there *(check: the attach call was
not traced)*. If the gun is put on `Wrist_R` instead, it sits about 0.1 units short and the left hand
seems to float: check that first.

---

## 8. The disco ball (SPEC-009 §1.5)

This examiner cannot run the game. The code path stands as SPEC-009 says: the club's state settings
(0, 0, 0, frames 0 to 0) freeze the sparkle on `sparkle.001`. Only someone looking at the Babylon Club in
the running game (or an emulator) can confirm it; the founder's choice to have it cycle in the exports is a
fine way to show it until then.

---

## 9. Xbox functions read [checked on the Xbox]

| Address | Name (work queue) | What it does |
|---|---|---|
| `0x1811B0` | `NISCharacterEffectAction::vfunc_07` | runs the effect action |
| `0x17F490` | `sub_0017F490` | the effect action: joints, direction, type switch, wall splash ray |
| `0x184EC0` | `sub_00184EC0` | effect type name by number |
| `0x187070` | `sub_00187070` | reads `NISCharacterEffect`'s fields |
| `0x0D7130` | `sub_000D7130` | joint name key → body joint number (42 names; 43 for none) |
| `0x163F50` | `sub_00163F50` | a character's body joint position |
| `0x1CF3D0` | `sub_001CF3D0` | finds the `EffectsObject` |
| `0x1CF980` | `sub_001CF980` | headshot effect |
| `0x1CF860` | `sub_001CF860` | gore effect |
| `0x1CF8F0` | `sub_001CF8F0` | grenade effect |
| `0x1CFA40` | `sub_001CFA40` | light or heavy shot effect |
| `0x1CF4F0` | `sub_001CF4F0` | starts a blood pool |
| `0x1CF130` | `sub_001CF130` | a weapon's decal of one surface at a point |
| `0x17B9D0` | `sub_0017B9D0` | a character's weapon kind |
| `0x048710` | `sub_00048710` | plays an effect at a matrix |
| `0x048790` | `sub_00048790` | sets one of an effect's four multipliers |
| `0x055A10` | `sub_00055A10` | passes the multipliers to the particle system |
| `0x1800C0` | `NISWeaponFireAction::vfunc_12` | holds and lets go of the fire control |
| `0x187600` | `sub_00187600` | reads `NISWeaponFire`'s fields |
| `0x162520` | `sub_00162520` | sets a control's state |
| `0x1625C0` | `sub_001625C0` | is a control down |
| `0x16B8D0` | `sub_0016B8D0` | the pad into the controls |
| `0x17F440` | `NISFadeAction::vfunc_07` | runs the fade action |
| `0x17E800` | `sub_0017E800` | the fade action's choice of fade |
| `0x186880` | `sub_00186880` | reads `NISFade`'s fields |
| `0x1A0170` | `sub_001A0170` | starts the coloured fade |
| `0x19FB70` | `sub_0019FB70` | copies its times |
| `0x1A0350` | `sub_001A0350` | the overlay's states and alpha |
| `0x22F460` | `sub_0022F460` | the screen fade to black |
| `0x270CE0` | `pure3d::ParticleSystemLoader::vfunc_06` | reads `0x1580C` |
| `0x271AF0` | `sub_00271AF0` | reads `0x15900` |
| `0x271A80` | `pure3d::DefaultParticleGeneratorHandler::vfunc_05` | picks the generator reader by chunk id |
| `0x271330` | `sub_00271330` | reads the point generator |
| `0x271540` | `sub_00271540` | reads the plane generator |
| `0x271780` | `sub_00271780` | reads the sphere generator |
| `0x2A5210` | `sub_002A5210` | point generator channels |
| `0x2A55E0` | `sub_002A55E0` | plane generator channels |
| `0x2A5B70` | `sub_002A5B70` | sphere generator channels |
| `0x2708A0` | `sub_002708A0` | builds the update steps from the mode word |
| `0x25EBE0` | `sub_0025EBE0` | samples the `SPAR` curves into 20 steps |
| `0x25D8B0` | `sub_0025D8B0` | binds the `SPEM` channels |
| `0x25F780` | `pure3d::SpriteParticleEmitter::vfunc_18` | the emitter's step: follow, rate |
| `0x25F430` | `sub_0025F430` | evaluates the emitter's channels |
| `0x25F4B0` | `sub_0025F4B0` | makes the counted particles |
| `0x25EFF0` | `pure3d::SpriteParticleEmitter::vfunc_20` | sets up one new particle |
| `0x25F2A0` | `pure3d::SpriteParticleEmitter::vfunc_23` | sets a multiplier |
| `0x2872B0` | `sub_002872B0` | area under a float channel between two frames |
| `0x1F2C00` | `sub_001F2C00` | random number between −1 and +1 |
| `0x2A4FE0` | `pure3d::SpriteParticleUpdater::vfunc_05` | particle step with life curves |
| `0x2A5130` | `pure3d::SpriteParticleUpdater::vfunc_06` | particle step without |
| `0x295800` | `sub_00295800` | adds an offset to a colour, kept in range |

The small step functions (`0x2A4530` to `0x2A4F20`) are not separate entries in the queue.

---

## 10. What to build

1. `p3d.py`: read `0x1580C`, `0x15900`, `0x15B00`/`01`/`02` and `0x122000` by §1.3, §1.4, §1.7 (names, the mode
   word split into its four parts).
2. A particle player: the system's frames at 30 a second; per emitter, evaluate `SPEM` at the frame; count
   with the area under `RAT`; make particles by §1.7; step them by §1.8 with the `SPAR` tables of §1.6.
   Test on `fxSys_PistolUzi_MuzzleFlashShape` (2 emitters, 5 frames) first.
3. Draw them: camera-facing squares, the shader's texture and `BLMD` (§1.9). In Blender, bake each
   particle to an animated plane, or bake the whole effect to an image sequence: whichever is simpler.
4. Effects in cutscenes: `NISCharacterEffect` by §2 (type → system, joint, direction from the source's `Neck`,
   size); `BloodPool` as a growing decal (§4.2); the wall splash ray (§2.2) if the scene's walls are loaded.
5. Gun fire: from `FrameBegin` to `FrameEnd`, a shot every `FiringRate`, each playing the gun prop's `fire1`
   (or `fire2`) effects at their offsets from the gun; a tracer every `TracerFrequency`-th shot.
6. Prop state effects: name → composite in Common.p3d → its parts (§1.1); start at the state-clock time.
7. `NISFade` by §5, as an overlay with straight-line alpha.
8. Check the gun goes on `right_hand_attach` (§7).
9. FORMATS.md: the particle chunks, in your own words.
10. Match the §9 functions, small ones first.

---

## Questions from the implementer, and answers

*From the implementer, 19 November 2026, with the examiner's answers the same day (put into §1.7, §1.9 and
§1.10 above):*

* **Which way is "forward" for a spray, and is its spread the full angle or half of it?** The emitter's own
  +Y, and each spread is a half-angle (± that much), horizontal and vertical separately: §1.7.
* **Does a looping muzzle flash restart with each shot?** Yes, on a prop: each start makes a new copy and
  entering a state winds the old ones down (§1.10). Through a renderable, no: a live copy is only moved
  (§1.9).
* **What does the spawn rate count as before its first key?** As the first key's value, for the whole step
  that starts there; after the last key, as the last key's value (§1.7). The one-frame bursts therefore come
  at the very start of an effect.

*From the implementer, 19 November 2026, after building §10 steps 1 to 9 with the answers above (run on made-up
files only so far; the founder's computer was offline):*

* **Built.** `p3d.py` reads `0x1580C`, `0x15900` and the generators; `particles.py` plays a system by §1.5 to
  §1.8: `RAT` held flat outside its keys, forward along +Y with the two half-angle spreads, `RDVA` along the
  direction, the plane's rectangle across +Y and the sphere's ball with the same spreads.
  `cutscene_fx.py` puts each particle in the glTF as a square facing the camera. In cutscenes:
  `NISCharacterEffect` by §2 (a second one on the same body and system while the first lives adds nothing:
  §1.9); `BloodPool` by §4.2; gun fire by §3 and §1.10 (every shot starts the `fire1` effects anew and winds
  the last shot's down; the last shot's run until the trigger is let go); prop-state effects wound down when
  the prop enters its next state; `NISFade` by §5. §7: the gun sits on `right_hand_attach` with no turn
  towards the other hand.
* **Not built:** the wall splash and the mark on the target's model (§2.2: the export has no collision to
  cast the ray against); the start-kind word of §1.10 (every effect is held on its joint); picture modes 1
  to 3 (the birth picture is kept) and turning mode 2 (drawn unturned); particles of one step spread along
  the emitter's path.
