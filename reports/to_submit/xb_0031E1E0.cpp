// bin: xb
// va: 0x0031E1E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E1E0 (0x0031E1E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C548[];
extern "C" char DAT_0044C550[];
extern "C" Object DAT_004907E8;
extern "C" char sub_002163E0[];

void __cdecl sub_0031E1E0(void)
{
    DAT_004907E8.sub_0006F830((int)DAT_0044C550, (int)DAT_0044C548, (int)sub_002163E0, 0, 2, 2);
}
