// bin: proto
// va: 0x002E1D30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1D30 (Proto 0x002E1D30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F9BE0[];
extern "C" Object DAT_0044F6BC;
extern "C" char sub_00066B80[];

void __cdecl sub_002E1D30(void)
{
    DAT_0044F6BC.sub_000654B0(0, (int)DAT_003F9BE0, (int)sub_00066B80, 0, 4, 4);
}
