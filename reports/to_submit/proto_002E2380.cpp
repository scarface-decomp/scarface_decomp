// bin: proto
// va: 0x002E2380
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2380 (Proto 0x002E2380, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FCE6C[];
extern "C" Object DAT_00453118;
extern "C" char sub_0006C9A0[];

void __cdecl sub_002E2380(void)
{
    DAT_00453118.sub_00065550(0, (int)DAT_003FCE6C, (int)sub_0006C9A0, 0, 2, 5);
}
