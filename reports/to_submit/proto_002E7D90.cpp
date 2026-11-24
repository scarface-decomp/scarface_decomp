// bin: proto
// va: 0x002E7D90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7D90 (Proto 0x002E7D90, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411248[];
extern "C" char DAT_0041125C[];
extern "C" Object DAT_0045F7EC;
extern "C" char sub_0018B640[];

void __cdecl sub_002E7D90(void)
{
    DAT_0045F7EC.sub_00065550((int)DAT_0041125C, (int)DAT_00411248, (int)sub_0018B640, 0, 2, 2);
}
