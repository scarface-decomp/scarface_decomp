// bin: proto
// va: 0x002E7AB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7AB0 (Proto 0x002E7AB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410D88[];
extern "C" char DAT_00410D94[];
extern "C" Object DAT_0045F52C;
extern "C" char sub_0018B050[];

void __cdecl sub_002E7AB0(void)
{
    DAT_0045F52C.sub_00065550((int)DAT_00410D94, (int)DAT_00410D88, (int)sub_0018B050, 0, 4, 4);
}
