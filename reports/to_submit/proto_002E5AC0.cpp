// bin: proto
// va: 0x002E5AC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5AC0 (Proto 0x002E5AC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A434[];
extern "C" char DAT_0040A43C[];
extern "C" Object DAT_0045C888;
extern "C" char sub_001426D0[];

void __cdecl sub_002E5AC0(void)
{
    DAT_0045C888.sub_00065550((int)DAT_0040A43C, (int)DAT_0040A434, (int)sub_001426D0, 0, 2, 2);
}
