// bin: xb
// va: 0x00316A40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316A40 (0x00316A40, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042887C[];
extern "C" Object DAT_004899A8;
extern "C" char sub_00119930[];

void __cdecl sub_00316A40(void)
{
    DAT_004899A8.sub_0006F830(0, (int)DAT_0042887C, (int)sub_00119930, 0, 2, 2);
}
