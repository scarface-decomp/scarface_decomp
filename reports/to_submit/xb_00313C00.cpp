// bin: xb
// va: 0x00313C00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313C00 (0x00313C00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041EEC4[];
extern "C" Object DAT_0047AB2C;
extern "C" char sub_00070E80[];

void __cdecl sub_00313C00(void)
{
    DAT_0047AB2C.sub_0006F790(0, (int)DAT_0041EEC4, (int)sub_00070E80, 0, 1, 1);
}
