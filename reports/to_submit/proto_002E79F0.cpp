// bin: proto
// va: 0x002E79F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E79F0 (Proto 0x002E79F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00410C98[];
extern "C" char DAT_00410CB0[];
extern "C" Object DAT_0045F450;
extern "C" char sub_0018AF30[];

void __cdecl sub_002E79F0(void)
{
    DAT_0045F450.sub_000654B0((int)DAT_00410CB0, (int)DAT_00410C98, (int)sub_0018AF30, 0, 2, 2);
}
