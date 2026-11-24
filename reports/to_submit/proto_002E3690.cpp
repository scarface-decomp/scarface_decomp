// bin: proto
// va: 0x002E3690
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3690 (Proto 0x002E3690, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_00384E6C[];
extern "C" Object DAT_0045981C;
extern "C" char sub_000BD240[];

void __cdecl sub_002E3690(void)
{
    DAT_0045981C.sub_000D8CC0(14, 19, 4, 54, 38, (int)DAT_00384E6C, (int)sub_000BD240, 80, 0, 0);
}
