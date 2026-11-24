// bin: xb
// va: 0x0031B360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B360 (0x0031B360, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00439468[];
extern "C" char DAT_0043947C[];
extern "C" Object DAT_0048EAAC;
extern "C" char sub_001C9F90[];

void __cdecl sub_0031B360(void)
{
    DAT_0048EAAC.sub_0006F830((int)DAT_0043947C, (int)DAT_00439468, (int)sub_001C9F90, 0, 4, 4);
}
