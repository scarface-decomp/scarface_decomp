// bin: xb
// va: 0x00320160
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320160 (0x00320160, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E82C[];
extern "C" Object DAT_004926D8;
extern "C" char sub_00230E90[];

void __cdecl sub_00320160(void)
{
    DAT_004926D8.sub_0006F830(0, (int)DAT_0044E82C, (int)sub_00230E90, 0, 1, 2);
}
