// bin: proto
// va: 0x002EC290
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC290 (Proto 0x002EC290, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_004274AC[];
extern "C" Object DAT_00462BF0;
extern "C" char sub_001E5B20[];

void __cdecl sub_002EC290(void)
{
    DAT_00462BF0.sub_000655A0(0, (int)DAT_004274AC, (int)sub_001E5B20, 0, 3, 3);
}
