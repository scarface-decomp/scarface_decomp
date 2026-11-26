# SPEC-019: `core::InstanceDrive` and `core::File`

**Examiner:** Claude (AI assistant) for RRutherrfordd, 2026-11-26.
**Outside material read:** no leaked file was opened for this page; bytes and run-time type information of
`default.xbe` only. The examiner had already read the 2003 drive base class's source for SPEC-016 to
SPEC-018 and is therefore not a clean reader.
**Status:** nothing compiled; no second reviewer. Class-card format: patterns first, then one line per slot.

## 1. Shared pieces

| Name here | VA | What |
| :--- | :--- | :--- |
| Alloc(n) | 0x2A9880 | verified, `__cdecl`, one argument: the request classes' allocator |
| FileAlloc(n) | 0x2AAEA0 | verified, `__cdecl`: `core::File`'s allocator |
| Queue(r, priority, atHead) | 0x2AC690 | verified member of `core::Drive`: forwards to the drive thread's queue |
| Split | 0x251220 | open, `__cdecl`, five arguments: splits a name into parts |
| caps | drive's slot 8 (`[table + 0x20]`) | returns flags; bit 7 is tested as `test al, al; jns` |

**Pattern P, "post a request":** `r = new Class(args)` through Alloc, then `drive->Queue(r, priority,
atHead)`, with `drive` = +0xC and `priority` = +0x10 re-read after the constructor. A null from Alloc
queues a null. Two emitted shapes: **D**, the Queue call duplicated in the null arm (`xor eax, eax` and
pushes of EAX for the zeros), and **J**, the arms joined before one Queue call.

**Pattern S, "split the name"** (frame 0x120): locals +0 `const char* a = 0`; +4 `const char* b = 0`;
+8 char[0x14]; +0x1C char[0x104]. `Split(name, +0x1C, +8, &b, &a)`; `p = b`; if `caps & 0x80`, `p = a`.
The two zero stores (a, then b) sit between the last push and the call; `b` is read into EDI before the
stack is cleaned and before caps is called.

## 2. `core::InstanceDrive`

Bases (RTTI): `core::IDrive` (: `core::IRefCount`) at +0, `core::IMutable` at +4. Tables 0x3DAB3C (50
slots) and 0x3DAB30 (+4: lock 0x2AB770, unlock 0x2AB780, both verified).

| Offset | Type | Role |
| :--- | :--- | :--- |
| +0x08 | int | reference count (a member of this class, not of a counting base) |
| +0x0C | `core::Drive*` | the real drive |
| +0x10 | 32-bit | priority passed to Queue |
| +0x14 | 32-bit | tested `== 0` by slot 22 |
| +0x18 | 32-bit | returned by slot 24 when the drive is not in error (examiner's reading: this object's own last error) |
| +0x20 | bool | a directory search is open |

| Slot | VA | Size | Arguments | Body |
| :--- | :--- | :--- | :--- | :--- |
| 0 | 0x2AB6D0 | 32 | none | Lock; count += 1; Unlock as a tail jump. `this` stays in EDI, the +4 part in ESI. Shared with `core::File` slot 0 |
| 1 | 0x2AB6F0 | 128 | none | Lock; count −= 1. Not zero: Unlock, tail jump (last block, 0x2AB76A). Zero and +0x20 set: +0x20 = false; Unlock; P(0xC, `DriveFindCloseRequest` 0x2AAD30 (this), atHead 0), shape D. Zero and +0x20 clear (0x2AB754): count = 0x5DC; Unlock; own slot 3 with 1 |
| 5 | 0x2AB7A0 | 80 | (a) | P(0x10, `DriveMediaRequest` 0x2AABE0 (this, a), 0), D |
| 6 | 0x2AB7F0 | 64 | none | P(0xC, `DriveFormatRequest` 0x2AAC10 (this), 0), D |
| 7 | 0x2AB830 | 144 | (name) | S; P(0x20, `DriveCreateDirectoryRequest` 0x2AAC30 (this, p), 0), J |
| 8 | 0x2AB8C0 | 144 | (name) | S; P(0x20, `DriveDestroyDirectoryRequest` 0x2AAC70 (this, p), 0), J |
| 9 | 0x2AB950 | 160 | (name, b) | S; P(0x114, `DriveFindFirstRequest` 0x2AACB0 (this, p, b), 0), J |
| 10 | 0x2AB9F0 | 80 | (a) | P(0x10, `DriveFindNextRequest` 0x2AAD00 (this, a), 0), D |
| 11 | 0x2ABA40 | 144 | (name) | S; P(0x110, `DriveFileDestroyRequest` 0x2AAD50 (this, p), 0), J |
| 19 | 0x2ABBA0 | 64 | none | P(0xC, `DriveCancelRequest` 0x2AAE00 (this), atHead 1), D |
| 20 | 0x2ABBE0 | 96 | (a, b) | P(0x18, `DriveCompletionRequest` 0x2AA730 (current thread, this, a, b), 0), D. The allocation is kept in EDI; 0x283EB0 is called after b, a and `this` are pushed |
| 21 | 0x2ABC40 | 80 | (a) | P(0x10, `CompletionEventRequest` 0x2AA580 (a, drive), 0), D. Shared with `core::File` slot 20 |
| 22 | 0x2ABC90 | 48 | none | Lock; `b = (+0x14 == 0)` (`sete bl`); Unlock; return b |
| 24 | 0x2ABCF0 | 64 | none | Lock; if the drive is in error (0x2AC5B0): e = drive's last error (0x2AC3E0), else e = +0x18; Unlock; return e. Two endings, the error arm first |
| 34 | 0x2ABDB0 | 208 | (File** out, name, a3..a8), `ret 0x20` | S; `m = FileAlloc(0x168)`; `*out = m ? ctor 0x2AB570 (m; drive, p, a3, a4, a5, a6, a7, a8, 1) : 0`. Two endings, each stores `*out`. No Queue here |
| 36 | 0x2ABEC0 | 208 | (File** out, name, a3..a7), `ret 0x1C` | the same with ctor 0x2AB470 (m; drive, p, a3, a4, a5, a6, a7) |

The request class at each row is the one whose table its constructor stores; all but 0x2AACB0 and
0x2AA730 are verified.

## 3. `core::File`

Bases (RTTI): `core::IFile` (: `core::IRefCount`) at +0, `core::IMutable` at +4. Tables 0x3DAA94 (34
slots) and 0x3DAA88 (+4: 0x2AAF50, 0x2AAF60, verified); the mutable base's own table is 0x3DAA74. Size
0x168.

| Offset | Type | Role |
| :--- | :--- | :--- |
| +0x08 | int | reference count, starts at 1 |
| +0x0C | `core::Drive*` | the drive; the constructor calls its slot 0 |
| +0x10 | 32-bit | priority |
| +0x14 | 32-bit | returned under lock by slot 23 (examiner's reading: last error) |
| +0x18 | 32-bit | tested `== 0` by slot 21 |
| +0x1C | bool | open |
| +0x1D | bool | constructor argument 3 |
| +0x1E | char[0x100] + terminator at +0x11E | the name |
| +0x120, +0x124, +0x128 | 32-bit each | zero at construction |
| +0x12C | member object | constructed by 0x2BE6C0 |
| +0x160 | bool | true from ctor 0x2AB470, false from ctor 0x2AB570 |
| +0x164 | 32-bit | 0x800 |

| Slot | VA | Size | Arguments | Body |
| :--- | :--- | :--- | :--- | :--- |
| 1 | 0x2AAED0 | 128 | none | as InstanceDrive slot 1 with the flag at +0x1C, **not cleared**, and P(0xC, `FileCloseRequest` 0x2AA990 (this), 0) |
| 4 | 0x2AAFB0 | 80 | (a, b, c) | P(0x18, `FileReadRequest` 0x2AA9D0 (this, a, b, c), 0), D |
| 5 | 0x2AB000 | 80 | (a, b, c) | P(0x18, `FileWriteRequest` 0x2AAA10 (this, a, b, c), 0), D |
| 6 | 0x2AB050 | 80 | (a) | P(0x10, `FileSetPositionRequest` 0x2AAA50 (this, a), 0) |
| 7 | 0x2AB0A0 | 80 | (a) | P(0x10, ctor 0x2AAA80 (this, a), 0) |
| 8 | 0x2AB0F0 | 80 | (a) | P(0x10, ctor 0x2AAB20 (this, a), 0) |
| 9 | 0x2AAF70 | 64 | none | P(0xC, `FileCommitRequest` 0x2AA9B0 (this), 0), D |
| 18 | 0x2AB220 | 64 | none | P(0xC, `FileCancelRequest` 0x2AAB50 (this), atHead 1), D |
| 19 | 0x2AB260 | 96 | (a, b) | as InstanceDrive slot 20 with `FileCompletionRequest` 0x2AA650 |
| 21 | 0x2AB2C0 | 48 | none | Lock; `b = (+0x18 == 0)`; Unlock; return b |
| 23 | 0x2AB320 | 32 | none | Lock; e = +0x14; Unlock; return e |
| 25 | 0x2AB340 | 32 | none | if `caps & 0x80` return null; else return `this + 0x1E` |

Slots 6, 7 and 8: only their calls, sizes and `ret 4` were checked; the shape is expected to be slot 5's
of InstanceDrive.

**Constructor 0x2AB470** (256 bytes padded; (drive, name, bool a3, a4, a5, a6, priority), `ret 0x1C`):

1. +4 ← 0x3DAA74; +0x10 = priority; +0 ← 0x3DAA94; +4 ← 0x3DAA88; +8 = 1; +0xC = drive; +0x14 = 0;
   +0x18 = 0; +0x1C = false; +0x1D = a3; +0x120, +0x124, +0x128 = 0. In that byte order (the priority
   store comes between the two +4 stores).
2. Construct +0x12C (0x2BE6C0, called). +0x160 = true; +0x164 = 0x800. Call 0x250EB0.
3. drive's slot 0 (add a reference).
4. `if (0x283A80(this + 0x1E, name, 0x100) < 0) { 0x2FC450(this + 0x1E, name, 0x100); +0x11E = 0; }`.
5. Call caps; the result is not used.
6. P(0x1C, ctor 0x2AA950 (this, a4, a3, a5, a6), 0), J. Return `this`.

**Constructor 0x2AB570** (256 bytes padded; nine arguments, `ret 0x24`; read: 1 drive, 2 name, 3 bool,
4, 5 priority, 9 bool; 6, 7, 8 are not read): steps 1 to 5 as above with +0x160 = false. Then, only if
argument 9 is true: P(0x14, ctor 0x2AA860 (this, a4, a3), 0), J. Return `this`.
EBX is zero throughout both constructors.
