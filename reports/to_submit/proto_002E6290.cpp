// bin: proto
// va: 0x002E6290
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6290 (Proto 0x002E6290, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B25C[];
extern "C" char DAT_0040B270[];
extern "C" Object DAT_0045D228;
extern "C" char sub_00158180[];

void __cdecl sub_002E6290(void)
{
    DAT_0045D228.sub_000654B0((int)DAT_0040B270, (int)DAT_0040B25C, (int)sub_00158180, 0, 2, 2);
}
