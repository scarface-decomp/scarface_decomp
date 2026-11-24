// bin: proto
// va: 0x002EB310
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB310 (Proto 0x002EB310, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425F40[];
extern "C" char DAT_00425F54[];
extern "C" Object DAT_00461AF8;
extern "C" char sub_001DAB90[];

void __cdecl sub_002EB310(void)
{
    DAT_00461AF8.sub_00065550((int)DAT_00425F54, (int)DAT_00425F40, (int)sub_001DAB90, 0, 4, 4);
}
