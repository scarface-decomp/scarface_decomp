// bin: proto
// va: 0x002EC9E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC9E0 (Proto 0x002EC9E0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AC0F0[];
extern "C" Object DAT_00462F9C;
extern "C" char sub_001EED80[];

void __cdecl sub_002EC9E0(void)
{
    DAT_00462F9C.sub_000D8CC0(49, 35, 8, 80, 2, (int)DAT_003AC0F0, (int)sub_001EED80, 509, 0, 1);
}
