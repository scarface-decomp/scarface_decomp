// bin: xb
// va: 0x003164A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003164A0 (0x003164A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042776C[];
extern "C" Object DAT_00488FE0;
extern "C" char sub_000EB650[];

void __cdecl sub_003164A0(void)
{
    DAT_00488FE0.sub_0006F830(0, (int)DAT_0042776C, (int)sub_000EB650, 0, 2, 2);
}
