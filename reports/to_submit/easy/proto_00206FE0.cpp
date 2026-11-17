// bin: proto
// va: 0x00206FE0
// tool: the portal's starter code (no AI)
// sub_00206FE0 (0x00206FE0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

int __cdecl sub_00206FE0(int a1)
{
    int r_eax;

    r_eax = 0;
    if (a1) {
        if (!*(unsigned short*)a1) goto L_18;
        do {
            r_eax += 1;
        } while (*(unsigned short*)(a1 + (r_eax * 2)));
    }
L_18:
    return r_eax;
}
