// bin: proto
// va: 0x002E6770
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6770 (Proto 0x002E6770, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B7AC[];
extern "C" char DAT_0040B7BC[];
extern "C" Object DAT_0045D8DC;
extern "C" char sub_00158550[];

void __cdecl sub_002E6770(void)
{
    DAT_0045D8DC.sub_000654B0((int)DAT_0040B7BC, (int)DAT_0040B7AC, (int)sub_00158550, 0, 3, 4);
}
