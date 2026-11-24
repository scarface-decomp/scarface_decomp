// bin: proto
// va: 0x002E2500
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2500 (Proto 0x002E2500, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FCF7C[];
extern "C" Object DAT_00453328;
extern "C" char sub_0006C720[];

void __cdecl sub_002E2500(void)
{
    DAT_00453328.sub_00065550(0, (int)DAT_003FCF7C, (int)sub_0006C720, 0, 1, 1);
}
