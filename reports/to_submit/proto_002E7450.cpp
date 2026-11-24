// bin: proto
// va: 0x002E7450
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7450 (Proto 0x002E7450, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004102E4[];
extern "C" char DAT_004102F8[];
extern "C" Object DAT_0045EF80;
extern "C" char sub_0018A0E0[];

void __cdecl sub_002E7450(void)
{
    DAT_0045EF80.sub_00065550((int)DAT_004102F8, (int)DAT_004102E4, (int)sub_0018A0E0, 0, 4, 4);
}
