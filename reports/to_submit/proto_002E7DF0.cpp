// bin: proto
// va: 0x002E7DF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7DF0 (Proto 0x002E7DF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004112B0[];
extern "C" char DAT_004112C4[];
extern "C" Object DAT_0045F870;
extern "C" char sub_0018B690[];

void __cdecl sub_002E7DF0(void)
{
    DAT_0045F870.sub_00065550((int)DAT_004112C4, (int)DAT_004112B0, (int)sub_0018B690, 0, 3, 3);
}
