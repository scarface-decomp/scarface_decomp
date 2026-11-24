// bin: xb
// va: 0x003183A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003183A0 (0x003183A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FAFC[];
extern "C" char DAT_0042FB0C[];
extern "C" Object DAT_0048AFCC;
extern "C" char sub_00178930[];

void __cdecl sub_003183A0(void)
{
    DAT_0048AFCC.sub_0006F880((int)DAT_0042FB0C, (int)DAT_0042FAFC, (int)sub_00178930, 0, 3, 4);
}
