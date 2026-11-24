// bin: proto
// va: 0x002E7D10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7D10 (Proto 0x002E7D10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004111C0[];
extern "C" char DAT_004111E4[];
extern "C" Object DAT_0045F73C;
extern "C" char sub_0018B5D0[];

void __cdecl sub_002E7D10(void)
{
    DAT_0045F73C.sub_00065550((int)DAT_004111E4, (int)DAT_004111C0, (int)sub_0018B5D0, 0, 5, 5);
}
