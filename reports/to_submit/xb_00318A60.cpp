// bin: xb
// va: 0x00318A60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318A60 (0x00318A60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00430280[];
extern "C" char DAT_00430290[];
extern "C" Object DAT_0048B914;
extern "C" char sub_001786B0[];

void __cdecl sub_00318A60(void)
{
    DAT_0048B914.sub_0006F830((int)DAT_00430290, (int)DAT_00430280, (int)sub_001786B0, 0, 2, 2);
}
