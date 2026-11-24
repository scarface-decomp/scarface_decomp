// bin: xb
// va: 0x00313920
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313920 (0x00313920, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041E900[];
extern "C" Object DAT_00476AB8;
extern "C" char sub_00068A00[];

void __cdecl sub_00313920(void)
{
    DAT_00476AB8.sub_0006F880(0, (int)DAT_0041E900, (int)sub_00068A00, 0, 3, 4);
}
