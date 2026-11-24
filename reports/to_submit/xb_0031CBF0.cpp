// bin: xb
// va: 0x0031CBF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CBF0 (0x0031CBF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043E8BC[];
extern "C" char DAT_0043E8D0[];
extern "C" Object DAT_0048FBB8;
extern "C" char sub_001EE9D0[];

void __cdecl sub_0031CBF0(void)
{
    DAT_0048FBB8.sub_0006F790((int)DAT_0043E8D0, (int)DAT_0043E8BC, (int)sub_001EE9D0, 0, 2, 2);
}
