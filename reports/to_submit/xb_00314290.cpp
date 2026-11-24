// bin: xb
// va: 0x00314290
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314290 (0x00314290, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_004221A0[];
extern "C" Object DAT_00480B88;
extern "C" char sub_00076FA0[];

void __cdecl sub_00314290(void)
{
    DAT_00480B88.sub_0006F740(0, (int)DAT_004221A0, (int)sub_00076FA0, 0, 1, 1);
}
