// bin: proto
// va: 0x002E62F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E62F0 (Proto 0x002E62F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B2B8[];
extern "C" char DAT_0040B2C4[];
extern "C" Object DAT_0045D2AC;
extern "C" char sub_001581C0[];

void __cdecl sub_002E62F0(void)
{
    DAT_0045D2AC.sub_000654B0((int)DAT_0040B2C4, (int)DAT_0040B2B8, (int)sub_001581C0, 0, 3, 4);
}
