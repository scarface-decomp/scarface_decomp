// bin: xb
// va: 0x0031E420
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E420 (0x0031E420, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C78C[];
extern "C" char DAT_0044C798[];
extern "C" Object DAT_00490B00;
extern "C" char sub_00216780[];

void __cdecl sub_0031E420(void)
{
    DAT_00490B00.sub_0006F830((int)DAT_0044C798, (int)DAT_0044C78C, (int)sub_00216780, 0, 3, 3);
}
