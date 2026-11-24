// bin: proto
// va: 0x002E1370
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1370 (Proto 0x002E1370, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F7628[];
extern "C" Object DAT_0044A1B0;
extern "C" char sub_00039330[];

void __cdecl sub_002E1370(void)
{
    DAT_0044A1B0.sub_000655A0(0, (int)DAT_003F7628, (int)sub_00039330, 0, 1, 1);
}
