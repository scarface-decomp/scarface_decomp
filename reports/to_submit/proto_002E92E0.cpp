// bin: proto
// va: 0x002E92E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E92E0 (Proto 0x002E92E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00414E6C[];
extern "C" char DAT_00414E7C[];
extern "C" Object DAT_0046079C;
extern "C" char sub_0019F3A0[];

void __cdecl sub_002E92E0(void)
{
    DAT_0046079C.sub_000654B0((int)DAT_00414E7C, (int)DAT_00414E6C, (int)sub_0019F3A0, 0, 2, 2);
}
