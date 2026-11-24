// bin: xb
// va: 0x00319020
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319020 (0x00319020, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_004315C8[];
extern "C" char DAT_004315DC[];
extern "C" Object DAT_0048BDE4;
extern "C" char sub_0017AA30[];

void __cdecl sub_00319020(void)
{
    DAT_0048BDE4.sub_0006F790((int)DAT_004315DC, (int)DAT_004315C8, (int)sub_0017AA30, 0, 3, 3);
}
