// bin: xb
// va: 0x0031E140
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E140 (0x0031E140, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C4A4[];
extern "C" char DAT_0044C4B4[];
extern "C" Object DAT_0049070C;
extern "C" char sub_00216010[];

void __cdecl sub_0031E140(void)
{
    DAT_0049070C.sub_0006F830((int)DAT_0044C4B4, (int)DAT_0044C4A4, (int)sub_00216010, 0, 2, 2);
}
