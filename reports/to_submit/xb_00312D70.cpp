// bin: xb
// va: 0x00312D70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312D70 (0x00312D70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041C218[];
extern "C" Object DAT_00474798;
extern "C" char sub_0002EB50[];

void __cdecl sub_00312D70(void)
{
    DAT_00474798.sub_0006F880(0, (int)DAT_0041C218, (int)sub_0002EB50, 0, 2, 2);
}
