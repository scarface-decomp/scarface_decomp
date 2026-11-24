// bin: xb
// va: 0x0031E280
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E280 (0x0031E280, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C5E0[];
extern "C" char DAT_0044C5F4[];
extern "C" Object DAT_004908C4;
extern "C" char sub_00216570[];

void __cdecl sub_0031E280(void)
{
    DAT_004908C4.sub_0006F830((int)DAT_0044C5F4, (int)DAT_0044C5E0, (int)sub_00216570, 0, 4, 4);
}
