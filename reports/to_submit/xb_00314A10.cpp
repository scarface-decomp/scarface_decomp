// bin: xb
// va: 0x00314A10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314A10 (0x00314A10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004231A4[];
extern "C" Object DAT_004816A4;
extern "C" char sub_0008FB30[];

void __cdecl sub_00314A10(void)
{
    DAT_004816A4.sub_0006F830(0, (int)DAT_004231A4, (int)sub_0008FB30, 0, 2, 2);
}
