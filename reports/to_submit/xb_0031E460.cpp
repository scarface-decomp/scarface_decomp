// bin: xb
// va: 0x0031E460
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E460 (0x0031E460, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044C7C8[];
extern "C" char DAT_0044C7D4[];
extern "C" Object DAT_00490B58;
extern "C" char sub_002160F0[];

void __cdecl sub_0031E460(void)
{
    DAT_00490B58.sub_0006F880((int)DAT_0044C7D4, (int)DAT_0044C7C8, (int)sub_002160F0, 0, 2, 2);
}
