// bin: proto
// va: 0x002E83D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E83D0 (Proto 0x002E83D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_00411B88[];
extern "C" char DAT_00411B9C[];
extern "C" Object DAT_0045FE74;
extern "C" char sub_0018C240[];

void __cdecl sub_002E83D0(void)
{
    DAT_0045FE74.sub_00065460((int)DAT_00411B9C, (int)DAT_00411B88, (int)sub_0018C240, 0, 3, 3);
}
