// bin: proto
// va: 0x002E0AD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0AD0 (Proto 0x002E0AD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F6748[];
extern "C" char DAT_003F674C[];
extern "C" Object DAT_004495A0;
extern "C" char sub_0002A9F0[];

void __cdecl sub_002E0AD0(void)
{
    DAT_004495A0.sub_000655A0((int)DAT_003F674C, (int)DAT_003F6748, (int)sub_0002A9F0, 0, 3, 3);
}
