// bin: xb
// va: 0x0031B120
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B120 (0x0031B120, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00438974[];
extern "C" Object DAT_0048E838;
extern "C" char sub_001C84F0[];

void __cdecl sub_0031B120(void)
{
    DAT_0048E838.sub_0006F790(0, (int)DAT_00438974, (int)sub_001C84F0, 0, 3, 3);
}
