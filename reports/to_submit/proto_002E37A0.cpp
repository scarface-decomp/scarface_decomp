// bin: proto
// va: 0x002E37A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E37A0 (Proto 0x002E37A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003FF960[];
extern "C" Object DAT_00459934;
extern "C" char sub_000BE760[];

void __cdecl sub_002E37A0(void)
{
    DAT_00459934.sub_00065460(0, (int)DAT_003FF960, (int)sub_000BE760, 0, 1, 1);
}
