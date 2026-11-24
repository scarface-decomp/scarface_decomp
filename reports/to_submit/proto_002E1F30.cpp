// bin: proto
// va: 0x002E1F30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1F30 (Proto 0x002E1F30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F9C78[];
extern "C" Object DAT_0044F97C;
extern "C" char sub_00066950[];

void __cdecl sub_002E1F30(void)
{
    DAT_0044F97C.sub_000654B0(0, (int)DAT_003F9C78, (int)sub_00066950, 0, 2, 2);
}
