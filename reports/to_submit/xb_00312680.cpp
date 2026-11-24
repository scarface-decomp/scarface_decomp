// bin: xb
// va: 0x00312680
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312680 (0x00312680, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041AA94[];
extern "C" char DAT_0041AAA4[];
extern "C" Object DAT_004719AC;
extern "C" char sub_00024D50[];

void __cdecl sub_00312680(void)
{
    DAT_004719AC.sub_0006F830((int)DAT_0041AAA4, (int)DAT_0041AA94, (int)sub_00024D50, 0, 4, 4);
}
