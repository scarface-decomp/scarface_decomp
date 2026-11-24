// bin: xb
// va: 0x003125A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003125A0 (0x003125A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041A9D8[];
extern "C" Object DAT_00471878;
extern "C" char sub_00024B30[];

void __cdecl sub_003125A0(void)
{
    DAT_00471878.sub_0006F880(0, (int)DAT_0041A9D8, (int)sub_00024B30, 0, 1, 1);
}
