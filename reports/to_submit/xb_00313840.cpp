// bin: xb
// va: 0x00313840
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313840 (0x00313840, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A1C5C[];
extern "C" Object DAT_00476358;
extern "C" char sub_00064C90[];

void __cdecl sub_00313840(void)
{
    DAT_00476358.sub_000EB3A0(3, 3, 3, 55, 46, (int)DAT_003A1C5C, (int)sub_00064C90, 509, 3, 1);
}
