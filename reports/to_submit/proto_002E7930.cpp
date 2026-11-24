// bin: proto
// va: 0x002E7930
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7930 (Proto 0x002E7930, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410BA8[];
extern "C" Object DAT_0045F374;
extern "C" char sub_0018ADF0[];

void __cdecl sub_002E7930(void)
{
    DAT_0045F374.sub_00065550(0, (int)DAT_00410BA8, (int)sub_0018ADF0, 0, 7, 8);
}
