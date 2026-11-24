// bin: proto
// va: 0x002E6890
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6890 (Proto 0x002E6890, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B8C4[];
extern "C" char DAT_0040B8DC[];
extern "C" Object DAT_0045DA68;
extern "C" char sub_001586C0[];

void __cdecl sub_002E6890(void)
{
    DAT_0045DA68.sub_000655A0((int)DAT_0040B8DC, (int)DAT_0040B8C4, (int)sub_001586C0, 0, 2, 2);
}
