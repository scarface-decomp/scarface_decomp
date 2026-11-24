// bin: proto
// va: 0x002E1C70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1C70 (Proto 0x002E1C70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F9B80[];
extern "C" Object DAT_0044F5B4;
extern "C" char sub_000667A0[];

void __cdecl sub_002E1C70(void)
{
    DAT_0044F5B4.sub_000655A0(0, (int)DAT_003F9B80, (int)sub_000667A0, 0, 2, 2);
}
