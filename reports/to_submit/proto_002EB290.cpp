// bin: proto
// va: 0x002EB290
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB290 (Proto 0x002EB290, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425ECC[];
extern "C" char DAT_00425ED4[];
extern "C" Object DAT_00461A48;
extern "C" char sub_001DAA60[];

void __cdecl sub_002EB290(void)
{
    DAT_00461A48.sub_00065550((int)DAT_00425ED4, (int)DAT_00425ECC, (int)sub_001DAA60, 0, 2, 2);
}
