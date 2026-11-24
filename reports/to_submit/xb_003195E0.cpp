// bin: xb
// va: 0x003195E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003195E0 (0x003195E0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003BBB50[];
extern "C" Object DAT_0048C240;
extern "C" char sub_00196EC0[];

void __cdecl sub_003195E0(void)
{
    DAT_0048C240.sub_000EB3A0(52, 38, 10, 85, 1, (int)DAT_003BBB50, (int)sub_00196EC0, 509, 0, 1);
}
