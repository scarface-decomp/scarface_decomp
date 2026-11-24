// bin: xb
// va: 0x00319EC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319EC0 (0x00319EC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00436990[];
extern "C" Object DAT_0048D740;
extern "C" char sub_001BD630[];

void __cdecl sub_00319EC0(void)
{
    DAT_0048D740.sub_0006F880(0, (int)DAT_00436990, (int)sub_001BD630, 0, 1, 1);
}
