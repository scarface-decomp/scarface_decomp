// bin: xb
// va: 0x00318D60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318D60 (0x00318D60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00430D20[];
extern "C" char DAT_00430D38[];
extern "C" Object DAT_0048BC40;
extern "C" char sub_00179E00[];

void __cdecl sub_00318D60(void)
{
    DAT_0048BC40.sub_0006F880((int)DAT_00430D38, (int)DAT_00430D20, (int)sub_00179E00, 0, 2, 2);
}
