// bin: proto
// va: 0x002E8F10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8F10 (Proto 0x002E8F10, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00414228[];
extern "C" char DAT_00414234[];
extern "C" Object DAT_0046043C;
extern "C" char sub_0019B8D0[];

void __cdecl sub_002E8F10(void)
{
    DAT_0046043C.sub_00065550((int)DAT_00414234, (int)DAT_00414228, (int)sub_0019B8D0, 0, 3, 3);
}
