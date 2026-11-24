// bin: xb
// va: 0x00316A20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316A20 (0x00316A20, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00428864[];
extern "C" Object DAT_0048997C;
extern "C" char sub_00119AC0[];

void __cdecl sub_00316A20(void)
{
    DAT_0048997C.sub_0006F830(0, (int)DAT_00428864, (int)sub_00119AC0, 0, 5, 7);
}
