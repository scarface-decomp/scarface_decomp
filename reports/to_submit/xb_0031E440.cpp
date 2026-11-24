// bin: xb
// va: 0x0031E440
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E440 (0x0031E440, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C7A8[];
extern "C" char DAT_0044C7B8[];
extern "C" Object DAT_00490B2C;
extern "C" char sub_002160A0[];

void __cdecl sub_0031E440(void)
{
    DAT_00490B2C.sub_0006F830((int)DAT_0044C7B8, (int)DAT_0044C7A8, (int)sub_002160A0, 0, 4, 4);
}
