// bin: xb
// va: 0x0031AE60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AE60 (0x0031AE60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00438828[];
extern "C" char DAT_00438830[];
extern "C" Object DAT_0048E628;
extern "C" char sub_001C71A0[];

void __cdecl sub_0031AE60(void)
{
    DAT_0048E628.sub_0006F830((int)DAT_00438830, (int)DAT_00438828, (int)sub_001C71A0, 0, 2, 2);
}
