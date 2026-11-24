// bin: proto
// va: 0x002E8590
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8590 (Proto 0x002E8590, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004122C8[];
extern "C" char DAT_004122D8[];
extern "C" Object DAT_0045FF80;
extern "C" char sub_00191C40[];

void __cdecl sub_002E8590(void)
{
    DAT_0045FF80.sub_00065550((int)DAT_004122D8, (int)DAT_004122C8, (int)sub_00191C40, 0, 2, 2);
}
