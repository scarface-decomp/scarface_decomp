// bin: proto
// va: 0x002E5820
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5820 (Proto 0x002E5820, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409AAC[];
extern "C" char DAT_00409ACC[];
extern "C" Object DAT_0045C5BC;
extern "C" char sub_001419F0[];

void __cdecl sub_002E5820(void)
{
    DAT_0045C5BC.sub_00065550((int)DAT_00409ACC, (int)DAT_00409AAC, (int)sub_001419F0, 0, 3, 3);
}
