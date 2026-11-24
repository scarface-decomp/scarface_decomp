// bin: proto
// va: 0x002E7C90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7C90 (Proto 0x002E7C90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004110E8[];
extern "C" char DAT_004110FC[];
extern "C" Object DAT_0045F6B8;
extern "C" char sub_0018B4A0[];

void __cdecl sub_002E7C90(void)
{
    DAT_0045F6B8.sub_00065550((int)DAT_004110FC, (int)DAT_004110E8, (int)sub_0018B4A0, 0, 3, 3);
}
