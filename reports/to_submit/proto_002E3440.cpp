// bin: proto
// va: 0x002E3440
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3440 (Proto 0x002E3440, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FF35C[];
extern "C" char DAT_003FF368[];
extern "C" Object DAT_0045951C;
extern "C" char sub_000BAB60[];

void __cdecl sub_002E3440(void)
{
    DAT_0045951C.sub_00065550((int)DAT_003FF368, (int)DAT_003FF35C, (int)sub_000BAB60, 0, 3, 6);
}
