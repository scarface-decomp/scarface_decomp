// bin: proto
// va: 0x002E7BF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7BF0 (Proto 0x002E7BF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041100C[];
extern "C" char DAT_00411014[];
extern "C" Object DAT_0045F608;
extern "C" char sub_0018B380[];

void __cdecl sub_002E7BF0(void)
{
    DAT_0045F608.sub_00065550((int)DAT_00411014, (int)DAT_0041100C, (int)sub_0018B380, 0, 3, 3);
}
