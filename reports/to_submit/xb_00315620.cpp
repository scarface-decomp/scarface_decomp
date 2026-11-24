// bin: xb
// va: 0x00315620
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315620 (0x00315620, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424CE4[];
extern "C" Object DAT_004871AC;
extern "C" char sub_000CED80[];

void __cdecl sub_00315620(void)
{
    DAT_004871AC.sub_0006F830(0, (int)DAT_00424CE4, (int)sub_000CED80, 0, 2, 2);
}
