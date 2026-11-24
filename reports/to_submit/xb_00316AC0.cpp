// bin: xb
// va: 0x00316AC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316AC0 (0x00316AC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004288D8[];
extern "C" char DAT_004288E8[];
extern "C" Object DAT_00489A2C;
extern "C" char sub_00119A00[];

void __cdecl sub_00316AC0(void)
{
    DAT_00489A2C.sub_0006F830((int)DAT_004288E8, (int)DAT_004288D8, (int)sub_00119A00, 0, 3, 3);
}
