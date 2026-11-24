// bin: proto
// va: 0x002E2DD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2DD0 (Proto 0x002E2DD0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_00383804[];
extern "C" Object DAT_00453BD0;
extern "C" char sub_00081FB0[];

void __cdecl sub_002E2DD0(void)
{
    DAT_00453BD0.sub_000D8CC0(45, 32, 22, 32, 5, (int)DAT_00383804, (int)sub_00081FB0, 509, 3, 1);
}
