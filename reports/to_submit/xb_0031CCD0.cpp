// bin: xb
// va: 0x0031CCD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CCD0 (0x0031CCD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043E9D0[];
extern "C" char DAT_0043E9EC[];
extern "C" Object DAT_0048FCEC;
extern "C" char sub_001EEA70[];

void __cdecl sub_0031CCD0(void)
{
    DAT_0048FCEC.sub_0006F830((int)DAT_0043E9EC, (int)DAT_0043E9D0, (int)sub_001EEA70, 0, 3, 3);
}
