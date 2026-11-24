// bin: proto
// va: 0x002E8050
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8050 (Proto 0x002E8050, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004115CC[];
extern "C" Object DAT_0045FB5C;
extern "C" char sub_0018B9C0[];

void __cdecl sub_002E8050(void)
{
    DAT_0045FB5C.sub_000655A0(0, (int)DAT_004115CC, (int)sub_0018B9C0, 0, 2, 2);
}
