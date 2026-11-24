// bin: proto
// va: 0x002E6830
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6830 (Proto 0x002E6830, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B85C[];
extern "C" char DAT_0040B87C[];
extern "C" Object DAT_0045D9E4;
extern "C" char sub_00158FA0[];

void __cdecl sub_002E6830(void)
{
    DAT_0045D9E4.sub_00065550((int)DAT_0040B87C, (int)DAT_0040B85C, (int)sub_00158FA0, 0, 3, 4);
}
