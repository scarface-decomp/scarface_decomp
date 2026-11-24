// bin: proto
// va: 0x002E5B40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5B40 (Proto 0x002E5B40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A4A4[];
extern "C" char DAT_0040A4B4[];
extern "C" Object DAT_0045C938;
extern "C" char sub_001427B0[];

void __cdecl sub_002E5B40(void)
{
    DAT_0045C938.sub_00065550((int)DAT_0040A4B4, (int)DAT_0040A4A4, (int)sub_001427B0, 0, 7, 7);
}
