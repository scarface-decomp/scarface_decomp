// bin: xb
// va: 0x0024B8F0
// tool: the portal's starter code (no AI)
// sub_0024B8F0 (0x0024B8F0, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

int __cdecl sub_0024B8F0(int a1)
{
    int r_eax, r_ecx;

    r_ecx = a1;
    r_eax = 0;
    if (a1) {
        if (!*(unsigned short*)r_ecx) goto L_19;
        do {
            r_eax += 1;
        } while (*(unsigned short*)(r_ecx + (r_eax * 2)));
    }
L_19:
    return r_eax;
}
