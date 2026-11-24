// bin: xb
// va: 0x00319E80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319E80 (0x00319E80, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436968[];
extern "C" Object DAT_0048D6E8;
extern "C" char sub_001BD5E0[];

void __cdecl sub_00319E80(void)
{
    DAT_0048D6E8.sub_0006F830(0, (int)DAT_00436968, (int)sub_001BD5E0, 0, 3, 3);
}
