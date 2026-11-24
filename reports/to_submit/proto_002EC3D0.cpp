// bin: proto
// va: 0x002EC3D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC3D0 (Proto 0x002EC3D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0042760C[];
extern "C" Object DAT_00462DA8;
extern "C" char sub_001E5C60[];

void __cdecl sub_002EC3D0(void)
{
    DAT_00462DA8.sub_00065550(0, (int)DAT_0042760C, (int)sub_001E5C60, 0, 3, 3);
}
