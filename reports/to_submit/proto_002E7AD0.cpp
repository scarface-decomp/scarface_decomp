// bin: proto
// va: 0x002E7AD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7AD0 (Proto 0x002E7AD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410DA0[];
extern "C" char DAT_00410DAC[];
extern "C" Object DAT_0045F558;
extern "C" char sub_0018B090[];

void __cdecl sub_002E7AD0(void)
{
    DAT_0045F558.sub_00065550((int)DAT_00410DAC, (int)DAT_00410DA0, (int)sub_0018B090, 0, 3, 3);
}
