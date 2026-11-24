// bin: xb
// va: 0x0031FA80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FA80 (0x0031FA80, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D2094[];
extern "C" Object DAT_00491F9E;
extern "C" char sub_0022B450[];

void __cdecl sub_0031FA80(void)
{
    DAT_00491F9E.sub_000EB3A0(6, 5, 51, 88, 7, (int)DAT_003D2094, (int)sub_0022B450, 8, 0, 1);
}
