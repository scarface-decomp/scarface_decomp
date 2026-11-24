// bin: xb
// va: 0x0031C870
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C870 (0x0031C870, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E1C0[];
extern "C" char DAT_0043E1D0[];
extern "C" Object DAT_0048F7EC;
extern "C" char sub_001EE130[];

void __cdecl sub_0031C870(void)
{
    DAT_0048F7EC.sub_0006F830((int)DAT_0043E1D0, (int)DAT_0043E1C0, (int)sub_001EE130, 0, 3, 3);
}
