// bin: xb
// va: 0x00318860
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318860 (0x00318860, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043004C[];
extern "C" char DAT_0043005C[];
extern "C" Object DAT_0048B654;
extern "C" char sub_00178490[];

void __cdecl sub_00318860(void)
{
    DAT_0048B654.sub_0006F790((int)DAT_0043005C, (int)DAT_0043004C, (int)sub_00178490, 0, 2, 2);
}
