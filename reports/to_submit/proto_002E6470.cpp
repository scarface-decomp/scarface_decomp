// bin: proto
// va: 0x002E6470
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6470 (Proto 0x002E6470, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B45C[];
extern "C" char DAT_0040B470[];
extern "C" Object DAT_0045D4BC;
extern "C" char sub_00158CD0[];

void __cdecl sub_002E6470(void)
{
    DAT_0045D4BC.sub_00065550((int)DAT_0040B470, (int)DAT_0040B45C, (int)sub_00158CD0, 0, 4, 4);
}
