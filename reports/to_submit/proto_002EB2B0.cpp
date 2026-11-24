// bin: proto
// va: 0x002EB2B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB2B0 (Proto 0x002EB2B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_00425EE4[];
extern "C" char DAT_00425EF0[];
extern "C" Object DAT_00461A74;
extern "C" char sub_001DAA80[];

void __cdecl sub_002EB2B0(void)
{
    DAT_00461A74.sub_00065460((int)DAT_00425EF0, (int)DAT_00425EE4, (int)sub_001DAA80, 0, 2, 2);
}
