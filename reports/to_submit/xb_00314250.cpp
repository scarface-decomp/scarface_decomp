// bin: xb
// va: 0x00314250
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314250 (0x00314250, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042216C[];
extern "C" Object DAT_00480B30;
extern "C" char sub_00077340[];

void __cdecl sub_00314250(void)
{
    DAT_00480B30.sub_0006F830(0, (int)DAT_0042216C, (int)sub_00077340, 0, 2, 5);
}
