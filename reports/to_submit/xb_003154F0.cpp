// bin: xb
// va: 0x003154F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003154F0 (0x003154F0, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A5E10[];
extern "C" Object DAT_004870D4;
extern "C" char sub_000CD800[];

void __cdecl sub_003154F0(void)
{
    DAT_004870D4.sub_000EB3A0(17, 21, 7, 59, 38, (int)DAT_003A5E10, (int)sub_000CD800, 80, 0, 0);
}
