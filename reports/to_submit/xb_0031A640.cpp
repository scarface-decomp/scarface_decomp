// bin: xb
// va: 0x0031A640
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A640 (0x0031A640, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437630[];
extern "C" char DAT_00437648[];
extern "C" Object DAT_0048DE20;
extern "C" char sub_001BED40[];

void __cdecl sub_0031A640(void)
{
    DAT_0048DE20.sub_0006F830((int)DAT_00437648, (int)DAT_00437630, (int)sub_001BED40, 0, 5, 5);
}
