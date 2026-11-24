// bin: xb
// va: 0x00320180
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320180 (0x00320180, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E838[];
extern "C" Object DAT_00492704;
extern "C" char sub_00231060[];

void __cdecl sub_00320180(void)
{
    DAT_00492704.sub_0006F830(0, (int)DAT_0044E838, (int)sub_00231060, 0, 1, 3);
}
