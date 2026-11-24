// bin: xb
// va: 0x003199E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003199E0 (0x003199E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436108[];
extern "C" char DAT_00436110[];
extern "C" Object DAT_0048D2F4;
extern "C" char sub_001BCAB0[];

void __cdecl sub_003199E0(void)
{
    DAT_0048D2F4.sub_0006F830((int)DAT_00436110, (int)DAT_00436108, (int)sub_001BCAB0, 0, 3, 3);
}
