// bin: xb
// va: 0x00315DD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315DD0 (0x00315DD0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00424F34[];
extern "C" Object DAT_00487654;
extern "C" char sub_000D9880[];

void __cdecl sub_00315DD0(void)
{
    DAT_00487654.sub_0006F830(0, (int)DAT_00424F34, (int)sub_000D9880, 0, 3, 3);
}
