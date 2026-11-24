// bin: proto
// va: 0x002ECFB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECFB0 (Proto 0x002ECFB0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AC45C[];
extern "C" Object DAT_004635E4;
extern "C" char sub_001F0B50[];

void __cdecl sub_002ECFB0(void)
{
    DAT_004635E4.sub_000D8CC0(6, 46, 13, 92, 9, (int)DAT_003AC45C, (int)sub_001F0B50, 509, 3, 0);
}
