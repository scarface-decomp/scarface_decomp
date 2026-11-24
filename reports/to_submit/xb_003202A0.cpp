// bin: xb
// va: 0x003202A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003202A0 (0x003202A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0044E8FC[];
extern "C" Object DAT_00492890;
extern "C" char sub_00231440[];

void __cdecl sub_003202A0(void)
{
    DAT_00492890.sub_0006F880(0, (int)DAT_0044E8FC, (int)sub_00231440, 0, 1, 1);
}
