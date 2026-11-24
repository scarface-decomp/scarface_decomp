// bin: xb
// va: 0x0031B220
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B220 (0x0031B220, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00438A2C[];
extern "C" Object DAT_0048E998;
extern "C" char sub_001C8760[];

void __cdecl sub_0031B220(void)
{
    DAT_0048E998.sub_0006F790(0, (int)DAT_00438A2C, (int)sub_001C8760, 0, 2, 2);
}
