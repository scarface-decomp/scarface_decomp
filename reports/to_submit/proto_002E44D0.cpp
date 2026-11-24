// bin: proto
// va: 0x002E44D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E44D0 (Proto 0x002E44D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000654B0(int, int, int, int, int, int);
};

extern "C" char DAT_004022A4[];
extern "C" Object DAT_0045B3C8;
extern "C" char sub_000D8EE0[];

void __cdecl sub_002E44D0(void)
{
    DAT_0045B3C8.sub_000654B0(0, (int)DAT_004022A4, (int)sub_000D8EE0, 0, 1, 1);
}
