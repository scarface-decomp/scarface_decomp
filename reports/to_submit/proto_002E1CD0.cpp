// bin: proto
// va: 0x002E1CD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1CD0 (Proto 0x002E1CD0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F9BBC[];
extern "C" Object DAT_0044F638;
extern "C" char sub_00066B00[];

void __cdecl sub_002E1CD0(void)
{
    DAT_0044F638.sub_000654B0(0, (int)DAT_003F9BBC, (int)sub_00066B00, 0, 1, 1);
}
