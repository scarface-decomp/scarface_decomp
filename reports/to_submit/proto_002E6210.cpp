// bin: proto
// va: 0x002E6210
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6210 (Proto 0x002E6210, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B1CC[];
extern "C" char DAT_0040B1DC[];
extern "C" Object DAT_0045D178;
extern "C" char sub_001588E0[];

void __cdecl sub_002E6210(void)
{
    DAT_0045D178.sub_000655A0((int)DAT_0040B1DC, (int)DAT_0040B1CC, (int)sub_001588E0, 0, 3, 5);
}
