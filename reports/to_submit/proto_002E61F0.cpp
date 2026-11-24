// bin: proto
// va: 0x002E61F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E61F0 (Proto 0x002E61F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B1A0[];
extern "C" char DAT_0040B1BC[];
extern "C" Object DAT_0045D14C;
extern "C" char sub_00158160[];

void __cdecl sub_002E61F0(void)
{
    DAT_0045D14C.sub_000655A0((int)DAT_0040B1BC, (int)DAT_0040B1A0, (int)sub_00158160, 0, 2, 2);
}
