// bin: proto
// va: 0x002E57C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E57C0 (Proto 0x002E57C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409A3C[];
extern "C" char DAT_00409A54[];
extern "C" Object DAT_0045C538;
extern "C" char sub_001418B0[];

void __cdecl sub_002E57C0(void)
{
    DAT_0045C538.sub_00065550((int)DAT_00409A54, (int)DAT_00409A3C, (int)sub_001418B0, 0, 3, 3);
}
