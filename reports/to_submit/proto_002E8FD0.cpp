// bin: proto
// va: 0x002E8FD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8FD0 (Proto 0x002E8FD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_004142B8[];
extern "C" char DAT_004142C8[];
extern "C" Object DAT_00460544;
extern "C" char sub_0019B9C0[];

void __cdecl sub_002E8FD0(void)
{
    DAT_00460544.sub_000654B0((int)DAT_004142C8, (int)DAT_004142B8, (int)sub_0019B9C0, 0, 2, 2);
}
