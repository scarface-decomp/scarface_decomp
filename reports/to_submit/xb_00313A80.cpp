// bin: xb
// va: 0x00313A80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313A80 (0x00313A80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0041E98C[];
extern "C" Object DAT_00476C9C;
extern "C" char sub_00068B10[];

void __cdecl sub_00313A80(void)
{
    DAT_00476C9C.sub_0006F790(0, (int)DAT_0041E98C, (int)sub_00068B10, 0, 3, 63);
}
