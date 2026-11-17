// bin: proto
// va: 0x00290890
// tool: the portal's starter code (no AI)
// sub_00290890 (0x00290890, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

void __cdecl sub_00290890(int a1, int a2, int a3)
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
