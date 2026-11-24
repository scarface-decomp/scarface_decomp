// bin: xb
// va: 0x0031E360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E360 (0x0031E360, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044C6CC[];
extern "C" char DAT_0044C6E0[];
extern "C" Object DAT_004909F8;
extern "C" char sub_002166F0[];

void __cdecl sub_0031E360(void)
{
    DAT_004909F8.sub_0006F880((int)DAT_0044C6E0, (int)DAT_0044C6CC, (int)sub_002166F0, 0, 2, 2);
}
