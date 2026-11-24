// bin: proto
// va: 0x002E7A30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7A30 (Proto 0x002E7A30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00410CD8[];
extern "C" Object DAT_0045F4A8;
extern "C" char sub_0018AF80[];

void __cdecl sub_002E7A30(void)
{
    DAT_0045F4A8.sub_000654B0(0, (int)DAT_00410CD8, (int)sub_0018AF80, 0, 3, 3);
}
