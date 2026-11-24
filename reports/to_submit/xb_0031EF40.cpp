// bin: xb
// va: 0x0031EF40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031EF40 (0x0031EF40, 10 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0021FDA0();
};

extern "C" Object DAT_004912D8;

void __cdecl sub_0031EF40(void)
{
    DAT_004912D8.sub_0021FDA0();
}
