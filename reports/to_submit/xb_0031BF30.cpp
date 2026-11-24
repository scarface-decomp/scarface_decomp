// bin: xb
// va: 0x0031BF30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BF30 (0x0031BF30, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043B3B4[];
extern "C" Object DAT_0048F204;
extern "C" char sub_001D6CD0[];

void __cdecl sub_0031BF30(void)
{
    DAT_0048F204.sub_0006F880(0, (int)DAT_0043B3B4, (int)sub_001D6CD0, 0, 1, 1);
}
