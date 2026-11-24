// bin: proto
// va: 0x002E5BC0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5BC0 (Proto 0x002E5BC0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A51C[];
extern "C" char DAT_0040A530[];
extern "C" Object DAT_0045C9E8;
extern "C" char sub_00142920[];

void __cdecl sub_002E5BC0(void)
{
    DAT_0045C9E8.sub_00065550((int)DAT_0040A530, (int)DAT_0040A51C, (int)sub_00142920, 0, 3, 3);
}
