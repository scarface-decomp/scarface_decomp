// bin: xb
// va: 0x00322950
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322950 (0x00322950, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039E22C[];
extern "C" char DAT_00472290[];

int __cdecl sub_00322950(void)
{
    int r_eax, r_ecx;

    r_eax = (int)DAT_00472290;
    r_ecx = 25;
    do {
        r_eax -= 72;
        r_ecx -= 1;
        *(int*)r_eax = (int)DAT_0039E22C;
    } while (r_ecx);
    return r_eax;
}
