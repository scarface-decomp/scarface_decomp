// bin: proto
// va: 0x002E9AA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9AA0 (Proto 0x002E9AA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004179EC[];
extern "C" char DAT_004179F4[];
extern "C" Object DAT_00460C68;
extern "C" char sub_001B44A0[];

void __cdecl sub_002E9AA0(void)
{
    DAT_00460C68.sub_00065550((int)DAT_004179F4, (int)DAT_004179EC, (int)sub_001B44A0, 0, 4, 4);
}
