// bin: xb
// va: 0x00317340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317340 (0x00317340, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042B13C[];
extern "C" Object DAT_00489C24;
extern "C" char sub_0011D000[];

void __cdecl sub_00317340(void)
{
    DAT_00489C24.sub_0006F830(0, (int)DAT_0042B13C, (int)sub_0011D000, 0, 2, 2);
}
