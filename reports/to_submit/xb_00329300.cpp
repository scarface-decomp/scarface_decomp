// bin: xb
// va: 0x00329300
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00329300 (0x00329300, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00298420();
};

extern "C" Object DAT_004BC218;

void __cdecl sub_00329300(void)
{
    DAT_004BC218.sub_00298420();
}
