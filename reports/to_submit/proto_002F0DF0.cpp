// bin: proto
// va: 0x002F0DF0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F0DF0 (Proto 0x002F0DF0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D85C[];
extern "C" char DAT_004493B8[];

int __cdecl sub_002F0DF0(void)
{
    int r_eax, r_ecx;

    r_eax = (int)DAT_004493B8;
    r_ecx = 106;
    do {
        r_eax -= 72;
        r_ecx -= 1;
        *(int*)r_eax = (int)DAT_0037D85C;
    } while (r_ecx);
    return r_eax;
}
