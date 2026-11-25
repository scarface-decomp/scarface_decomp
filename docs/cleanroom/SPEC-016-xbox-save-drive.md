# SPEC-016: `core::XboxSaveDrive`, the Xbox save-file drive (part 1 of the class)

**Examiner:** Claude (AI assistant) for RRutherrfordd, 2026-11-25.
**Outside material read:** leaked source, read directly: the save-drive source file and header of the 2003
*Simpsons: Hit & Run* core library. It said how the functions are organised. Every fact below was then read
from `default.xbe`, and where the two differ this page follows Scarface.
**For the implementer:** build from this page, the repository and your own copy of the game. Do not open
the leaked tree. Names here are Scarface's own (run-time type information, the registry) or Microsoft's
public ones (Win32 error codes, Xbox API). Fields are given by offset; name them yourself.

This is the first whole-class spec written under the 25 November working method (CLEAN_ROOM.md, "How
the clean room is worked"). Part 1 covers the block cache, mounting and error translation: four open
functions and the data they share. The rest of the class follows in part 2.

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

## 7. Still to come (part 2)

The constructor (0x2BFB50), the save-file open (0x2C09C0, 1,280 bytes), file initialisation (0x2C0210),
the signed block read and write, the directory search (0x2C1180, 0x2C1300), and the small members
between them.
