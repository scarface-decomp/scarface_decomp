// bin: xb
// va: 0x00313BC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313BC0 (0x00313BC0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041EEA0[];
extern "C" Object DAT_0047AAD4;
extern "C" char sub_00070B30[];

void __cdecl sub_00313BC0(void)
{
    DAT_0047AAD4.sub_0006F880(0, (int)DAT_0041EEA0, (int)sub_00070B30, 0, 2, 2);
}
