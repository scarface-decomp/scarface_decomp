// bin: proto
// va: 0x002ECC70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECC70 (Proto 0x002ECC70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0042795C[];
extern "C" Object DAT_004631E8;
extern "C" char sub_001ECCC0[];

void __cdecl sub_002ECC70(void)
{
    DAT_004631E8.sub_000655A0(0, (int)DAT_0042795C, (int)sub_001ECCC0, 0, 1, 1);
}
