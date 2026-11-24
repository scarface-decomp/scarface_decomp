// bin: proto
// va: 0x002ECBD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECBD0 (Proto 0x002ECBD0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004278F0[];
extern "C" Object DAT_0046310C;
extern "C" char sub_001EEA50[];

void __cdecl sub_002ECBD0(void)
{
    DAT_0046310C.sub_00065550(0, (int)DAT_004278F0, (int)sub_001EEA50, 0, 2, 2);
}
