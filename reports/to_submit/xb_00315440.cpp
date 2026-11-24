// bin: xb
// va: 0x00315440
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315440 (0x00315440, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424918[];
extern "C" Object DAT_00486FFC;
extern "C" char sub_000CA720[];

void __cdecl sub_00315440(void)
{
    DAT_00486FFC.sub_0006F830(0, (int)DAT_00424918, (int)sub_000CA720, 0, 4, 5);
}
