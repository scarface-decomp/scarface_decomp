// bin: proto
// va: 0x002E7D30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7D30 (Proto 0x002E7D30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004111F4[];
extern "C" char DAT_00411200[];
extern "C" Object DAT_0045F768;
extern "C" char sub_0018B5F0[];

void __cdecl sub_002E7D30(void)
{
    DAT_0045F768.sub_00065550((int)DAT_00411200, (int)DAT_004111F4, (int)sub_0018B5F0, 0, 2, 2);
}
