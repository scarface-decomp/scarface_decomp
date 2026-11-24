// bin: proto
// va: 0x002E6630
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6630 (Proto 0x002E6630, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B63C[];
extern "C" char DAT_0040B64C[];
extern "C" Object DAT_0045D724;
extern "C" char sub_00158E60[];

void __cdecl sub_002E6630(void)
{
    DAT_0045D724.sub_00065550((int)DAT_0040B64C, (int)DAT_0040B63C, (int)sub_00158E60, 0, 3, 3);
}
