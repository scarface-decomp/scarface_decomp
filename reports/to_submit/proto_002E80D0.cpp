// bin: proto
// va: 0x002E80D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E80D0 (Proto 0x002E80D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00411614[];
extern "C" char DAT_00411628[];
extern "C" Object DAT_0045FBE0;
extern "C" char sub_0018BA00[];

void __cdecl sub_002E80D0(void)
{
    DAT_0045FBE0.sub_000655A0((int)DAT_00411628, (int)DAT_00411614, (int)sub_0018BA00, 0, 2, 2);
}
