// bin: proto
// va: 0x002E9380
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E9380 (Proto 0x002E9380, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00414EF4[];
extern "C" char DAT_00414F04[];
extern "C" Object DAT_0046084C;
extern "C" char sub_0019F6B0[];

void __cdecl sub_002E9380(void)
{
    DAT_0046084C.sub_000654B0((int)DAT_00414F04, (int)DAT_00414EF4, (int)sub_0019F6B0, 0, 3, 3);
}
