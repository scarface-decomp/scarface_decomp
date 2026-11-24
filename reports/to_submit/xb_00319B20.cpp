// bin: xb
// va: 0x00319B20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319B20 (0x00319B20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043642C[];
extern "C" char DAT_0043643C[];
extern "C" Object DAT_0048D3D0;
extern "C" char sub_001BCE50[];

void __cdecl sub_00319B20(void)
{
    DAT_0048D3D0.sub_0006F830((int)DAT_0043643C, (int)DAT_0043642C, (int)sub_001BCE50, 0, 4, 4);
}
