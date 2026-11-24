// bin: proto
// va: 0x002E7CB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7CB0 (Proto 0x002E7CB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041110C[];
extern "C" Object DAT_0045F6E4;
extern "C" char sub_0018B4C0[];

void __cdecl sub_002E7CB0(void)
{
    DAT_0045F6E4.sub_00065550(0, (int)DAT_0041110C, (int)sub_0018B4C0, 0, 9, 9);
}
