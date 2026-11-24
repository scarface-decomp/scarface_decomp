// bin: xb
// va: 0x00320020
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320020 (0x00320020, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0044E510[];
extern "C" Object DAT_00492520;
extern "C" char sub_002307D0[];

void __cdecl sub_00320020(void)
{
    DAT_00492520.sub_0006F790(0, (int)DAT_0044E510, (int)sub_002307D0, 0, 2, 2);
}
