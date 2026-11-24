// bin: xb
// va: 0x003149F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003149F0 (0x003149F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00423184[];
extern "C" Object DAT_00481678;
extern "C" char sub_0008FB10[];

void __cdecl sub_003149F0(void)
{
    DAT_00481678.sub_0006F830(0, (int)DAT_00423184, (int)sub_0008FB10, 0, 2, 2);
}
