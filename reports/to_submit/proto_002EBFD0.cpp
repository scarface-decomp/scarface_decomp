// bin: proto
// va: 0x002EBFD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EBFD0 (Proto 0x002EBFD0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_00427104[];
extern "C" char DAT_00427114[];
extern "C" Object DAT_00462854;
extern "C" char sub_001E5550[];

void __cdecl sub_002EBFD0(void)
{
    DAT_00462854.sub_00065460((int)DAT_00427114, (int)DAT_00427104, (int)sub_001E5550, 0, 4, 4);
}
