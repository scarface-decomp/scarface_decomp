// bin: xb
// va: 0x00320040
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320040 (0x00320040, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0044E52C[];
extern "C" Object DAT_0049254C;
extern "C" char sub_002308D0[];

void __cdecl sub_00320040(void)
{
    DAT_0049254C.sub_0006F740(0, (int)DAT_0044E52C, (int)sub_002308D0, 0, 3, 3);
}
