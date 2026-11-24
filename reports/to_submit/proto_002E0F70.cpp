// bin: proto
// va: 0x002E0F70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0F70 (Proto 0x002E0F70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F71F8[];
extern "C" Object DAT_00449C74;
extern "C" char sub_00069330[];

void __cdecl sub_002E0F70(void)
{
    DAT_00449C74.sub_00065460(0, (int)DAT_003F71F8, (int)sub_00069330, 0, 1, 2);
}
