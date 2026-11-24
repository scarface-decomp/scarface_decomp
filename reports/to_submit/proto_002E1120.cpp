// bin: proto
// va: 0x002E1120
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1120 (Proto 0x002E1120, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0037F590[];
extern "C" Object DAT_00449ED4;
extern "C" char sub_00034A40[];

void __cdecl sub_002E1120(void)
{
    DAT_00449ED4.sub_000D8CC0(18, 21, 9, 56, 34, (int)DAT_0037F590, (int)sub_00034A40, 80, 0, 0);
}
