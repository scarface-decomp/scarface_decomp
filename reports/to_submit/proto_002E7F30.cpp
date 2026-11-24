// bin: proto
// va: 0x002E7F30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7F30 (Proto 0x002E7F30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411494[];
extern "C" char DAT_004114A8[];
extern "C" Object DAT_0045F9FC;
extern "C" char sub_0018B830[];

void __cdecl sub_002E7F30(void)
{
    DAT_0045F9FC.sub_00065550((int)DAT_004114A8, (int)DAT_00411494, (int)sub_0018B830, 0, 3, 3);
}
