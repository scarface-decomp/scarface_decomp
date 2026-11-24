// bin: xb
// va: 0x00312A50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312A50 (0x00312A50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041B898[];
extern "C" char DAT_0041B8A8[];
extern "C" Object DAT_004742D4;
extern "C" char sub_0002D780[];

void __cdecl sub_00312A50(void)
{
    DAT_004742D4.sub_0006F830((int)DAT_0041B8A8, (int)DAT_0041B898, (int)sub_0002D780, 0, 3, 3);
}
