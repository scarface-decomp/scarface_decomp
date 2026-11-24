// bin: xb
// va: 0x00313CC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313CC0 (0x00313CC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041EF14[];
extern "C" Object DAT_0047AC34;
extern "C" char sub_00070F70[];

void __cdecl sub_00313CC0(void)
{
    DAT_0047AC34.sub_0006F790(0, (int)DAT_0041EF14, (int)sub_00070F70, 0, 2, 2);
}
