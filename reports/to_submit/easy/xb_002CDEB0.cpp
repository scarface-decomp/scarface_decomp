// bin: xb
// va: 0x002CDEB0
// tool: the portal's starter code (no AI)
// sub_002CDEB0 (0x002CDEB0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_002CDEB0(int a1, int a2, int a3)
{
    if (a1) {
        if (!a2) goto L_30;
        if (!(512 & *(int*)(a1 + 104))) {
            *(int*)(a2 + 60) = *(int*)a3;
            *(int*)(a2 + 64) = *(int*)(a3 + 4);
            *(int*)(a2 + 8) |= 512;
        }
    }
L_30:
    ;
}
