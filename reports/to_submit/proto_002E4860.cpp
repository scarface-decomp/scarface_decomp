// bin: proto
// va: 0x002E4860
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4860 (Proto 0x002E4860, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004024D0[];
extern "C" Object DAT_0045B874;
extern "C" char sub_000DB7E0[];

void __cdecl sub_002E4860(void)
{
    DAT_0045B874.sub_00065550(0, (int)DAT_004024D0, (int)sub_000DB7E0, 0, 2, 2);
}
