// bin: proto
// va: 0x002E0AF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0AF0 (Proto 0x002E0AF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003F6754[];
extern "C" char DAT_003F675C[];
extern "C" Object DAT_004495CC;
extern "C" char sub_0002AA20[];

void __cdecl sub_002E0AF0(void)
{
    DAT_004495CC.sub_000655A0((int)DAT_003F675C, (int)DAT_003F6754, (int)sub_0002AA20, 0, 3, 3);
}
