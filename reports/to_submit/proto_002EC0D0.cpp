// bin: proto
// va: 0x002EC0D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC0D0 (Proto 0x002EC0D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427334[];
extern "C" Object DAT_00462988;
extern "C" char sub_001E58B0[];

void __cdecl sub_002EC0D0(void)
{
    DAT_00462988.sub_00065550(0, (int)DAT_00427334, (int)sub_001E58B0, 0, 7, 8);
}
