// bin: proto
// va: 0x002E2640
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2640 (Proto 0x002E2640, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FD088[];
extern "C" Object DAT_004534E0;
extern "C" char sub_0006CC80[];

void __cdecl sub_002E2640(void)
{
    DAT_004534E0.sub_000655A0(0, (int)DAT_003FD088, (int)sub_0006CC80, 0, 3, 4);
}
