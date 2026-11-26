# SPEC-018: `core::DriveThread` and the thread library under it

**Examiner:** Claude (AI assistant) for RRutherrfordd, 2026-11-26.
**Outside material read:** leaked source, read directly: the drive-thread source file and header of the
2003 *Simpsons: Hit & Run* core library (for part B), and, in the previous round, one function of its
thread source (the wait in §A.4.1). It said how part B's functions are organised. Scarface's thread
library is built differently from the 2003 one (plain structures and free functions, with fibers), so
part A is from the bytes alone. Every fact below was read from `default.xbe`, and where the two differ
this page follows Scarface.
**For the implementer:** build from this page, the repository and your own copy of the game. Do not open
the leaked tree. Class names are Scarface's own (run-time type information); system names are
Microsoft's public ones. Fields are given by offset. Function titles are the examiner's wording.

## 0. Three function starts the queue does not have

| VA | Size | What | Witness |
| :--- | :--- | :--- | :--- |
| 0x2C18B0 | 586 | the drive thread's entry function (§B.4.11) | its address is pushed at 0x2C1BC5 |
| 0x283E70 | 52 | the system-thread entry stub (§A.4.9) | pushed at 0x283F9E as `CreateThread`'s start address |
| 0x283F20 | 42 | the fiber entry stub (§A.4.10) | pushed at 0x28404E |

None is called directly, so no call graph finds them.

# Part A: the thread library (one file, 0x283AE0 to 0x284093)

## A.1 The two structures

**Fiber, 0x24 bytes**

| Offset | Type | Role | Witness |
| :--- | :--- | :--- | :--- |
| +0x00 | function pointer | entry: `__cdecl`, one pointer argument, returns 32 bits | 0x283E8A `call [esi + 8]` on a thread |
| +0x04 | pointer | the entry's argument | 0x283E86 |
| +0x08 | Thread* | owner | 0x283CC9, 0x28402D |
| +0x0C | Fiber* | next in the owner's list | 0x283B38 |
| +0x10 | Fiber* | previous | 0x283B30 |
| +0x14 | pointer | the system's fiber | 0x283CC3, 0x284066 |
| +0x18, +0x1C, +0x20 | 32-bit each | zeroed at creation; +0x18 is zeroed again by the fiber stub | 0x28405F, 0x284062, 0x284020 |

**Thread, 0x4C bytes**

| Offset | Type | Role | Witness |
| :--- | :--- | :--- | :--- |
| +0x00 | Thread* | next in the global list | 0x283C31 |
| +0x04 | Thread* | previous | 0x283C0D |
| +0x08 | Fiber | the thread's own first fiber, embedded | 0x283CA8 `lea edi, [esi + 8]` |
| +0x2C | Fiber* | current fiber | 0x283CD2, 0x283EFA |
| +0x30 | Fiber* | head of this thread's fiber list | 0x283B3D |
| +0x34 | Fiber* | tail | 0x283B4F |
| +0x38 | bool | running | 0x283C9F, 0x283E93 |
| +0x3C | 32-bit | the entry function's result | 0x283E90 |
| +0x40 | int | priority, 0 to 4 | 0x283CFD, 0x283FB4 |
| +0x44 | 32-bit | system thread id | 0x283CAC |
| +0x48 | handle | system thread handle | 0x283CAF, 0x283FAE |

## A.2 File-scope variables

| Address | Type | Role |
| :--- | :--- | :--- |
| 0x4BDCD0 | Thread | the record of the thread that initialised the library. Its embedded fiber is 0x4BDCD8 |
| 0x4BDD1C | Thread* | tail of the global list |
| 0x4BDD20 | Thread* | head of the global list |
| 0x4BDD24 | bool | library initialised |
| 0x4BDD28 | critical section | guards the global list |
| 0x45B0AC | int[5] | system priority for each library priority: −15, −2, 0, 1, 2 |

Critical-section calls go through the import cells 0x39D290 (enter), 0x39D28C (leave) and 0x39D358
(initialise), written `call dword ptr [cell]`.

## A.3 Callees

| VA | What it is (examiner's reading where the repository has no name) |
| :--- | :--- |
| 0x234837 | `GetCurrentThreadId` |
| 0x2347C9 | `CreateThread` |
| 0x2345A7 | `SetThreadPriority` |
| 0x2345F9 | expected `ResumeThread` (one argument) |
| 0x235F82 | expected `Sleep` |
| 0x235F56 | expected `WaitForSingleObject` (handle, timeout) |
| 0x309527 | expected `ConvertThreadToFiber` (one argument) |
| 0x309449 | expected `CreateFiber` (stack size, start, parameter) |
| 0x3094D5 | expected `DeleteFiber` |
| 0x3094E8 | expected `SwitchToFiber` |
| 0x283AE0 | verified: `Sleep` forward (milliseconds) |
| 0x283EB0 | verified: finds the calling thread's record in the global list |
| 0x283EF0 | verified: current fiber of the calling thread, or null |

## A.4 The open functions

All are `__cdecl` free functions unless it says otherwise.

### A.4.1 0x283AF0: wait for a thread to end (26 bytes)

(Thread*) returns the entry's result. While running (+0x38): the `Sleep` forward 0x283AE0 with 0,
**expanded** (`push 0; call 0x235F82`). Then return +0x3C. The loop test is at the top and the loop
closes with `jmp`. Your attempt packet of 25 November has the bytes; my source-shape answer is in the
"part 2d" note and is still untested. One new fact: the body of the loop is the expanded forward, not a
direct call to the system function.

### A.4.2 0x283B10: unlink a fiber (80 bytes padded)

(Fiber* f), no result.

1. If `f` is not the address 0x4BDCD8 and `f` is not `&f->owner->firstFiber` (owner + 8): call
   `DeleteFiber` with `f`'s system fiber.
2. `owner`, `next`, `previous` are read once each. If `previous` is null: owner's head = `next`;
   otherwise `previous->next = next`.
3. If `next` is null: owner's tail = `previous`; otherwise `next->previous = previous`.

Two endings, one per arm of step 3; the "tail" arm is first.

### A.4.3 0x283BF0: add a thread to the global list (80 bytes padded)

(Thread* t). Enter the critical section. If head is null: head = `t`; `t->previous = 0`. Otherwise:
`tail->next = t`; `t->previous = tail` (the tail variable is read from memory twice). Then tail = `t`;
`t->next = 0`; leave. The `t->next = 0` store sits between the push of the critical section and the
leave call.

### A.4.4 0x283C40: remove a thread from the global list (80 bytes padded)

(Thread* t). Enter. If `t->previous` is null: head = `t->next`; otherwise `t->previous->next =
t->next`. If `t->next` is null: tail = `t->previous`; otherwise `t->next->previous = t->previous`.
Leave. Two endings, each with its own leave call; the "tail" arm is first.

### A.4.5 0x283C90: set up a record for the calling thread (144 bytes padded)

(Thread* t). In byte order:

1. head of fibers (+0x30) = 0; tail (+0x34) = 0; running = true.
2. id = `GetCurrentThreadId()`.
3. handle = 0xFFFFFFFE; first fiber's +0x20 = 0; its entry = 0; its argument = 0.
4. first fiber's system fiber = `ConvertThreadToFiber(0)`.
5. first fiber's owner = `t`; its +0x18 = 0; its +0x1C = 0; current fiber = the first fiber.
6. Append the first fiber to the fiber list: if head is null, head = it and its previous = 0;
   otherwise `tail->next = it` and its previous = tail. Then tail = it; its next = 0.
7. Add `t` to the global list (0x283BF0, called).
8. priority = 2; `SetThreadPriority(handle, table[2])`. The table entry is read from the fixed address
   0x45B0B4.

Notes:

* Step 6's test of head is really emitted (`cmp [esi + 0x30], ebx`) although step 1 zeroed it,
  because calls sit between them.
* Step 8 is the same "set priority" as the end of §A.4.7 with the constant 2 folded in.
* EBX holds zero throughout; EDI holds the first fiber's address.

### A.4.6 0x283D20 and 0x283D80: shut down and start the library

**0x283D20** (96 bytes padded, no arguments): §A.4.2 applied to the fixed fiber 0x4BDCD8,
**expanded** with step 1 folded away, then §A.4.4 called with 0x4BDCD0. The call to 0x283C40 is
duplicated in both endings. The verified 0x283DB0 calls it.

**0x283D80** (48 bytes padded): initialise the critical section; the bool 0x4BDD24 = true; call
0x250EC0; then §A.4.5 with 0x4BDCD0 as a tail jump that first overwrites this function's own first
argument slot (`mov dword ptr [esp + 4], 0x4BDCD0; jmp 0x283C90`). So the function has at least one
parameter, which it does not read.

### A.4.7 0x283F50: start a new thread (128 bytes padded)

(Thread* t, entry, argument, int priority, unsigned stack size).

1. running = true; current fiber = the first fiber; first fiber's +0x20 = 0; its entry and
   argument = the two parameters; its owner = `t`; its system fiber, +0x18 and +0x1C = 0.
2. head of fibers = the first fiber; its previous = 0; tail = it; its next = 0.
3. Add `t` to the global list (0x283BF0).
4. handle = `CreateThread(0, stack size, 0x283E70, t, 4, &t->id)`.
5. first fiber's +0x1C = 0 again; priority = the parameter;
   `SetThreadPriority(handle, table[priority])`.
6. `ResumeThread(t->handle)` (re-read from the record).

Step 2 is step 6 of §A.4.5 with the test folded away: no call sits between the zeroing of the list and
the append, so only the four final stores are left. One shared inline "start the fiber list with the
first fiber" explains both functions. The verified 0x283FE0 forwards its first five arguments here and
drops its sixth.

### A.4.8 0x284010: create a fiber on the calling thread (96 bytes padded)

Called by the verified 0x284070 with six arguments. Read here: 1 = Fiber* f, 2 = entry, 3 = argument,
5 = stack size.

1. `f->+0x20 = 0`; entry and argument stored.
2. owner = the calling thread's record (0x283EB0).
3. Append `f` to the owner's fiber list, with the real test of head.
4. system fiber = `CreateFiber(stack size, 0x283F20, f)`; +0x1C = 0; +0x18 = 0. The system fiber is
   stored last, after the two zero stores and one `pop`.

### A.4.9 0x283E70: the system-thread entry stub (52 bytes, not in the queue)

`__stdcall`, one argument (Thread* t), `ret 4`, returns 0.
first fiber's +0x18 = 0; its system fiber = `ConvertThreadToFiber(0)`; `result = entry(argument)`;
+0x3C = result; running = false; first fiber's +0x20 = 0.

### A.4.10 0x283F20: the fiber entry stub (42 bytes, not in the queue)

`__stdcall`, one argument it does not read, `ret 4`.
`f` = the current fiber (0x283EF0, **expanded**); `f->+0x18 = 0`; `f->entry(f->argument)`.
The expansion leaves two copies of the last two statements: one for "no thread record" (EAX is zero
and is used as the pointer, and as the zero stored) and one for the normal case.

### A.4.11 Two neighbours that are not thread code: 0x283AA0 and 0x283AC0 (32 bytes padded each)

Each takes one pointer. If it is null, return (EAX is zero). Otherwise jump to 0x2A92E0 (for
0x283AA0) or 0x2A97B0 (for 0x283AC0), after storing the pointer back into its own argument slot
(`mov [esp + 4], eax; jmp`). They sit with the verified text forwards 0x283A80 and 0x283A90.

# Part B: `core::DriveThread`

## B.1 Bases and tables

Bases as `core::Drive` (SPEC-017 §1): `IRefCount` at +0, `Object` at +4, `SafeRefCount` at +0xC.

| Table | At | Slots |
| :--- | :--- | :--- |
| 0x3DB608 | +0 | 0 = 0x2AC390 (the same function as `core::Drive`'s slot 0: one copy serves both classes), 1 = 0x2C1450, 2 = 0x2D5920, 3 = 0x2C1BE0 (destructor, verified) |
| 0x3DB600 | +4 | 0 = 0x2C1890 (`sub ecx, 4; jmp 0x2C1BE0`) |
| 0x3DB5F0 | +0xC | 0 = 0x2C1460 (lock: 0x283B80 on the mutex), 1 = 0x2C1470 (unlock: 0x283B70), 2 = 0x2C18A0 (`sub ecx, 0xC; jmp 0x2C1BE0`) |

Every table function is verified. The open functions below are all non-virtual members.

## B.2 Layout (0xCC bytes)

| Offset | Type | Role | Witness |
| :--- | :--- | :--- | :--- |
| +0x10 | int | reference count | 0x2C1B24 |
| +0x14 | pointer | the mutex shared with the drives (a critical section) | 0x2C1B41, 0x2C1460 |
| +0x18 | Thread (0x4C) | the worker thread's record, §A.1 | 0x2C1BC2 |
| +0x64 | bool | stop the worker | 0x2C18C9 |
| +0x68 | semaphore (4 bytes: the handle) | one count per queued request | 0x2C1B9E |
| +0x6C | `core::Request*`[3] | queue heads, by priority | 0x2C14AA |
| +0x78 | `core::Request*`[3] | queue tails | 0x2C149A |
| +0x84 | 3 records of 0x10 bytes | per-priority hold state, below | 0x2C1516 |
| +0xB4 | unsigned int | wake-ups to swallow | 0x2C1528, 0x2C17C1 |
| +0xB8 | semaphore | signalled when an error is answered | 0x2C1BA8 |
| +0xBC | bool | retry, the answer | 0x2C1794 |
| +0xC0 | unsigned int | requests outstanding | 0x2C14DC |
| +0xC4 | `core::Request*` | the request being worked on | 0x2C1837 |
| +0xC8 | bool | the request being worked on was cancelled. **Scarface-only** | 0x2C15D4 |

**Hold record** (at +0x84 + priority × 0x10):

| Offset | Type | Role |
| :--- | :--- | :--- |
| +0x0 | 32-bit | set to 0 in §B.4.1 only; the constructor does not touch it |
| +0x4 | unsigned int | 0 at construction and whenever a hold starts or ends; tested `> 0` in §B.4.1 |
| +0x8 | int | −1 at construction and whenever a hold starts or ends |
| +0xC | unsigned short | hold count |
| +0xE | bool | "woken while held" |

The whole hold mechanism and +0xB4 are **Scarface-only**.

`core::Request` (seven slots): 0 destructor with delete flag; 1 do the work, returns a status; 2
(key) "should this be cancelled", returns bool; 3 the owning drive; 4 prepare again after an error,
returns a status; 5 and 6 as SPEC-017 §2. Its +4 is the next pointer. Status: 0 error, 1 done, 2 more
to do; anything else is left alone.

"Lock" and "Unlock" are slots 0 and 1 of the +0xC part through the table, as in SPEC-017.
"Wait(s)" is 0x283BC0 and "Signal(s)" is 0x283BD0, both verified, `__cdecl`, one argument.

## B.3 Where each helper is called and where it is expanded

| Helper | Called at | Expanded at |
| :--- | :--- | :--- |
| clear the current request, 0x2C1850 | 0x2C19FA, 0x2C1A5F, 0x2C1A8F | 0x2C1983, 0x2C1AA5 |
| wait for the error to be answered, 0x2C1760 (verified) | 0x2C1A50 | 0x2C194B, 0x2C1A04 |
| queue, 0x2C1480 | 0x2C19C7, 0x2C1A70, 0x2C1A9E | |
| next request, 0x2C17B0 | 0x2C18DE | |
| release a hold, unlocked body 0x2C16A0 | 0x2C171A | |
| `core::Drive` accessors 0x2AC3E0, 0x2AC400, 0x2AC550, 0x2AC680, 0x2AC5D0 | every use | |

## B.4 The functions

### B.4.1 0x2C1480: queue a request (208 bytes padded)

(request, priority, bool atHead), `ret 0xC`.

1. Lock.
2. If atHead: if tail[p] is null, tail[p] = request; request->next = head[p]; head[p] = request.
   Otherwise: if head[p] is null, head[p] = request, else tail[p]->next = request; request->next =
   0; tail[p] = request.
3. outstanding += 1.
4. `signal = (hold count of p == 0)`.
5. If the hold count is above 0, and the record's +4 is above 0, and its "woken" flag is false:
   record +0 = 0; `signal = true`; "woken" = true; +0xB4 += 1.
6. Unlock. If `signal`: Signal(+0x68).

Notes: the hold count is read once (`movzx`) and tested twice (`test; sete bl` then `test; jbe`).
"woken" is stored from BL just after `mov bl, 1`. EBX is pushed late, at 0x2C14DB. Steps 4 and 5
are Scarface-only; 2003 signals always.

### B.4.2 0x2C1550: cancel requests (160 bytes padded)

(key, priority), `ret 8`.

1. Lock. `walk = &head[p]`; `last = 0`.
2. While `*walk` is not null: if `(*walk)`'s slot 2(key) is true: `current = *walk; *walk =
   current->next`; delete `current`; outstanding −= 1; Wait(+0x68). Otherwise `last = *walk; walk =
   &last->next`.
3. tail[p] = `last`.
4. If the request being worked on (+0xC4) is not null and its slot 2(key) is true: +0xC8 = true.
5. Unlock.

The loop is entered through a first test of head[p]. Scarface-only: the decrement in step 2, and step 4.

### B.4.3 0x2C15F0: any requests outstanding (48 bytes padded)

Lock; `b = (outstanding != 0)` (`setne bl`); Unlock; return `b`.

### B.4.4 0x2C1620: hold a priority (128 bytes padded)

(priority, a second argument not read), `ret 8`. Returns 0xFFFFFFFF (`or eax, -1`).

1. Lock.
2. If the hold count of p is 0: for each request in queue p (`for (r = head[p]; r; r = r->next)`):
   Wait(+0x68). Then record +4 = 0; "woken" = false; record +8 = −1.
3. hold count += 1 (`inc word ptr`). Unlock.

The address of the hold count is kept in the first argument's stack slot across the loop
(0x2C163F, 0x2C1663). The loop top is padded to 0x2C1650.

### B.4.5 0x2C16A0: end a hold, without locking (96 bytes padded)

(priority, a second argument not read), `ret 8`, no result. `this` in EBP.
If the hold count of p is 1: for each request in queue p: Signal(+0x68). Then the same three
stores as §B.4.4 step 2. In every case hold count −= 1.

### B.4.6 0x2C1700 and 0x2C1730

**0x2C1700** (48 bytes padded): (a, b), `ret 8`: Lock; §B.4.5 with (a, b), called; Unlock.

**0x2C1730** (48 bytes padded): (priority), `ret 4`: Lock; read the hold count (`movzx`); Unlock;
return `0 < count` in EAX (`xor eax, eax; cmp eax, edi; sbb eax, eax; neg eax`).

### B.4.7 0x2C17B0: take the next request (160 bytes padded)

(int* priority out, may be null), `ret 4`. Returns the request or null.

1. `result = 0`. Lock.
2. If +0xB4 is above 0: +0xB4 −= 1; Unlock; return 0 (the literal: `xor eax, eax`). This block is
   inline, before the loop.
3. For `i` from 0 while below 3 (unsigned): if the hold count of `i` is not above 0 and head[i] is
   not null: `result = head[i]`; if `result == tail[i]`, tail[i] = 0; head[i] = result->next;
   result->next = 0; if the out pointer is not null, `*out = i`; stop.
4. +0xC4 = `result`. Unlock. Return `result`.

Notes: the loop walks two pointers (EDX = `&head[0]`, ECX = the first hold count at `this + 0x90`,
step 0x10) and is padded to 0x2C17F0 with `lea esp, [esp]`. Its two tests are `cmp word ptr [ecx],
0; ja` and `cmp dword ptr [edx], 0; jne`. Step 4's store sits between loading the table and the unlock
call. Scarface-only: step 2, the hold test, and step 4's store.

### B.4.8 0x2C1850: clear the current request (64 bytes padded)

No arguments. Lock; `r` = +0xC4; +0xC8 = false; +0xC4 = 0; Unlock; if `r` is not null, delete it.
The two stores are in that order, after the unlock's table is loaded.

### B.4.9 0x2C1B00: the constructor (224 bytes padded)

(mutex, allocator), `ret 8`, returns `this`.

1. Base stores as SPEC-017 §4.11 steps 1 to 4, then +0 ← 0x3DB608; +4 ← 0x3DB600; +0xC ← 0x3DB5F0.
2. Member initialisers in this order: +0x14 = mutex; +0x64 = false; +0xB4 = 0; +0xBC = false; +0xC0 =
   0; +0xC4 = 0; +0xC8 = false.
3. Call 0x250EB0.
4. Loop of 3 (a counter from 3 down to 0; pointers at `this + 0x78` and `this + 0x88`): head[i] = 0;
   tail[i] = 0; hold count = 0; record +4 = 0; "woken" = false; record +8 = −1. In that order.
5. 0x283B90(&+0x68, 0); 0x283B90(&+0xB8, 0) (verified: creates a semaphore).
6. 0x283FE0(&+0x18, 0x2C18B0, `this`, 4, 0x2000, allocator).

The three calls of steps 5 and 6 share one `add esp, 0x28`. The mutex argument is read into ECX
before the first table store. The loop top is padded to 0x2C1B80.

### B.4.10 The verified ones, for reference

0x2C13E0 destructor (your H3); 0x2C1760 (drive, request): the drive's 0x2AC5D0 with the request, then
Wait(+0xB8); 0x2C1790 (bool): +0xBC = it, Signal(+0xB8).

### B.4.11 0x2C18B0: the worker's entry function (586 bytes, not in the queue)

`__cdecl`, one argument (the `core::DriveThread`), returns 0. One `push ecx` of frame: its top byte
(`[esp + 0x13]` once the four registers are pushed) is the bool `errorRetry`. The priority local lives
in the argument's own stack slot (`[esp + 0x18]`). Registers: parent ESI, request EDI, drive EBP,
status EBX.

`errorRetry = false`. Then forever:

1. Wait(parent +0x68). If parent's stop flag (+0x64) is set, return 0.
2. `request` = parent's §B.4.7 with `&priority`. If null, go round again.
3. `drive` = request's slot 3().
4. `e` = drive's last error (0x2AC3E0). If `e` is neither 0 nor 1: `status` = request's slot 4();
   if `status == 1`, `status` = request's slot 1(). Otherwise `status` = request's slot 1().
5. If `errorRetry == true` (compared with 1), and drive's last error is 0, and drive's error
   behaviour (0x2AC550) is 2, and drive's 0x2AC680 `== true` (compared with 1): wait for the error to
   be answered (drive, request), expanded; `errorRetry = false`.
6. Switch on `status`:
   * **2:** if parent's +0xC8 is false: queue (request, priority, true). Otherwise the bytes fall
     into case 1's block.
   * **1:** clear the current request, expanded (0x2C1983).
   * **0:** switch on drive's error behaviour:
     * **2:** if parent's +0xC8 is true: clear the current request (called). Otherwise: wait for
       the error to be answered (drive, request), expanded; then
       * if parent's retry (+0xBC) is false: clear the current request (called);
       * else if parent's +0xC8 is false: queue (request, priority, true); retry = false;
         `errorRetry = true`;
       * else: if drive's 0x2AC680 `== true`: `saved` = drive's last error; drive's 0x2AC400(0);
         parent's 0x2C1760(drive, request), called; drive's 0x2AC400(`saved`). Then, in either
         case, clear the current request (called).
     * **1:** if parent's +0xC8 is true, clear the current request (called); otherwise queue
       (request, priority, true).
     * **0:** clear the current request, expanded (0x2C1AA5).
7. Lock (parent's, through the table); outstanding −= 1 (`dec dword ptr`); Unlock. Go round again.

**Block order in the bytes:** loop top 0x2C18C0 (padded); step 6 dispatch at 0x2C1967 (`mov eax, ebx;
xor ebx, ebx; sub eax, ebx; je` case 0; `dec eax; je` case 1; `dec eax; jne` step 7); case 2 at
0x2C1979; case 1 at 0x2C1983; case 2's queue at 0x2C19BD; case 0 at 0x2C19D1 with the same
`sub` / `dec` / `dec` dispatch; behaviour 2 at 0x2C19EE; behaviour 1 at 0x2C1A83; behaviour 0 at
0x2C1AA5; step 7 at 0x2C1AD6; the return at 0x2C1AF2, last.

**Notes:**

* EBX is zero from 0x2C1969 and supplies the zero stored into +0xC4 by the two expanded clears. In
  the "saved error" arm it is reused for `saved`.
* Behaviour 2's three arms that clear the current request share one call at 0x2C1A5D.
* Case 2 reaching case 1's block is either a written fall-through or the compiler merging an
  expanded clear with case 1's; both are worth a try.
* Nothing clears +0xC4 after a re-queue; §B.4.7 overwrites it on the next turn.

**Where Scarface differs from 2003** (facts about Scarface): the null test in step 2; every use of
+0xC8; the "saved error" arm; step 5 passes the request; the current request is set inside §B.4.7 and
cleared by §B.4.8, which also deletes it.

## B.5 Status

Nothing here has been compiled. No second reviewer has read the page.
