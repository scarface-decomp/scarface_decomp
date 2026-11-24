// bin: xb
// va: 0x00314C60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314C60 (0x00314C60, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A4584[];
extern "C" Object DAT_00481B58;
extern "C" char sub_00096430[];

void __cdecl sub_00314C60(void)
{
    DAT_00481B58.sub_000EB3A0(57, 43, 53, 91, 50, (int)DAT_003A4584, (int)sub_00096430, 72, 0, 0);
}
