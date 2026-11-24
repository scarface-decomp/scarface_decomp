// bin: xb
// va: 0x0031A320
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A320 (0x0031A320, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004370C0[];
extern "C" Object DAT_0048DB34;
extern "C" char sub_001BE5A0[];

void __cdecl sub_0031A320(void)
{
    DAT_0048DB34.sub_0006F830(0, (int)DAT_004370C0, (int)sub_001BE5A0, 0, 2, 2);
}
