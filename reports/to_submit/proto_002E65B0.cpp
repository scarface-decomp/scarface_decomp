// bin: proto
// va: 0x002E65B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E65B0 (Proto 0x002E65B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B5B0[];
extern "C" char DAT_0040B5C8[];
extern "C" Object DAT_0045D674;
extern "C" char sub_001583D0[];

void __cdecl sub_002E65B0(void)
{
    DAT_0045D674.sub_000654B0((int)DAT_0040B5C8, (int)DAT_0040B5B0, (int)sub_001583D0, 0, 2, 2);
}
