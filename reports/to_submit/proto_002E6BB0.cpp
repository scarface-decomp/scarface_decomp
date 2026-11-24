// bin: proto
// va: 0x002E6BB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6BB0 (Proto 0x002E6BB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040C8B0[];
extern "C" char DAT_0040C8C0[];
extern "C" Object DAT_0045DD10;
extern "C" char sub_0015A6A0[];

void __cdecl sub_002E6BB0(void)
{
    DAT_0045DD10.sub_000655A0((int)DAT_0040C8C0, (int)DAT_0040C8B0, (int)sub_0015A6A0, 0, 2, 2);
}
