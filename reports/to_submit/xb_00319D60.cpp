// bin: xb
// va: 0x00319D60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319D60 (0x00319D60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436878[];
extern "C" char DAT_00436880[];
extern "C" Object DAT_0048D55C;
extern "C" char sub_001BD3D0[];

void __cdecl sub_00319D60(void)
{
    DAT_0048D55C.sub_0006F830((int)DAT_00436880, (int)DAT_00436878, (int)sub_001BD3D0, 0, 3, 3);
}
