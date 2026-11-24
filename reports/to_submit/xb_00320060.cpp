// bin: xb
// va: 0x00320060
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320060 (0x00320060, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0044E54C[];
extern "C" Object DAT_00492578;
extern "C" char sub_00230980[];

void __cdecl sub_00320060(void)
{
    DAT_00492578.sub_0006F790(0, (int)DAT_0044E54C, (int)sub_00230980, 0, 2, 2);
}
