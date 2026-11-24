// bin: xb
// va: 0x0031B0C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B0C0 (0x0031B0C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00438934[];
extern "C" Object DAT_0048E7B4;
extern "C" char sub_001C8480[];

void __cdecl sub_0031B0C0(void)
{
    DAT_0048E7B4.sub_0006F830(0, (int)DAT_00438934, (int)sub_001C8480, 0, 3, 3);
}
