// bin: xb
// va: 0x00316950
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316950 (0x00316950, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AD4A0[];
extern "C" Object DAT_004898BC;
extern "C" char sub_00115360[];

void __cdecl sub_00316950(void)
{
    DAT_004898BC.sub_000EB3A0(42, 29, 26, 69, 10, (int)DAT_003AD4A0, (int)sub_00115360, 64, 0, 0);
}
