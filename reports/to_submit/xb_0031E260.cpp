// bin: xb
// va: 0x0031E260
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E260 (0x0031E260, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C5BC[];
extern "C" char DAT_0044C5D0[];
extern "C" Object DAT_00490898;
extern "C" char sub_00216510[];

void __cdecl sub_0031E260(void)
{
    DAT_00490898.sub_0006F830((int)DAT_0044C5D0, (int)DAT_0044C5BC, (int)sub_00216510, 0, 4, 4);
}
