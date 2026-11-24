// bin: xb
// va: 0x00319DE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319DE0 (0x00319DE0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043691C[];
extern "C" Object DAT_0048D60C;
extern "C" char sub_001BD480[];

void __cdecl sub_00319DE0(void)
{
    DAT_0048D60C.sub_0006F830(0, (int)DAT_0043691C, (int)sub_001BD480, 0, 1, 1);
}
