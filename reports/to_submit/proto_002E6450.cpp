// bin: proto
// va: 0x002E6450
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6450 (Proto 0x002E6450, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B438[];
extern "C" char DAT_0040B44C[];
extern "C" Object DAT_0045D490;
extern "C" char sub_00158330[];

void __cdecl sub_002E6450(void)
{
    DAT_0045D490.sub_000655A0((int)DAT_0040B44C, (int)DAT_0040B438, (int)sub_00158330, 0, 2, 2);
}
