// bin: xb
// va: 0x003135F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003135F0 (0x003135F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041DD04[];
extern "C" Object DAT_00475B84;
extern "C" char sub_00060740[];

void __cdecl sub_003135F0(void)
{
    DAT_00475B84.sub_0006F830(0, (int)DAT_0041DD04, (int)sub_00060740, 0, 3, 3);
}
