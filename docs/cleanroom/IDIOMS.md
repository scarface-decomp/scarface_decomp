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
I19. (pending J2) VA order inside an object = compile order, callees before callers; a lower-VA same-file
     callee is "already compiled" for I13. [drive-thread file vs 2003 text order; save-drive file.]
I20. Every core constructor level ends with a call to the module-name accessor 0x250EB0 (returns "core"),
     result dropped. [0x2AA580, 0x2AA650, 0x2AC7E0, 0x2AB470, 0x2C1B00.] Other libraries will have their
     own accessor: look for a `mov eax, imm; ret` called from constructors.
I21. Strings: Scarface's engine wraps the C string routines (bounded copy 0x2A9520 with C-library
     fallback in 0x2AB470; null-checked forwards 0x283AA0 / 0x283AC0). Expect a wrapper wherever 2003
     has a bare C call. [H4; pending X1..X5 for the copy.]
I22. Numbered library stubs: identity = shape + kernel export numbers + targets (yours, G4). A bare
     `jmp [cell]` or `mov eax,[cell]` stub is identified by the cell's export alone. [0x239C84, 0x30A65F.]
I28. The compiled 2003 program is a control for compiler questions: same source + VC 7.0 shows what the
     old compiler did. Where 2003 and your compile agree and Scarface differs, suspect the compiler build,
     not the source. [K1: 0C 02 in 2003, in yours; 0C 10 in Scarface.]
I29. Scarface-only engine code is recognisable as such: no counterpart in the 2003 request / drive files
     (open-by-key, drive lock, hold / release, the cancelled flag, +0x74 failed request). Treat these as
     bytes-first work; the examiner can add nothing from 2003. [K3; SPEC-017/018 differences.]
I30. A non-virtual member reached only through a one-line virtual forwarder of another class
     (`mov ecx,[esp+4]; call member; ret 4`) is the "Unlock(request)" style API. Write the forwarder as
     `request->Member()`. [0x2AC070 -> 0x2AA4E0.]
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
I23. An `inline` wrapper around an intrinsic string copy is NOT expanded in a large function; only
     __forceinline expands it, and then the bytes equal the bare intrinsic. [0x2C09C0: 644 vs 1277.]
I24. Each request base's Finish(status, error) is an inline member expanded at every exit; take the
     status into a local before `return Finish(status, owner->LastError())` (arguments are evaluated
     right to left). [21 work functions, 0x2A9D70..0x2AA430.]
I25. A deleting destructor with an inline class `operator delete` through a global allocator: own table,
     body, base table store, then `if (flags & 1) { lock; allocator->free(this); unlock; } return this;`;
     the base table store is scheduled between the flag test and the branch. [0x2AAAB0, 0x2AAD90,
     0x2AA8D0.]
I26. Public C library code is matched by compiling the published file unchanged with `/TC` and the
     library flags; a proposal is the include plus a `// verify:` line naming the function. [zlib 1.2.1,
     libpng 1.2.8: 106 functions.]
I27. A function that ends in a call that never returns has no `ret`; the measured size then includes one
     int3 of padding. [png_error 0x2C6800, png_chunk_error 0x2C68F0.]
I31. A public library function the game's copy changed is matched by compiling the published file with the
     function renamed away (`#define name name_as_published` before the include), then the altered
     function after it, marked as altered. The rest of the file stays above it, so the functions it calls
     are known to the compiler as in the game's file (I13). [png_handle_sPLT 0x2CA770: libpng 1.2.8's
     `int data_length` is `png_uint_32` in the game.]
I32. x87 loads follow the order local floats are declared in, not the order of the expression that uses
     them: `float x = d.x; float z = d.z; ... sqrt(x * x + z * z)` loads x then z; the same expression
     written on the members loads z first. [0x243CA0.]
I33. A transpose that keeps the upper triangle in locals and writes the matrix back in row order gives
     the game's mix of x87 and integer moves exactly. [0x2433E0.]
I34. A null-pointer test that ends at the bottom of the function is `if (p != 0) { ...; return h; }
     return h;` (both returns written), not an early `if (p == 0) return h;`. [0x243F40.]
```
