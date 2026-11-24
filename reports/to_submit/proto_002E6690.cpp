// bin: proto
// va: 0x002E6690
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6690 (Proto 0x002E6690, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B6A0[];
extern "C" char DAT_0040B6C0[];
extern "C" Object DAT_0045D7A8;
extern "C" char sub_00158480[];

void __cdecl sub_002E6690(void)
{
    DAT_0045D7A8.sub_00065550((int)DAT_0040B6C0, (int)DAT_0040B6A0, (int)sub_00158480, 0, 3, 4);
}
