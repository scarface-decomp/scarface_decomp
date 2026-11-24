// bin: proto
// va: 0x002E7C30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7C30 (Proto 0x002E7C30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041108C[];
extern "C" char DAT_00411098[];
extern "C" Object DAT_0045F634;
extern "C" char sub_0018B420[];

void __cdecl sub_002E7C30(void)
{
    DAT_0045F634.sub_00065550((int)DAT_00411098, (int)DAT_0041108C, (int)sub_0018B420, 0, 2, 2);
}
