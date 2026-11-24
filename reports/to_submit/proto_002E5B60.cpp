// bin: proto
// va: 0x002E5B60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5B60 (Proto 0x002E5B60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A4C0[];
extern "C" char DAT_0040A4D8[];
extern "C" Object DAT_0045C964;
extern "C" char sub_00142820[];

void __cdecl sub_002E5B60(void)
{
    DAT_0045C964.sub_00065550((int)DAT_0040A4D8, (int)DAT_0040A4C0, (int)sub_00142820, 0, 7, 7);
}
