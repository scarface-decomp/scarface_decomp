// bin: xb
// va: 0x00319840
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319840 (0x00319840, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00435F30[];
extern "C" char DAT_00435F40[];
extern "C" Object DAT_0048D194;
extern "C" char sub_001BC820[];

void __cdecl sub_00319840(void)
{
    DAT_0048D194.sub_0006F830((int)DAT_00435F40, (int)DAT_00435F30, (int)sub_001BC820, 0, 3, 4);
}
