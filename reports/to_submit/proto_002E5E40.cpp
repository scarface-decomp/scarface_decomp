// bin: proto
// va: 0x002E5E40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5E40 (Proto 0x002E5E40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_0040A9D8[];
extern "C" Object DAT_0045CC28;
extern "C" char sub_00146320[];

void __cdecl sub_002E5E40(void)
{
    DAT_0045CC28.sub_00065550(0, (int)DAT_0040A9D8, (int)sub_00146320, 0, 2, 2);
}
