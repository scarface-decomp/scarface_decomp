// bin: proto
// va: 0x002E74F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E74F0 (Proto 0x002E74F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410458[];
extern "C" char DAT_00410460[];
extern "C" Object DAT_0045F004;
extern "C" char sub_0018A270[];

void __cdecl sub_002E74F0(void)
{
    DAT_0045F004.sub_00065550((int)DAT_00410460, (int)DAT_00410458, (int)sub_0018A270, 0, 3, 3);
}
