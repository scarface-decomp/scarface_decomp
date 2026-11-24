// bin: proto
// va: 0x002E7670
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7670 (Proto 0x002E7670, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0041069C[];
extern "C" Object DAT_0045F190;
extern "C" char sub_0018A530[];

void __cdecl sub_002E7670(void)
{
    DAT_0045F190.sub_000655A0(0, (int)DAT_0041069C, (int)sub_0018A530, 0, 1, 1);
}
