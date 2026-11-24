// bin: xb
// va: 0x00318400
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318400 (0x00318400, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042FB6C[];
extern "C" char DAT_0042FB80[];
extern "C" Object DAT_0048B050;
extern "C" char sub_001780A0[];

void __cdecl sub_00318400(void)
{
    DAT_0048B050.sub_0006F790((int)DAT_0042FB80, (int)DAT_0042FB6C, (int)sub_001780A0, 0, 2, 2);
}
