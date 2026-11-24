// bin: xb
// va: 0x00316AA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316AA0 (0x00316AA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004288AC[];
extern "C" char DAT_004288C8[];
extern "C" Object DAT_00489A00;
extern "C" char sub_001199E0[];

void __cdecl sub_00316AA0(void)
{
    DAT_00489A00.sub_0006F830((int)DAT_004288C8, (int)DAT_004288AC, (int)sub_001199E0, 0, 3, 3);
}
