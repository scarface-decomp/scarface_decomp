// bin: proto
// va: 0x002ECD10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECD10 (Proto 0x002ECD10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427A98[];
extern "C" Object DAT_0046329C;
extern "C" char sub_001EF1A0[];

void __cdecl sub_002ECD10(void)
{
    DAT_0046329C.sub_00065550(0, (int)DAT_00427A98, (int)sub_001EF1A0, 0, 1, 1);
}
