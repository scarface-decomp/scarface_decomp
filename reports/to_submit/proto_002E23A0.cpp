// bin: proto
// va: 0x002E23A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E23A0 (Proto 0x002E23A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FCE84[];
extern "C" Object DAT_00453144;
extern "C" char sub_0006C4F0[];

void __cdecl sub_002E23A0(void)
{
    DAT_00453144.sub_00065550(0, (int)DAT_003FCE84, (int)sub_0006C4F0, 0, 2, 2);
}
