// bin: proto
// va: 0x002E0E70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0E70 (Proto 0x002E0E70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F7140[];
extern "C" Object DAT_00449B14;
extern "C" char sub_0002C0A0[];

void __cdecl sub_002E0E70(void)
{
    DAT_00449B14.sub_00065460(0, (int)DAT_003F7140, (int)sub_0002C0A0, 0, 1, 1);
}
