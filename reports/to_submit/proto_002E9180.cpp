// bin: proto
// va: 0x002E9180
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9180 (Proto 0x002E9180, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00414A3C[];
extern "C" Object DAT_0046070C;
extern "C" char sub_0019ECF0[];

void __cdecl sub_002E9180(void)
{
    DAT_0046070C.sub_00065550(0, (int)DAT_00414A3C, (int)sub_0019ECF0, 0, 2, 2);
}
