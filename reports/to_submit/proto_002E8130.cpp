// bin: proto
// va: 0x002E8130
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8130 (Proto 0x002E8130, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411660[];
extern "C" char DAT_0041166C[];
extern "C" Object DAT_0045FC64;
extern "C" char sub_0018BA50[];

void __cdecl sub_002E8130(void)
{
    DAT_0045FC64.sub_00065550((int)DAT_0041166C, (int)DAT_00411660, (int)sub_0018BA50, 0, 3, 3);
}
