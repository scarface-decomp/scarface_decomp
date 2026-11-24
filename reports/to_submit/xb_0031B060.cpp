// bin: xb
// va: 0x0031B060
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B060 (0x0031B060, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004388EC[];
extern "C" Object DAT_0048E730;
extern "C" char sub_001C8400[];

void __cdecl sub_0031B060(void)
{
    DAT_0048E730.sub_0006F830(0, (int)DAT_004388EC, (int)sub_001C8400, 0, 2, 2);
}
