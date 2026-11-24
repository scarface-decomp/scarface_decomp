// bin: xb
// va: 0x003153C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003153C0 (0x003153C0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_004247BC[];
extern "C" char DAT_004247D0[];
extern "C" Object DAT_00486F4C;
extern "C" char sub_000CA050[];

void __cdecl sub_003153C0(void)
{
    DAT_00486F4C.sub_0006F830((int)DAT_004247D0, (int)DAT_004247BC, (int)sub_000CA050, 0, 3, 3);
}
