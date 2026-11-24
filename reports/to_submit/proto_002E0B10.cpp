// bin: proto
// va: 0x002E0B10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0B10 (Proto 0x002E0B10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F6764[];
extern "C" char DAT_003F676C[];
extern "C" Object DAT_004495F8;
extern "C" char sub_0002AA70[];

void __cdecl sub_002E0B10(void)
{
    DAT_004495F8.sub_00065550((int)DAT_003F676C, (int)DAT_003F6764, (int)sub_0002AA70, 0, 2, 2);
}
