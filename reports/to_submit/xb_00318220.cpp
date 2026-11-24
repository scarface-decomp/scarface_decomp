// bin: xb
// va: 0x00318220
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318220 (0x00318220, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F8D8[];
extern "C" char DAT_0042F8EC[];
extern "C" Object DAT_0048AE3C;
extern "C" char sub_00177DE0[];

void __cdecl sub_00318220(void)
{
    DAT_0048AE3C.sub_0006F830((int)DAT_0042F8EC, (int)DAT_0042F8D8, (int)sub_00177DE0, 0, 3, 3);
}
