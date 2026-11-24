// bin: proto
// va: 0x002E9CC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9CC0 (Proto 0x002E9CC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00417BF0[];
extern "C" char DAT_00417C08[];
extern "C" Object DAT_00460F28;
extern "C" char sub_001B4430[];

void __cdecl sub_002E9CC0(void)
{
    DAT_00460F28.sub_00065550((int)DAT_00417C08, (int)DAT_00417BF0, (int)sub_001B4430, 0, 3, 3);
}
