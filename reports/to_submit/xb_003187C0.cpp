// bin: xb
// va: 0x003187C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003187C0 (0x003187C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042FFAC[];
extern "C" char DAT_0042FFB8[];
extern "C" Object DAT_0048B578;
extern "C" char sub_001783D0[];

void __cdecl sub_003187C0(void)
{
    DAT_0048B578.sub_0006F790((int)DAT_0042FFB8, (int)DAT_0042FFAC, (int)sub_001783D0, 0, 2, 2);
}
