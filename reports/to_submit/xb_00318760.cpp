// bin: xb
// va: 0x00318760
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318760 (0x00318760, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042FF34[];
extern "C" char DAT_0042FF50[];
extern "C" Object DAT_0048B4F4;
extern "C" char sub_001783B0[];

void __cdecl sub_00318760(void)
{
    DAT_0048B4F4.sub_0006F830((int)DAT_0042FF50, (int)DAT_0042FF34, (int)sub_001783B0, 0, 3, 3);
}
