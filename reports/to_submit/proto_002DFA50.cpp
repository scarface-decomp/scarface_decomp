// bin: proto
// va: 0x002DFA50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002DFA50 (Proto 0x002DFA50, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_003F40D0[];
extern "C" Object DAT_0043D888;
extern "C" char sub_00011850[];

void __cdecl sub_002DFA50(void)
{
    DAT_0043D888.sub_00065460(0, (int)DAT_003F40D0, (int)sub_00011850, 0, 3, 3);
}
