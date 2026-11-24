// bin: xb
// va: 0x003153E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003153E0 (0x003153E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004247E4[];
extern "C" char DAT_004247F4[];
extern "C" Object DAT_00486F78;
extern "C" char sub_000CA070[];

void __cdecl sub_003153E0(void)
{
    DAT_00486F78.sub_0006F830((int)DAT_004247F4, (int)DAT_004247E4, (int)sub_000CA070, 0, 4, 4);
}
