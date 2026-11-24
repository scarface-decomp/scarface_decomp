// bin: xb
// va: 0x00319900
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319900 (0x00319900, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436000[];
extern "C" char DAT_00436010[];
extern "C" Object DAT_0048D270;
extern "C" char sub_001BC9B0[];

void __cdecl sub_00319900(void)
{
    DAT_0048D270.sub_0006F830((int)DAT_00436010, (int)DAT_00436000, (int)sub_001BC9B0, 0, 3, 3);
}
