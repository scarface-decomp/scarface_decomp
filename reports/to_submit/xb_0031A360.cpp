// bin: xb
// va: 0x0031A360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A360 (0x0031A360, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004370F8[];
extern "C" Object DAT_0048DB8C;
extern "C" char sub_001BE5F0[];

void __cdecl sub_0031A360(void)
{
    DAT_0048DB8C.sub_0006F880(0, (int)DAT_004370F8, (int)sub_001BE5F0, 0, 1, 1);
}
