// bin: proto
// va: 0x002E2400
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2400 (Proto 0x002E2400, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FCED4[];
extern "C" Object DAT_004531C8;
extern "C" char sub_0006C5B0[];

void __cdecl sub_002E2400(void)
{
    DAT_004531C8.sub_00065550(0, (int)DAT_003FCED4, (int)sub_0006C5B0, 0, 2, 2);
}
