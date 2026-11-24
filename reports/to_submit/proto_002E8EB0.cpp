// bin: proto
// va: 0x002E8EB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8EB0 (Proto 0x002E8EB0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00413F9C[];
extern "C" char DAT_00413FA8[];
extern "C" Object DAT_00460410;
extern "C" char sub_0019B0B0[];

void __cdecl sub_002E8EB0(void)
{
    DAT_00460410.sub_00065550((int)DAT_00413FA8, (int)DAT_00413F9C, (int)sub_0019B0B0, 0, 3, 3);
}
