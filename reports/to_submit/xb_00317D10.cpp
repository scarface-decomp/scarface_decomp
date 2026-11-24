// bin: xb
// va: 0x00317D10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317D10 (0x00317D10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042F274[];
extern "C" char DAT_0042F280[];
extern "C" Object DAT_0048A8B0;
extern "C" char sub_0015F740[];

void __cdecl sub_00317D10(void)
{
    DAT_0048A8B0.sub_0006F880((int)DAT_0042F280, (int)DAT_0042F274, (int)sub_0015F740, 0, 2, 2);
}
