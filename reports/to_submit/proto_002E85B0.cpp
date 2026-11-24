// bin: proto
// va: 0x002E85B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E85B0 (Proto 0x002E85B0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004122E4[];
extern "C" char DAT_004122F4[];
extern "C" Object DAT_0045FFAC;
extern "C" char sub_00191C30[];

void __cdecl sub_002E85B0(void)
{
    DAT_0045FFAC.sub_00065550((int)DAT_004122F4, (int)DAT_004122E4, (int)sub_00191C30, 0, 2, 2);
}
