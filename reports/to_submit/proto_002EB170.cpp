// bin: proto
// va: 0x002EB170
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB170 (Proto 0x002EB170, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00425DA8[];
extern "C" char DAT_00425DB0[];
extern "C" Object DAT_004618BC;
extern "C" char sub_001DA860[];

void __cdecl sub_002EB170(void)
{
    DAT_004618BC.sub_00065550((int)DAT_00425DB0, (int)DAT_00425DA8, (int)sub_001DA860, 0, 2, 2);
}
