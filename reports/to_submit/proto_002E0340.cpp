// bin: proto
// va: 0x002E0340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0340 (Proto 0x002E0340, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F4EA4[];
extern "C" char DAT_003F4EB0[];
extern "C" Object DAT_00446988;
extern "C" char sub_0001E850[];

void __cdecl sub_002E0340(void)
{
    DAT_00446988.sub_000655A0((int)DAT_003F4EB0, (int)DAT_003F4EA4, (int)sub_0001E850, 0, 2, 2);
}
