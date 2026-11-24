// bin: xb
// va: 0x00320200
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320200 (0x00320200, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E888[];
extern "C" Object DAT_004927B4;
extern "C" char sub_002312D0[];

void __cdecl sub_00320200(void)
{
    DAT_004927B4.sub_0006F830(0, (int)DAT_0044E888, (int)sub_002312D0, 0, 2, 6);
}
