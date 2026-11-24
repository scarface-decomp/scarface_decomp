// bin: proto
// va: 0x002E5800
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5800 (Proto 0x002E5800, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409A8C[];
extern "C" char DAT_00409A9C[];
extern "C" Object DAT_0045C590;
extern "C" char sub_00141960[];

void __cdecl sub_002E5800(void)
{
    DAT_0045C590.sub_00065550((int)DAT_00409A9C, (int)DAT_00409A8C, (int)sub_00141960, 0, 6, 7);
}
