// bin: proto
// va: 0x002E8110
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8110 (Proto 0x002E8110, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411648[];
extern "C" char DAT_00411658[];
extern "C" Object DAT_0045FC38;
extern "C" char sub_0018BA20[];

void __cdecl sub_002E8110(void)
{
    DAT_0045FC38.sub_00065550((int)DAT_00411658, (int)DAT_00411648, (int)sub_0018BA20, 0, 4, 4);
}
