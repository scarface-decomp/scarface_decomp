// bin: xb
// va: 0x00312C30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312C30 (0x00312C30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041BD38[];
extern "C" char DAT_0041BD3C[];
extern "C" Object DAT_00474434;
extern "C" char sub_0002DD40[];

void __cdecl sub_00312C30(void)
{
    DAT_00474434.sub_0006F880((int)DAT_0041BD3C, (int)DAT_0041BD38, (int)sub_0002DD40, 0, 3, 3);
}
