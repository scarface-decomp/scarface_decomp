// bin: xb
// va: 0x00318380
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318380 (0x00318380, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FAD0[];
extern "C" char DAT_0042FAEC[];
extern "C" Object DAT_0048AFA0;
extern "C" char sub_00178080[];

void __cdecl sub_00318380(void)
{
    DAT_0048AFA0.sub_0006F880((int)DAT_0042FAEC, (int)DAT_0042FAD0, (int)sub_00178080, 0, 2, 2);
}
