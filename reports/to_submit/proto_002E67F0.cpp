// bin: proto
// va: 0x002E67F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E67F0 (Proto 0x002E67F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B824[];
extern "C" char DAT_0040B830[];
extern "C" Object DAT_0045D98C;
extern "C" char sub_001585F0[];

void __cdecl sub_002E67F0(void)
{
    DAT_0045D98C.sub_00065550((int)DAT_0040B830, (int)DAT_0040B824, (int)sub_001585F0, 0, 3, 4);
}
