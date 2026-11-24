// bin: proto
// va: 0x002E5B80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5B80 (Proto 0x002E5B80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A4E4[];
extern "C" char DAT_0040A4F8[];
extern "C" Object DAT_0045C990;
extern "C" char sub_00142890[];

void __cdecl sub_002E5B80(void)
{
    DAT_0045C990.sub_00065550((int)DAT_0040A4F8, (int)DAT_0040A4E4, (int)sub_00142890, 0, 5, 5);
}
