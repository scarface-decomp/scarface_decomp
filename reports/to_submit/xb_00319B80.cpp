// bin: xb
// va: 0x00319B80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319B80 (0x00319B80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436468[];
extern "C" char DAT_0043647C[];
extern "C" Object DAT_0048D428;
extern "C" char sub_001BCEB0[];

void __cdecl sub_00319B80(void)
{
    DAT_0048D428.sub_0006F830((int)DAT_0043647C, (int)DAT_00436468, (int)sub_001BCEB0, 0, 6, 6);
}
