// bin: xb
// va: 0x00317C10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317C10 (0x00317C10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F138[];
extern "C" char DAT_0042F148[];
extern "C" Object DAT_0048A794;
extern "C" char sub_0015D3F0[];

void __cdecl sub_00317C10(void)
{
    DAT_0048A794.sub_0006F830((int)DAT_0042F148, (int)DAT_0042F138, (int)sub_0015D3F0, 0, 2, 2);
}
