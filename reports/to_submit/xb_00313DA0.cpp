// bin: xb
// va: 0x00313DA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313DA0 (0x00313DA0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041EF50[];
extern "C" Object DAT_0047AD68;
extern "C" char sub_000711D0[];

void __cdecl sub_00313DA0(void)
{
    DAT_0047AD68.sub_0006F740(0, (int)DAT_0041EF50, (int)sub_000711D0, 0, 3, 3);
}
