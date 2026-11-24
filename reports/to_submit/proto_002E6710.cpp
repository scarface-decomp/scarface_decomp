// bin: proto
// va: 0x002E6710
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6710 (Proto 0x002E6710, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B748[];
extern "C" char DAT_0040B760[];
extern "C" Object DAT_0045D858;
extern "C" char sub_00158F80[];

void __cdecl sub_002E6710(void)
{
    DAT_0045D858.sub_000654B0((int)DAT_0040B760, (int)DAT_0040B748, (int)sub_00158F80, 0, 2, 2);
}
