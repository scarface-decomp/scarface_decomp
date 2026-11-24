// bin: proto
// va: 0x002EB230
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB230 (Proto 0x002EB230, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00425E68[];
extern "C" char DAT_00425E7C[];
extern "C" Object DAT_004619C4;
extern "C" char sub_001DA9D0[];

void __cdecl sub_002EB230(void)
{
    DAT_004619C4.sub_000654B0((int)DAT_00425E7C, (int)DAT_00425E68, (int)sub_001DA9D0, 0, 3, 3);
}
