// bin: xb
// va: 0x00319A80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319A80 (0x00319A80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436328[];
extern "C" char DAT_00436330[];
extern "C" Object DAT_0048D34C;
extern "C" char sub_001BCCE0[];

void __cdecl sub_00319A80(void)
{
    DAT_0048D34C.sub_0006F830((int)DAT_00436330, (int)DAT_00436328, (int)sub_001BCCE0, 0, 3, 3);
}
