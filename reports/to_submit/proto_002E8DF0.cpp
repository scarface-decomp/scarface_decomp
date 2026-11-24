// bin: proto
// va: 0x002E8DF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8DF0 (Proto 0x002E8DF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00413D74[];
extern "C" char DAT_00413D88[];
extern "C" Object DAT_0046038C;
extern "C" char sub_0019AEE0[];

void __cdecl sub_002E8DF0(void)
{
    DAT_0046038C.sub_000654B0((int)DAT_00413D88, (int)DAT_00413D74, (int)sub_0019AEE0, 0, 3, 3);
}
