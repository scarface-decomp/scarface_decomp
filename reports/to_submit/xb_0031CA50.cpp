// bin: xb
// va: 0x0031CA50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CA50 (0x0031CA50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E3B4[];
extern "C" char DAT_0043E3D0[];
extern "C" Object DAT_0048FA80;
extern "C" char sub_001EE320[];

void __cdecl sub_0031CA50(void)
{
    DAT_0048FA80.sub_0006F830((int)DAT_0043E3D0, (int)DAT_0043E3B4, (int)sub_001EE320, 0, 2, 3);
}
