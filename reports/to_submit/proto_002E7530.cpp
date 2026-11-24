// bin: proto
// va: 0x002E7530
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7530 (Proto 0x002E7530, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004104C8[];
extern "C" char DAT_004104D4[];
extern "C" Object DAT_0045F030;
extern "C" char sub_0018A300[];

void __cdecl sub_002E7530(void)
{
    DAT_0045F030.sub_000655A0((int)DAT_004104D4, (int)DAT_004104C8, (int)sub_0018A300, 0, 2, 2);
}
