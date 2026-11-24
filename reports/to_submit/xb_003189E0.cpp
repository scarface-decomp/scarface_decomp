// bin: xb
// va: 0x003189E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003189E0 (0x003189E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_004301E4[];
extern "C" char DAT_00430200[];
extern "C" Object DAT_0048B864;
extern "C" char sub_00178670[];

void __cdecl sub_003189E0(void)
{
    DAT_0048B864.sub_0006F880((int)DAT_00430200, (int)DAT_004301E4, (int)sub_00178670, 0, 2, 2);
}
