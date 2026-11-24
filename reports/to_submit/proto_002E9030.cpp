// bin: proto
// va: 0x002E9030
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9030 (Proto 0x002E9030, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00414690[];
extern "C" Object DAT_0046059C;
extern "C" char sub_0019BA60[];

void __cdecl sub_002E9030(void)
{
    DAT_0046059C.sub_00065550(0, (int)DAT_00414690, (int)sub_0019BA60, 0, 1, 1);
}
