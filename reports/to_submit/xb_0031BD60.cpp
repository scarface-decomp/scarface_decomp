// bin: xb
// va: 0x0031BD60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BD60 (0x0031BD60, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043AC94[];
extern "C" Object DAT_0048F02C;
extern "C" char sub_001D3500[];

void __cdecl sub_0031BD60(void)
{
    DAT_0048F02C.sub_0006F880(0, (int)DAT_0043AC94, (int)sub_001D3500, 0, 4, 4);
}
