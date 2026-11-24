// bin: xb
// va: 0x00319E40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319E40 (0x00319E40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436950[];
extern "C" Object DAT_0048D690;
extern "C" char sub_001BD570[];

void __cdecl sub_00319E40(void)
{
    DAT_0048D690.sub_0006F830(0, (int)DAT_00436950, (int)sub_001BD570, 0, 1, 2);
}
