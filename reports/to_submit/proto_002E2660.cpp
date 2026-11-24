// bin: proto
// va: 0x002E2660
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2660 (Proto 0x002E2660, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FD098[];
extern "C" Object DAT_0045350C;
extern "C" char sub_0006CD30[];

void __cdecl sub_002E2660(void)
{
    DAT_0045350C.sub_000655A0(0, (int)DAT_003FD098, (int)sub_0006CD30, 0, 3, 3);
}
