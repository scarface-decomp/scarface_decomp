// bin: proto
// va: 0x002ECF80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECF80 (Proto 0x002ECF80, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AC434[];
extern "C" Object DAT_004635D0;
extern "C" char sub_001F0690[];

void __cdecl sub_002ECF80(void)
{
    DAT_004635D0.sub_000D8CC0(5, 5, 19, 85, 8, (int)DAT_003AC434, (int)sub_001F0690, 509, 3, 0);
}
