// bin: xb
// va: 0x00317360
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317360 (0x00317360, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042B154[];
extern "C" Object DAT_00489C50;
extern "C" char sub_0011CF70[];

void __cdecl sub_00317360(void)
{
    DAT_00489C50.sub_0006F790(0, (int)DAT_0042B154, (int)sub_0011CF70, 0, 2, 2);
}
