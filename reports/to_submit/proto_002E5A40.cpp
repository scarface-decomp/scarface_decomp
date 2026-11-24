// bin: proto
// va: 0x002E5A40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5A40 (Proto 0x002E5A40, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409EA4[];
extern "C" char DAT_00409EB4[];
extern "C" Object DAT_0045C830;
extern "C" char sub_00141E90[];

void __cdecl sub_002E5A40(void)
{
    DAT_0045C830.sub_00065550((int)DAT_00409EB4, (int)DAT_00409EA4, (int)sub_00141E90, 0, 2, 2);
}
