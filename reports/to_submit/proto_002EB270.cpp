// bin: proto
// va: 0x002EB270
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB270 (Proto 0x002EB270, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425EAC[];
extern "C" char DAT_00425EBC[];
extern "C" Object DAT_00461A1C;
extern "C" char sub_001DAA30[];

void __cdecl sub_002EB270(void)
{
    DAT_00461A1C.sub_00065550((int)DAT_00425EBC, (int)DAT_00425EAC, (int)sub_001DAA30, 0, 3, 3);
}
