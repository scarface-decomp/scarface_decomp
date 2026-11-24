// bin: proto
// va: 0x002E8470
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8470 (Proto 0x002E8470, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411C54[];
extern "C" char DAT_00411C68[];
extern "C" Object DAT_0045FF24;
extern "C" char sub_0018C3B0[];

void __cdecl sub_002E8470(void)
{
    DAT_0045FF24.sub_00065550((int)DAT_00411C68, (int)DAT_00411C54, (int)sub_0018C3B0, 0, 2, 2);
}
