// bin: xb
// va: 0x0031AAC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AAC0 (0x0031AAC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00437C28[];
extern "C" char DAT_00437C30[];
extern "C" Object DAT_0048E31C;
extern "C" char sub_001BF6F0[];

void __cdecl sub_0031AAC0(void)
{
    DAT_0048E31C.sub_0006F830((int)DAT_00437C30, (int)DAT_00437C28, (int)sub_001BF6F0, 0, 3, 3);
}
