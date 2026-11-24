// bin: xb
// va: 0x003152B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003152B0 (0x003152B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3A0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_003A53EC[];
extern "C" Object DAT_00486E64;
extern "C" char sub_000C6760[];

void __cdecl sub_003152B0(void)
{
    DAT_00486E64.sub_000EB3A0(15, 44, 30, 92, 52, (int)DAT_003A53EC, (int)sub_000C6760, 197, 0, 1);
}
