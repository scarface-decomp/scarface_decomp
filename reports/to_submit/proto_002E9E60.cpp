// bin: proto
// va: 0x002E9E60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9E60 (Proto 0x002E9E60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00418128[];
extern "C" char DAT_0041813C[];
extern "C" Object DAT_00461060;
extern "C" char sub_001B4A80[];

void __cdecl sub_002E9E60(void)
{
    DAT_00461060.sub_00065550((int)DAT_0041813C, (int)DAT_00418128, (int)sub_001B4A80, 0, 3, 3);
}
