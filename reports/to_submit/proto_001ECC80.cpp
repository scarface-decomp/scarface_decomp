// bin: proto
// va: 0x001ECC80
// what: 
// tool: the portal's starter code (no AI)

// sub_001ECC80 (Proto 0x001ECC80, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00462F98;
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_001ECC80(int a1, int a2, int a3)
{
    int t1, t2;

    t1 = DAT_00462F98;
    t2 = sub_002C96FE(*(int*)(a3 + 4));
    if (t2 != *(int*)(t1 + 68)) {
        if (t2 > 4) goto L_26;
        *(int*)(t1 + 72) = t2;
    }
L_26:
    ;
}
