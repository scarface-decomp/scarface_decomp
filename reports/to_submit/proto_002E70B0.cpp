// bin: proto
// va: 0x002E70B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E70B0 (Proto 0x002E70B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040F42C[];
extern "C" Object DAT_0045E050;
extern "C" char sub_0016EC80[];

void __cdecl sub_002E70B0(void)
{
    DAT_0045E050.sub_00065550(0, (int)DAT_0040F42C, (int)sub_0016EC80, 0, 1, 1);
}
