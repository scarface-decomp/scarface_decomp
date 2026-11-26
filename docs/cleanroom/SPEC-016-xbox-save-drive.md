# SPEC-016: `core::XboxSaveDrive`, the Xbox save-file drive (parts 1 to 2c)

**Examiner:** Claude (AI assistant) for RRutherrfordd, 2026-11-25.
**Outside material read:** leaked source, read directly: the save-drive source file and header of the 2003
*Simpsons: Hit & Run* core library. It said how the functions are organised. Every fact below was then read
from `default.xbe`, and where the two differ this page follows Scarface.
**For the implementer:** build from this page, the repository and your own copy of the game. Do not open
the leaked tree. Names here are Scarface's own (run-time type information, the registry) or Microsoft's
public ones (Win32 error codes, Xbox API). Fields are given by offset; name them yourself.

This is the first whole-class spec written under the 25 November working method (CLEAN_ROOM.md, "How
the clean room is worked"). Part 1 (§1 to §6) covers the block cache, mounting and error translation: four open
functions and the data they share. Part 2a (§7) adds nine small functions around them. Part 2b follows.

## 1. Shared data

### 1.1 The object (`this` in ECX)

| Offset | Type | Role | Witness |
| :--- | :--- | :--- | :--- |
| +0xD0 | 32-bit enum | last error (values in §2) | written on every failure path below |
| +0xE4 | unsigned int | number of open files | 0x2BFF63: tested with an unsigned compare (`jbe`) |
| +0xE8 | char array | the drive's name. Its first character is tested against `'U'`; characters 7 and 8 are the port digit and the slot letter | 0x2BFF17, 0x2BFF29, 0x2BFF30 |
| +0xF9 | bool | mounted | 0x2BFFC9, 0x2C0015 |
| +0xFA | char | drive letter the system assigned at mount | 0x2BFFD3: its address is passed to the mount call |

### 1.2 File-scope variables

| Address | Type | Role |
| :--- | :--- | :--- |
| 0x4BDDF0 | 2 bytes | memory-unit state. Byte 0 is a mask of units present; byte 1 is a mask of units changed since last cleared. Bit number = port + slot × 4 |
| 0x4BFE38 | pointer | the transfer buffer (one block, 0x2000 bytes) |
| 0x4BFE3C | file handle | the file whose block is in the buffer |
| 0x4BFE40 | unsigned int | which block of that file is in the buffer |
| 0x4BFE44 | 32-bit enum | buffer state: 0 = nothing valid, 1 = valid and unchanged, 2 = changed and not yet written |

The memory-unit state has four small operations. Two are separate functions and two are always expanded
at the point of use. Write them accordingly:

* **Separate functions** (`this` = 0x4BDDF0 in ECX):
  * 0x2BF6A0: refresh both masks from the system. No arguments.
  * 0x2BF700: "is the unit at (port, slot) present". Two stack arguments, returns bool.
* **Expanded in place:** "has (port, slot) changed" and "clear the changed bit for (port, slot)". Both
  compute the bit as `(unsigned char)1 << (port + slot * 4)` and work on byte 1.

### 1.3 Functions this part calls

| VA | What it is |
| :--- | :--- |
| 0x2BF8F0 | member: writes the port and the slot through two `int*` arguments (order: port pointer, slot pointer) |
| 0x2BF930 | member: unmount, no arguments |
| 0x2BF7A0 | `__cdecl`, two arguments (file size, pointer to a 20-byte signature): computes the signature of the cached block; returns bool |
| 0x2C0030 | member, verified: takes a system error code; stores its translation as the last error |
| 0x233A64 | `GetFileSize(handle, NULL)` |
| 0x23383D | `SetFilePointer(handle, distance, NULL, FILE_BEGIN)` |
| 0x2335F6 | `ReadFile(handle, buffer, count, &done, NULL)` |
| 0x2336E3 | `WriteFile(handle, buffer, count, &done, NULL)` |
| 0x234B47 | `GetLastError()` |
| 0x396B85 | `XMountMU(port, slot, char* driveLetter)` |

## 2. 0x2BFE10: translate a system error code (256 bytes, open)

* **Signature:** member, one `unsigned int` argument, returns the 32-bit error enum. `ret 4`.
* **Source shape:** one `switch` on the argument with a `return` in every case. The compiler builds a
  byte-indexed jump table for values 0 to 0x11 (byte table 0x2BFEF4, jump table 0x2BFEDC) and compare
  chains for the rest.

| Argument | Win32 name | Returns |
| ---: | :--- | ---: |
| 0 | `ERROR_SUCCESS` | 0 |
| 2, 3, 15 | `ERROR_FILE_NOT_FOUND`, `ERROR_PATH_NOT_FOUND`, `ERROR_INVALID_DRIVE` | 1 |
| 11 | `ERROR_BAD_FORMAT` | 5 |
| 14 | `ERROR_OUTOFMEMORY` | 8 |
| 17 | `ERROR_NOT_SAME_DEVICE` | 3 |
| 0x1A | `ERROR_NOT_DOS_DISK` | 0xB |
| 0x1B | `ERROR_SECTOR_NOT_FOUND` | 5 |
| 0x22 | `ERROR_WRONG_DISK` | 3 |
| 0x55 | `ERROR_ALREADY_ASSIGNED` | 0 |
| 0x70 | `ERROR_DISK_FULL` | 7 |
| 0x3ED | `ERROR_UNRECOGNIZED_VOLUME` | 5 |
| 0x48F | `ERROR_DEVICE_NOT_CONNECTED` | see below |
| anything else | | 8 |

**The 0x48F case:**

1. Refresh the memory-unit state (0x2BF6A0).
2. Get the port and slot into two local `int`s (0x2BF8F0).
3. Return 3 if the unit is present (0x2BF700), otherwise 4. The compiler writes this as
   `neg al; sbb eax, eax; add eax, 4`, which a plain `if (present) return 3; else return 4;` produces.

**Codegen notes:**

* The two locals live in the argument slot and one pushed slot (`push ecx` at entry).
* `ERROR_OUTOFMEMORY` has its own case label even though it returns the default's value.
* `ERROR_ALREADY_ASSIGNED` is a separate case from `ERROR_SUCCESS`; both return 0.

## 3. 0x2BFF10: mount (288 bytes, open)

* **Signature:** member, no arguments, returns bool. Plain `ret`.

**Steps, in order:**

1. **Work out port and slot** (expanded in place here, although 0x2BF8F0 exists as a function):
   * If the drive name's first character is `'U'`, both are −1.
   * Otherwise port = (name character 7) − `'1'` and slot = (name character 8) − `'A'`, each read as a
     signed char.
2. **Refresh** the memory-unit state (0x2BF6A0).
3. **If port ≥ 0 and slot ≥ 0 and that unit's changed bit is set:**
   * If the open-file count is above zero: set the last error to what §2 returns for 0x48F (the whole
     0x48F case is expanded here, calls and all), and return false.
   * Otherwise clear the changed bit and call unmount (0x2BF930).
4. **If not mounted:** call `XMountMU(port, slot, &driveLetter)`.
   * Result 0: carry on.
   * Result 0x70: last error = 0xD; return false.
   * Any other result: last error = translate(result) through 0x2BFE10; return false.
5. Set mounted to true, last error to 0, and return true.

**Where Scarface differs from 2003** (facts about Scarface):

* The `'U'` branch in step 1, and the "port ≥ 0 and slot ≥ 0" guard in step 3.
* The special case for result 0x70 in step 4, with error value 0xD.

**Codegen notes:**

* Step 3's failure branch calls the translate logic expanded in place, so write it as a call to the
  translate function with the constant `ERROR_DEVICE_NOT_CONNECTED`; the compiler expands the single
  matching case.
* The function keeps port in EDI and slot in EBX across the whole body.

## 4. 0x2C0100: write the cached block back if it changed (272 bytes, open)

* **Signature:** member, no arguments, returns bool. Plain `ret`. Uses `this` only to record errors.

**Steps:**

1. If the buffer state is not 2, return true.
2. `size = GetFileSize(cachedHandle, NULL)`. If it is 0xFFFFFFFF, go to the failure exit.
3. Compute the block's signature into a 20-byte local (0x2BF7A0 with `size` and the local's address). If it
   returns false, go to the failure exit.
4. `start = cachedBlock * 0x2000` and `end = start + 0x2000`; if `end` is not below `size` (unsigned),
   `end = size`.
5. Copy the 20-byte signature into the buffer at offset `end - 20 - start`. The compiler copies it as five
   32-bit moves, which a `memcpy` of a 20-byte structure produces.
6. `SetFilePointer(cachedHandle, start, NULL, FILE_BEGIN)`. If the result is not `start`, go to the failure
   exit.
7. `WriteFile(cachedHandle, buffer, end - start, &written, NULL)`. If it returns 0, go to the failure exit.
8. Buffer state = 1; return true.

**Failure exit** (one shared tail at 0x2C012C, a second copy at 0x2C01E6): last error =
translate(`GetLastError()`) through 0x2BFE10; return false.

**Codegen notes:**

* Stack frame 0x18: the 20-byte signature and the `written` count.
* Steps 6 and 7 are one condition joined with `||`.
* In step 4 the byte count for step 7 is computed before 20 is subtracted from `end`.

## 5. 0x2C0760: load a block into the cache (416 bytes, open)

* **Signature:** member, two arguments (file handle, block number), returns bool. `ret 8`.

**Steps:**

1. If the buffer state is not 0, and the cached handle equals the handle, and the cached block equals the
   block: return true.
2. `size = GetFileSize(handle, NULL)`. If 0xFFFFFFFF: last error = translate(`GetLastError()`); return false.
3. Call §4's function. If it returns false, return false.
4. Buffer state = 0.
5. `start = block * 0x2000`; `end = start + 0x2000`, clamped to `size` as in §4; `count = end - start`;
   then `end -= 20`.
6. If `SetFilePointer(handle, start, NULL, FILE_BEGIN) != start` or
   `ReadFile(handle, buffer, count, &read, NULL)` returns 0: last error = translate(`GetLastError()`);
   return false.
7. Copy 20 bytes from the buffer at offset `end - start` into a local signature (five 32-bit moves).
8. Cached handle = handle; cached block = block.
9. Compute the signature of what was read into a second 20-byte local (0x2BF7A0 with `size`). If that
   returns false: call 0x2C0030 with `GetLastError()`, and return false.
10. Compare the two signatures (20 bytes; the compiler emits `repe cmpsd` over 5 dwords, which `memcmp`
    of two 20-byte structures produces). If they differ: last error = 0xC; return false.
11. Buffer state = 1; return true.

**Codegen notes:**

* Stack frame 0x30: two 20-byte signatures, the `read` count, and a saved copy of `this`.
* Step 9 calls the error-recording member out of line; steps 2 and 6 have the same logic expanded in
  place. Writing all three as calls to the same small member reproduces that: the compiler expands it
  where it chooses.

## 6. Error enum values seen so far

0 = no error; 1 = file not found; 3 = wrong media; 4 = no media; 5 = media not formatted; 7 = no free
space; 8 = hardware failure (the default); 0xB = media invalid; 0xC = data corrupt; 0xD = returned for a
full unit at mount. The meanings are the examiner's reading of the Win32 codes that map to each value.

## 7. Part 2a: the small functions around the cache (nine open functions)

Suggested names in this part are the examiner's own wording; rename freely.

### 7.1 More layout

| Offset | Type | Role | Witness |
| :--- | :--- | :--- | :--- |
| +0x10C | 4 entries of 0x208 bytes | directory-search pool. Each entry is a 0x204-byte search string followed by a 32-bit handle; an unused handle is 0xFFFFFFFF | 0x2BF948: loop of 4 from `this + 0x310`, step 0x208 |
| whole object | 0x92C bytes | | 0x2C0095: the allocation size |

### 7.2 Callees new in this part

| VA | What it is (confirm against your library names) |
| :--- | :--- |
| 0x396663 | `XGetDeviceChanges(type, &inserted, &removed)`; the type object passed is at 0x395660 |
| 0x23949C | `XCalculateSignatureBegin(flags)` |
| 0x2394B0 | `XCalculateSignatureUpdate(handle, data, size)` |
| 0x2394FE | `XCalculateSignatureEnd(handle, signature)` |
| 0x396CB7 | `XUnmountMU(port, slot)` |
| 0x30A4EB | closes a directory-search handle (one argument) |
| 0x250E80 | `__cdecl`, two arguments (value, 0x4000): used to round a size |
| 0x244450 | the engine's allocating `new` (allocator, size); see §8 |

### 7.3 0x2BF6A0: refresh the memory-unit state (96 bytes)

* **Signature:** member of the 2-byte state object (`this` = 0x4BDDF0), no arguments, no result.
* **Steps:**
  1. Call `XGetDeviceChanges` with two local 32-bit masks. If it returns 0, return.
  2. Fold each mask to 8 bits: `(mask & 0xF) | ((mask >> 12) & 0xF0)`. The compiler emits its
     bit-merge form (`shr 12; xor; and 0xF; xor`); the plain expression produces it.
  3. `present ^= inserted ^ removed;` then `changed |= inserted | removed;`.

### 7.4 0x2BF700: is the unit present (48 bytes)

* **Signature:** member of the state object, (int port, int slot), returns bool. `ret 8`.
* **Steps:** if port < 0 or slot < 0, return true. Otherwise return whether bit `port + slot * 4` of the
  present mask is set (`(unsigned char)1 << n`, then `!= 0`).
* **Scarface-only:** the negative-argument guard.

### 7.5 0x2BF730: on-disk size of a save (48 bytes)

* **Signature:** `__cdecl`, one `unsigned int` argument, returns `unsigned int`.
* **Result:** `size + 4 + 20 * ((size + 4 + 0x1FEB) / 0x1FEC)`. In words: a 4-byte header, plus one
  20-byte signature for every 0x1FEC bytes (a 0x2000 block less its signature), rounded up.
* **Codegen:** the division is by the constant 0x1FEC (the compiler's multiply by 0xA0643F with the
  subtract-shift-add fix-up, then `shr 12`), so write it as a division by a named constant.

### 7.6 0x2BF8A0: space a new save needs (80 bytes)

* **Signature:** member, two arguments (pointer to a structure, `unsigned int` size), returns
  `unsigned int`. `ret 8`. `this` is not used.
* **Steps:** compute §7.5's value for `size` (expanded in place); round it with 0x250E80(value, 0x4000);
  add 0x8000; if the first 32-bit field of the structure is not zero, add another 0x4000.

### 7.7 0x2BF7A0: signature of the cached block (96 bytes)

* **Signature:** `__cdecl`, (unsigned int fileSize, pointer to the 20-byte result), returns bool.
* **Steps:**
  1. `start = cachedBlock * 0x2000`; `end = start + 0x2000`, clamped to `fileSize` (unsigned).
  2. `h = XCalculateSignatureBegin(0)`. If `h` is 0xFFFFFFFF, return false.
  3. `XCalculateSignatureUpdate(h, buffer, end - start - 20)`.
  4. `XCalculateSignatureEnd(h, result)`. Return true.
* **Note:** the verified 0x2BF760 (50 bytes) is the general form of steps 2 to 4 (buffer, size, result).
  This one is the caller with that form expanded in place.

### 7.8 0x2BF930: unmount (144 bytes)

* **Signature:** member, no arguments, no result.
* **Steps:**
  1. If the drive letter (+0xFA) is `'U'`, return.
  2. If not mounted (+0xF9), return.
  3. For each of the 4 search-pool entries: if its handle is not 0xFFFFFFFF, close it (0x30A4EB) and set
     it to 0xFFFFFFFF.
  4. Work out port and slot (expanded in place, with the `'U'` name test as in §3 step 1).
  5. `XUnmountMU(port, slot)`; mounted = false.

### 7.9 0x2BF9C0: wide-string prefix test (64 bytes)

* **Signature:** member, two arguments (pointers to 16-bit characters), returns bool. `ret 8`. `this` is
  not used.
* **Steps:** walk both strings together. While the first string's character is not zero: if the second's
  is zero or differs, return false; advance both. Return true when the first string ends. So it answers
  "does the second string start with the first".

### 7.10 0x2C0090: create the drive (64 bytes)

* **Signature:** `__cdecl`, three arguments (pointer to the result pointer, drive name, allocator).
* **Steps:** store the allocator in the global 0x45894C; allocate 0x92C bytes with 0x244450; if that
  gave memory, construct the object (0x2BFB50, passing the drive name) and store the result through the
  first argument; otherwise store null.

### 7.11 0x2C0480: guarded forward (64 bytes)

* **Signature:** `__cdecl`. If the first argument is 0, return −3. If the second is 0, return −2.
  Otherwise call 0x2BFA00 with three arguments and return its result. What 0x2BFA00 does was not read.

## 8. Questions and answers (from the implementer's attempts, 2026-11-25)

Twelve of the thirteen functions in §2 to §7 are verified. Sizes given in this spec are padded extents
(to the next function); the verified code sizes are in the registry. What the attempts established:

* **Has-changed carries its own guard** (0x2BFF10). The "port ≥ 0 and slot ≥ 0" test of §3 step 3 is
  inside the always-expanded has-changed helper, which returns false for a negative argument. Witness:
  `setne cl; test cl, cl` at 0x2BFF5C, the merged result of two return paths. Clear-changed has no guard.
* **Is-present** (0x2BF700) is the mirror: it returns true for a negative argument. It is not a witness
  for the inlining level; the call is kept under every setting tried.
* **The core library is built with the default inlining level.** The translate function (§2) is an
  ordinary out-of-class member defined above mount; `/O2` expands its 0x48F case into mount as the game
  has it, and `/Ob1` does not. This corrects the examiner's reading in the note of 25 November.
* **0x2C0100:** the file-size failure and the signature failure are two separate `if` statements; the
  shared tail is the optimiser's merge. Steps 6 and 7 are one `||`. The signature is stored by structure
  assignment through a cast pointer.
* **0x2C0760:** the error-recording member 0x2C0030 is an ordinary out-of-class member (it stores the
  translation and returns whether it is zero); the compiler expands it at 0x2C07A7 and 0x2C08D6 and calls
  it at 0x2C0884. The compare is `memcmp(computed, stored)`; the locals are declared stored, then computed.
* **0x2BF6A0:** two `unsigned char` locals hold the folded masks.
* **0x2BF730 / 0x2BF8A0:** the divisor is written `0x2000 - 20`; the numerator is
  `size + 4 + divisor - 1`. 0x2BF8A0 is virtual (slot 6).
* **0x2BF7A0** calls an inline function with 0x2BF760's body.
* **0x2BF930** gets port and slot through an in-class inline helper taking two `int*`.
* **0x2C0090 (correction to §7.2):** the allocator 0x244450 takes (allocator, size), in that order. The
  constructor 0x2BFB50 takes (name, allocator).

## 9. The class's virtual tables (from the constructor's stores, 0x2BFB50)

| Table | Stored at | Slots | What it is |
| :--- | :--- | ---: | :--- |
| 0x3DB584 | +0 | 24 | the main table |
| 0x3DB56C | +0xC | 3 | a second base: 0x2BF800, 0x2BF810, 0x2BFD40 (all verified) |
| 0x3DB55C | +0xD8 | 3 | the signed-read interface: slot 0 = 0x2C0F80 (§10.4); 0x2BF880; 0x2BF890 |
| 0x3DB54C | +0xDC | 3 | the signed-write interface: slot 0 = 0x2C1020 (§10.5); 0x2BF880; 0x2BF890 |

The two interfaces' own tables (0x3DB52C, 0x3DB53C: three pure slots each) are stored first by their
inlined base constructors.

Main table, slot → function (open ones marked):

| Slot | VA | | Slot | VA | |
| ---: | :--- | :--- | ---: | :--- | :--- |
| 0 | 0x2AC390 | open, inherited | 12 | 0x2BF840 | |
| 1 | 0x2C1450 | | 13 | 0x2C0EC0 | open, §10.6 |
| 2 | 0x2D5920 | | 14 | 0x2BFCF0 | open, §10.8 |
| 3 | 0x2C00D0 | | 15 | 0x2BFD10 | |
| 4 | 0x2AC8C0 | open, inherited | 16 | 0x1284A0 | |
| 5 | 0x2BF830 | | 17, 18 | 0x14F2D0 | |
| 6 | 0x2BF8A0 | §7.6 | 19 | 0x2C10E0 | open, §10.7 |
| 7 | 0x4A770 | | 20 | 0x2C1180 | open, part 2c |
| 8 | 0x2BF820 | | 21 | 0x2C1300 | open, part 2c |
| 9 | 0x2C0900 | open, part 2c | 22 | 0x2BFD50 | |
| 10 | 0x29D8F0 | | 23 | 0x22710 | |
| 11 | 0x2C09C0 | open, part 2c | | | |

**Not virtual** (reached only by direct calls): 0x2BFE10, 0x2BFF10, 0x2BF930, 0x2C0030, 0x2C0100,
0x2C0760, 0x2BF8F0, 0x2BF9C0, 0x2C0210, 0x2C04C0, 0x2C06B0. **Not members:** 0x2BF730, 0x2BF760,
0x2BF7A0, 0x2BFA00, 0x2BFAA0, 0x2C0090, 0x2C0480, and the state object's 0x2BF6A0 and 0x2BF700.

**A start to remove:** 0x2C0920 is not a function. The slot-9 function begins at 0x2C0900, calls
0x2C04C0 at 0x2C0903 and runs on through 0x2C0920 to 0x2C09C0.

### 9.1 More layout

| Offset | Type | Role | Witness |
| :--- | :--- | :--- | :--- |
| +0xFC | 4 file handles | files whose first block still needs its size written | 0x2C0EE6: loop of 4, unsigned counter; cleared to 0xFFFFFFFF at 0x2C0F56 |

So the tail of the object is: +0xE4 open-file count, +0xE8 name (17 bytes), +0xF9 mounted, +0xFA drive
letter, +0xFC the four handles, +0x10C the search pool, end 0x92C.

## 10. Part 2b: text conversion, signed read and write, commit, delete

### 10.1 0x2BFA00: 16-bit text to 8-bit text, with a size limit (160 bytes, open)

* **Arguments:** destination (`char*`) in ECX, source (pointer to 16-bit characters) in EAX, then three
  on the stack, cleaned by the caller: A (passed through), the destination's capacity in bytes, C
  (passed through). Returns `int`.
* **Callers:** 0x2C0480 (§10.3) and 0x2C06B0, both in this file.
* **Steps:**
  1. If source and destination are the same pointer, return −5.
  2. `written = 0`. While the source's current 16-bit unit is not zero:
     1. Decode one character: 0x2A95A0(source, &unitsBytes, &character, C), `__cdecl`, returns bool. If
        false, return −2.
     2. Encode it: 0x2A9430(character, destination, capacity − written − 1, A, &produced, C), `__cdecl`,
        returns `int`. If the result is not 0: when it is −1, store a zero byte at the destination first;
        in both cases return the result.
     3. `source` advances by `unitsBytes` bytes; `destination` and `written` advance by `produced`.
  3. Store a zero byte at the destination and return 0.
* **Locals:** three 32-bit values (frame 0xC): the decoded character, the source bytes consumed, the
  bytes produced.
* **Codegen:** `written` is kept in EBX and zeroed with `xor`; the loop test is at the bottom, with a
  separate first test before the loop.

### 10.2 0x2BFAA0: 8-bit text to 16-bit text (176 bytes, open)

The mirror image of §10.1, same shape instruction for instruction:

* Destination (16-bit) in ECX, source (`char*`) in EAX, the same three stack arguments.
* The loop runs while the source byte is not zero.
* Decode with 0x2A93A0, encode with 0x2A9610, same argument lists.
* The room passed to the encoder is `capacity − written − 2`.
* The terminator stored is a 16-bit zero, on the normal exit and on the −1 exit.
* **Callers:** 0x2C09C0, 0x2C10E0 and 0x2C1180.

The two functions differ only in the character types and the helper pair, so one template, or two copies
of one function, are both possible sources. Try a function template over the two character types first.

### 10.3 0x2C0480: checked entry to §10.1 (64 bytes, open)

* **Signature:** `__cdecl`, five arguments (destination, source, A, capacity, C).
* **Steps:** destination null → −3; source null → −2; otherwise call §10.1 with destination in ECX,
  source in EAX and the last three arguments pushed in order, and return its result.
* **Caller:** 0x2C04C0 only. 0x2C06B0 calls §10.1 directly (this wrapper expanded there).

**On the register arguments.** Whether Visual C++ 7.1 gives a file-local function this convention under
plain `/O2`, or only with link-time code generation, is the open question from the previous round.
These two functions settle it with one compile: put §10.1 (as `static`) and §10.3 in one file under
`/O2` with no `/GL`. If the call site comes out as the game's (`mov ecx`, `mov eax`, three pushes,
`add esp, 0xC`), file-local functions get it without link-time code generation and the examiner's
claim of 24 November is withdrawn for every file-local case. If it comes out as an ordinary five-push
call, the claim stands.

### 10.4 0x2C0F80: read part of a signed block (160 bytes, open; signed-read interface slot 0)

* **Signature:** member reached through the interface at +0xD8 (the function subtracts 0xD8 from ECX to
  get the object). Seven stack arguments: handle, file name (unused), block, position, byte count,
  destination, memory-space value (unused). `ret 0x1C`. Returns a 32-bit status: 1 = done, 0 = failed.
* **Steps:**
  1. If mount (§3) fails, return 0.
  2. `size = GetFileSize(handle, NULL)`; on 0xFFFFFFFF record the translated `GetLastError()` and return 0.
  3. If `block * 0x2000 >= size` (unsigned): last error = 0; return 1.
  4. If load-block (§5) with (handle, block) fails, return 0.
  5. Copy `count` bytes from `buffer + position` to the destination (`memcpy`: `rep movsd` then
     `rep movsb`). Last error = 0; return 1.
* **Codegen:** the last-error store is written relative to the interface pointer (`[ebx - 8]`).

### 10.5 0x2C1020: write part of a signed block (192 bytes, open; signed-write interface slot 0)

* **Signature:** as §10.4 through the interface at +0xDC, with eight stack arguments: handle, file name
  (unused), block, position, byte count, source, pointer to a size result, memory-space value (unused).
  `ret 0x20`.
* **Steps:**
  1. If mount fails, return 0.
  2. `size = GetFileSize(handle, NULL)`; on 0xFFFFFFFF record the translated error and return 0.
  3. If load-block with (handle, block) fails, return 0.
  4. Buffer state = 0. Copy `count` bytes from the source to `buffer + position`. Buffer state = 2.
  5. Store through the size pointer: `size − 20 * ((size + 0x1FFF) >> 13)`.
  6. Last error = 0; return 1.
* **Scarface-only:** step 5 counts one signature per 0x2000 bytes of file. It is not §7.5's formula.
* **Codegen:** both stores to the buffer state survive, either side of the copy, so the state variable
  behaves as if it cannot be folded (the same as in §4 and §5).

### 10.6 0x2C0EC0: commit a file (192 bytes, open; main-table slot 13)

* **Signature:** member, (handle, file name unused), `ret 8`. Returns the same 32-bit status.
* **Steps:**
  1. If mount fails or write-back (§4) fails, return 0.
  2. Look through the four handles at +0xFC for one equal to the cached handle (`for` with an unsigned
     counter below 4). If none matches, go to step 6.
  3. If load-block with (handle, 0) fails, return 0.
  4. `size = GetFileSize(handle, NULL)`; on 0xFFFFFFFF record the translated error and return 0.
  5. Store `size` as the first 32-bit value of the buffer; buffer state = 2; if write-back fails, return
     0; set that list entry to 0xFFFFFFFF.
  6. Last error = 0; return 1.

### 10.7 0x2C10E0: delete a save (160 bytes, open; main-table slot 19)

* **Signature:** member, one argument (the save's name, `const char*`), `ret 4`. Frame 0x208.
* **Steps:**
  1. If mount fails, return 0.
  2. Build a 4-character drive string in a local: the drive letter (+0xFA), `':'`, `'\\'`, zero.
  3. If the name is not null, convert it to 16-bit text in a 0x204-byte local with §10.2 (stack
     arguments 0, 0x202, 0).
  4. Call 0x30A2CA with (drive string, 16-bit name). If the result is not 0: last error =
     translate(result); return 0.
  5. Last error = 0; return 1.
* 0x30A2CA is expected to be `XDeleteSaveGame`; confirm against your library names.
* **Scarface-only:** the name is converted directly, with no path building, and may be null.

### 10.8 0x2BFCF0: slot 14, a forward (32 bytes)

Corrected in §11: it takes eight stack arguments, drops the third, puts `this` first, adds 0xD8 to ECX
(the read interface) and jumps to 0x2CC160.

## 11. Questions and answers, second round (2026-11-25)

All eight functions of §10 are verified, with 0x2C0900 and 0x2C06B0 written from the bytes ahead of
this part. What the attempts established:

* **Register arguments need no link-time code generation.** A `static` function compiled with plain
  `/O2` gets its first parameter in ECX and its second in EAX, the rest on the stack, caller-cleaned
  (0x2BFA00 and 0x2C0480 match that way). The examiner's claim of 24 November (SPEC-014 §5.5) is
  withdrawn for every file-local function, and `reports/exam_regarg_xb.json` with it: no entry has
  callers in two provably different files.
* **0x2BFA00 / 0x2BFAA0** are one `static` function template over the two character types, or two
  `static` copies; both forms match. The −1 exit is `*out = 0; return -1;` with the literal. 0x2BFAA0
  needs the source walked through a local copy of the pointer.
* **0x2C0F80 / 0x2C1020:** the class has real multiple inheritance: a front part of 0xD8 bytes, then
  the two 4-byte interfaces. Each function overrides its interface's slot 0. 0x2C1020's size is
  `size - 20 * ((size + 0x1FFF) / 0x2000)`.
* **0x2C0EC0:** mount and write-back are two `if` statements. The search loop's form is free.
* **0x2C10E0:** `if (name != 0)` is also what an always-expanded checked wrapper around 0x2BFAA0
  leaves.
* **0x2BFCF0 (correction to §10.8):** it takes **eight** stack arguments (file, name, unused,
  position, destination, count, pointer to a done-count, memory space), drops the third, and tail-calls
  0x2CC160 on the read interface with (this, file, name, position, destination, count, done, space).
  0x2BFD10 (slot 15) is the same into 0x2CC250 with nine.
* **0x2CC160 / 0x2CC250** are non-virtual members of the two interface classes, `core::SignedReader`
  and `core::SignedWriter` (the names are in the run-time type information of tables 0x3DB52C and
  0x3DB53C). They split a read or write into a first partial block, whole blocks and a remainder,
  calling slot 0 for each; slots 1 and 2 give the block's data size and the header size.
* **0x250E60** rounds down to a multiple; **0x250E80** rounds up.
* **0x2C0900 (slot 9):** calls 0x2C04C0, then, unless the drive letter is `'U'`: if files are open and
  the unit changed, sets both error fields (+0x7C and +0xD0) to 3 if the unit is present and 4 if not,
  as an `if`/`else` with two stores each, and returns 0; if no files are open, clears the changed bit
  (guarded). It returns whether the last error is 0. Is-present is expanded here.
* **0x2C06B0:** member with four arguments (entry, find data, search handle, prefix); fills one
  directory entry from a find result, using 0x2BF9C0 and the checked conversion of §10.3 expanded.
* **0x2C0920** is not a function start.

## 12. Part 2c: media information, file initialisation, and a neighbour that is another class

### 12.1 More layout: the media-information block in the base part

| Offset | Type | Role | Witness |
| :--- | :--- | :--- | :--- |
| +0x7C | 32-bit enum | media state. Scarface stores the drive's **error value** here (same numbers as +0xD0) | 0x2C057E, 0x2C05AA, 0x2C0623, 0x2C0639, 0x2C064D |
| +0x80 | unsigned int | free space in bytes, 0xFFFFFFFF if it does not fit | 0x2C0658, 0x2C0668 |
| +0x84 | unsigned int | free space in sectors | 0x2C069D |
| +0x88 | unsigned int | sector size, default 0x200 | 0x2C04D5 |
| +0x8C | char[0x41] | volume name | 0x2C05B7: cleared as 0x10 dwords and one byte |

### 12.2 0x2C04C0: refresh the media information (496 bytes padded, open; not virtual)

* **Signature:** member, no arguments, no result. Frame 0x5C.
* **Locals:** a 16-bit name buffer of 0x20 characters; three 64-bit values; a 4-character drive string.
* **Steps:**
  1. Sector size = 0x200; free space = 0; free sectors = 0.
  2. If the drive letter (+0xFA) is not `'U'`:
     1. Volume name's first character = 0.
     2. Work out port and slot (expanded, with the `'U'` name test giving −1, −1).
     3. Refresh the memory-unit state (0x2BF6A0).
     4. If has-changed(port, slot) (expanded, guarded): unmount (0x2BF930).
     5. If is-present(port, slot) is false (expanded; negative arguments count as present): media
        state = 4 and last error = 4; return.
     6. If mount (§3) fails: media state = last error; return.
     7. `code = translate(XMUNameFromDriveLetter(driveLetter, wideName, 0x20))`. If `code` is not 0:
        media state = `code`; volume name's first character = 0; return. The last error is not written
        on this path.
     8. Clear the whole volume name (0x41 bytes), then convert `wideName` into it with the checked
        conversion 0x2C0480(volumeName, wideName, 0, 0x41, 0). This is a real call (0x2C05CF).
  3. Build the drive string: drive letter, `':'`, `'\\'`, zero.
  4. `GetDiskFreeSpaceExA(drive, &freeToCaller, &total, &totalFree)`. If it returns 0: volume name's
     first character = 0; `e = translate(GetLastError())`; media state = `e`; last error = `e`; return.
  5. Media state = 0; last error = 0.
  6. Free space = 0xFFFFFFFF if `freeToCaller`'s high half is not 0, otherwise its low half.
  7. `s = XGetDiskSectorSizeA(drive)`; sector size = `s` if not 0, otherwise 0x200.
  8. Free sectors = free space / sector size (unsigned).
* **Where Scarface differs from 2003** (facts about Scarface): the media state holds the error value
  directly, with no second enum; several paths write the last error as well; the volume name is fetched
  as 16-bit text into a local and converted; "not present" is value 4.
* **Codegen notes:**
  * EDI is zeroed at entry and used as the constant 0 for the stores in steps 1 and 5; it is reloaded
    with the slot in between and zeroed again at 0x2C05D7.
  * In step 2.8 the clear (`rep stosd`, `stosb`) is interleaved with the pushes for the call.
  * In step 6 the test is `high != 0` first, with the 0xFFFFFFFF store in the taken branch.
  * Is-present and has-changed each leave `setne al; test al, al`: both are in-class inline functions
    returning bool.

### 12.3 0x2C0210: write a new save file's blocks (624 bytes padded, open; not virtual)

* **Signature:** member, three arguments (handle, `unsigned int` size, `bool` valid-header), returns
  bool. `ret 0xC`. Frame 0x1C: a 20-byte signature, the written count, a saved `this`.
* **Steps:**
  1. If write-back (§4) fails, return false.
  2. Buffer state = 0. Clear the whole 0x2000-byte buffer.
  3. `remaining = size`. If valid-header: store `size` as the buffer's first 32-bit value.
  4. If `size > 0x2000` (unsigned): sign the first 0x1FEC bytes of the buffer and copy the 20-byte
     signature to `buffer + 0x1FEC`. The signing is 0x2BF760's body expanded (begin; −1 fails;
     update; end). On failure: record the translated `GetLastError()` and return false.
  5. If `SetFilePointer(handle, 0, NULL, FILE_BEGIN)` is not 0: record the translated error; return
     false.
  6. `block = 0`. While `remaining > 0x2000`:
     1. `WriteFile(handle, buffer, 0x2000, &written, NULL)`; on 0 fail.
     2. If `block == 0` and valid-header: store 0 as the buffer's first 32-bit value, sign the first
        0x1FEC bytes again (expanded) and copy the signature to `buffer + 0x1FEC`; a −1 from begin
        fails.
     3. `remaining -= 0x2000; block++`.
  7. If `remaining > 0`:
     1. Store 0 as the buffer's first 32-bit value.
     2. Sign `remaining - 20` bytes with a **call** to 0x2BF760(buffer, remaining − 20, &signature); on
        false fail.
     3. Copy the signature to `buffer + remaining - 20`.
     4. `WriteFile(handle, buffer, remaining, &written, NULL)`; on 0 fail.
     5. `block++`.
  8. Cached handle = handle; cached block = `block - 1`; buffer state = 1; return true.
* **Failure exits:**
  * Steps 4 and 5 have the error-recording member expanded, each with its own exit (0x2C02F3,
    0x2C02D4).
  * Every failure in steps 6 and 7 shares one exit at 0x2C045D, which **calls** 0x2C0030 with
    `GetLastError()`.
* **Codegen notes:**
  * `remaining` is EBX; `block` is EBP inside the loop (EBP holds `this` before it, saved at
    `[esp+0x10]`).
  * The 4-byte stores are plain `mov dword` (a `memset`/`memcpy` of 4 bytes).
  * The signature copies are five 32-bit moves each.
  * The end is `inc ebp` then `dec ebp`: `block++` in 7.5 and `block - 1` in step 8, not folded.
  * The media-state field +0x7C is not written here.

### 12.4 0x2C13E0 is not this class: it is `core::DriveThread`'s destructor (107 bytes, open)

* **Witness:** it stores the three tables 0x3DB608 (+0), 0x3DB600 (+4) and 0x3DB5F0 (+0xC), whose
  run-time type information says `core::DriveThread`. Its only caller is 0x2C1BE3, inside that
  class's slot-3 deleting destructor.
* **Steps:**
  1. Store the three tables.
  2. Set the byte at +0x64 to 1.
  3. Call, each with one pushed argument and one shared `add esp, 0x14` after the last:
     0x283BD0(this + 0x68); 0x283AF0(this + 0x18); 0x283DD0(this + 0x18); 0x283BB0(this + 0x68);
     0x283BB0(this + 0xB8).
  4. The base destructors, expanded: store 0x3DAC24 (`core::SafeRefCount`) at +0xC; copy +8 into the
     global 0x45894C (the current allocator); store 0x39F08C at +4 and 0x39E22C at +0.
* 0x283BD0, 0x283DD0 and 0x283BB0 are verified already; 0x283AF0 (32 bytes) is open.

## 13. Still to come (part 2d)

The directory search (0x2C1180, 0x2C1300), the constructor (0x2BFB50) and the save-file open
(0x2C09C0).
