// bin: proto
// va: 0x002E7C50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7C50 (Proto 0x002E7C50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004110A8[];
extern "C" char DAT_004110BC[];
extern "C" Object DAT_0045F660;
extern "C" char sub_0018B430[];

void __cdecl sub_002E7C50(void)
{
    DAT_0045F660.sub_00065550((int)DAT_004110BC, (int)DAT_004110A8, (int)sub_0018B430, 0, 2, 2);
}
