// bin: xb
// va: 0x003163E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003163E0 (0x003163E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0042770C[];
extern "C" Object DAT_00488ED8;
extern "C" char sub_000EB5C0[];

void __cdecl sub_003163E0(void)
{
    DAT_00488ED8.sub_0006F790(0, (int)DAT_0042770C, (int)sub_000EB5C0, 0, 1, 1);
}
