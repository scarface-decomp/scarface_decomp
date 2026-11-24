// bin: proto
// va: 0x002E5920
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5920 (Proto 0x002E5920, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409C70[];
extern "C" char DAT_00409C80[];
extern "C" Object DAT_0045C6F0;
extern "C" char sub_00141C40[];

void __cdecl sub_002E5920(void)
{
    DAT_0045C6F0.sub_00065550((int)DAT_00409C80, (int)DAT_00409C70, (int)sub_00141C40, 0, 3, 3);
}
