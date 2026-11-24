// bin: xb
// va: 0x0031AE40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AE40 (0x0031AE40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00438814[];
extern "C" char DAT_0043881C[];
extern "C" Object DAT_0048E5FC;
extern "C" char sub_001C7190[];

void __cdecl sub_0031AE40(void)
{
    DAT_0048E5FC.sub_0006F830((int)DAT_0043881C, (int)DAT_00438814, (int)sub_001C7190, 0, 2, 2);
}
