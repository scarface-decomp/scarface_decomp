// bin: proto
// va: 0x002E6B90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6B90 (Proto 0x002E6B90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040C894[];
extern "C" char DAT_0040C8A4[];
extern "C" Object DAT_0045DCE4;
extern "C" char sub_0015A690[];

void __cdecl sub_002E6B90(void)
{
    DAT_0045DCE4.sub_000655A0((int)DAT_0040C8A4, (int)DAT_0040C894, (int)sub_0015A690, 0, 2, 2);
}
