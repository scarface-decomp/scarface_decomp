// bin: proto
// va: 0x002E9E00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9E00 (Proto 0x002E9E00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_004180AC[];
extern "C" char DAT_004180C8[];
extern "C" Object DAT_00460FDC;
extern "C" char sub_001B4A40[];

void __cdecl sub_002E9E00(void)
{
    DAT_00460FDC.sub_000654B0((int)DAT_004180C8, (int)DAT_004180AC, (int)sub_001B4A40, 0, 2, 2);
}
