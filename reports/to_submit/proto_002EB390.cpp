// bin: proto
// va: 0x002EB390
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB390 (Proto 0x002EB390, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425FC8[];
extern "C" char DAT_00425FEC[];
extern "C" Object DAT_00461BA8;
extern "C" char sub_001DACB0[];

void __cdecl sub_002EB390(void)
{
    DAT_00461BA8.sub_00065550((int)DAT_00425FEC, (int)DAT_00425FC8, (int)sub_001DACB0, 0, 3, 3);
}
