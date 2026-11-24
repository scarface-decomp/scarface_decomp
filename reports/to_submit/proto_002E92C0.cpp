// bin: proto
// va: 0x002E92C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E92C0 (Proto 0x002E92C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00414E48[];
extern "C" char DAT_00414E58[];
extern "C" Object DAT_00460770;
extern "C" char sub_0019F640[];

void __cdecl sub_002E92C0(void)
{
    DAT_00460770.sub_000654B0((int)DAT_00414E58, (int)DAT_00414E48, (int)sub_0019F640, 0, 3, 3);
}
