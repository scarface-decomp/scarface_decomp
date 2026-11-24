// bin: xb
// va: 0x00326490
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00326490 (0x00326490, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048ECB8;
extern "C" int DAT_0048ECBC;
extern "C" int __cdecl sub_002444F0(int, int);

int __cdecl sub_00326490(void)
{
    int r_eax;

    r_eax = DAT_0048ECB8;
    DAT_0048ECBC = r_eax;
    if (r_eax) {
        r_eax = sub_002444F0(14, r_eax);
    }
    return r_eax;
}
