// bin: proto
// va: 0x002E6870
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6870 (Proto 0x002E6870, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B8AC[];
extern "C" char DAT_0040B8B4[];
extern "C" Object DAT_0045DA3C;
extern "C" char sub_00158690[];

void __cdecl sub_002E6870(void)
{
    DAT_0045DA3C.sub_000655A0((int)DAT_0040B8B4, (int)DAT_0040B8AC, (int)sub_00158690, 0, 2, 2);
}
