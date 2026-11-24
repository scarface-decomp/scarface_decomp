// bin: proto
// va: 0x002E0B30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0B30 (Proto 0x002E0B30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003F6774[];
extern "C" char DAT_003F677C[];
extern "C" Object DAT_00449624;
extern "C" char sub_0002AAD0[];

void __cdecl sub_002E0B30(void)
{
    DAT_00449624.sub_000654B0((int)DAT_003F677C, (int)DAT_003F6774, (int)sub_0002AAD0, 0, 3, 3);
}
