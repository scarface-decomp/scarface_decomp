// bin: proto
// va: 0x002E93C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E93C0 (Proto 0x002E93C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00414F10[];
extern "C" char DAT_00414F18[];
extern "C" Object DAT_00460878;
extern "C" char sub_0019F570[];

void __cdecl sub_002E93C0(void)
{
    DAT_00460878.sub_00065550((int)DAT_00414F18, (int)DAT_00414F10, (int)sub_0019F570, 0, 2, 2);
}
