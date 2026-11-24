// bin: xb
// va: 0x00316770
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316770 (0x00316770, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00427938[];
extern "C" Object DAT_00489384;
extern "C" char sub_000EEC30[];

void __cdecl sub_00316770(void)
{
    DAT_00489384.sub_0006F830(0, (int)DAT_00427938, (int)sub_000EEC30, 0, 2, 2);
}
