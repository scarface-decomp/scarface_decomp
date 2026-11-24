// bin: proto
// va: 0x002E7AF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7AF0 (Proto 0x002E7AF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410DB8[];
extern "C" char DAT_00410DC4[];
extern "C" Object DAT_0045F584;
extern "C" char sub_0018B0C0[];

void __cdecl sub_002E7AF0(void)
{
    DAT_0045F584.sub_00065550((int)DAT_00410DC4, (int)DAT_00410DB8, (int)sub_0018B0C0, 0, 2, 2);
}
