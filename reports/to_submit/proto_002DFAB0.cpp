// bin: proto
// va: 0x002DFAB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002DFAB0 (Proto 0x002DFAB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003F40E8[];
extern "C" Object DAT_0043D8E0;
extern "C" char sub_00011680[];

void __cdecl sub_002DFAB0(void)
{
    DAT_0043D8E0.sub_00065550(0, (int)DAT_003F40E8, (int)sub_00011680, 0, 2, 2);
}
