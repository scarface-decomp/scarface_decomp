// bin: xb
// va: 0x0031B140
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B140 (0x0031B140, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_00438990[];
extern "C" Object DAT_0048E864;
extern "C" char sub_001C8520[];

void __cdecl sub_0031B140(void)
{
    DAT_0048E864.sub_0006F880(0, (int)DAT_00438990, (int)sub_001C8520, 0, 2, 2);
}
