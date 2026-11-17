// bin: proto
// va: 0x00219150
// tool: the portal's starter code (no AI)
// sub_00219150 (0x00219150, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00217B20(int);
};

void __stdcall sub_00219150(int a1)
{
    int r_esi, t2;

    if (!a1) goto L_32;
    r_esi = 0;
    if (*(int*)(a1 + 16) <= 0) goto L_31;
L_13:
    if (r_esi < *(int*)(a1 + 12)) {
        if (!*(int*)(*(int*)(a1 + 20) + (r_esi * 4))) goto L_29;
        ((Object*)*(int*)(*(int*)(a1 + 20) + (r_esi * 4)))->sub_00217B20(1);
    }
L_29:
    t2 = *(int*)(a1 + 16);
    r_esi += 1;
    if (r_esi < t2) goto L_13;
L_31:
L_32:
    ;
}
