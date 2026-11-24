// bin: proto
// va: 0x002E8170
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8170 (Proto 0x002E8170, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_00411690[];
extern "C" char DAT_004116A4[];
extern "C" Object DAT_0045FCBC;
extern "C" char sub_0018BA90[];

void __cdecl sub_002E8170(void)
{
    DAT_0045FCBC.sub_00065460((int)DAT_004116A4, (int)DAT_00411690, (int)sub_0018BA90, 0, 2, 2);
}
