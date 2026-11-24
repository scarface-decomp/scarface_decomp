// bin: proto
// va: 0x002E60F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E60F0 (Proto 0x002E60F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B094[];
extern "C" char DAT_0040B0A4[];
extern "C" Object DAT_0045CFEC;
extern "C" char sub_00157F80[];

void __cdecl sub_002E60F0(void)
{
    DAT_0045CFEC.sub_000655A0((int)DAT_0040B0A4, (int)DAT_0040B094, (int)sub_00157F80, 0, 2, 2);
}
