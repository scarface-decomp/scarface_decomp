// bin: xb
// va: 0x0031A5C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A5C0 (0x0031A5C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004375A8[];
extern "C" char DAT_004375B8[];
extern "C" Object DAT_0048DD70;
extern "C" char sub_001BECD0[];

void __cdecl sub_0031A5C0(void)
{
    DAT_0048DD70.sub_0006F880((int)DAT_004375B8, (int)DAT_004375A8, (int)sub_001BECD0, 0, 3, 3);
}
