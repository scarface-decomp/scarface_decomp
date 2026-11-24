// bin: xb
// va: 0x00317C30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317C30 (0x00317C30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F154[];
extern "C" char DAT_0042F160[];
extern "C" Object DAT_0048A7C0;
extern "C" char sub_0015D400[];

void __cdecl sub_00317C30(void)
{
    DAT_0048A7C0.sub_0006F830((int)DAT_0042F160, (int)DAT_0042F154, (int)sub_0015D400, 0, 4, 4);
}
