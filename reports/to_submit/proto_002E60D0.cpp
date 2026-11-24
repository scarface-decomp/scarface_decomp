// bin: proto
// va: 0x002E60D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E60D0 (Proto 0x002E60D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B070[];
extern "C" char DAT_0040B084[];
extern "C" Object DAT_0045CFC0;
extern "C" char sub_00157F70[];

void __cdecl sub_002E60D0(void)
{
    DAT_0045CFC0.sub_00065550((int)DAT_0040B084, (int)DAT_0040B070, (int)sub_00157F70, 0, 2, 2);
}
