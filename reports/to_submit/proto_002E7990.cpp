// bin: proto
// va: 0x002E7990
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7990 (Proto 0x002E7990, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410C44[];
extern "C" char DAT_00410C4C[];
extern "C" Object DAT_0045F3CC;
extern "C" char sub_0018AEF0[];

void __cdecl sub_002E7990(void)
{
    DAT_0045F3CC.sub_00065550((int)DAT_00410C4C, (int)DAT_00410C44, (int)sub_0018AEF0, 0, 3, 3);
}
