// bin: proto
// va: 0x002E5D40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5D40 (Proto 0x002E5D40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040A800[];
extern "C" char DAT_0040A80C[];
extern "C" Object DAT_0045CB6C;
extern "C" char sub_001449B0[];

void __cdecl sub_002E5D40(void)
{
    DAT_0045CB6C.sub_000655A0((int)DAT_0040A80C, (int)DAT_0040A800, (int)sub_001449B0, 0, 2, 2);
}
