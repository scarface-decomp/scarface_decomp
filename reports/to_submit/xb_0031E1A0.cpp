// bin: xb
// va: 0x0031E1A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E1A0 (0x0031E1A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0044C504[];
extern "C" char DAT_0044C518[];
extern "C" Object DAT_00490790;
extern "C" char sub_00216370[];

void __cdecl sub_0031E1A0(void)
{
    DAT_00490790.sub_0006F790((int)DAT_0044C518, (int)DAT_0044C504, (int)sub_00216370, 0, 3, 3);
}
