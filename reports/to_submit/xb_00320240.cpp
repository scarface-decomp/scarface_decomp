// bin: xb
// va: 0x00320240
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320240 (0x00320240, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044E8B4[];
extern "C" Object DAT_0049280C;
extern "C" char sub_00231160[];

void __cdecl sub_00320240(void)
{
    DAT_0049280C.sub_0006F880(0, (int)DAT_0044E8B4, (int)sub_00231160, 0, 1, 1);
}
