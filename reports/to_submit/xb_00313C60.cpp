// bin: xb
// va: 0x00313C60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313C60 (0x00313C60, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041EEF8[];
extern "C" Object DAT_0047ABB0;
extern "C" char sub_00070EF0[];

void __cdecl sub_00313C60(void)
{
    DAT_0047ABB0.sub_0006F790(0, (int)DAT_0041EEF8, (int)sub_00070EF0, 0, 3, 3);
}
