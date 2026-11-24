// bin: proto
// va: 0x002E7E50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7E50 (Proto 0x002E7E50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004113A0[];
extern "C" char DAT_004113B8[];
extern "C" Object DAT_0045F8C8;
extern "C" char sub_0018B790[];

void __cdecl sub_002E7E50(void)
{
    DAT_0045F8C8.sub_00065550((int)DAT_004113B8, (int)DAT_004113A0, (int)sub_0018B790, 0, 2, 2);
}
