# SPEC-017: `core::Drive`, the base class of every file drive

**Examiner:** Claude (AI assistant) for RRutherrfordd, 2026-11-25.
**Outside material read:** leaked source, read directly: the drive base class's source file and header,
the locked reference-count header and the request header of the 2003 *Simpsons: Hit & Run* core
library. It said how the functions are organised. Every fact below was then read from `default.xbe`,
and where the two differ this page follows Scarface.
**For the implementer:** build from this page, the repository and your own copy of the game. Do not open
the leaked tree. Class names are Scarface's own, from its run-time type information. Fields are given
by offset; name them yourself. Function titles are the examiner's own wording.

Scope: the 20 open functions between 0x2AC390 and 0x2AC9C2, which are one source file, and the layout
of the 0xD8-byte front part that SPEC-016 builds on. 0x2AC9D0 (112 bytes, a binary search with its
count in ECX and its element size in EDI) is called only from 0x2AD0D0 and belongs to the next file.

## 1. Bases, from the run-time type information

`core::Drive` (class hierarchy descriptor 0x4138B0) has these bases, in this order:

| Offset | Base | Its own table | Notes |
| :--- | :--- | :--- | :--- |
| +0x00 | `core::IRefCount` (a `struct`) | 0x39E22C | pure virtual slots |
| +0x04 | `core::Object`, which derives from `core::BaseObject` | 0x39F094 (`Object`), 0x39F08C (`BaseObject`) | one slot (the destructor); +4 of this part (object +8) is the allocator |
| +0x0C | `core::SafeRefCount`, which derives from `core::IMutable` (a `struct`) | 0x3DAC24 | slot 0 lock (pure), slot 1 unlock (pure), slot 2 destructor (0x2AC7C0, verified); +4 of this part (object +0x10) is the count |

This corrects my last note: the part at +4 is `core::Object`, and `core::BaseObject` is its base.
`core::DriveThread` (0x3DB608) has the same three bases in the same order.

`core::Drive`'s own tables: 0x3DAC4C at +0 (24 slots), 0x3DAC44 at +4 (one slot: 0x2AC7A0, `sub ecx,
4; jmp 0x2AC860`), 0x3DAC34 at +0xC (two pure slots, then 0x2AC7B0, `sub ecx, 0xC; jmp 0x2AC860`).

Main table, slots that are this class's own code: 0 = 0x2AC390 (open), 1 = 0x2C1450 (verified: `add
ecx, 0xC; jmp 0x2AC3B0`), 3 = 0x2AC860 (open), 4 = 0x2AC8C0 (open). Slots 5, 8, 9, 12 and 14 are pure.
The rest are verified small bodies.

## 2. Layout of the front part (0xD8 bytes)

| Offset | Type | Role | Witness |
| :--- | :--- | :--- | :--- |
| +0x00 | table pointer | `IRefCount` part | 0x2AC7E3 |
| +0x04 | table pointer | `Object` part | 0x2AC7E9 |
| +0x08 | 32-bit | allocator, copied from the global 0x45894C at construction | 0x2AC7F0 |
| +0x0C | table pointer | `SafeRefCount` part | 0x2AC7F8 |
| +0x10 | int | reference count, starts at 1 | 0x2AC7FF |
| +0x14 | object, 0x40 bytes | the library list. Constructor 0x2AD160 (verified), destructor 0x2ACC30 (open, next file). Inside it: +0x14 is a mutex | 0x2AC81D, 0x2AC87A |
| +0x54 | pointer | head of the list of finished callback requests (`core::CompletionCallbackRequest`; its +4 is the next pointer) | 0x2AC44E, 0x2AC8DA |
| +0x58 | pointer | tail of that list | 0x2AC45E, 0x2AC946 |
| +0x5C | 32-bit enum | error behaviour: 0 by default, 2 once a handler or an event is registered | 0x2AC4A8, 0x2AC509 |
| +0x60 | pointer | semaphore to signal when an error occurs (a plain structure whose first field is the system handle, not an interface) | 0x2AC5F7 |
| +0x64 | pointer | the thread that registered the error handler | 0x2AC49B |
| +0x68 | pointer | error handler (an interface; slot 0 is the notification) | 0x2AC4A0, 0x2AC996 |
| +0x6C | pointer | the handler's user data | 0x2AC4A5 |
| +0x70 | bool | in error | 0x2AC5EC |
| +0x74 | `core::Request*` | the request that failed. **Scarface-only member** | 0x2AC5E9, 0x2AC626 |
| +0x78 | bool | report when an error clears; starts true | 0x2AC83F |
| +0x79 | bool | inside the error handler | 0x2AC95D |
| +0x7C | 0x54 bytes | media information (SPEC-016 §12.1) | 0x2AC430 |
| +0xD0 | 32-bit enum | last error; starts at 3 | 0x2AC846 |
| +0xD4 | pointer | the drive thread; starts null | 0x2AC850 |

`core::Request` has seven slots; slots 5 and 6 take no arguments and return a 32-bit value.

"Lock" and "Unlock" below are slots 0 and 1 of the +0xC part, always called through the table with ECX
= `this + 0xC`. Every function that locks keeps `this + 0xC` in a callee-saved register (`lea`), so
write them as calls to the base's virtual members from a `core::Drive` member.

## 3. Callees

| VA | What it is |
| :--- | :--- |
| 0x283EB0 | verified, no arguments: returns the current thread's object |
| 0x283BD0 | verified, `__cdecl`, one argument: signals the semaphore structure passed |
| 0x239EC0 | `mov al, 1; ret 4`, shared with many identical functions by the linker. Here it is a member of the callback request taking the thread, defined in another source file, so it is called and not expanded |
| 0x2C1790 | verified, member of the drive thread: (bool retry) |
| 0x2C1620, 0x2C1700 | open, members of the drive thread, two arguments each |
| 0x2444F0 | verified, `__cdecl`: (allocator, pointer) frees |
| 0x250EB0 | verified, no arguments (SPEC-016 §14.2 step 5 calls it too) |

## 4. The functions

Each is a member with `this` in ECX unless it says otherwise.

### 4.1 0x2AC390: add a reference (main-table slot 0, 32 bytes padded)

Lock; count += 1; Unlock. The unlock is a tail jump (`jmp [edx + 4]`). This is the base's "locked
increment" expanded into the slot function.

### 4.2 0x2AC3B0: drop a reference (48 bytes padded; `this` is the `SafeRefCount` part)

* Lock; count −= 1.
* If the count is now 0: count = 0x5DC; Unlock; call this part's slot 2 with the argument 1 (delete).
* Otherwise: Unlock, as a tail jump.
* The zero branch is inline; the other is the last two instructions (`pop esi; jmp [edx + 4]`).
* Callers: 0x2C1450 (slot 1 above) and 0x2ACEB0 (`core::CementLibrary`). It is the base's "locked
  decrement", kept as one shared out-of-line copy and reached by a jump from each class's slot.

### 4.3 The locked accessors

| VA | Size (padded) | Arguments | Body between Lock and Unlock | Returns |
| :--- | :--- | :--- | :--- | :--- |
| 0x2AC3E0 | 32 | none | read +0xD0 | that value |
| 0x2AC400 | 48 | (value), `ret 4` | +0xD0 = value | nothing |
| 0x2AC4F0 | 48 | (semaphore), `ret 4` | +0x60 = semaphore; +0x5C = 2 | nothing |
| 0x2AC520 | 48 | (behaviour), `ret 4` | +0x5C = behaviour | nothing |
| 0x2AC550 | 32 | none | read +0x5C | that value |
| 0x2AC5B0 | 32 | none | read the bool at +0x70 (held in BL) | that bool |

The getters copy the member into a local between the two calls and return the local. 0x2AC400 is
Scarface-only.

### 4.4 0x2AC440: append a finished callback request (64 bytes padded)

* (request), `ret 4`.
* Lock. If head (+0x54) is null: head = request. Otherwise tail->next (+4) = request. Then
  request->next = 0; tail = request. Unlock.

### 4.5 0x2AC480: register the error handler (64 bytes padded)

* (handler, user data), `ret 8`.
* Lock; +0x64 = current thread (0x283EB0); +0x68 = handler; +0x6C = user data; +0x5C = 2; Unlock.
* The call to 0x283EB0 comes first, right after Lock, before the arguments are read.

### 4.6 0x2AC4C0: unregister the error handler (48 bytes padded)

* One argument, not read; `ret 4`.
* Lock; +0x68 = 0; +0x64 = 0; +0x5C = 0; Unlock. The three stores are in that order.

### 4.7 0x2AC570: resume after an error (64 bytes padded)

* (bool retry), `ret 4`.
* Lock; +0x70 = false; +0x74 = 0; Unlock; then call 0x2C1790 on the drive thread (+0xD4) with `retry`.
* **Scarface-only:** the lock, and the clearing of +0x74.

### 4.8 0x2AC5D0: enter the error state (64 bytes padded)

* (the failed request), `ret 4`.
* Lock; +0x74 = request; +0x70 = true. If the semaphore (+0x60) is not null: Unlock, then
  0x283BD0(semaphore). Otherwise: Unlock.
* Both stores come after Lock. The semaphore branch is inline; the other is behind its `ret`.
* **Scarface-only:** the argument and the +0x74 store.

### 4.9 0x2AC610: describe the current error (96 bytes padded; Scarface-only)

* (pointer to a 32-bit value, pointer to a 32-bit value), `ret 8`, returns bool.
* Lock. If in error (+0x70): `*first` = the failed request's slot 6(); `*second` = its slot 5();
  result true. Otherwise result false. Unlock; return the result.
* The bytes have two separate endings, each `Unlock; return`, with the result held in BL across
  the unlock (`mov bl, 1` at 0x2AC646, `xor bl, bl` at 0x2AC657). The true ending is inline.
* +0x74 is re-read from the object for each of the two calls.

### 4.10 The unlocked small ones

| VA | Size (padded) | What |
| :--- | :--- | :--- |
| 0x2AC670 | 16 | (bool), `ret 4`: +0x78 = the argument |
| 0x2AC6C0 | 32 | (a), `ret 4`: calls 0x2C1620 on the drive thread with (a, 0). The verified 0x2AC6E0 is the two-argument form, a plain jump |
| 0x2AC6F0 | 32 | (a), `ret 4`: calls 0x2C1700 on the drive thread with (a, −1). The verified 0x2AC710 is the two-argument form |

### 4.11 0x2AC7E0: the constructor (128 bytes padded)

No arguments; returns `this`. In order:

1. +0 ← 0x39E22C.
2. +4 ← 0x39F094.
3. +8 ← the global 0x45894C.
4. +0xC ← 0x3DAC24; +0x10 ← 1.
5. +0 ← 0x3DAC4C; +4 ← 0x3DAC44; +0xC ← 0x3DAC34.
6. Construct the member at +0x14 with 0x2AD160, called.
7. Zero, in this order: +0x54, +0x58, +0x5C, +0x60, +0x64, +0x68, +0x6C, the byte at +0x70, +0x74.
   Then the byte at +0x78 = 1; the byte at +0x79 = 0; +0xD0 = 3; +0xD4 = 0.
8. Call 0x250EB0.

Notes:

* `BaseObject`'s own table (0x39F08C) is never stored here; only `Object`'s is.
* EAX is zeroed once after step 6 and supplies every zero.
* +0x74 is initialised between +0x70 and +0x78, so it is declared between those two `bool`s.
* The base constructors and the count's initial value 1 are all expanded.

### 4.12 0x2AC860: the destructor with the delete flag (main-table slot 3, 96 bytes padded)

(flags), `ret 4`, returns `this`. In order:

1. +0 ← 0x3DAC4C; +4 ← 0x3DAC44; +0xC ← 0x3DAC34.
2. Destroy the member at +0x14 with 0x2ACC30, called.
3. +0xC ← 0x3DAC24.
4. The global 0x45894C ← +8.
5. +4 ← 0x39F08C; +0 ← 0x39E22C.
6. If `flags & 1`: 0x2444F0(the global 0x45894C, `this`).

Notes:

* The class's destructor body is empty; everything above is the compiler's.
* `Object`'s table (0x39F094) is never stored here; only `BaseObject`'s is. That mirrors §4.11.
* Step 6 re-reads the global from memory. So the class's `operator delete` is a one-line function
  that frees through the global, and the base destructor of the +4 part is what sets the global.
  This agrees with your H3.
* The `test byte ptr [esp + 8], 1` sits between steps 4 and 5.

### 4.13 0x2AC8C0: service (main-table slot 4, 272 bytes padded)

No arguments, no result. Frame 0xC: +0 "last kept", +4 the current thread, +8 "next".

1. `thread` = 0x283EB0(). Lock.
2. `walk` = the address of head (+0x54). `last kept` = null.
3. While `*walk` is not null:
   * If 0x239EC0 called on `*walk` with `thread` returns true: `current = *walk`; `*walk =
     current->next`; Unlock; call `current`'s slot 7 (no arguments); Lock; delete `current` (its
     slot 0 with the argument 1).
   * Otherwise: `last kept = *walk`; a local `next = (*walk)->next`; `walk = &next`.
4. tail (+0x58) = `last kept`.
5. If the bool at +0x70 **equals 1** and the handler (+0x68) is not null:
   * If the bool at +0x79 is false:
     1. +0x79 = true; Unlock.
     2. `answer` = handler's slot 0 with five arguments: (last error (+0xD0), this object's slot 5
        (the drive's name), failed request's slot 6(), failed request's slot 5(), user data
        (+0x6C)).
     3. Call 0x2AC570 (§4.7) with `answer`.
     4. +0x79 = false.
   * Otherwise: Unlock.

   Otherwise: Unlock.

**Where Scarface differs from 2003** (facts about Scarface): step 5 does not compare threads; there is
one form of the handler call, with five arguments, two of them taken from the failed request.

**Codegen notes:**

* `this` in ESI, `this + 0xC` in EDI, `walk` in EBX. EBP is pushed only when the loop is entered
  (0x2AC8EC) and popped when it ends (0x2AC93D). The loop top is padded to 0x2AC8F0.
* The loop is entered through a first test of head (`mov eax, [esi + 0x54]; test eax, eax`) and
  closes with `cmp dword ptr [ebx], 0; jne`.
* In the "otherwise" arm, `last kept` passes through EBX: `mov ebx, [ebx]; mov eax, [ebx + 4];` store
  `last kept`; store `next`; `lea ebx, [next]`.
* Step 5's first test is `cmp byte ptr [esi + 0x70], 1`, placed before step 4's store. A plain
  truth test would give `test al, al`; the source compares the `bool` with `true`.
* Step 5.2, in byte order: read +0x74 into ECX, the handler into EAX, user data into EDX; read the
  handler's table into EBX; copy +0x74 to EDI; push user data; store +0x74 into the frame's +8
  slot; call slot 5 of the request; push the result; call slot 6; push; call this object's slot 5;
  push; push last error; re-read the handler from +0x68 into ECX; `call [ebx]`.
* Three endings: the main one (0x2AC9A0), "already inside the handler" (0x2AC9AB), and "not in
  error or no handler" (0x2AC9B5), in that order, each with its own unlock and return.
* The result of the handler is pushed as a whole register.

## 5. Where each helper is called and where it is expanded

| Helper | Called | Expanded |
| :--- | :--- | :--- |
| locked increment | | 0x2AC390 |
| locked decrement | 0x2AC3B0 is the one copy; slots jump to it | |
| Lock, Unlock | every use, through the table | |
| base constructors and destructors | | 0x2AC7E0, 0x2AC860 |
| member at +0x14: constructor, destructor | 0x2AC81D, 0x2AC87A | |
| "is this the request's thread" 0x239EC0 | 0x2AC8F7 | |
| resume, 0x2AC570 | 0x2AC99B, and by jump from 0x2ABD70 | |
| "is in error" 0x2AC5B0 | from `core::InstanceDrive` | not used inside this file: §4.13 reads +0x70 directly |

## 6. Status

Nothing here has been compiled. No second reviewer has read the page.
