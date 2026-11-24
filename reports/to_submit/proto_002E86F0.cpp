// bin: proto
// va: 0x002E86F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E86F0 (Proto 0x002E86F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00412DA0[];
extern "C" char DAT_00412DB4[];
extern "C" Object DAT_004600C0;
extern "C" char sub_00193540[];

void __cdecl sub_002E86F0(void)
{
    DAT_004600C0.sub_00065550((int)DAT_00412DB4, (int)DAT_00412DA0, (int)sub_00193540, 0, 4, 4);
}
