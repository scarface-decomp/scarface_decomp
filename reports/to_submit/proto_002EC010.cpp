// bin: proto
// va: 0x002EC010
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC010 (Proto 0x002EC010, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004272AC[];
extern "C" Object DAT_00462880;
extern "C" char sub_001E5840[];

void __cdecl sub_002EC010(void)
{
    DAT_00462880.sub_00065550(0, (int)DAT_004272AC, (int)sub_001E5840, 0, 2, 2);
}
