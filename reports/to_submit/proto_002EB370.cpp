// bin: proto
// va: 0x002EB370
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB370 (Proto 0x002EB370, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425FAC[];
extern "C" char DAT_00425FB8[];
extern "C" Object DAT_00461B7C;
extern "C" char sub_001DAC80[];

void __cdecl sub_002EB370(void)
{
    DAT_00461B7C.sub_00065550((int)DAT_00425FB8, (int)DAT_00425FAC, (int)sub_001DAC80, 0, 3, 3);
}
