// bin: xb
// va: 0x003184A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003184A0 (0x003184A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042FC0C[];
extern "C" char DAT_0042FC20[];
extern "C" Object DAT_0048B12C;
extern "C" char sub_00178180[];

void __cdecl sub_003184A0(void)
{
    DAT_0048B12C.sub_0006F790((int)DAT_0042FC20, (int)DAT_0042FC0C, (int)sub_00178180, 0, 2, 2);
}
