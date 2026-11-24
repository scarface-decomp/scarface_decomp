// bin: proto
// va: 0x002E46E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E46E0 (Proto 0x002E46E0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_004023C0[];
extern "C" Object DAT_0045B664;
extern "C" char sub_000DB690[];

void __cdecl sub_002E46E0(void)
{
    DAT_0045B664.sub_00065500(0, (int)DAT_004023C0, (int)sub_000DB690, 0, 2, 2);
}
