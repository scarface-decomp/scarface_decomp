// bin: proto
// va: 0x002E7DB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7DB0 (Proto 0x002E7DB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041126C[];
extern "C" char DAT_00411278[];
extern "C" Object DAT_0045F818;
extern "C" char sub_0018B650[];

void __cdecl sub_002E7DB0(void)
{
    DAT_0045F818.sub_00065550((int)DAT_00411278, (int)DAT_0041126C, (int)sub_0018B650, 0, 3, 3);
}
