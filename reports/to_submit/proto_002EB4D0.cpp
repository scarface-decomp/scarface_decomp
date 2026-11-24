// bin: proto
// va: 0x002EB4D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB4D0 (Proto 0x002EB4D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00426110[];
extern "C" char DAT_0042611C[];
extern "C" Object DAT_00461D60;
extern "C" char sub_001DADF0[];

void __cdecl sub_002EB4D0(void)
{
    DAT_00461D60.sub_00065550((int)DAT_0042611C, (int)DAT_00426110, (int)sub_001DADF0, 0, 3, 3);
}
