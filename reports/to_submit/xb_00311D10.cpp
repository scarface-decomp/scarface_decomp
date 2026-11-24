// bin: xb
// va: 0x00311D10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00311D10 (0x00311D10, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0039D7D4[];
extern "C" Object DAT_00471168;
extern "C" char sub_00017B40[];

void __cdecl sub_00311D10(void)
{
    DAT_00471168.sub_000EB3A0(24, 26, 13, 64, 31, (int)DAT_0039D7D4, (int)sub_00017B40, 64, 0, 0);
}
