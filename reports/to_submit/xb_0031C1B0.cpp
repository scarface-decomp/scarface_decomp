// bin: xb
// va: 0x0031C1B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C1B0 (0x0031C1B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043B8B8[];
extern "C" char DAT_0043B8C0[];
extern "C" Object DAT_0048F3C8;
extern "C" char sub_001D7560[];

void __cdecl sub_0031C1B0(void)
{
    DAT_0048F3C8.sub_0006F830((int)DAT_0043B8C0, (int)DAT_0043B8B8, (int)sub_001D7560, 0, 2, 2);
}
