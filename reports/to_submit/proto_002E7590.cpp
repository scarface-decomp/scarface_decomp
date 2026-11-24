// bin: proto
// va: 0x002E7590
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7590 (Proto 0x002E7590, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00410510[];
extern "C" char DAT_00410520[];
extern "C" Object DAT_0045F0B4;
extern "C" char sub_0018A330[];

void __cdecl sub_002E7590(void)
{
    DAT_0045F0B4.sub_000655A0((int)DAT_00410520, (int)DAT_00410510, (int)sub_0018A330, 0, 3, 4);
}
