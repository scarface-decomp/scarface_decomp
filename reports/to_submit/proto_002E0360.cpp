// bin: proto
// va: 0x002E0360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0360 (Proto 0x002E0360, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F4F30[];
extern "C" Object DAT_004469B4;
extern "C" char sub_0001E900[];

void __cdecl sub_002E0360(void)
{
    DAT_004469B4.sub_00065550(0, (int)DAT_003F4F30, (int)sub_0001E900, 0, 2, 2);
}
