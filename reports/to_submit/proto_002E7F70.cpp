// bin: proto
// va: 0x002E7F70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7F70 (Proto 0x002E7F70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004114E0[];
extern "C" char DAT_004114F8[];
extern "C" Object DAT_0045FA54;
extern "C" char sub_0018B880[];

void __cdecl sub_002E7F70(void)
{
    DAT_0045FA54.sub_000655A0((int)DAT_004114F8, (int)DAT_004114E0, (int)sub_0018B880, 0, 2, 2);
}
