// bin: xb
// va: 0x00318A20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318A20 (0x00318A20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043022C[];
extern "C" char DAT_00430244[];
extern "C" Object DAT_0048B8BC;
extern "C" char sub_00179050[];

void __cdecl sub_00318A20(void)
{
    DAT_0048B8BC.sub_0006F790((int)DAT_00430244, (int)DAT_0043022C, (int)sub_00179050, 0, 2, 2);
}
