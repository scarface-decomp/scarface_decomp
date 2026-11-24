// bin: xb
// va: 0x003165B0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003165B0 (0x003165B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F7E0(int, int, int, int, int, int);
};

extern "C" char DAT_00427808[];
extern "C" Object DAT_0048911C;
extern "C" char sub_000EEAA0[];

void __cdecl sub_003165B0(void)
{
    DAT_0048911C.sub_0006F7E0(0, (int)DAT_00427808, (int)sub_000EEAA0, 0, 2, 2);
}
