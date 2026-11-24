// bin: xb
// va: 0x00318AE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318AE0 (0x00318AE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00430304[];
extern "C" char DAT_0043031C[];
extern "C" Object DAT_0048B9C4;
extern "C" char sub_002A9290[];

void __cdecl sub_00318AE0(void)
{
    DAT_0048B9C4.sub_0006F830((int)DAT_0043031C, (int)DAT_00430304, (int)sub_002A9290, 0, 3, 3);
}
