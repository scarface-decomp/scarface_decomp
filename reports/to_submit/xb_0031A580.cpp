// bin: xb
// va: 0x0031A580
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A580 (0x0031A580, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043755C[];
extern "C" char DAT_00437574[];
extern "C" Object DAT_0048DD18;
extern "C" char sub_001BEC90[];

void __cdecl sub_0031A580(void)
{
    DAT_0048DD18.sub_0006F830((int)DAT_00437574, (int)DAT_0043755C, (int)sub_001BEC90, 0, 2, 2);
}
