// bin: proto
// va: 0x002E6670
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6670 (Proto 0x002E6670, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B67C[];
extern "C" char DAT_0040B690[];
extern "C" Object DAT_0045D77C;
extern "C" char sub_00158F10[];

void __cdecl sub_002E6670(void)
{
    DAT_0045D77C.sub_00065550((int)DAT_0040B690, (int)DAT_0040B67C, (int)sub_00158F10, 0, 3, 4);
}
