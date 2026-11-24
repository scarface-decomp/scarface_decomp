// bin: xb
// va: 0x00315660
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315660 (0x00315660, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_00424D10[];
extern "C" Object DAT_00487204;
extern "C" char sub_000CEDE0[];

void __cdecl sub_00315660(void)
{
    DAT_00487204.sub_0006F740(0, (int)DAT_00424D10, (int)sub_000CEDE0, 0, 1, 1);
}
