// bin: proto
// va: 0x002E8270
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8270 (Proto 0x002E8270, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411894[];
extern "C" char DAT_0041189C[];
extern "C" Object DAT_0045FD98;
extern "C" char sub_0018BDE0[];

void __cdecl sub_002E8270(void)
{
    DAT_0045FD98.sub_00065550((int)DAT_0041189C, (int)DAT_00411894, (int)sub_0018BDE0, 0, 2, 2);
}
