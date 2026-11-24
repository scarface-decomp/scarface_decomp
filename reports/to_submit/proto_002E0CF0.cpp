// bin: proto
// va: 0x002E0CF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0CF0 (Proto 0x002E0CF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F6C50[];
extern "C" char DAT_003F6C58[];
extern "C" Object DAT_00449758;
extern "C" char sub_0002B370[];

void __cdecl sub_002E0CF0(void)
{
    DAT_00449758.sub_00065460((int)DAT_003F6C58, (int)DAT_003F6C50, (int)sub_0002B370, 0, 2, 2);
}
