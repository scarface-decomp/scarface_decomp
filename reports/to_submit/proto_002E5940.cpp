// bin: proto
// va: 0x002E5940
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5940 (Proto 0x002E5940, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409C90[];
extern "C" char DAT_00409CA4[];
extern "C" Object DAT_0045C71C;
extern "C" char sub_00141BF0[];

void __cdecl sub_002E5940(void)
{
    DAT_0045C71C.sub_00065550((int)DAT_00409CA4, (int)DAT_00409C90, (int)sub_00141BF0, 0, 6, 6);
}
