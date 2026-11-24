// bin: xb
// va: 0x0031E120
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E120 (0x0031E120, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C480[];
extern "C" char DAT_0044C494[];
extern "C" Object DAT_004906E0;
extern "C" char sub_00216160[];

void __cdecl sub_0031E120(void)
{
    DAT_004906E0.sub_0006F830((int)DAT_0044C494, (int)DAT_0044C480, (int)sub_00216160, 0, 3, 3);
}
