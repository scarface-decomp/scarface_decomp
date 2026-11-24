// bin: proto
// va: 0x002E68D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E68D0 (Proto 0x002E68D0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040B910[];
extern "C" char DAT_0040B924[];
extern "C" Object DAT_0045DAC0;
extern "C" char sub_001586E0[];

void __cdecl sub_002E68D0(void)
{
    DAT_0045DAC0.sub_000655A0((int)DAT_0040B924, (int)DAT_0040B910, (int)sub_001586E0, 0, 3, 3);
}
