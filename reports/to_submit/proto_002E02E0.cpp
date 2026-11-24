// bin: proto
// va: 0x002E02E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E02E0 (Proto 0x002E02E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F4E68[];
extern "C" char DAT_003F4E74[];
extern "C" Object DAT_00446904;
extern "C" char sub_0001E7E0[];

void __cdecl sub_002E02E0(void)
{
    DAT_00446904.sub_00065550((int)DAT_003F4E74, (int)DAT_003F4E68, (int)sub_0001E7E0, 0, 5, 6);
}
