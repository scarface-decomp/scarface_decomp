// bin: proto
// va: 0x002EB430
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB430 (Proto 0x002EB430, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00426074[];
extern "C" char DAT_00426084[];
extern "C" Object DAT_00461C84;
extern "C" char sub_001DA7B0[];

void __cdecl sub_002EB430(void)
{
    DAT_00461C84.sub_00065550((int)DAT_00426084, (int)DAT_00426074, (int)sub_001DA7B0, 0, 3, 3);
}
