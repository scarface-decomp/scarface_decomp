// bin: proto
// va: 0x002E5AE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5AE0 (Proto 0x002E5AE0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A448[];
extern "C" char DAT_0040A45C[];
extern "C" Object DAT_0045C8B4;
extern "C" char sub_001426E0[];

void __cdecl sub_002E5AE0(void)
{
    DAT_0045C8B4.sub_00065550((int)DAT_0040A45C, (int)DAT_0040A448, (int)sub_001426E0, 0, 3, 3);
}
