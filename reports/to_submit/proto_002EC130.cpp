// bin: proto
// va: 0x002EC130
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC130 (Proto 0x002EC130, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427370[];
extern "C" Object DAT_00462A0C;
extern "C" char sub_001E59A0[];

void __cdecl sub_002EC130(void)
{
    DAT_00462A0C.sub_00065550(0, (int)DAT_00427370, (int)sub_001E59A0, 0, 2, 2);
}
