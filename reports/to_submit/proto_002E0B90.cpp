// bin: proto
// va: 0x002E0B90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0B90 (Proto 0x002E0B90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F67B0[];
extern "C" char DAT_003F67BC[];
extern "C" Object DAT_004496A8;
extern "C" char sub_0002AA80[];

void __cdecl sub_002E0B90(void)
{
    DAT_004496A8.sub_00065550((int)DAT_003F67BC, (int)DAT_003F67B0, (int)sub_0002AA80, 0, 3, 3);
}
