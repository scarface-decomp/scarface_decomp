// bin: xb
// va: 0x00318C00
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318C00 (0x00318C00, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_00430458[];
extern "C" char DAT_00430464[];
extern "C" Object DAT_0048BB50;
extern "C" char sub_00179070[];

void __cdecl sub_00318C00(void)
{
    DAT_0048BB50.sub_0006F790((int)DAT_00430464, (int)DAT_00430458, (int)sub_00179070, 0, 5, 7);
}
