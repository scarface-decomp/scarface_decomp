// bin: proto
// va: 0x002E3260
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3260 (Proto 0x002E3260, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003FE9B0[];
extern "C" Object DAT_004543A4;
extern "C" char sub_0008D690[];

void __cdecl sub_002E3260(void)
{
    DAT_004543A4.sub_00065460(0, (int)DAT_003FE9B0, (int)sub_0008D690, 0, 3, 3);
}
