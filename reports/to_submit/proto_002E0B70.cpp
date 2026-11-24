// bin: proto
// va: 0x002E0B70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0B70 (Proto 0x002E0B70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F67A0[];
extern "C" char DAT_003F67A8[];
extern "C" Object DAT_0044967C;
extern "C" char sub_0002AB60[];

void __cdecl sub_002E0B70(void)
{
    DAT_0044967C.sub_000654B0((int)DAT_003F67A8, (int)DAT_003F67A0, (int)sub_0002AB60, 0, 2, 2);
}
