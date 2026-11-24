// bin: proto
// va: 0x002E8670
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8670 (Proto 0x002E8670, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004123F8[];
extern "C" char DAT_0041240C[];
extern "C" Object DAT_00460068;
extern "C" char sub_00192030[];

void __cdecl sub_002E8670(void)
{
    DAT_00460068.sub_00065550((int)DAT_0041240C, (int)DAT_004123F8, (int)sub_00192030, 0, 3, 3);
}
