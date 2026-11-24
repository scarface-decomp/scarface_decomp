// bin: proto
// va: 0x002E3170
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3170 (Proto 0x002E3170, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003FE948[];
extern "C" Object DAT_0045424C;
extern "C" char sub_0008D540[];

void __cdecl sub_002E3170(void)
{
    DAT_0045424C.sub_000654B0(0, (int)DAT_003FE948, (int)sub_0008D540, 0, 2, 2);
}
