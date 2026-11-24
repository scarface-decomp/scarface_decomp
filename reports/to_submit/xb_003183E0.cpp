// bin: xb
// va: 0x003183E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003183E0 (0x003183E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FB3C[];
extern "C" char DAT_0042FB5C[];
extern "C" Object DAT_0048B024;
extern "C" char sub_00178C00[];

void __cdecl sub_003183E0(void)
{
    DAT_0048B024.sub_0006F830((int)DAT_0042FB5C, (int)DAT_0042FB3C, (int)sub_00178C00, 0, 5, 11);
}
