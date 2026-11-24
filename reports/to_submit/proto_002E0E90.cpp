// bin: proto
// va: 0x002E0E90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0E90 (Proto 0x002E0E90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F715C[];
extern "C" Object DAT_00449B40;
extern "C" char sub_0002C0C0[];

void __cdecl sub_002E0E90(void)
{
    DAT_00449B40.sub_000655A0(0, (int)DAT_003F715C, (int)sub_0002C0C0, 0, 2, 2);
}
