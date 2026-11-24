// bin: proto
// va: 0x002E8E70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8E70 (Proto 0x002E8E70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00413EFC[];
extern "C" char DAT_00413F04[];
extern "C" Object DAT_004603E4;
extern "C" char sub_0019B030[];

void __cdecl sub_002E8E70(void)
{
    DAT_004603E4.sub_00065550((int)DAT_00413F04, (int)DAT_00413EFC, (int)sub_0019B030, 0, 2, 2);
}
