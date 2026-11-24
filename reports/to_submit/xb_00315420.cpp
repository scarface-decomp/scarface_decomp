// bin: xb
// va: 0x00315420
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315420 (0x00315420, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004248F0[];
extern "C" Object DAT_00486FD0;
extern "C" char sub_000CA6A0[];

void __cdecl sub_00315420(void)
{
    DAT_00486FD0.sub_0006F830(0, (int)DAT_004248F0, (int)sub_000CA6A0, 0, 4, 5);
}
