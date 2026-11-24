// bin: xb
// va: 0x0031C810
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031C810 (0x0031C810, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E17C[];
extern "C" char DAT_0043E184[];
extern "C" Object DAT_0048F794;
extern "C" char sub_001EE3E0[];

void __cdecl sub_0031C810(void)
{
    DAT_0048F794.sub_0006F830((int)DAT_0043E184, (int)DAT_0043E17C, (int)sub_001EE3E0, 0, 4, 4);
}
