// bin: proto
// va: 0x002E4B90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4B90 (Proto 0x002E4B90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00403360[];
extern "C" char DAT_00403370[];
extern "C" Object DAT_0045BE44;
extern "C" char sub_000FE730[];

void __cdecl sub_002E4B90(void)
{
    DAT_0045BE44.sub_00065550((int)DAT_00403370, (int)DAT_00403360, (int)sub_000FE730, 0, 4, 4);
}
