// bin: proto
// va: 0x002E92A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E92A0 (Proto 0x002E92A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00414E28[];
extern "C" char DAT_00414E34[];
extern "C" Object DAT_00460744;
extern "C" char sub_0019F610[];

void __cdecl sub_002E92A0(void)
{
    DAT_00460744.sub_000654B0((int)DAT_00414E34, (int)DAT_00414E28, (int)sub_0019F610, 0, 3, 3);
}
