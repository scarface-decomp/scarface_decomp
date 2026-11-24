// bin: proto
// va: 0x002E0D30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0D30 (Proto 0x002E0D30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F6C80[];
extern "C" char DAT_003F6C90[];
extern "C" Object DAT_004497B0;
extern "C" char sub_0002B6D0[];

void __cdecl sub_002E0D30(void)
{
    DAT_004497B0.sub_000654B0((int)DAT_003F6C90, (int)DAT_003F6C80, (int)sub_0002B6D0, 0, 2, 2);
}
