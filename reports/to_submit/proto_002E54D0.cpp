// bin: proto
// va: 0x002E54D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E54D0 (Proto 0x002E54D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00409008[];
extern "C" Object DAT_0045C2E4;
extern "C" char sub_0012D330[];

void __cdecl sub_002E54D0(void)
{
    DAT_0045C2E4.sub_000655A0(0, (int)DAT_00409008, (int)sub_0012D330, 0, 3, 3);
}
