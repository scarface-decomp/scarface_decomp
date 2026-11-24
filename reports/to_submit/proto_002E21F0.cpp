// bin: proto
// va: 0x002E21F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E21F0 (Proto 0x002E21F0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F9D88[];
extern "C" Object DAT_0044FD44;
extern "C" char sub_00066A10[];

void __cdecl sub_002E21F0(void)
{
    DAT_0044FD44.sub_00065460(0, (int)DAT_003F9D88, (int)sub_00066A10, 0, 4, 4);
}
