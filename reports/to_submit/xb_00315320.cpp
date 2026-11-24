// bin: xb
// va: 0x00315320
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315320 (0x00315320, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424704[];
extern "C" char DAT_00424710[];
extern "C" Object DAT_00486E70;
extern "C" char sub_000C9F00[];

void __cdecl sub_00315320(void)
{
    DAT_00486E70.sub_0006F830((int)DAT_00424710, (int)DAT_00424704, (int)sub_000C9F00, 0, 3, 6);
}
