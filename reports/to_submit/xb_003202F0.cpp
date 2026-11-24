// bin: xb
// va: 0x003202F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003202F0 (0x003202F0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003D32E0[];
extern "C" Object DAT_004928F4;
extern "C" char sub_00231EF0[];

void __cdecl sub_003202F0(void)
{
    DAT_004928F4.sub_000EB3A0(0, 0, 0, 50, 57, (int)DAT_003D32E0, (int)sub_00231EF0, 509, 3, 1);
}
