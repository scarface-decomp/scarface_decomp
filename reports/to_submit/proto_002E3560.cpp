// bin: proto
// va: 0x002E3560
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3560 (Proto 0x002E3560, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000655A0(int, int, int, int, int, int);
};

extern "C" char DAT_003FF498[];
extern "C" char DAT_003FF4A4[];
extern "C" Object DAT_004596A8;
extern "C" char sub_000BAD20[];

void __cdecl sub_002E3560(void)
{
    DAT_004596A8.sub_000655A0((int)DAT_003FF4A4, (int)DAT_003FF498, (int)sub_000BAD20, 0, 2, 2);
}
