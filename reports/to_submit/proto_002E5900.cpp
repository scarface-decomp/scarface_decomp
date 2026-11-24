// bin: proto
// va: 0x002E5900
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5900 (Proto 0x002E5900, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00409C4C[];
extern "C" char DAT_00409C60[];
extern "C" Object DAT_0045C6C4;
extern "C" char sub_00141BC0[];

void __cdecl sub_002E5900(void)
{
    DAT_0045C6C4.sub_00065550((int)DAT_00409C60, (int)DAT_00409C4C, (int)sub_00141BC0, 0, 3, 3);
}
