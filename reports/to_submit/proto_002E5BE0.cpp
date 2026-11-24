// bin: proto
// va: 0x002E5BE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5BE0 (Proto 0x002E5BE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A53C[];
extern "C" char DAT_0040A550[];
extern "C" Object DAT_0045CA14;
extern "C" char sub_00142940[];

void __cdecl sub_002E5BE0(void)
{
    DAT_0045CA14.sub_00065550((int)DAT_0040A550, (int)DAT_0040A53C, (int)sub_00142940, 0, 7, 7);
}
