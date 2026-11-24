// bin: xb
// va: 0x00312BB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312BB0 (0x00312BB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041BCC0[];
extern "C" char DAT_0041BCD4[];
extern "C" Object DAT_00474384;
extern "C" char sub_0002DD30[];

void __cdecl sub_00312BB0(void)
{
    DAT_00474384.sub_0006F830((int)DAT_0041BCD4, (int)DAT_0041BCC0, (int)sub_0002DD30, 0, 2, 2);
}
