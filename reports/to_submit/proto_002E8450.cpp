// bin: proto
// va: 0x002E8450
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8450 (Proto 0x002E8450, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411C34[];
extern "C" char DAT_00411C48[];
extern "C" Object DAT_0045FEF8;
extern "C" char sub_0018C3A0[];

void __cdecl sub_002E8450(void)
{
    DAT_0045FEF8.sub_00065550((int)DAT_00411C48, (int)DAT_00411C34, (int)sub_0018C3A0, 0, 2, 2);
}
