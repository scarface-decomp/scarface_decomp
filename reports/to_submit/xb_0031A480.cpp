// bin: xb
// va: 0x0031A480
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A480 (0x0031A480, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004373CC[];
extern "C" char DAT_004373D4[];
extern "C" Object DAT_0048DC10;
extern "C" char sub_001BEA60[];

void __cdecl sub_0031A480(void)
{
    DAT_0048DC10.sub_0006F830((int)DAT_004373D4, (int)DAT_004373CC, (int)sub_001BEA60, 0, 3, 3);
}
