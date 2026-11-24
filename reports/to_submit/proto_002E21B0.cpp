// bin: proto
// va: 0x002E21B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E21B0 (Proto 0x002E21B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F9D70[];
extern "C" Object DAT_0044FCEC;
extern "C" char sub_000669F0[];

void __cdecl sub_002E21B0(void)
{
    DAT_0044FCEC.sub_00065550(0, (int)DAT_003F9D70, (int)sub_000669F0, 0, 2, 2);
}
