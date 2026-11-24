// bin: proto
// va: 0x002E5880
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5880 (Proto 0x002E5880, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00409B30[];
extern "C" char DAT_00409B44[];
extern "C" Object DAT_0045C640;
extern "C" char sub_00141A30[];

void __cdecl sub_002E5880(void)
{
    DAT_0045C640.sub_000655A0((int)DAT_00409B44, (int)DAT_00409B30, (int)sub_00141A30, 0, 2, 2);
}
