// bin: proto
// va: 0x002E8FB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8FB0 (Proto 0x002E8FB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_004142A0[];
extern "C" char DAT_004142AC[];
extern "C" Object DAT_00460518;
extern "C" char sub_0019B990[];

void __cdecl sub_002E8FB0(void)
{
    DAT_00460518.sub_000654B0((int)DAT_004142AC, (int)DAT_004142A0, (int)sub_0019B990, 0, 2, 2);
}
