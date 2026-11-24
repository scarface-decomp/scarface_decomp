// bin: xb
// va: 0x00318920
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318920 (0x00318920, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043010C[];
extern "C" char DAT_0043012C[];
extern "C" Object DAT_0048B75C;
extern "C" char sub_00178F70[];

void __cdecl sub_00318920(void)
{
    DAT_0048B75C.sub_0006F830((int)DAT_0043012C, (int)DAT_0043010C, (int)sub_00178F70, 0, 3, 4);
}
