// bin: proto
// va: 0x002E76D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E76D0 (Proto 0x002E76D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004106C4[];
extern "C" Object DAT_0045F214;
extern "C" char sub_0018A570[];

void __cdecl sub_002E76D0(void)
{
    DAT_0045F214.sub_00065550(0, (int)DAT_004106C4, (int)sub_0018A570, 0, 1, 1);
}
