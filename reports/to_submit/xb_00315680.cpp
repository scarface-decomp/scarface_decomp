// bin: xb
// va: 0x00315680
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315680 (0x00315680, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424D28[];
extern "C" Object DAT_00487230;
extern "C" char sub_000CEDF0[];

void __cdecl sub_00315680(void)
{
    DAT_00487230.sub_0006F830(0, (int)DAT_00424D28, (int)sub_000CEDF0, 0, 2, 2);
}
