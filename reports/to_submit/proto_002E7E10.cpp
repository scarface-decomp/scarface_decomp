// bin: proto
// va: 0x002E7E10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7E10 (Proto 0x002E7E10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_004112D4[];
extern "C" char DAT_004112E8[];
extern "C" Object DAT_0045F89C;
extern "C" char sub_0018B6B0[];

void __cdecl sub_002E7E10(void)
{
    DAT_0045F89C.sub_000654B0((int)DAT_004112E8, (int)DAT_004112D4, (int)sub_0018B6B0, 0, 2, 2);
}
