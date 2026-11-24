// bin: proto
// va: 0x002E7690
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7690 (Proto 0x002E7690, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004106AC[];
extern "C" Object DAT_0045F1BC;
extern "C" char sub_0018A540[];

void __cdecl sub_002E7690(void)
{
    DAT_0045F1BC.sub_00065550(0, (int)DAT_004106AC, (int)sub_0018A540, 0, 1, 1);
}
