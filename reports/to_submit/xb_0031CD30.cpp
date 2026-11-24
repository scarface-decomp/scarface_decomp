// bin: xb
// va: 0x0031CD30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CD30 (0x0031CD30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043EA20[];
extern "C" char DAT_0043EA30[];
extern "C" Object DAT_0048FD44;
extern "C" char sub_001EEB40[];

void __cdecl sub_0031CD30(void)
{
    DAT_0048FD44.sub_0006F790((int)DAT_0043EA30, (int)DAT_0043EA20, (int)sub_001EEB40, 0, 2, 2);
}
