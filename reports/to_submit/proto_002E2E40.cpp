// bin: proto
// va: 0x002E2E40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2E40 (Proto 0x002E2E40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_003FDF34[];
extern "C" Object DAT_00453CB8;
extern "C" char sub_00084B30[];

void __cdecl sub_002E2E40(void)
{
    DAT_00453CB8.sub_000654B0(0, (int)DAT_003FDF34, (int)sub_00084B30, 0, 1, 1);
}
