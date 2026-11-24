// bin: proto
// va: 0x002E8950
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8950 (Proto 0x002E8950, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0039FCBC[];
extern "C" Object DAT_0046018C;
extern "C" char sub_001977D0[];

void __cdecl sub_002E8950(void)
{
    DAT_0046018C.sub_000D8CC0(51, 37, 21, 82, 0, (int)DAT_0039FCBC, (int)sub_001977D0, 64, 0, 1);
}
