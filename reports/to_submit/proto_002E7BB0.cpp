// bin: proto
// va: 0x002E7BB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7BB0 (Proto 0x002E7BB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410E40[];
extern "C" Object DAT_0045F5DC;
extern "C" char sub_0018B140[];

void __cdecl sub_002E7BB0(void)
{
    DAT_0045F5DC.sub_00065550(0, (int)DAT_00410E40, (int)sub_0018B140, 0, 2, 3);
}
