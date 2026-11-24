// bin: proto
// va: 0x002EB1D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB1D0 (Proto 0x002EB1D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425E08[];
extern "C" char DAT_00425E18[];
extern "C" Object DAT_00461940;
extern "C" char sub_001DA790[];

void __cdecl sub_002EB1D0(void)
{
    DAT_00461940.sub_00065550((int)DAT_00425E18, (int)DAT_00425E08, (int)sub_001DA790, 0, 2, 2);
}
