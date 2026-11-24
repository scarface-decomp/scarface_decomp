// bin: proto
// va: 0x002E8690
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8690 (Proto 0x002E8690, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0041241C[];
extern "C" char DAT_00412434[];
extern "C" Object DAT_00460094;
extern "C" char sub_00192050[];

void __cdecl sub_002E8690(void)
{
    DAT_00460094.sub_00065550((int)DAT_00412434, (int)DAT_0041241C, (int)sub_00192050, 0, 3, 3);
}
