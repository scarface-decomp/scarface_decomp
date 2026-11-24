// bin: xb
// va: 0x00318F80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318F80 (0x00318F80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004313CC[];
extern "C" char DAT_004313DC[];
extern "C" Object DAT_0048BD34;
extern "C" char sub_0017A720[];

void __cdecl sub_00318F80(void)
{
    DAT_0048BD34.sub_0006F790((int)DAT_004313DC, (int)DAT_004313CC, (int)sub_0017A720, 0, 3, 3);
}
