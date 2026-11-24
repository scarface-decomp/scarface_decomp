// bin: xb
// va: 0x00318300
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318300 (0x00318300, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FA44[];
extern "C" char DAT_0042FA58[];
extern "C" Object DAT_0048AEF0;
extern "C" char sub_00178000[];

void __cdecl sub_00318300(void)
{
    DAT_0048AEF0.sub_0006F830((int)DAT_0042FA58, (int)DAT_0042FA44, (int)sub_00178000, 0, 2, 2);
}
