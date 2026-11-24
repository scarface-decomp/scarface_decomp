// bin: xb
// va: 0x0031E3A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E3A0 (0x0031E3A0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0044C710[];
extern "C" char DAT_0044C720[];
extern "C" Object DAT_00490A50;
extern "C" char sub_00216060[];

void __cdecl sub_0031E3A0(void)
{
    DAT_00490A50.sub_0006F790((int)DAT_0044C720, (int)DAT_0044C710, (int)sub_00216060, 0, 2, 2);
}
