// bin: proto
// va: 0x002E4BB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4BB0 (Proto 0x002E4BB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00403380[];
extern "C" char DAT_0040339C[];
extern "C" Object DAT_0045BE70;
extern "C" char sub_000FE760[];

void __cdecl sub_002E4BB0(void)
{
    DAT_0045BE70.sub_00065550((int)DAT_0040339C, (int)DAT_00403380, (int)sub_000FE760, 0, 5, 5);
}
