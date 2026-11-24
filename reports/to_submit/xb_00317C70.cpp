// bin: xb
// va: 0x00317C70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317C70 (0x00317C70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F188[];
extern "C" char DAT_0042F190[];
extern "C" Object DAT_0048A818;
extern "C" char sub_0015D460[];

void __cdecl sub_00317C70(void)
{
    DAT_0048A818.sub_0006F830((int)DAT_0042F190, (int)DAT_0042F188, (int)sub_0015D460, 0, 2, 2);
}
