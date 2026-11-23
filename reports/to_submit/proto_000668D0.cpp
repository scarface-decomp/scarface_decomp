// bin: proto
// va: 0x000668D0
// what: 
// tool: the portal's starter code (no AI)

// sub_000668D0 (Proto 0x000668D0, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_000668D0(int a1, int a2, int a3)
{
    int r_eax;
    bool t1;

    r_eax = a3;
    r_eax = *(int*)(r_eax + 4);
L_07:
    t1 = *(bool*)r_eax;
    if (*(bool*)r_eax != 32) {
        if (t1 == 10) goto L_18;
        if (t1 != 9) goto L_1B;
    }
L_18:
    r_eax += 1;
    goto L_07;
L_1B:
    return r_eax;
}
