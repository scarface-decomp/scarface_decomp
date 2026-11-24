// bin: xb
// va: 0x0031FDA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FDA0 (0x0031FDA0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E230[];
extern "C" Object DAT_004921C8;
extern "C" char sub_0022E1A0[];

void __cdecl sub_0031FDA0(void)
{
    DAT_004921C8.sub_0006F830(0, (int)DAT_0044E230, (int)sub_0022E1A0, 0, 1, 1);
}
