// bin: xb
// va: 0x00312D10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312D10 (0x00312D10, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3F0(int, int, int);
};

extern "C" Object DAT_0047473D;
extern "C" char sub_0002E7C0[];

void __cdecl sub_00312D10(void)
{
    DAT_0047473D.sub_000EB3F0(2, (int)sub_0002E7C0, 0);
}
