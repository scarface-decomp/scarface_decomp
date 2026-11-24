// bin: proto
// va: 0x002E8F30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8F30 (Proto 0x002E8F30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00414240[];
extern "C" char DAT_00414250[];
extern "C" Object DAT_00460468;
extern "C" char sub_0019B900[];

void __cdecl sub_002E8F30(void)
{
    DAT_00460468.sub_00065550((int)DAT_00414250, (int)DAT_00414240, (int)sub_0019B900, 0, 3, 3);
}
