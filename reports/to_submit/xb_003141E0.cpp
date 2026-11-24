// bin: xb
// va: 0x003141E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003141E0 (0x003141E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0041F0D8[];
extern "C" Object DAT_0047D770;
extern "C" char sub_00072760[];

void __cdecl sub_003141E0(void)
{
    DAT_0047D770.sub_0006F830(0, (int)DAT_0041F0D8, (int)sub_00072760, 0, 1, 1);
}
