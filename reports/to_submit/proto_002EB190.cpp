// bin: proto
// va: 0x002EB190
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB190 (Proto 0x002EB190, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425DC0[];
extern "C" char DAT_00425DD4[];
extern "C" Object DAT_004618E8;
extern "C" char sub_001DA880[];

void __cdecl sub_002EB190(void)
{
    DAT_004618E8.sub_00065550((int)DAT_00425DD4, (int)DAT_00425DC0, (int)sub_001DA880, 0, 2, 2);
}
