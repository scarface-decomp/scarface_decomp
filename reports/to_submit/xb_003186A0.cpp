// bin: xb
// va: 0x003186A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003186A0 (0x003186A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0042FE5C[];
extern "C" char DAT_0042FE6C[];
extern "C" Object DAT_0048B3EC;
extern "C" char sub_00178CF0[];

void __cdecl sub_003186A0(void)
{
    DAT_0048B3EC.sub_0006F880((int)DAT_0042FE6C, (int)DAT_0042FE5C, (int)sub_00178CF0, 0, 6, 6);
}
