// bin: xb
// va: 0x003144F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003144F0 (0x003144F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00422370[];
extern "C" Object DAT_00480ECC;
extern "C" char sub_00077540[];

void __cdecl sub_003144F0(void)
{
    DAT_00480ECC.sub_0006F880(0, (int)DAT_00422370, (int)sub_00077540, 0, 6, 8);
}
