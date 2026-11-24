// bin: xb
// va: 0x003189C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003189C0 (0x003189C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004301C0[];
extern "C" char DAT_004301D4[];
extern "C" Object DAT_0048B838;
extern "C" char sub_001785F0[];

void __cdecl sub_003189C0(void)
{
    DAT_0048B838.sub_0006F880((int)DAT_004301D4, (int)DAT_004301C0, (int)sub_001785F0, 0, 3, 3);
}
