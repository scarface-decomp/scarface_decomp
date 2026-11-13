# Clean-room work

Some useful research on Scarface was done by people who had leaked source code open while they worked.
Its *code* and *names* can't come into this project ([PROVENANCE.md](PROVENANCE.md)). What the research
found out about the game's files and behaviour can, through a
[clean-room](https://en.wikipedia.org/wiki/Clean-room_design) process: the knowledge crosses over as a
written description, and the code is written fresh by someone who never saw the original.

## Roles

* **Examiner.** Reads the outside research and writes a **spec** in `docs/cleanroom/`: what the game's
  files contain and what the game does with them, in their own words. No code, no pseudo-code, no
  names from the research. Names allowed in a spec are the ones this repository already has (from the
  game's own type information and strings) and text stored in the game's files. Every statement must be
  something anyone can check on their own copy of the game. An examiner doesn't implement that spec.
* **Reviewer.** Checks the spec before anyone builds from it: no code, no names that only the outside
  research has (compare every identifier against the repository and against the research's name lists),
  nothing copied word for word. Records the result below.
* **Implementer.** Builds from the spec, the repository and their own copy of the game, and **never opens
  the outside research** (not its code, notes or name lists). If the spec is unclear or wrong, the
  implementer checks the game files or asks the examiner a question in an issue. The answer goes into
  the spec, so the record stays complete.

Anyone can be an examiner, but once you have read the outside research you can't be the implementer
for anything it covers. Say which side you are on in your pull request.

## Record

| Spec | Examiner | Outside material read | Review | Implementer |
| :--- | :--- | :--- | :--- | :--- |
| [SPEC-001](cleanroom/SPEC-001-lights-sky-streaming.md): lights, time of day, the sky, the stream graph | Claude (AI assistant) for RRutherrfordd, 2026-11-12 | the notes (`re/notes/`) and name lists of the extended *scarface-p3d* by aap, whose author worked with leaked Scarface and *Simpsons: Hit & Run* source | 2026-11-12: no code; every identifier is already in the repository, is text in the game files (light, mesh, animation, slot and package names), or is an English word or a glTF term; none appears only in the research's name lists. Layouts and values then read back from the PC game files (2026-11-12); the stream trigger's last three fields were added from that check | a separate AI agent that was given only the spec and this repository, 2026-11-12 |
| SPEC-001 part 2 (§3.3, §3.4, §5 checked; §6 and work items 6 to 9 added): one weather at a time, the sky through the day, fog | Claude (AI assistant) for RRutherrfordd, 2026-11-12 | the same; the new facts were read from the PC game files with the repository's own tools (script decompiler, chunk reader) | 2026-11-12: as above; the fog property names and the `tod` object's property names come from the game's own files through the repository's decompiler and chunk reader | a separate AI agent, new, given only the spec and this repository, 2026-11-12 |
| [SPEC-002](cleanroom/SPEC-002-materials-ocean-shadows.md): see-through surfaces, the ocean, shadows | Claude (AI assistant) for RRutherrfordd, 2026-11-12 | the same research's notes on shader state, depth writes, the ocean and shadows | 2026-11-12: no code; every identifier is already in the repository, is text in the game files (shader kinds and settings, texture, mesh and script names), a public Direct3D constant, or an English word; none appears only in the research's name lists. Shader statistics, textures, scripts and shadow records read back from the PC files with the repository's own tools | a separate AI agent, new, given only the spec and this repository, 2026-11-12 |
| [SPEC-003](cleanroom/SPEC-003-props-zones-xbox-blending.md): prop states, a placed prop's starting state, draw distances, occluders, characters' and vehicles' shaders, the water chunks' names, how the Xbox blends | Claude (AI assistant) for RRutherrfordd, 2026-11-13 | the same research's notes on state prop data, the game's own chunk loaders and placed props | 2026-11-13: no code; every identifier is already in the repository, is text in the game files (state, property, effect, world geometry, model, shader and texture names), a class name in the Xbox program's run-time type information, a public Direct3D value, or an English word; none appears only in the research's name lists, and no six words in a row match the notes. Layouts and values read back from the PC files with the repository's chunk reader; the state-name list, the water loaders and the blend table read from the user's own `default.xbe` | a separate AI agent, new, given only the spec and this repository, 2026-11-13 |

Text in the game files that SPEC-001 names, for the first person who checks it on their own copy:
`MiamiSunShape`, `MiamiFillShape`, `MiamiAmbientShape`, `MiamiBuildingAmbientShape`, `zone_lights`,
`zone_rainlights`, `lamp_talllight`, `lamp_shortlight`, `vehicle_headlight`, `sky`, `rainy_skybox`,
`sun_grp`, `PTRN_sky`, `skyboxShape` and the other `skybox*Shape` meshes, `VRTX_*`,
`Cloud_variant_001.tga`, `loadTrigger`, the slot names (`Global_S`, `Global_D`, `Region_S`,
`Region_D`, `Shell`, `Detail`, `ZoneAnimation`), `environment_clear_<hour>`, `environment_rainy_<hour>`
and `tod`.
