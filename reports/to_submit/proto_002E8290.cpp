// bin: proto
// va: 0x002E8290
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8290 (Proto 0x002E8290, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004118A8[];
extern "C" Object DAT_0045FDC4;
extern "C" char sub_0018BDF0[];

void __cdecl sub_002E8290(void)
{
    DAT_0045FDC4.sub_00065550(0, (int)DAT_004118A8, (int)sub_0018BDF0, 0, 6, 6);
}
