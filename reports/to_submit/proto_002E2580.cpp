// bin: proto
// va: 0x002E2580
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2580 (Proto 0x002E2580, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_003FCFE0[];
extern "C" Object DAT_004533D8;
extern "C" char sub_0006C780[];

void __cdecl sub_002E2580(void)
{
    DAT_004533D8.sub_00065550(0, (int)DAT_003FCFE0, (int)sub_0006C780, 0, 3, 3);
}
