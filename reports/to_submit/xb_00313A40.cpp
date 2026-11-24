// bin: xb
// va: 0x00313A40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313A40 (0x00313A40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0041E970[];
extern "C" Object DAT_00476C44;
extern "C" char sub_0006F990[];

void __cdecl sub_00313A40(void)
{
    DAT_00476C44.sub_0006F880(0, (int)DAT_0041E970, (int)sub_0006F990, 0, 3, 5);
}
