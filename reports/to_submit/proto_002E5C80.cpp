// bin: proto
// va: 0x002E5C80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5C80 (Proto 0x002E5C80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A5C8[];
extern "C" char DAT_0040A5D0[];
extern "C" Object DAT_0045CAF0;
extern "C" char sub_00142A60[];

void __cdecl sub_002E5C80(void)
{
    DAT_0045CAF0.sub_00065550((int)DAT_0040A5D0, (int)DAT_0040A5C8, (int)sub_00142A60, 0, 2, 2);
}
