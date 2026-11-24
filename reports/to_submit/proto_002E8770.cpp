// bin: proto
// va: 0x002E8770
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8770 (Proto 0x002E8770, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004133AC[];
extern "C" char DAT_004133B4[];
extern "C" Object DAT_0046011C;
extern "C" char sub_00196A70[];

void __cdecl sub_002E8770(void)
{
    DAT_0046011C.sub_00065550((int)DAT_004133B4, (int)DAT_004133AC, (int)sub_00196A70, 0, 3, 3);
}
