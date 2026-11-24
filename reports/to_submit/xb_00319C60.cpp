// bin: xb
// va: 0x00319C60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319C60 (0x00319C60, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00436648[];
extern "C" char DAT_00436658[];
extern "C" Object DAT_0048D4D8;
extern "C" char sub_001BD110[];

void __cdecl sub_00319C60(void)
{
    DAT_0048D4D8.sub_0006F880((int)DAT_00436658, (int)DAT_00436648, (int)sub_001BD110, 0, 3, 4);
}
