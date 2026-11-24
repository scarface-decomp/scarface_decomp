// bin: xb
// va: 0x0031A900
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A900 (0x0031A900, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043787C[];
extern "C" Object DAT_0048E190;
extern "C" char sub_001BF180[];

void __cdecl sub_0031A900(void)
{
    DAT_0048E190.sub_0006F880(0, (int)DAT_0043787C, (int)sub_001BF180, 0, 1, 1);
}
