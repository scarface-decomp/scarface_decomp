// bin: xb
// va: 0x00320080
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320080 (0x00320080, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E564[];
extern "C" Object DAT_004925A4;
extern "C" char sub_00230830[];

void __cdecl sub_00320080(void)
{
    DAT_004925A4.sub_0006F830(0, (int)DAT_0044E564, (int)sub_00230830, 0, 2, 2);
}
