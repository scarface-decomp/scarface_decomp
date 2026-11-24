// bin: proto
// va: 0x002E6B70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6B70 (Proto 0x002E6B70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_0040C878[];
extern "C" char DAT_0040C888[];
extern "C" Object DAT_0045DCB8;
extern "C" char sub_0015A680[];

void __cdecl sub_002E6B70(void)
{
    DAT_0045DCB8.sub_000655A0((int)DAT_0040C888, (int)DAT_0040C878, (int)sub_0015A680, 0, 2, 2);
}
