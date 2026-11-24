// bin: xb
// va: 0x0031F2E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F2E0 (0x0031F2E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044DAE8[];
extern "C" Object DAT_00491AE0;
extern "C" char sub_00222C10[];

void __cdecl sub_0031F2E0(void)
{
    DAT_00491AE0.sub_0006F880(0, (int)DAT_0044DAE8, (int)sub_00222C10, 0, 5, 5);
}
