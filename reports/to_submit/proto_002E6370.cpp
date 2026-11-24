// bin: proto
// va: 0x002E6370
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6370 (Proto 0x002E6370, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B334[];
extern "C" char DAT_0040B348[];
extern "C" Object DAT_0045D35C;
extern "C" char sub_001582A0[];

void __cdecl sub_002E6370(void)
{
    DAT_0045D35C.sub_000654B0((int)DAT_0040B348, (int)DAT_0040B334, (int)sub_001582A0, 0, 2, 2);
}
