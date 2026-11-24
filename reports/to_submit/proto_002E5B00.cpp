// bin: proto
// va: 0x002E5B00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5B00 (Proto 0x002E5B00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A468[];
extern "C" char DAT_0040A47C[];
extern "C" Object DAT_0045C8E0;
extern "C" char sub_00142710[];

void __cdecl sub_002E5B00(void)
{
    DAT_0045C8E0.sub_00065550((int)DAT_0040A47C, (int)DAT_0040A468, (int)sub_00142710, 0, 3, 3);
}
