// bin: proto
// va: 0x002E2320
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2320 (Proto 0x002E2320, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FCE18[];
extern "C" Object DAT_00453094;
extern "C" char sub_0006C4A0[];

void __cdecl sub_002E2320(void)
{
    DAT_00453094.sub_00065550(0, (int)DAT_003FCE18, (int)sub_0006C4A0, 0, 3, 3);
}
