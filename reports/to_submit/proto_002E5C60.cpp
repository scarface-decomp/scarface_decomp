// bin: proto
// va: 0x002E5C60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5C60 (Proto 0x002E5C60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A5AC[];
extern "C" char DAT_0040A5BC[];
extern "C" Object DAT_0045CAC4;
extern "C" char sub_00142A30[];

void __cdecl sub_002E5C60(void)
{
    DAT_0045CAC4.sub_00065550((int)DAT_0040A5BC, (int)DAT_0040A5AC, (int)sub_00142A30, 0, 3, 3);
}
