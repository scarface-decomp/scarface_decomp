// bin: xb
// va: 0x00313B40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313B40 (0x00313B40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041E9F0[];
extern "C" Object DAT_00476DA4;
extern "C" char sub_00068D70[];

void __cdecl sub_00313B40(void)
{
    DAT_00476DA4.sub_0006F830(0, (int)DAT_0041E9F0, (int)sub_00068D70, 0, 1, 1);
}
