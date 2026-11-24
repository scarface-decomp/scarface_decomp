// bin: xb
// va: 0x00317A30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317A30 (0x00317A30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042EA24[];
extern "C" char DAT_0042EA34[];
extern "C" Object DAT_0048A558;
extern "C" char sub_0015C850[];

void __cdecl sub_00317A30(void)
{
    DAT_0048A558.sub_0006F830((int)DAT_0042EA34, (int)DAT_0042EA24, (int)sub_0015C850, 0, 2, 2);
}
