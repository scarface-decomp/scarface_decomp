// bin: xb
// va: 0x00317D30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317D30 (0x00317D30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042F298[];
extern "C" Object DAT_0048A8DC;
extern "C" char sub_0015F7D0[];

void __cdecl sub_00317D30(void)
{
    DAT_0048A8DC.sub_0006F880(0, (int)DAT_0042F298, (int)sub_0015F7D0, 0, 1, 1);
}
