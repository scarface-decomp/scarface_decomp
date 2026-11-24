// bin: xb
// va: 0x003154C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003154C0 (0x003154C0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A5C20[];
extern "C" Object DAT_004870C8;
extern "C" char sub_000CB970[];

void __cdecl sub_003154C0(void)
{
    DAT_004870C8.sub_000EB3A0(35, 27, 14, 65, 21, (int)DAT_003A5C20, (int)sub_000CB970, 509, 0, 1);
}
