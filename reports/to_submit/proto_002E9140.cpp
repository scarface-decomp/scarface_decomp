// bin: proto
// va: 0x002E9140
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9140 (Proto 0x002E9140, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00414A10[];
extern "C" Object DAT_004606B4;
extern "C" char sub_0019ECD0[];

void __cdecl sub_002E9140(void)
{
    DAT_004606B4.sub_000655A0(0, (int)DAT_00414A10, (int)sub_0019ECD0, 0, 1, 1);
}
