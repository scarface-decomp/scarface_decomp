// bin: xb
// va: 0x00312240
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312240 (0x00312240, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00419FC4[];
extern "C" char DAT_00419FC8[];
extern "C" Object DAT_0047162C;
extern "C" char sub_000209F0[];

void __cdecl sub_00312240(void)
{
    DAT_0047162C.sub_0006F830((int)DAT_00419FC8, (int)DAT_00419FC4, (int)sub_000209F0, 0, 2, 2);
}
