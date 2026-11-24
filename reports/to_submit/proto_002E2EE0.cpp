// bin: proto
// va: 0x002E2EE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2EE0 (Proto 0x002E2EE0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FDF94[];
extern "C" Object DAT_00453D94;
extern "C" char sub_000590D0[];

void __cdecl sub_002E2EE0(void)
{
    DAT_00453D94.sub_000655A0(0, (int)DAT_003FDF94, (int)sub_000590D0, 0, 2, 2);
}
