# Standing idiom list

How this game's source was written, as far as it shows in the compiled code: each rule says what to write
to get the bytes the original has. The examiner started the list (round of 26 November 2026) and adds to
it each round; the implementer adds what its own compiles prove. Evidence is in brackets: an address is a
function of `default.xbe` where the rule was measured; "yours" marks a finding of the implementer;
"H1", "S-a", "F7" and the like point at the examiner's round files, and "SPEC-nnn" at a page of this folder.

Where a rule says what the 2003 source did, that is the examiner's reading put in its own words; no code
and no name from the leaked tree is here. The compiler notes that need no outside reading are in
[METHODOLOGY.md](../METHODOLOGY.md), section 5.

```text
I1. OUT-PARAMETER FLAG GETTER. A loop or test on a `bool` member that must not be rotated / hoisted is
    written through `inline void Get(const T*, bool* out)` into an address-taken local. Byte signature:
    loop top = `mov r8,[obj+d]; test r8,r8; jcc exit`, closed by `jmp top`, no guard copy of the test.
    [0x283AF0 +0x38; 0x2C18B0 +0x64. Scarface-era.]
I2. INLINE TWIN OF A MEMBER. A helper exists both as an inline function and as an out-of-line member with
    identical statements; the linker folds them. Signature: one function is both called and expanded in
    the same caller, and calls that should cross-jump do not. [0x2C1850.]
I3. FOLDED IDENTICAL FUNCTIONS ACROSS CLASSES. Same VA in several tables. [0x2AC390 Drive + DriveThread;
    0x2AB6D0 File + InstanceDrive; 0x2ABC40 File + InstanceDrive; 0x2D5920; 0x239EC0.]
I4. BASE CTOR / DTOR AS INLINE HELPERS ON PART STRUCTS; a cast to a ONE-field struct is transparent to
    store elimination, two or more fields is not. [yours: 0x2C1B00, 0x2AC7E0, 0x2BFB50.]
I5. LOCKED ACCESSORS: copy to a local between Lock and Unlock, one return. Two byte endings are the
    compiler's. [0x2AC610.] Lock / Unlock are virtual calls on the mutable base, never expanded.
I6. `bool == true` WRITTEN OUT gives `cmp r8, 1`. [0x2AC8C0 +0x70; 0x2C18B0 errorRetry, 0x2AC680.]
I7. EMBEDDED STRUCT FIELDS are written `obj->member.field`, array records `m_Arr[i].field` at every use;
    a pointer local to the element changes addressing and aliasing. [yours: 3b, 4b, 9a.]
I8. `if (ok) { ... } else { fail; return; }`: an else that ends in ret is placed after the next block that
    ends in ret. A far failure block = written as an else, not as an early return. [H1; S-a above.]
I9. FIRST N USES OF A SMALL IN-FILE FUNCTION EXPAND, LATER ONES CALL (N = 2 so far). [0x2BF760, 0x2C0030,
    0x2C1760.] Write it once as an ordinary function, call it everywhere.
I10. FAILURE EXITS ARE WRITTEN OUT AT EACH SITE; merging is the compiler's. [F7 iv.]
I11. `new T(args)` THROUGH A CLASS ALLOCATOR: `p = Alloc(sizeof T); r = p ? ctor(p, args) : 0; use(r)`.
    Two emitted shapes from one source: D = the use duplicated in both arms (short functions), J = arms
    joined before the use (functions with a frame). [SPEC-019.]
I12. DATA-ONLY STARTS: entry stubs are reached by `push imm32`; scan found 128. [yours, section 6.]
```

## Added by the implementer

Each of these was measured by compiling; none needed outside reading.

```text
I13. A CALL TO A FUNCTION DEFINED EARLIER IN THE SAME FILE THAT WRITES NO MEMORY does not make the compiler
    forget what it read: a value read through a pointer before the call stays in its register after it.
    Declared only, the same call forces a reload, and that can move every register after it.
    [0x2C09C0: with 0x2BF730 defined in the file, 447 -> 1070 of 1279 bytes; EDI keeps `*out` across the
    call at +0x35E.]
I14. STORES ARE SCHEDULED. A store whose value is an argument just loaded into a scratch register can be
    emitted ahead of earlier stores of constants. Write the members in declared order; the byte order is the
    compiler's. [0x2AB470, 0x2AB570: `+0x10 = priority` sits between the two +4 table stores in the bytes
    and after `m_Drive = drive` in the source.]
I15. A BASE THAT IS ONLY A TABLE keeps its table store when its inline constructor helper RETURNS the part
    pointer; a void helper on a one-field struct loses it. Refines I4. [0x2AB470, 0x2AB570: core::IMutable's
    table at +4, with core::IFile's at +0 dropped as in I4.]
I16. A COPY OF A VALUE HANDED BACK THROUGH A POINTER is taken into a local before the branch that uses it
    (`size = openSize; if (create) ...`); the copy stays in a callee-saved register across later calls and
    the address-taken original stays on the stack. [0x2C09C0 +0x422, EDI; also what makes the zero
    register EBP.]
I17. REQUEST POSTING (I11's D and J) is one source: `T* m = (T*)Alloc(sizeof(T)); T* r = m ? m->ctor(args)
    : 0; drive->Queue(r, m_Priority, atHead);`. D comes out in functions without a frame, J in functions
    with one. No second form was needed. [28 functions of SPEC-019.]
I18. `flags & 0x80` on a 32-bit return value compiles to `test al, al; jns`. [0x2AB340 and pattern S.]
```
