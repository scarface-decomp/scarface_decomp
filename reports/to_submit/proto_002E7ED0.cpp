// bin: proto
// va: 0x002E7ED0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7ED0 (Proto 0x002E7ED0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0041142C[];
extern "C" char DAT_0041143C[];
extern "C" Object DAT_0045F978;
extern "C" char sub_0018B800[];

void __cdecl sub_002E7ED0(void)
{
    DAT_0045F978.sub_000654B0((int)DAT_0041143C, (int)DAT_0041142C, (int)sub_0018B800, 0, 2, 2);
}
