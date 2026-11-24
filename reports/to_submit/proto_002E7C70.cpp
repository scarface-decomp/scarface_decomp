// bin: proto
// va: 0x002E7C70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7C70 (Proto 0x002E7C70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004110CC[];
extern "C" char DAT_004110D8[];
extern "C" Object DAT_0045F68C;
extern "C" char sub_0018B440[];

void __cdecl sub_002E7C70(void)
{
    DAT_0045F68C.sub_00065550((int)DAT_004110D8, (int)DAT_004110CC, (int)sub_0018B440, 0, 6, 7);
}
