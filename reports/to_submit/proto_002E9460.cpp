// bin: proto
// va: 0x002E9460
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9460 (Proto 0x002E9460, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00414F8C[];
extern "C" char DAT_00414FA0[];
extern "C" Object DAT_00460954;
extern "C" char sub_0019F5C0[];

void __cdecl sub_002E9460(void)
{
    DAT_00460954.sub_000654B0((int)DAT_00414FA0, (int)DAT_00414F8C, (int)sub_0019F5C0, 0, 2, 2);
}
