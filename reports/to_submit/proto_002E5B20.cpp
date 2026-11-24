// bin: proto
// va: 0x002E5B20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5B20 (Proto 0x002E5B20, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A488[];
extern "C" char DAT_0040A498[];
extern "C" Object DAT_0045C90C;
extern "C" char sub_00142740[];

void __cdecl sub_002E5B20(void)
{
    DAT_0045C90C.sub_00065550((int)DAT_0040A498, (int)DAT_0040A488, (int)sub_00142740, 0, 7, 7);
}
