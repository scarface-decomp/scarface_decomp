// bin: proto
// va: 0x002E64F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E64F0 (Proto 0x002E64F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B4E4[];
extern "C" char DAT_0040B4F8[];
extern "C" Object DAT_0045D56C;
extern "C" char sub_00158370[];

void __cdecl sub_002E64F0(void)
{
    DAT_0045D56C.sub_00065550((int)DAT_0040B4F8, (int)DAT_0040B4E4, (int)sub_00158370, 0, 2, 2);
}
