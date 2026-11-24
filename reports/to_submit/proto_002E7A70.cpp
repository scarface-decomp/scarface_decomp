// bin: proto
// va: 0x002E7A70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7A70 (Proto 0x002E7A70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00410D0C[];
extern "C" Object DAT_0045F500;
extern "C" char sub_0018AFE0[];

void __cdecl sub_002E7A70(void)
{
    DAT_0045F500.sub_000655A0(0, (int)DAT_00410D0C, (int)sub_0018AFE0, 0, 1, 1);
}
