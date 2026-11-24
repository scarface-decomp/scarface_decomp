// bin: proto
// va: 0x002E31C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E31C0 (Proto 0x002E31C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FE960[];
extern "C" Object DAT_004542B8;
extern "C" char sub_0008D570[];

void __cdecl sub_002E31C0(void)
{
    DAT_004542B8.sub_00065550(0, (int)DAT_003FE960, (int)sub_0008D570, 0, 2, 2);
}
