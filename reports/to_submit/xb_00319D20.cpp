// bin: xb
// va: 0x00319D20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319D20 (0x00319D20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436800[];
extern "C" char DAT_00436808[];
extern "C" Object DAT_0048D530;
extern "C" char sub_001BD360[];

void __cdecl sub_00319D20(void)
{
    DAT_0048D530.sub_0006F830((int)DAT_00436808, (int)DAT_00436800, (int)sub_001BD360, 0, 2, 2);
}
