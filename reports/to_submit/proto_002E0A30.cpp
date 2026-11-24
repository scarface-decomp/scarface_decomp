// bin: proto
// va: 0x002E0A30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0A30 (Proto 0x002E0A30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F6608[];
extern "C" char DAT_003F6610[];
extern "C" Object DAT_0044951C;
extern "C" char sub_0002A350[];

void __cdecl sub_002E0A30(void)
{
    DAT_0044951C.sub_00065550((int)DAT_003F6610, (int)DAT_003F6608, (int)sub_0002A350, 0, 3, 10);
}
