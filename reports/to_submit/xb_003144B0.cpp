// bin: xb
// va: 0x003144B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003144B0 (0x003144B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00422344[];
extern "C" Object DAT_00480E74;
extern "C" char sub_00077290[];

void __cdecl sub_003144B0(void)
{
    DAT_00480E74.sub_0006F830(0, (int)DAT_00422344, (int)sub_00077290, 0, 2, 2);
}
