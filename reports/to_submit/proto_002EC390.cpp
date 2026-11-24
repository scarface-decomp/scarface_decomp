// bin: proto
// va: 0x002EC390
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC390 (Proto 0x002EC390, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_004275D0[];
extern "C" Object DAT_00462D50;
extern "C" char sub_001E5BF0[];

void __cdecl sub_002EC390(void)
{
    DAT_00462D50.sub_00065460(0, (int)DAT_004275D0, (int)sub_001E5BF0, 0, 1, 1);
}
