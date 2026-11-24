// bin: proto
// va: 0x002E69F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E69F0 (Proto 0x002E69F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040BA54[];
extern "C" char DAT_0040BA68[];
extern "C" Object DAT_0045DC4C;
extern "C" char sub_00158820[];

void __cdecl sub_002E69F0(void)
{
    DAT_0045DC4C.sub_00065550((int)DAT_0040BA68, (int)DAT_0040BA54, (int)sub_00158820, 0, 3, 3);
}
