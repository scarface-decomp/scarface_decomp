// bin: proto
// va: 0x002E0D10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0D10 (Proto 0x002E0D10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F6C68[];
extern "C" char DAT_003F6C70[];
extern "C" Object DAT_00449784;
extern "C" char sub_0002B6C0[];

void __cdecl sub_002E0D10(void)
{
    DAT_00449784.sub_000654B0((int)DAT_003F6C70, (int)DAT_003F6C68, (int)sub_0002B6C0, 0, 2, 2);
}
