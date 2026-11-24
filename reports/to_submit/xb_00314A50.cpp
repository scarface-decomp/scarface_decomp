// bin: xb
// va: 0x00314A50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314A50 (0x00314A50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004231DC[];
extern "C" Object DAT_004816FC;
extern "C" char sub_0008FB60[];

void __cdecl sub_00314A50(void)
{
    DAT_004816FC.sub_0006F830(0, (int)DAT_004231DC, (int)sub_0008FB60, 0, 4, 5);
}
