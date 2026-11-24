// bin: proto
// va: 0x002E7650
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7650 (Proto 0x002E7650, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00410684[];
extern "C" Object DAT_0045F164;
extern "C" char sub_0018A520[];

void __cdecl sub_002E7650(void)
{
    DAT_0045F164.sub_00065550(0, (int)DAT_00410684, (int)sub_0018A520, 0, 1, 1);
}
