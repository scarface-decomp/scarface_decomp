// bin: xb
// va: 0x00319F60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319F60 (0x00319F60, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436A04[];
extern "C" Object DAT_0048D81C;
extern "C" char sub_001BD6D0[];

void __cdecl sub_00319F60(void)
{
    DAT_0048D81C.sub_0006F830(0, (int)DAT_00436A04, (int)sub_001BD6D0, 0, 2, 2);
}
