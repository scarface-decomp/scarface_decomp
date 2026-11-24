// bin: proto
// va: 0x002E7F50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7F50 (Proto 0x002E7F50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004114B8[];
extern "C" char DAT_004114D0[];
extern "C" Object DAT_0045FA28;
extern "C" char sub_0018B850[];

void __cdecl sub_002E7F50(void)
{
    DAT_0045FA28.sub_00065550((int)DAT_004114D0, (int)DAT_004114B8, (int)sub_0018B850, 0, 5, 5);
}
