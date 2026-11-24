// bin: proto
// va: 0x002EB3D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB3D0 (Proto 0x002EB3D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00426018[];
extern "C" char DAT_00426024[];
extern "C" Object DAT_00461C00;
extern "C" char sub_001DAD10[];

void __cdecl sub_002EB3D0(void)
{
    DAT_00461C00.sub_00065550((int)DAT_00426024, (int)DAT_00426018, (int)sub_001DAD10, 0, 2, 2);
}
