// bin: proto
// va: 0x002E1190
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1190 (Proto 0x002E1190, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F7498[];
extern "C" Object DAT_00449F14;
extern "C" char sub_00039080[];

void __cdecl sub_002E1190(void)
{
    DAT_00449F14.sub_00065550(0, (int)DAT_003F7498, (int)sub_00039080, 0, 3, 3);
}
