// bin: proto
// va: 0x002E6990
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6990 (Proto 0x002E6990, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040B9F4[];
extern "C" char DAT_0040BA04[];
extern "C" Object DAT_0045DBC8;
extern "C" char sub_001587C0[];

void __cdecl sub_002E6990(void)
{
    DAT_0045DBC8.sub_00065550((int)DAT_0040BA04, (int)DAT_0040B9F4, (int)sub_001587C0, 0, 2, 2);
}
