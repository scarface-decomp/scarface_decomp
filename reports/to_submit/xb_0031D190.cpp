// bin: xb
// va: 0x0031D190
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031D190 (0x0031D190, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043FD14[];
extern "C" char DAT_0043FD24[];
extern "C" Object DAT_004902D4;
extern "C" char sub_001FD300[];

void __cdecl sub_0031D190(void)
{
    DAT_004902D4.sub_0006F830((int)DAT_0043FD24, (int)DAT_0043FD14, (int)sub_001FD300, 0, 3, 3);
}
