// bin: xb
// va: 0x0031E0C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E0C0 (0x0031E0C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C424[];
extern "C" char DAT_0044C434[];
extern "C" Object DAT_0049065C;
extern "C" char sub_00215FB0[];

void __cdecl sub_0031E0C0(void)
{
    DAT_0049065C.sub_0006F830((int)DAT_0044C434, (int)DAT_0044C424, (int)sub_00215FB0, 0, 3, 4);
}
