// bin: xb
// va: 0x00315380
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315380 (0x00315380, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424770[];
extern "C" char DAT_00424788[];
extern "C" Object DAT_00486EF4;
extern "C" char sub_000CA020[];

void __cdecl sub_00315380(void)
{
    DAT_00486EF4.sub_0006F830((int)DAT_00424788, (int)DAT_00424770, (int)sub_000CA020, 0, 2, 2);
}
