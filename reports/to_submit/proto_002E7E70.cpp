// bin: proto
// va: 0x002E7E70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7E70 (Proto 0x002E7E70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004113C8[];
extern "C" char DAT_004113DC[];
extern "C" Object DAT_0045F8F4;
extern "C" char sub_0018B7A0[];

void __cdecl sub_002E7E70(void)
{
    DAT_0045F8F4.sub_00065550((int)DAT_004113DC, (int)DAT_004113C8, (int)sub_0018B7A0, 0, 2, 2);
}
