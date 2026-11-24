// bin: proto
// va: 0x002E74D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E74D0 (Proto 0x002E74D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041043C[];
extern "C" char DAT_0041044C[];
extern "C" Object DAT_0045EFD8;
extern "C" char sub_0018A260[];

void __cdecl sub_002E74D0(void)
{
    DAT_0045EFD8.sub_00065550((int)DAT_0041044C, (int)DAT_0041043C, (int)sub_0018A260, 0, 2, 2);
}
