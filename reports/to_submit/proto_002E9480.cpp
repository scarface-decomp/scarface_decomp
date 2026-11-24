// bin: proto
// va: 0x002E9480
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9480 (Proto 0x002E9480, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00414FAC[];
extern "C" char DAT_00414FBC[];
extern "C" Object DAT_00460980;
extern "C" char sub_0019F730[];

void __cdecl sub_002E9480(void)
{
    DAT_00460980.sub_00065550((int)DAT_00414FBC, (int)DAT_00414FAC, (int)sub_0019F730, 0, 3, 3);
}
