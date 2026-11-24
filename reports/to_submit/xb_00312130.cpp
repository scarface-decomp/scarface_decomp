// bin: xb
// va: 0x00312130
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312130 (0x00312130, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0039E114[];
extern "C" Object DAT_00471518;
extern "C" char sub_0001F220[];

void __cdecl sub_00312130(void)
{
    DAT_00471518.sub_000EB3A0(13, 2, 5, 57, 41, (int)DAT_0039E114, (int)sub_0001F220, 509, 3, 1);
}
