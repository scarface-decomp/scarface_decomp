// bin: xb
// va: 0x00318840
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318840 (0x00318840, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00430024[];
extern "C" char DAT_0043003C[];
extern "C" Object DAT_0048B628;
extern "C" char sub_00178460[];

void __cdecl sub_00318840(void)
{
    DAT_0048B628.sub_0006F830((int)DAT_0043003C, (int)DAT_00430024, (int)sub_00178460, 0, 3, 3);
}
