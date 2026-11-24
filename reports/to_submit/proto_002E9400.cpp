// bin: proto
// va: 0x002E9400
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9400 (Proto 0x002E9400, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00414F38[];
extern "C" char DAT_00414F40[];
extern "C" Object DAT_004608D0;
extern "C" char sub_0019F590[];

void __cdecl sub_002E9400(void)
{
    DAT_004608D0.sub_00065550((int)DAT_00414F40, (int)DAT_00414F38, (int)sub_0019F590, 0, 2, 2);
}
