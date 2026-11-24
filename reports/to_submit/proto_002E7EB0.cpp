// bin: proto
// va: 0x002E7EB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7EB0 (Proto 0x002E7EB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041140C[];
extern "C" char DAT_0041141C[];
extern "C" Object DAT_0045F94C;
extern "C" char sub_0018B7E0[];

void __cdecl sub_002E7EB0(void)
{
    DAT_0045F94C.sub_00065550((int)DAT_0041141C, (int)DAT_0041140C, (int)sub_0018B7E0, 0, 3, 3);
}
