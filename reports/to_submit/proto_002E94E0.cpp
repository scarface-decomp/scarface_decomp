// bin: proto
// va: 0x002E94E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E94E0 (Proto 0x002E94E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00414FFC[];
extern "C" char DAT_00415008[];
extern "C" Object DAT_00460A04;
extern "C" char sub_0019F600[];

void __cdecl sub_002E94E0(void)
{
    DAT_00460A04.sub_000655A0((int)DAT_00415008, (int)DAT_00414FFC, (int)sub_0019F600, 0, 2, 2);
}
