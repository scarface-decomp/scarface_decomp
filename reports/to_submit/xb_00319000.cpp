// bin: xb
// va: 0x00319000
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319000 (0x00319000, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_004315A4[];
extern "C" char DAT_004315B8[];
extern "C" Object DAT_0048BDB8;
extern "C" char sub_0017A9B0[];

void __cdecl sub_00319000(void)
{
    DAT_0048BDB8.sub_0006F740((int)DAT_004315B8, (int)DAT_004315A4, (int)sub_0017A9B0, 0, 3, 4);
}
