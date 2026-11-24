// bin: proto
// va: 0x002E7230
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7230 (Proto 0x002E7230, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040FF3C[];
extern "C" char DAT_0040FF58[];
extern "C" Object DAT_0045EDC8;
extern "C" char sub_00189C80[];

void __cdecl sub_002E7230(void)
{
    DAT_0045EDC8.sub_000654B0((int)DAT_0040FF58, (int)DAT_0040FF3C, (int)sub_00189C80, 0, 4, 4);
}
