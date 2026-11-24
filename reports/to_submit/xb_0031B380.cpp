// bin: xb
// va: 0x0031B380
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B380 (0x0031B380, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00439488[];
extern "C" char DAT_00439490[];
extern "C" Object DAT_0048EAD8;
extern "C" char sub_001C9D90[];

void __cdecl sub_0031B380(void)
{
    DAT_0048EAD8.sub_0006F830((int)DAT_00439490, (int)DAT_00439488, (int)sub_001C9D90, 0, 3, 3);
}
