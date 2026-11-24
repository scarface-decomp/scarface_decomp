// bin: proto
// va: 0x002E5D60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5D60 (Proto 0x002E5D60, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040A824[];
extern "C" Object DAT_0045CB98;
extern "C" char sub_00144A40[];

void __cdecl sub_002E5D60(void)
{
    DAT_0045CB98.sub_000655A0(0, (int)DAT_0040A824, (int)sub_00144A40, 0, 1, 1);
}
