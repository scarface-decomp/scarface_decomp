// bin: xb
// va: 0x003188E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003188E0 (0x003188E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004300C0[];
extern "C" char DAT_004300D0[];
extern "C" Object DAT_0048B704;
extern "C" char sub_00178500[];

void __cdecl sub_003188E0(void)
{
    DAT_0048B704.sub_0006F830((int)DAT_004300D0, (int)DAT_004300C0, (int)sub_00178500, 0, 3, 3);
}
