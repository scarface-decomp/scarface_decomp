// bin: proto
// va: 0x002ECF50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECF50 (Proto 0x002ECF50, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AC38C[];
extern "C" Object DAT_004635C4;
extern "C" char sub_001EFD60[];

void __cdecl sub_002ECF50(void)
{
    DAT_004635C4.sub_000D8CC0(44, 39, 15, 68, 6, (int)DAT_003AC38C, (int)sub_001EFD60, 1, 0, 1);
}
