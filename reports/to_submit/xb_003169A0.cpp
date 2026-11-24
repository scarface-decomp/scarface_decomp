// bin: xb
// va: 0x003169A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003169A0 (0x003169A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00428654[];
extern "C" Object DAT_004898EC;
extern "C" char sub_00115300[];

void __cdecl sub_003169A0(void)
{
    DAT_004898EC.sub_0006F830(0, (int)DAT_00428654, (int)sub_00115300, 0, 2, 2);
}
