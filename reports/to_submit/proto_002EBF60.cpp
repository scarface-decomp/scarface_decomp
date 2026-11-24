// bin: proto
// va: 0x002EBF60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EBF60 (Proto 0x002EBF60, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003AAFCC[];
extern "C" Object DAT_004626E8;
extern "C" char sub_001E5280[];

void __cdecl sub_002EBF60(void)
{
    DAT_004626E8.sub_000D8CC0(47, 34, 26, 79, 3, (int)DAT_003AAFCC, (int)sub_001E5280, 80, 0, 0);
}
