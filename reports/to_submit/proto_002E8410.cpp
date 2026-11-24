// bin: proto
// va: 0x002E8410
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8410 (Proto 0x002E8410, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_00411BC4[];
extern "C" char DAT_00411BCC[];
extern "C" Object DAT_0045FECC;
extern "C" char sub_0018C330[];

void __cdecl sub_002E8410(void)
{
    DAT_0045FECC.sub_000654B0((int)DAT_00411BCC, (int)DAT_00411BC4, (int)sub_0018C330, 0, 2, 2);
}
