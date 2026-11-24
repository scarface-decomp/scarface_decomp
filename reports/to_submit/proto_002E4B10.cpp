// bin: proto
// va: 0x002E4B10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4B10 (Proto 0x002E4B10, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00403300[];
extern "C" Object DAT_0045BDC0;
extern "C" char sub_000FE7D0[];

void __cdecl sub_002E4B10(void)
{
    DAT_0045BDC0.sub_00065550(0, (int)DAT_00403300, (int)sub_000FE7D0, 0, 5, 7);
}
