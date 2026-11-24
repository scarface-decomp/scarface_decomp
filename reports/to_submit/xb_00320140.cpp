// bin: xb
// va: 0x00320140
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320140 (0x00320140, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E7CC[];
extern "C" Object DAT_004926AC;
extern "C" char sub_00230DB0[];

void __cdecl sub_00320140(void)
{
    DAT_004926AC.sub_0006F830(0, (int)DAT_0044E7CC, (int)sub_00230DB0, 0, 2, 2);
}
