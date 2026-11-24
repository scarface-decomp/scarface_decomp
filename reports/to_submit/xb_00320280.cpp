// bin: xb
// va: 0x00320280
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320280 (0x00320280, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044E8E8[];
extern "C" Object DAT_00492864;
extern "C" char sub_00231400[];

void __cdecl sub_00320280(void)
{
    DAT_00492864.sub_0006F830(0, (int)DAT_0044E8E8, (int)sub_00231400, 0, 4, 4);
}
