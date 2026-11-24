// bin: proto
// va: 0x002E5C20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5C20 (Proto 0x002E5C20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A578[];
extern "C" char DAT_0040A588[];
extern "C" Object DAT_0045CA6C;
extern "C" char sub_001429F0[];

void __cdecl sub_002E5C20(void)
{
    DAT_0045CA6C.sub_00065550((int)DAT_0040A588, (int)DAT_0040A578, (int)sub_001429F0, 0, 2, 2);
}
