// bin: proto
// va: 0x002E9C60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9C60 (Proto 0x002E9C60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00417B80[];
extern "C" char DAT_00417B90[];
extern "C" Object DAT_00460EA4;
extern "C" char sub_001B43A0[];

void __cdecl sub_002E9C60(void)
{
    DAT_00460EA4.sub_00065550((int)DAT_00417B90, (int)DAT_00417B80, (int)sub_001B43A0, 0, 3, 3);
}
