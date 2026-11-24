// bin: proto
// va: 0x002E6190
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6190 (Proto 0x002E6190, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B13C[];
extern "C" char DAT_0040B148[];
extern "C" Object DAT_0045D0C8;
extern "C" char sub_001580B0[];

void __cdecl sub_002E6190(void)
{
    DAT_0045D0C8.sub_000655A0((int)DAT_0040B148, (int)DAT_0040B13C, (int)sub_001580B0, 0, 5, 5);
}
