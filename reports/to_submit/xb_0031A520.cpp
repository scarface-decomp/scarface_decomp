// bin: xb
// va: 0x0031A520
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A520 (0x0031A520, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004374A8[];
extern "C" char DAT_004374BC[];
extern "C" Object DAT_0048DCC0;
extern "C" char sub_001BEB80[];

void __cdecl sub_0031A520(void)
{
    DAT_0048DCC0.sub_0006F830((int)DAT_004374BC, (int)DAT_004374A8, (int)sub_001BEB80, 0, 3, 3);
}
