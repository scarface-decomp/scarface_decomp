// bin: xb
// va: 0x00322F00
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322F00 (0x00322F00, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE560();
};

extern "C" char DAT_004810E0[];

void __cdecl sub_00322F00(void)
{
    int r_edi, r_esi;

    r_esi = (int)DAT_004810E0;
    r_edi = 2;
    do {
        r_esi -= 76;
        ((Object*)r_esi + 16)->sub_002CE560();
        ((Object*)r_esi)->sub_002CE560();
        r_edi -= 1;
    } while (r_edi);
}
