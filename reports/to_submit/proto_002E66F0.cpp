// bin: proto
// va: 0x002E66F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E66F0 (Proto 0x002E66F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B724[];
extern "C" char DAT_0040B738[];
extern "C" Object DAT_0045D82C;
extern "C" char sub_00158520[];

void __cdecl sub_002E66F0(void)
{
    DAT_0045D82C.sub_000654B0((int)DAT_0040B738, (int)DAT_0040B724, (int)sub_00158520, 0, 2, 2);
}
