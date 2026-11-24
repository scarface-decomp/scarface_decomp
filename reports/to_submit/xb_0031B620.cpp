// bin: xb
// va: 0x0031B620
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B620 (0x0031B620, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003C59BC[];
extern "C" Object DAT_0048EBFC;
extern "C" char sub_001CEF10[];

void __cdecl sub_0031B620(void)
{
    DAT_0048EBFC.sub_000EB3A0(53, 39, 24, 86, 0, (int)DAT_003C59BC, (int)sub_001CEF10, 64, 0, 1);
}
