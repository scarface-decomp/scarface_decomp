// bin: xb
// va: 0x00314F00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314F00 (0x00314F00, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A48E0[];
extern "C" Object DAT_004866E8;
extern "C" char sub_0009A9E0[];

void __cdecl sub_00314F00(void)
{
    DAT_004866E8.sub_000EB3A0(41, 28, 28, 68, 18, (int)DAT_003A48E0, (int)sub_0009A9E0, 80, 3, 0);
}
