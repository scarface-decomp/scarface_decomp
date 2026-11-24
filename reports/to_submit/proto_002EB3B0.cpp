// bin: proto
// va: 0x002EB3B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB3B0 (Proto 0x002EB3B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425FFC[];
extern "C" char DAT_00426008[];
extern "C" Object DAT_00461BD4;
extern "C" char sub_001DACE0[];

void __cdecl sub_002EB3B0(void)
{
    DAT_00461BD4.sub_00065550((int)DAT_00426008, (int)DAT_00425FFC, (int)sub_001DACE0, 0, 3, 3);
}
