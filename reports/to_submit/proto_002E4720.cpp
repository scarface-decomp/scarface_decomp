// bin: proto
// va: 0x002E4720
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4720 (Proto 0x002E4720, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_004023E4[];
extern "C" Object DAT_0045B6BC;
extern "C" char sub_000DB6D0[];

void __cdecl sub_002E4720(void)
{
    DAT_0045B6BC.sub_000654B0(0, (int)DAT_004023E4, (int)sub_000DB6D0, 0, 2, 2);
}
