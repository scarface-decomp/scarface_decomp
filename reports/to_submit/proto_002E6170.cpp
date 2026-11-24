// bin: proto
// va: 0x002E6170
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6170 (Proto 0x002E6170, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B11C[];
extern "C" char DAT_0040B12C[];
extern "C" Object DAT_0045D09C;
extern "C" char sub_00158090[];

void __cdecl sub_002E6170(void)
{
    DAT_0045D09C.sub_000655A0((int)DAT_0040B12C, (int)DAT_0040B11C, (int)sub_00158090, 0, 2, 2);
}
