// bin: proto
// va: 0x002E0D70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0D70 (Proto 0x002E0D70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F6CBC[];
extern "C" char DAT_003F6CC0[];
extern "C" Object DAT_00449808;
extern "C" char sub_0002B390[];

void __cdecl sub_002E0D70(void)
{
    DAT_00449808.sub_000655A0((int)DAT_003F6CC0, (int)DAT_003F6CBC, (int)sub_0002B390, 0, 3, 3);
}
