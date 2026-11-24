// bin: proto
// va: 0x002E5FB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5FB0 (Proto 0x002E5FB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040AD60[];
extern "C" char DAT_0040AD78[];
extern "C" Object DAT_0045CF34;
extern "C" char sub_00157BE0[];

void __cdecl sub_002E5FB0(void)
{
    DAT_0045CF34.sub_000654B0((int)DAT_0040AD78, (int)DAT_0040AD60, (int)sub_00157BE0, 0, 2, 2);
}
