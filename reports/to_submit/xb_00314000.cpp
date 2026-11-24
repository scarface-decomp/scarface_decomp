// bin: xb
// va: 0x00314000
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314000 (0x00314000, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0041F038[];
extern "C" Object DAT_0047B0AC;
extern "C" char sub_000719A0[];

void __cdecl sub_00314000(void)
{
    DAT_0047B0AC.sub_0006F740(0, (int)DAT_0041F038, (int)sub_000719A0, 0, 2, 2);
}
