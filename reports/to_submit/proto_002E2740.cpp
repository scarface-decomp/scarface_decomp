// bin: proto
// va: 0x002E2740
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2740 (Proto 0x002E2740, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FD130[];
extern "C" Object DAT_00453640;
extern "C" char sub_0006CEF0[];

void __cdecl sub_002E2740(void)
{
    DAT_00453640.sub_000655A0(0, (int)DAT_003FD130, (int)sub_0006CEF0, 0, 6, 7);
}
