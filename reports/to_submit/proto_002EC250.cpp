// bin: proto
// va: 0x002EC250
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC250 (Proto 0x002EC250, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427478[];
extern "C" Object DAT_00462B98;
extern "C" char sub_001E5AA0[];

void __cdecl sub_002EC250(void)
{
    DAT_00462B98.sub_00065550(0, (int)DAT_00427478, (int)sub_001E5AA0, 0, 1, 1);
}
