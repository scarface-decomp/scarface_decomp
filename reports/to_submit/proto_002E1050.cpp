// bin: proto
// va: 0x002E1050
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1050 (Proto 0x002E1050, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F72A0[];
extern "C" Object DAT_00449DA8;
extern "C" char sub_0021AF70[];

void __cdecl sub_002E1050(void)
{
    DAT_00449DA8.sub_000654B0(0, (int)DAT_003F72A0, (int)sub_0021AF70, 0, 2, 2);
}
