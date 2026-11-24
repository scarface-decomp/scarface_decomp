// bin: proto
// va: 0x002E4880
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4880 (Proto 0x002E4880, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_004024E8[];
extern "C" Object DAT_0045B8A0;
extern "C" char sub_000DB800[];

void __cdecl sub_002E4880(void)
{
    DAT_0045B8A0.sub_000654B0(0, (int)DAT_004024E8, (int)sub_000DB800, 0, 1, 1);
}
