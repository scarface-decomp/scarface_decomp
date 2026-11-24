// bin: proto
// va: 0x002E3100
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3100 (Proto 0x002E3100, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_00383D6C[];
extern "C" Object DAT_004541CC;
extern "C" char sub_0008C060[];

void __cdecl sub_002E3100(void)
{
    DAT_004541CC.sub_000D8CC0(20, 23, 29, 58, 32, (int)DAT_00383D6C, (int)sub_0008C060, 80, 0, 0);
}
