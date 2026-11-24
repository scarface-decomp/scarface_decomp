// bin: proto
// va: 0x002E1920
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1920 (Proto 0x002E1920, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_00380D64[];
extern "C" Object DAT_0044AE5C;
extern "C" char sub_0005A520[];

void __cdecl sub_002E1920(void)
{
    DAT_0044AE5C.sub_000D8CC0(2, 2, 1, 51, 46, (int)DAT_00380D64, (int)sub_0005A520, 509, 3, 1);
}
