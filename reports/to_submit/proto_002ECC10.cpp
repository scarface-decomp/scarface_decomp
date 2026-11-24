// bin: proto
// va: 0x002ECC10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECC10 (Proto 0x002ECC10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427918[];
extern "C" Object DAT_00463164;
extern "C" char sub_001ED370[];

void __cdecl sub_002ECC10(void)
{
    DAT_00463164.sub_00065550(0, (int)DAT_00427918, (int)sub_001ED370, 0, 1, 1);
}
