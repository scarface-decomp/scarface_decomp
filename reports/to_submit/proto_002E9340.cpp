// bin: proto
// va: 0x002E9340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9340 (Proto 0x002E9340, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00414EC0[];
extern "C" char DAT_00414ED0[];
extern "C" Object DAT_004607F4;
extern "C" char sub_0019F560[];

void __cdecl sub_002E9340(void)
{
    DAT_004607F4.sub_000654B0((int)DAT_00414ED0, (int)DAT_00414EC0, (int)sub_0019F560, 0, 2, 2);
}
