// bin: proto
// va: 0x002E4A70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4A70 (Proto 0x002E4A70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_00403170[];
extern "C" Object DAT_0045BD24;
extern "C" char sub_000FBC80[];

void __cdecl sub_002E4A70(void)
{
    DAT_0045BD24.sub_000655A0(0, (int)DAT_00403170, (int)sub_000FBC80, 0, 1, 1);
}
