// bin: xb
// va: 0x0031F380
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F380 (0x0031F380, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044DB9C[];
extern "C" Object DAT_00491BBC;
extern "C" char sub_00222D10[];

void __cdecl sub_0031F380(void)
{
    DAT_00491BBC.sub_0006F880(0, (int)DAT_0044DB9C, (int)sub_00222D10, 0, 1, 1);
}
