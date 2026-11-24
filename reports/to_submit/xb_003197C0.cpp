// bin: xb
// va: 0x003197C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003197C0 (0x003197C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00435E6C[];
extern "C" char DAT_00435E74[];
extern "C" Object DAT_0048D110;
extern "C" char sub_001BC790[];

void __cdecl sub_003197C0(void)
{
    DAT_0048D110.sub_0006F830((int)DAT_00435E74, (int)DAT_00435E6C, (int)sub_001BC790, 0, 3, 3);
}
