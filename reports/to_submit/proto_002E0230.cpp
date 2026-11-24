// bin: proto
// va: 0x002E0230
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0230 (Proto 0x002E0230, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0037D748[];
extern "C" Object DAT_00446870;
extern "C" char sub_0001DDA0[];

void __cdecl sub_002E0230(void)
{
    DAT_00446870.sub_000D8CC0(10, 1, 2, 52, 41, (int)DAT_0037D748, (int)sub_0001DDA0, 509, 3, 1);
}
