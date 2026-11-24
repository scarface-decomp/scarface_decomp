// bin: xb
// va: 0x00319480
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319480 (0x00319480, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00433FF8[];
extern "C" Object DAT_0048C110;
extern "C" char sub_00189660[];

void __cdecl sub_00319480(void)
{
    DAT_0048C110.sub_0006F830(0, (int)DAT_00433FF8, (int)sub_00189660, 0, 1, 2);
}
