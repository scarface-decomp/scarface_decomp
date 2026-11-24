// bin: xb
// va: 0x00314B90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314B90 (0x00314B90, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004232A8[];
extern "C" Object DAT_004818B4;
extern "C" char sub_0008FC30[];

void __cdecl sub_00314B90(void)
{
    DAT_004818B4.sub_0006F790(0, (int)DAT_004232A8, (int)sub_0008FC30, 0, 1, 1);
}
