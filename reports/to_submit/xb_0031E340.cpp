// bin: xb
// va: 0x0031E340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E340 (0x0031E340, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044C6B0[];
extern "C" char DAT_0044C6BC[];
extern "C" Object DAT_004909CC;
extern "C" char sub_002166C0[];

void __cdecl sub_0031E340(void)
{
    DAT_004909CC.sub_0006F880((int)DAT_0044C6BC, (int)DAT_0044C6B0, (int)sub_002166C0, 0, 2, 2);
}
