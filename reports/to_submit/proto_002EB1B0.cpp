// bin: proto
// va: 0x002EB1B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB1B0 (Proto 0x002EB1B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425DE4[];
extern "C" char DAT_00425DF8[];
extern "C" Object DAT_00461914;
extern "C" char sub_001DA8A0[];

void __cdecl sub_002EB1B0(void)
{
    DAT_00461914.sub_00065550((int)DAT_00425DF8, (int)DAT_00425DE4, (int)sub_001DA8A0, 0, 3, 3);
}
