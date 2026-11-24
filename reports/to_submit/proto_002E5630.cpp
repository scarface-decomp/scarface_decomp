// bin: proto
// va: 0x002E5630
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5630 (Proto 0x002E5630, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00409590[];
extern "C" char DAT_00409598[];
extern "C" Object DAT_0045C310;
extern "C" char sub_0012D8E0[];

void __cdecl sub_002E5630(void)
{
    DAT_0045C310.sub_000655A0((int)DAT_00409598, (int)DAT_00409590, (int)sub_0012D8E0, 0, 3, 3);
}
