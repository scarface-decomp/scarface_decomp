// bin: proto
// va: 0x002EC170
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC170 (Proto 0x002EC170, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_004273B0[];
extern "C" Object DAT_00462A64;
extern "C" char sub_001E59D0[];

void __cdecl sub_002EC170(void)
{
    DAT_00462A64.sub_00065550(0, (int)DAT_004273B0, (int)sub_001E59D0, 0, 2, 2);
}
