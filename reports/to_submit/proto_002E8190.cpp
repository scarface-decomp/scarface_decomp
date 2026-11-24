// bin: proto
// va: 0x002E8190
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8190 (Proto 0x002E8190, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004116AC[];
extern "C" Object DAT_0045FCE8;
extern "C" char sub_0018BAB0[];

void __cdecl sub_002E8190(void)
{
    DAT_0045FCE8.sub_00065550(0, (int)DAT_004116AC, (int)sub_0018BAB0, 0, 3, 3);
}
