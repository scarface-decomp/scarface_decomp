// bin: proto
// va: 0x002E5860
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5860 (Proto 0x002E5860, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409B08[];
extern "C" char DAT_00409B20[];
extern "C" Object DAT_0045C614;
extern "C" char sub_00141AA0[];

void __cdecl sub_002E5860(void)
{
    DAT_0045C614.sub_00065550((int)DAT_00409B20, (int)DAT_00409B08, (int)sub_00141AA0, 0, 3, 3);
}
