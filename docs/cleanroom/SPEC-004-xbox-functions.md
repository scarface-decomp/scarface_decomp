# Clean-room spec 004: Xbox functions to match, and the archive's name hash

* **Written by:** the examiner side (see [CLEAN_ROOM.md](../CLEAN_ROOM.md)). The examiner has read published
  notes by a third party whose research was done next to leaked source code. Those notes said where to look;
  every fact below was then read from the user's own `default.xbe` and game files. The implementer must not
  open the notes.
* **What this is:**
  * the archive name hash, which the repository's archive reader can use;
  * a list of `default.xbe` functions in the parts of the game the clean-room specs cover, each with what it
    does in the examiner's words, so they can be matched.

  No code, and no names except ones this repository already has, class names in the Xbox program's run-time
  type information, and text in the game's files.
* **How sure:** **[checked on the Xbox]** is read from `default.xbe` with a disassembler. **[checked]** is
  checked on the user's game files with the repository's own tools.

The functions are given by address and by the name the work queue (`reports/full_remaining_queue.json`) has for
them, with their sizes as the queue measures them. Matching follows [METHODOLOGY.md](../METHODOLOGY.md): the
implementer reads the disassembly, writes C++, and checks it with `portal/verify.py`. This spec only says what
each function is for, and the meaning of the fields and numbers it touches.

---

## 1. The archive's name hash

### 1.1 What it is **[checked]**

The entries in an `.rcf` archive's directory are in the order of a 32-bit number computed from each file's path. The path is written with
backslashes, as the name table has it:

1. If the first character is a backslash, skip it (one only).
2. Start at 0.
3. For each remaining character, take it as a signed byte. If it is below `a` (0x61), add 0x20 to it. That
   folds `A`–`Z` to lower case, but it also shifts `0`–`9`, `.`, `\`, `_` and the rest. Then the hash becomes
   hash × 31 + that value, kept to 32 bits.

On the user's PS2 disc (`Scarface - The World Is Yours (PS2).iso`, its `CEMENT.RCF`, read with
`rcf.open_rcf`), all 4,764 names give exactly the hash of the directory entry `rcf.py` pairs them with. So the
pairing by offset that `rcf.py` uses is right on that archive, and the hash proves it.

### 1.2 Where the Xbox has it **[checked on the Xbox]**

`sub_00251310` (62 bytes) is this hash. It takes the path as its one argument (`__cdecl`) and returns the
number. It returns 0 for a null pointer or an empty string, after the backslash check. Nothing else is in it.

---

## 2. A shader's blending and alpha test, on the Xbox

These belong to the shader settings of [SPEC-002](SPEC-002-materials-ocean-shadows.md) and the blend table of
[SPEC-003](SPEC-003-props-zones-xbox-blending.md) §8.1. All **[checked on the Xbox]**.

### 2.1 `sub_0029A390` (18 bytes): setting `BLMD`

It is a `__thiscall` method of a shader object that takes the `BLMD` value. It stores it at offset `0x18` of
the object, then calls `sub_0029A2F0` on the same object. It is reached through the shader kind's table of
settings: the `BLMD` entry is at `0x0045F688`, and its function pointer is filled in at `0x00320E68`.

### 2.2 `sub_0029A2F0` (146 bytes): working out the blend mode and the alpha reference

A `__thiscall` method of the same object, with no arguments and no result. It reads the byte value `v` at
offset `0x38`: a fade level, 0 to 255. Then it does four things:

1. It computes (255 − `v`) as a float. The compiler converts that unsigned number to float with the usual
   4294967296.0 correction (`0x0039F35C`). It then multiplies by 1/255 (0.0039215689 at `0x0039E9C0`).
2. It sets the blend mode it will use, at `0x1C`, to the `BLMD` value at `0x18`. One exception: when `BLMD` is
   0 and `v` is above 0, it uses 1 (ordinary see-through), so a fading solid surface blends.
3. It multiplies the result of step 1 by the float at `0x30`, the alpha-test reference (`ACTH`). It clamps that
   between 0.0 (`0x0039D584`) and 1.0 (`0x0039D664`) and stores it at `0x34`.
4. It copies the four 32-bit values at `0x64`, `0x68`, `0x6C` and `0x70` to `0x50`, `0x54`, `0x58` and `0x5C`,
   in the order the disassembly shows.

### 2.3 `sub_00282950` (103 bytes): applying them

A `__thiscall` method of the same object, with no arguments. It does three things:

1. It looks up the entry for its blend mode (offset `0x1C`) in the eight 16-byte entries at `0x0045C188`
   (SPEC-003 §8.1). Each entry holds a byte (blending on), the equation, and the source and destination factor
   indexes. It passes the four values to `sub_00282820` on the render context at offset `0x14`.
2. It calls `sub_002828C0` on the same render context with three arguments: the alpha test on or off (the byte
   at `0x28`), the comparison (offset `0x2C`), and 0.
3. It sets the alpha reference render state (`0x40340`) straight away to the float at `0x34` × 255.0
   (`0x003A0FC4`), converted to an integer by `sub_002FC20C`. It also stores that integer in the global
   `0x0033A974`.

The queue says this function has one look-alike. Matching it covers that one too.

### 2.4 `sub_00282820` (153 bytes): the blending render states

A `__thiscall` method of the render context, with four arguments (`ret 0x10`): blending on (a byte), the
equation, the source factor index and the destination factor index. The context keeps the last value of each:

* blending on, at `0x4C` (a byte);
* the equation, at `0x50`;
* the source index, at `0x54`;
* the destination index, at `0x58`.

For each one that changed, it stores the new value and sends a render state through `sub_0032C850`. That
function takes the state's number in `ecx` and its value in `edx` (`__fastcall`). It also copies the value
into a global:

| State | Value sent | Copied to |
| :--- | :--- | :--- |
| `0x40304` (blending on) | the byte | `0x0033A96C` |
| `0x40350` (equation) | the number as given | `0x0033A9A8` |
| `0x40344` (source factor) | the Direct3D value for the index, from the table at `0x0045C208` | `0x0033A978` |
| `0x40348` (destination factor) | the same, from `0x0045C208` | `0x0033A97C` |

When blending is off, it sends nothing for the other three. The disassembly shows the exact order of the checks.

### 2.5 `sub_002828C0` (130 bytes): the alpha-test render states

The same pattern, for the alpha test. It is a `__thiscall` method of the render context with three arguments
(`ret 0xC`):

| Argument | Last value kept at | State | Value sent | Copied to |
| :--- | :--- | :--- | :--- | :--- |
| on (a byte) | `0x5C` | `0x40300` | the byte | `0x0033A970` |
| the comparison index | `0x60` | `0x4033C` | from the comparison table at `0x0045C244` | `0x0033A968` |
| the reference | `0x10C` | `0x40340` | as given | `0x0033A974` |

When the test is off, it sends nothing for the other two.

---

## 3. The occluder loader **[checked on the Xbox]**

`occlude::OccluderLoader::vfunc_06` (494 bytes) loads one `0x0880000A` chunk, as SPEC-003 §5 describes. It
takes four arguments (`ret 0x10`): where to put the object, where to put its key, the chunk file, and the
inventory. In order, it:

1. Makes up the name `OccluderObject_<n>` from the format text at `0x003A03EC` and a counter at `0x00475638`,
   which it increases first. It hashes the name with the name-key function `sub_00244040` (with 0 as the second
   argument) and stores the result as the key.
2. Allocates 0x70 bytes (`sub_0023F760`) and constructs the object:
   * the base constructor `sub_00242DA0`;
   * the class's virtual table, `0x003A03D0`;
   * the angle at `0x24` set to 0, and the bytes at `0x28`, `0x29` and `0x68` set to 0;
   * `0x6C` set to −1;
   * the box's minimum (`0x0C`–`0x14`) set to 1e12 (`0x003A03C4`) and its maximum (`0x18`–`0x20`) to −1e12
     (`0x0039D7F0`).
3. Reads, through the chunk file's stream at offset `0x284` with `sub_00240570`:
   1. the position (3 floats);
   2. the way it faces (3 floats);
   3. the u32 kind: 1 sets the bytes at `0x29` and `0x28`; 2 sets only `0x28`;
   4. the unused u32;
   5. the three sizes.
4. Sets the box to the position − half of each size (0.5 at `0x0039D580`) for the minimum, and + half for the
   maximum. Then it overwrites the minimum's height with −1.0 (`0x0039D65C`).
5. Stores the arctangent of the facing x over the facing z (x87 `fpatan`) at `0x24`.
6. Registers the object with `sub_00047480`, and returns it through the first argument.

---

## 4. Drawing the shadow decals **[checked on the Xbox]**

`sub_00042AB0` (488 bytes) is a `__thiscall` method of `Display_List` with no arguments. The frame's drawing
function calls it at `0x00044D2F` (SPEC-003 §8.2). The list heads sit in an array at offset `0x30` of the
display list, 12 bytes per list. The function:

1. Calls the render context's method at `0x11C` with 0, and gets a value from `sub_00047E80`.
2. Draws list 7 (the head at `0x54`). If the list has anything, it first gets the render-context extension
   `0x10A` through the method at `0x194`. Then, for each element, it asks `sub_0003FFA0` whether to draw it. If yes, it sets the element's
   matrix around the drawing call through the global object at `0x00492F04` (its methods at `0x44`, `0x4C`
   and `0x48`), and draws the element (its method at `0x20`).
3. Does the same for list 8 (the head at `0x60`). It also gives each element a fade: the element's value from
   its method at `0x50`, set to 0 when it isn't above 0.0. It is passed through the drawable's method at
   `0x38`, and reset to 0 afterwards.
4. Draws the list at `0x39C` (list 77) the same way, with the fade, calling `sub_0025A500` to draw.
5. Calls the render context's method at `0x11C` with 1.

---

## 5. What to build

1. **`rcf.py`:**
   * a `name_hash(path)` function as §1.1 describes;
   * when an archive is opened, a check that every name hashes to its paired entry. On a mismatch it pairs by
     hash instead, warns, and keeps any name that can't be paired at all as now.
   * a `find_name(path)` (or similar) that finds an entry by its path through the hash.

   Tests on made-up archives, including one whose names are stored out of offset order.
2. **Matches,** each checked with `portal/verify.py --bin xb` and recorded the way the portal records them, so
   the registry and the generated files stay in step (`check_repo.py`). Credit `RRutherrfordd (Founder)`,
   with the tool `Claude (clean-room implementer, SPEC-004)`. Match as many as you can, smallest first:
   * `sub_0029A390`
   * `sub_00251310`
   * `sub_00282950`
   * `sub_002828C0`
   * `sub_0029A2F0`
   * `sub_00282820`
   * `sub_00042AB0`
   * `occlude::OccluderLoader::vfunc_06`

   A function that won't match after a fair try is left out, with a note on what differs.
3. **Names.** For each function matched, a name you choose from this spec's description: what it does, in
   the style of the repository's existing names. Put it where the repository keeps names for matched
   functions. If it has no place for that, use `reports/names.json` with `by` saying it comes from this spec.
   Names must not come from anywhere else.
4. **FORMATS.md** gets the archive's name hash beside the `.rcf` layout, with `sub_00251310`.
