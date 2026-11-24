// bin: xb
// va: 0x0031E2A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E2A0 (0x0031E2A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_0044C604[];
extern "C" char DAT_0044C618[];
extern "C" Object DAT_004908F0;
extern "C" char sub_002165D0[];

void __cdecl sub_0031E2A0(void)
{
    DAT_004908F0.sub_0006F7E0((int)DAT_0044C618, (int)DAT_0044C604, (int)sub_002165D0, 0, 2, 2);
}
