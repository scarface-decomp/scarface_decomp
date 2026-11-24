// bin: proto
// va: 0x002E5AA0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5AA0 (Proto 0x002E5AA0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A420[];
extern "C" char DAT_0040A428[];
extern "C" Object DAT_0045C85C;
extern "C" char sub_001426C0[];

void __cdecl sub_002E5AA0(void)
{
    DAT_0045C85C.sub_00065550((int)DAT_0040A428, (int)DAT_0040A420, (int)sub_001426C0, 0, 2, 2);
}
