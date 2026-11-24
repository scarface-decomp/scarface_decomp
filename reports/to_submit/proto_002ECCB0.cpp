// bin: proto
// va: 0x002ECCB0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ECCB0 (Proto 0x002ECCB0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00427A60[];
extern "C" Object DAT_00463218;
extern "C" char sub_001EF160[];

void __cdecl sub_002ECCB0(void)
{
    DAT_00463218.sub_00065550(0, (int)DAT_00427A60, (int)sub_001EF160, 0, 1, 1);
}
