// bin: xb
// va: 0x003136F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003136F0 (0x003136F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041DDA8[];
extern "C" Object DAT_00475CE4;
extern "C" char sub_00060840[];

void __cdecl sub_003136F0(void)
{
    DAT_00475CE4.sub_0006F830(0, (int)DAT_0041DDA8, (int)sub_00060840, 0, 2, 2);
}
