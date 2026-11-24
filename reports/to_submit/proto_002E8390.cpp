// bin: proto
// va: 0x002E8390
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8390 (Proto 0x002E8390, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00411B4C[];
extern "C" char DAT_00411B5C[];
extern "C" Object DAT_0045FE1C;
extern "C" char sub_0018C190[];

void __cdecl sub_002E8390(void)
{
    DAT_0045FE1C.sub_000655A0((int)DAT_00411B5C, (int)DAT_00411B4C, (int)sub_0018C190, 0, 2, 2);
}
