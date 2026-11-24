// bin: proto
// va: 0x002E6970
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6970 (Proto 0x002E6970, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065460(int, int, int, int, int, int);
};

extern "C" char DAT_0040B9C8[];
extern "C" char DAT_0040B9E4[];
extern "C" Object DAT_0045DB9C;
extern "C" char sub_001587A0[];

void __cdecl sub_002E6970(void)
{
    DAT_0045DB9C.sub_00065460((int)DAT_0040B9E4, (int)DAT_0040B9C8, (int)sub_001587A0, 0, 2, 2);
}
