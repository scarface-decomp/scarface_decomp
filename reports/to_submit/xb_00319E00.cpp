// bin: xb
// va: 0x00319E00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319E00 (0x00319E00, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00436934[];
extern "C" Object DAT_0048D638;
extern "C" char sub_001BD490[];

void __cdecl sub_00319E00(void)
{
    DAT_0048D638.sub_0006F880(0, (int)DAT_00436934, (int)sub_001BD490, 0, 1, 1);
}
