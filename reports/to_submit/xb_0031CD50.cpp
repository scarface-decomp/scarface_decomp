// bin: xb
// va: 0x0031CD50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CD50 (0x0031CD50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043EA48[];
extern "C" Object DAT_0048FD70;
extern "C" char sub_001EEB60[];

void __cdecl sub_0031CD50(void)
{
    DAT_0048FD70.sub_0006F790(0, (int)DAT_0043EA48, (int)sub_001EEB60, 0, 2, 3);
}
