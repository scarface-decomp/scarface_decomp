# Help wanted

What is still wrong or unfinished, written so someone new can pick one thing and start. Each item says
what is wrong, how to see it, and what "done" looks like. The numbers are from 13 November 2026.

Before you start: read [CONTRIBUTING.md](CONTRIBUTING.md) and [PROVENANCE.md](PROVENANCE.md). You need your
own copy of the game. Nothing here may come from leaked source code or from tools written beside it, and no
game files go into the repository. Say in [Discord](https://discord.gg/azvrtGBvau) what you are taking so
two people don't do the same thing.

**What you need for each kind of job**

| Job | You need |
| :--- | :--- |
| Matching functions | the portal, the game's program file, the VC++ 2003 compiler (see the setup card) |
| Naming and describing | the portal; an AI key helps but isn't required |
| Cutscenes and models | the portal, the game's data files, Blender |
| Portal and tools | Python; for the page, a browser |

---

## 1. Decompiling

Where it stands: 10,373 functions compile byte for byte (6,901 of 21,050 in the released game, 3,472 in
the 2006 Xbox prototype). Three of them read as finished C++.

### 1.1 Run "Match the easy ones" over the whole queue
- **Wrong:** nobody has run it start to finish. A sample of 300 open functions suggests about 5,000 match
  from the portal's own starter code; the real number is unknown.
- **See it:** Workbench, next to Batch Run. No AI, no key.
- **Done:** it has gone through every open function on one computer and the matches are submitted. Post
  how many it tried and how many matched.

### 1.2 Matched is not readable
- **Wrong:** almost every matched function is still its first draft: `sub_0011A060`, `a1`, `m_Field64`,
  pointer arithmetic on raw addresses. About 6,800 on the Xbox and PC builds have things left to name.
- **See it:** list "Matched, names still to work out"; each function says what is left.
- **Done, per function:** it still compiles to the same bytes and has fewer stand-ins. Use
  **Ask the AI to name them** or **Name the matched ones**, then read what the AI wrote before you submit.

### 1.3 Functions have no real names
- **Wrong:** 406 functions have a name in `reports/names.json`. Every other one is known by its address,
  so code that calls it can't say what it calls.
- **Done, per function:** **Name this function** with a name and one sentence on what shows it (what the
  code does, a string it uses, the game's class information). A name that is a guess is worse than none.

### 1.4 Empty functions and type tags can't be named from their own code
- **Wrong:** of the 123 functions one name from finished, 61 are empty, 41 return their own address as a
  type tag and most of the rest return a constant. Nothing in them says what they are for.
- **Done:** a way to name them from where they are used: which class's table an empty virtual sits in,
  which type a tag is compared against. Probably a tool, not hand work.

### 1.5 Only 51 functions say what they do in plain words
- **Done, per function:** one line in "What it does" on a matched function. Needs no compiler.

### 1.6 Nothing proves the decompiled code works as a program yet
- **Wrong:** each function is proven alone, against the original bytes. The functions are not built into
  anything that runs, and no test calls one and checks what it returns.
- **Done (first step):** a small harness that compiles a handful of matched, self-contained functions (the
  name key at Xbox `0x00243FA0` is a good first one) and checks their results against known inputs.
- **Done (later):** a plan for linking matched code back into the game, one object at a time.

### 1.7 135 queue entries still start inside another function
- **Wrong:** 85 on the Xbox, 50 in the prototype, 2 on PC. Either the earlier function's size is too
  large or the later start is not a function; the two rules in `sf_binaries.settle_overlaps` can't tell.
- **Done:** each one decided with a reason, or a third rule that is right on every case it touches.

### 1.8 The address-order lists show old sizes
- **Wrong:** `reconstructed_src/Original_Binary_Order_*.cpp` still list the 100 re-measured functions
  with their old sizes and the 63 false starts.
- **Done:** the lists regenerated from a settled queue on a computer with all three program files.

### 1.9 PS2: 0 of 24,297 matched
- **Wrong:** the PS2 build uses another compiler, checked through decomp.me, and nobody has matched one.
- **Done:** the first PS2 match, and notes on what it took ([PS2.md](PS2.md)).

### 1.10 PC: only 1,516 functions can be worked on
- **Wrong:** most of the PC program is not readable as shipped ([GAME_VERSIONS.md](GAME_VERSIONS.md)).
  Only the plain part is in the queue.
- **Done:** not something to "fix"; listed so nobody is surprised. PC work is the 1,516.

### 1.11 Work described by the specs
One small pull request each, naming the spec and section. Files win over specs; a question the spec does
not answer goes in its "Questions from the implementer" section.
- SPEC-005 section 6, item 3: STEP interpolation and visibility in the glTF export; then items 4 to 7.
- SPEC-006 section 7, items 2 to 4.
- SPEC-004 section 5: five open Xbox functions (`sub_00282950`, `sub_00282820`, `sub_002828C0`,
  `sub_00042AB0`, `occlude::OccluderLoader::vfunc_06`).
- SPEC-007 section 7 (billboards), starting in `p3d.py`.

---

## 2. AI runs (your own key)

### 2.1 Check every provider end to end
- **Wrong:** recent testing was almost all Gemini Flash. Anthropic, OpenAI, Ollama and a custom model
  name have not been run through a full Auto-Decompile, a names pass and a batch since the last changes.
- **Done:** for each provider, one real function matched, one named, and the spending meter's token
  counts compared with the provider's own bill. Report what broke.

### 2.2 Fast models answer with part of a file
- **Wrong:** the portal now refuses a reply that is only the function and asks again, but that still
  costs a request each time.
- **Done:** a prompt that gets a whole file first time from the common fast models, measured over 50
  functions before and after.

### 2.3 Which model for which size of function
- **Wrong:** nobody knows. Fast models stall on functions of 80 bytes and more.
- **Done:** a table from real runs: model, size tier, matched out of tried, cost per match.

### 2.4 Names an AI suggests need a person
- **Wrong:** the names pass records a function name with the AI's one-line reason. The bytes are proven;
  the name is not.
- **Done:** a review list of AI-suggested names (they end "suggested by <model>"), each confirmed,
  corrected or removed.

### 2.5 The compiler's error should point at the line
- **Wrong:** a compile error is shown as text under the editor; the line it names is not marked.
- **Done:** the line highlighted in the editor and the error beside it.

### 2.6 Class declarations are written again for every function
- **Wrong:** each matched function carries its own copy of its class, with only the members it uses.
  Two functions of one class can disagree.
- **Done:** one header per class that grows as functions are matched, checked so every function of the
  class still compiles to the same bytes against it.

---

## 3. Cutscenes in Blender

The portal opens the game's cutscenes in Blender from your own files (Game files tab). They play, but
they are not right yet.

### 3.1 Wheels do not spin
- **See it:** any cutscene with a moving car.
- **Done:** wheels turn at a rate that fits the car's speed, and steer.

### 3.2 Some people do not move
- **Wrong:** in some cutscenes a character stands in the rest pose while others are animated.
- **Done:** a list of which cutscenes and which characters, then the cause (animation not found, not
  bound to that skeleton, or driven by the mission script and not by the cutscene).

### 3.3 Animations are not fully right
- **Wrong:** stepped keys are blended as if smooth, and visibility tracks are ignored (SPEC-005 section 6).
- **Done:** STEP keys hold their value; things that should appear and disappear do.

### 3.4 Parts of the city are missing
- **Wrong:** 30 cutscenes load their room. Outdoor ones get the nearest piece of the map or nothing, so
  streets and buildings around the action are missing.
- **Done:** an outdoor cutscene loads the map pieces its camera can see.

### 3.5 People stand in the wrong place in some scenes
- **Wrong:** placement comes from the cutscene's stand position plus the character's root keys. In some
  scenes a character is off: the man with the pistol in `MNIS_A64_0_Daughter_Roughed_Up` should be
  beside the girl.
- **Done:** a list of scenes that are off, and the rule that fixes them for all (a per-scene patch is
  not a fix).

### 3.6 Guns
- **Wrong:** rifles were turned to sit in the hand and laid into the other hand; whether both hands
  really hold them, and whether pistols aim where they should, has not been confirmed since.
- **Done:** checked in three scenes with rifles and three with pistols; fixed by rule where wrong.

### 3.7 Faces
- **Wrong:** the top lip pulls down when the jaw opens, there are a few bad triangles on Tony's neck, and
  characters whose face is a separate `…nis_Face` model have no face animation.
- **Done:** lips and jaw move as in the game; the neck is clean; separate face models are attached and
  animated.

### 3.8 No sound
- **Wrong:** cutscenes are silent.
- **Done:** the cutscene's speech and effects on Blender's timeline, starting on the right frame.

### 3.9 No subtitles
- **Wrong:** the game's subtitle text is not shown.
- **Done:** each line shown while its audio plays, taken from the game's own text files and timed by the
  audio it belongs to.

### 3.10 Things the mission script does are missing
- **Wrong:** doors that are shot open, effects, and the weapon a character carried in from gameplay are
  set up by the mission script, not by the cutscene, so they are not there.
- **Done:** the script calls around a cutscene read, and the props and effects they name added.

### 3.11 The mansion shootout and the opening
- **Wrong:** the shootout is played by mission S01's script and several cutscene pieces, not one scene;
  the prologue is a movie file. Neither appears as "a cutscene" in the list.
- **Done:** the list says so, and the S01 pieces can be opened in order.

### 3.12 Cutscene names
- **Wrong:** the list shows file names (`MNIS_A64_0_Daughter_Roughed_Up`).
- **Done:** readable titles, grouped by mission, with the file name kept beside them.

### 3.13 Smaller things
- Thumbnails for cutscenes in the list.
- "View here" for the whole city, not one piece.
- Tony's outfit is read from the mission script; check it on every cutscene and list the ones that are wrong.

---

## 4. Portal and project

### 4.1 Test on a fresh download
- **Done:** on a computer that has never had the project: download, run the setup, open the portal, match
  one function. Write down every place you got stuck.

### 4.2 The real-compiler tests don't run on GitHub
- **Wrong:** `portal/tests/test_server_real.py` needs the compiler and a game file, so GitHub skips it.
  It is run by hand, rarely.
- **Done:** an easy way for a maintainer to run it before a release, and a note of the last time it passed.

### 4.3 Show "matched" and "named" side by side on the website
- **Wrong:** the website shows one number. "Matched" alone reads as "decompiled".
- **Done:** both numbers, with one line saying what each means.

### 4.4 Syncing while a background run is going
- **Wrong (fixed once, watch for it):** a sync pushed generated files one match ahead of the registry.
- **Done:** if the repository check fails after a sync again, report what was running at the time.

---

## How to report a problem you found

Open an issue with: the game version (Xbox, PC, prototype, PS2), the function's address or the cutscene's
file name, what you expected, what you saw, and a screenshot. For a function, paste the status line from
the workbench. Don't paste game code or bytes beyond what the portal already shows for that function.
