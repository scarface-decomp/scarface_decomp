// bin: xb
// va: 0x003129F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003129F0 (0x003129F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041B794[];
extern "C" char DAT_0041B7A0[];
extern "C" Object DAT_004742A8;
extern "C" char sub_0002D580[];

void __cdecl sub_003129F0(void)
{
    DAT_004742A8.sub_0006F830((int)DAT_0041B7A0, (int)DAT_0041B794, (int)sub_0002D580, 0, 3, 3);
}
