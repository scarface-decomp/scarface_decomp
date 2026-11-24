// bin: proto
// va: 0x002E6010
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6010 (Proto 0x002E6010, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040AE9C[];
extern "C" char DAT_0040AEB0[];
extern "C" Object DAT_0045CF90;
extern "C" char sub_00157CB0[];

void __cdecl sub_002E6010(void)
{
    DAT_0045CF90.sub_00065550((int)DAT_0040AEB0, (int)DAT_0040AE9C, (int)sub_00157CB0, 0, 3, 3);
}
