// bin: proto
// va: 0x002EB490
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB490 (Proto 0x002EB490, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004260D4[];
extern "C" char DAT_004260E4[];
extern "C" Object DAT_00461D08;
extern "C" char sub_001DAD90[];

void __cdecl sub_002EB490(void)
{
    DAT_00461D08.sub_00065550((int)DAT_004260E4, (int)DAT_004260D4, (int)sub_001DAD90, 0, 3, 3);
}
