// bin: proto
// va: 0x002E24A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E24A0 (Proto 0x002E24A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FCF34[];
extern "C" Object DAT_004532A4;
extern "C" char sub_0006C6E0[];

void __cdecl sub_002E24A0(void)
{
    DAT_004532A4.sub_00065550(0, (int)DAT_003FCF34, (int)sub_0006C6E0, 0, 1, 1);
}
